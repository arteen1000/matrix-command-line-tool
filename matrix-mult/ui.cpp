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


#define UP_ONE_LINE "\033[A"
#define DELETE_LINE "\033[2K"

// ******
// MASTER
// ******

// program control flow
bool UI::master(){
    
    handleUserInput();
    if (verifyPossible()){
        allocateDependencies();
        performOperation();
        deallocateDependencies();
    }
    else {
        cout << "Operation not possible with input dimensions." << endl << endl;
    }
    
    cout << endl << "Perform another operation (1) or exit program (0): "; readInput(yesno, NaM);
    m_count++;
    
    if (m_yesno) reinitializeConstructs();
    return m_yesno;
}

// initial requirements
UI::UI() : m_rowsA(0), m_colsA(1 << 31), m_rowsB(0), m_colsB(1 << 31), m_rowsC(0), m_colsC(0), m_prompt(1) , m_errors(0), m_yesno(0), m_count(0){
    m_C = nullptr;
    m_A.reserve(4);
    m_B.reserve(4);
}

// terminating message
UI::~UI(){
    string s = "operation";
    if (m_count > 1) s += 's';
    cout << "You performed " << m_count << " " << s;
    
    if (m_count < 10){
        cout << ". Single digits, you could do better." << endl;
    } else if (m_count < 20){
        cout << "...double digits...getting better, but not good enough." << endl;
    } else if (m_count < 30){
        cout << ". Almost there. You can make it." << endl;
    } else if (m_count < 40){
        cout << ". Keep going, I swear there's a prize for this." << endl;
    } else if (m_count < 50) {
        cout << ". C'mon, you can make it." << endl;
    } else {
        cout << ". Almost there..." << endl;
    }
}



// ********************
// READ AND PARSE INPUT
// ********************

void UI::readInput(const InputType inputType, const MatrixID matrixID){
    string s;
    retry:
        std::getline(cin, s);
        if (!(isValidInput(s, inputType)) || (!otherInput(s, inputType) && !matrixInput(s, matrixID))){
            cout << "Invalid input. Try again: "; m_errors++;
            goto retry;
        }
}

bool UI::isValidInput(const string& input, const InputType inputType){
    switch(inputType){
        case yesno:
            return input.find_first_not_of("01") == std::string::npos;
        case operation:
            return input.find_first_not_of("012") == std::string::npos;
        case scalar:
            return input.find_first_not_of("0123456789-.") == std::string::npos;
        case matrix:
            return input.find_first_not_of("0123456789-. ") == std::string::npos;
    }
    return false;
}

bool UI::otherInput(const std::string & input, const InputType inputType){
    if (inputType == matrix) return false;
    else if (inputType == operation){
        if (input.empty() || input.size() > 1 ) return false;
        m_buffer = istringstream(input);
        m_buffer >> m_operation;
        return true;
    } else if (inputType == scalar) return handleScalar(input);
    else {
        if (input.empty() || input.size() > 1) return false;
        m_buffer = istringstream(input);
        m_buffer >> m_yesno;
        return true;
    }
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
    
    if (input.empty()){
        m_prompt = false; return true;
    }

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

bool UI::handleMatrixA(const string& input){
    
    Entries value; m_buffer = istringstream(input);
    int cols = 0; vector<Entries> row; row.reserve(4);
    while (m_buffer >> value){
        cols++;
        row.push_back(value);
    }
    if (!m_buffer.eof()) return false;
    if (m_colsA == 1 << 31) m_colsA = cols;
    else if (cols != m_colsA) return false;
    
    m_A.push_back(std::move(row)); m_rowsA++;
    
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
    
    m_B.push_back(std::move(row)); m_rowsB++;
    
    return true;
}

// ******************
// OUTPUT && REFACTOR
// ******************

// output & refactor master

// user input
void UI::outputMatrix(const std::vector< std::vector<Entries> >& M, const int32_t rows, const int32_t cols){
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            std::printf("%-15.3f ", M[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

// output
void UI::outputMatrix(const Entries* M, const int32_t rows, const int32_t cols){
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            std::printf("%-15.3f ", M[i*cols+j]);
        }
        cout << endl;
    }
    cout << endl;
}

void UI::refactorMatrix(const int32_t rows){
    for (int i = 0 ; i < rows + 1 + m_errors; i++)
        cout << UP_ONE_LINE DELETE_LINE;
}

void UI::refactorOther(){
    for (int i = 0 ; i < m_errors + 1 ; i++)
        cout << UP_ONE_LINE DELETE_LINE;
}

void UI::resetRead(){
    m_prompt = true; m_errors = 0;
}



// *********
// USER INPUT
// *********

// MASTER
// ------

void UI::handleUserInput(){
    cout << endl << "*****************" << endl;
    cout << "MATRIX OPERATIONS" << endl;
    cout << "*****************" << endl << endl;
    
    cout << "Select an option below: " << endl << endl;
    cout << "(0) kA = C" << endl;
    cout << "(1) A+B = C" << endl;
    cout << "(2) AB = C" << endl << endl;
    
    cout << "Option: "; readInput(operation, NaM);
    if (m_errors > 0){
        refactorOther();
        resetRead();
        cout << "Option: " << m_operation << endl;
    }
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
    if (m_errors > 0){
        refactorOther();
        resetRead();
        cout << "k = " << m_k << endl;
    }
    cout << endl;
    
    cout << "Matrix A" << endl;
    cout << "--------" << endl << endl;
    readMatrix(A);
}

void UI::readMatrixAdd(){
    cout << "Matrix Addition" << endl;
    cout << "---------------" << endl << endl;
    
    readMatrixAB();
}

void UI::readMatrixMult(){
    cout << "Matrix Multiplication" << endl;
    cout << "---------------" << endl << endl;
    
    readMatrixAB();
}

void UI::readMatrixAB(){
    cout << "Matrix A" << endl;
    cout << "--------" << endl << endl;
    readMatrix(A);
    cout << "Matrix B" << endl;
    cout << "--------" << endl << endl;
    readMatrix(B);
}

void UI::readMatrix(MatrixID ID){
    
    for (int i = 1; m_prompt ; i++){
        cout << "Row " << i << ": "; readInput(matrix, ID);
    }
    switch(ID){
        case A:
            refactorMatrix(m_rowsA);
            outputMatrix(m_A, m_rowsA, m_colsA);
            break;
        case B:
            refactorMatrix(m_rowsB);
            outputMatrix(m_B, m_rowsB, m_colsB);
            break;
        case NaM:
            break;
    }
    resetRead();
}


// ***************
// VERIFICATION
// **************


// verify operation possibility based on user input && set dims of output
bool UI::verifyPossible(){
    switch(m_operation){
        case 0:
            m_rowsC = m_rowsA;
            m_colsC = m_colsA;
            return true;
        case 1:
            if (m_rowsA == m_rowsB && m_colsA == m_colsB) {
                m_rowsC = m_rowsA;
                m_colsC = m_colsA;
                return true;
            }
            else return false;
        case 2:
            if (m_colsA == m_rowsB){
                m_rowsC = m_rowsA;
                m_colsC = m_colsB;
                return true;
            }
            else return false;
        default:
            break;
    }
    
    return false;
}


// **********
// ALLOCATION
// **********

// reserve C
void UI::allocateDependencies(){
    m_C = new Entries[m_rowsC * m_colsC];
}

// *************
// DE-ALLOCATION
// *************

void UI::deallocateDependencies(){
    delete [] m_C;
}

// ****************
// OPERATION OUTPUT
// ****************

// MASTER
// ------

void UI::performOperation(){
    switch(m_operation){
        case 0:
            m_ops.performScalarMultiply(m_k, m_A, m_C, m_rowsC, m_colsC);
            break;
        case 1:
            m_ops.performMatrixAddition(m_A, m_B, m_C, m_rowsC, m_colsC);
            break;
        case 2:
            m_ops.performMatrixMultiply(m_A, m_B, m_C, m_rowsC, m_colsA, m_colsC);
            break;
        default:
            break;
    }
    
    switch(m_operation){
        case 0:
        case 1:
        case 2:
            outputMatrixC();
            break;
        default:
            break;
    }
    
}

// SLAVES
// ------

void UI::outputMatrixC(){
    cout << "Matrix C" << endl;
    cout << "--------" << endl << endl;
    
    outputMatrix(m_C, m_rowsC, m_colsC);
}


// *******
// RE-INIT
// *******
void UI::reinitializeConstructs(){
    m_rowsA = 0; m_colsA = 1 << 31; m_rowsB = 0; m_colsB = 1 << 31;
    m_rowsC = 0; m_colsC = 0; m_prompt = 1; m_errors = 0;
    m_C = nullptr;
    m_A = vector<vector<Entries>>(); m_A.reserve(4);
    m_B = vector<vector<Entries>>(); m_B.reserve(4);
}











































