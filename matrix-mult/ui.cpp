//
//  ui.cpp
//  matrix-mult

#include "ui.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cctype>
#include <vector>

using std::string;
using std::istringstream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;


// ******
// MASTER
// ******

// program control flow
void UI::master(){
    
    matrixOperationPrompt();
//    verifyOperationPossible();
//    allocateDependencies();
//    performOperation();
//    deallocateDependencies();
//    reinitializeForNextCycle();
}

// initial requirements
UI::UI() : m_rowsA(0), m_colsA(1 << 31), m_rowsB(0), m_colsB(1 << 31), m_rowsC(0), m_colsC(0), m_prompt(true) {
}

// terminating message
UI::~UI(){
    
}



// ********************
// READ AND PARSE INPUT
// ********************

void UI::readInput(const InputType inputType, const MatrixID matrixID){
    string s;
    retry:
        getline(cin, s);
        if (!(isValidInput(s, inputType)) || (!otherInput(s, inputType) && !matrixInput(s, matrixID))){
            cout << "Invalid input. Try again: ";
            goto retry;
        }
}

bool UI::isValidInput(const string& input, const InputType inputType){
    switch(inputType){
        case operation:
            return input.find_first_not_of("012") == std::string::npos;
        case scalar:
            return input.find_first_not_of("0123456789-.") == std::string::npos;
        case matrix:
            return input.find_first_not_of("0123456789-. ") == std::string::npos;
    }
}

bool UI::otherInput(const std::string & input, const InputType inputType){
    if (inputType == matrix) return false;
    else if (inputType == operation){
        if (input.empty()) return false;
        m_buffer = istringstream(input);
        m_buffer >> m_operation;
        return true;
    } else return handleScalar(input);
}

bool UI::handleScalar(const string& input){
    int n = static_cast<int> (input.size());
    previousInput prev = null;
    int dotCount = 0; bool digitLast = false;
    for (int i = 0 ; i < n ; i++){
        if (isdigit(input[i])){
            prev = digit; digitLast = true;
        } else if (input[i] == '-'){
            if (prev != null) return false;
            prev = minus; digitLast = false;
        } else {
            if (prev == dot) return false;
            prev = dot;
            dotCount++; digitLast = false;
        }
        if (dotCount > 1) return false;
    }
    if (!digitLast) return false;
    m_buffer = istringstream(input);
    if (m_buffer >> m_k) return true;
    return false;
}

bool UI::matrixInput(const string& input, const MatrixID matrixID){
    if (matrixID == NaM) return false;
    
    m_buffer = istringstream(input);
    
    if (!validateMatrixInputFormat(input)) return false;
    
    switch(matrixID){
        case A:
            return handleMatrixA(input);
        case B:
            return handleMatrixB(input);    // if (!m_buffer.eof()) return false;
        case NaM:
            break;
    }
        
    return true;
}

bool UI::validateMatrixInputFormat(const string& input){
    int n = static_cast<int> (input.size());
    previousInput prev = null;
    int dotCount = 0; bool badLast = false;
    for (int i = 0 ; i < n ; i++){
        if (isdigit(input[i])){
            prev = digit; badLast = false;
        } else if (input[i] == ' '){
            if (prev == dot) return false;
            prev = null; dotCount = 0;
        } else if (input[i] == '-'){
            if (prev != null) return false;
            prev = minus; badLast = true;
        } else {
            if (prev == dot) return false;
            prev = dot; badLast = true;
            dotCount++;
        }
        if (dotCount > 1) return false;
    }
    if (badLast) return false;
    return true;
}


// ********
// HANDLERS
// ********

bool UI::handleMatrixA(const string& input){    // as we input, have it return false if doesn't go to end of line (another input validation step)
    if (input.empty()){
        m_prompt = false; return true;
    }
    Entries value; m_buffer = istringstream(input);
    int cols = 0; vector<Entries> row; row.reserve(4);
    while (m_buffer >> value){
        cols++;
        row.push_back(value);
    }
    if (!m_buffer.eof()) return false;
    if (m_colsA == 1 << 31) m_colsA = cols;
    else if (cols != m_colsA) return false;
    
    m_matrix.addRow(m_A, row); m_rowsA++;
    
    return true;
}

bool UI::handleMatrixB(const string& input){
    Entries value; m_buffer = istringstream(input);
    int cols = 0; vector<Entries> row; row.reserve(4);
    while (m_buffer >> value){
        cols++;
        row.push_back(value);
    }
    if (!m_buffer.eof()) return false;
    if (m_colsB == 1 << 31) m_colsB = cols;
    else if (cols != m_colsB) return false;
    
    m_matrix.addRow(m_B, row); m_rowsB++;
    
    return true;
}

// ******************
// OUTPUT && REFACTOR
// ******************

// output & refactor master
void UI::outputMatrix(const std::vector< std::vector<Entries> >&, const int32_t, const int32_t){
    
}

void UI::refactorMatrix(const std::vector< std::vector<Entries> >&, const int32_t, const int32_t){
    
}

// *********
// DIRECTORS
// *********

// MASTER
// ------

void UI::matrixOperationPrompt(){
    cout << "*****************" << endl;
    cout << "MATRIX OPERATIONS" << endl;
    cout << "*****************" << endl << endl;
    
    cout << "Select an option below: " << endl << endl;
    cout << "(0) kA = C" << endl;
    cout << "(1) A+B = C" << endl;
    cout << "(2) AB = C" << endl << endl;
    
    cout << "Option: "; readInput(operation, NaM);
    cout << endl;
    switch(m_operation){
        case 0:
            readScalarMult();
            break;
        case 1:
            readMatrixAdd();
            break;
        case 2:
            readMatrixMult();
            break;
    }
}

// SLAVES
// ------

void UI::readScalarMult(){
    cout << "Scalar Multiplication" << endl;
    cout << "---------------------" << endl << endl;
    
    cout << "k = "; readInput(scalar, NaM);
    cout << endl;
    
    cout << "Matrix A" << endl;
    cout << "--------" << endl << endl;
    
    int i = 1;
    while (m_prompt){
        cout << "Row " << i << ": "; readInput(matrix, A);
    }
    m_prompt = true;
    
    
}

void UI::readMatrixAdd(){
    
}

void UI::readMatrixMult(){
    
}










void UI::allocateDependencies(){
    
}

void UI::performOperation(){
    
}

void UI::reinitializeConstructs(){
    
}











































