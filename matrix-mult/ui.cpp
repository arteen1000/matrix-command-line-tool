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
    
//    matrixOperationPrompt();
//    verifyOperationPossible();
//    allocateDependencies();
//    performOperation();
//    deallocateDependencies();
//    reinitializeForNextCycle();
}

// initial requirements
UI::UI() : m_rowsA(0), m_colsA(1 << 31), m_rowsB(0), m_colsB(1 << 31), m_rowsC(0), m_colsC(0) {
}

// terminating message
UI::~UI(){
    
}



// ********************
// READ AND PARSE INPUT
// ********************

void UI::coordinateInput(const InputType inputType, const MatrixID matrixID){
    string s; bool valid;
    do {
        getline(cin, s);
//        cout << "bool status: " << isValidInput(s, inputType) << endl;
        if (!(valid = isValidInput(s, inputType)) || (!otherInput(s, inputType) && !matrixInput(s, matrixID))){
            cout << "Invalid input. Try again: ";
        }
    } while (!valid);
    
    m_buffer = istringstream(s);
}

bool UI::isValidInput(const string& input, const InputType inputType){
    switch(inputType){
        case operation:
            return input.find_first_not_of("0123") == std::string::npos;
        case scalar:
            return input.find_first_not_of("0123456789-.") == std::string::npos;
        case matrix:
            return input.find_first_not_of("0123456789-. ") == std::string::npos;
    }
}

bool UI::otherInput(const std::string & input, const InputType inputType){
    if (inputType == matrix) return false;
    else if (inputType == operation){
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
    int dotCount = 0;
    for (int i = 0 ; i < n ; i++){
        if (isdigit(input[i])){
            prev = digit;
        } else if (input[i] == ' '){
            prev = null;
            dotCount = 0;
        } else if (input[i] == '-'){
            if (prev != null) return false;
            prev = minus;
        } else {
            if (prev == dot) return false;
            prev = dot;
            dotCount++;
        }
        if (dotCount > 1) return false;
    }
    
    return true;
}


// ************
// DIM-HANDLERS
// ************

void UI::outputMatrixA(){
    
    for (int i = 0 ; i < m_rowsA ; i++){
        for (int j = 0 ; j < m_colsA ; j++){
            cout << m_A[i][j] << " ";
        }
        cout << endl;
    }
}

bool UI::handleMatrixA(const string& input){    // as we input, have it return false if doesn't go to end of line (another input validation step)
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


// *********
// DIRECTORS
// *********

void UI::matrixOperationPrompt(){
    
}

void UI::allocateDependencies(){
    
}

void UI::performOperation(){
    
}

void UI::reinitializeConstructs(){
    
}











































