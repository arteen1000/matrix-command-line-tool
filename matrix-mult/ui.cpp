//
//  ui.cpp
//  matrix-mult

#include "ui.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cctype>

using std::string;
using std::istringstream;
using std::cin;
using std::cout;
using std::endl;


// ******
// MASTER
// ******

// program control flow
void UI::master(){
    
    coordinateInput(matrix, A);
//    matrixOperationPrompt();
//    verifyOperationPossible();
//    allocateDependencies();
//    performOperation();
//    deallocateDependencies();
//    reinitializeForNextCycle();
}

// initial requirements
UI::UI() : m_rowsA(1 << 31), m_colsA(1 << 31), m_rowsB(1 << 31), m_colsB(1 << 31), m_rowsC(1 << 31), m_colsC(1 << 31) {
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
    for (int i = 0 ; i < n ; i++){
        if (isdigit(input[i])){
            prev = digit;
        } else if (input[i] == '-'){
            if (prev != null) return false;
            prev = minus;
        } else if (input[i] == '.'){
            if (prev == dot) return false;
            prev = dot;
        } else return false;
    }
    m_buffer = istringstream(input);
    m_buffer >> m_k;
    return true;
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
    for (int i = 0 ; i < n ; i++){
        if (isdigit(input[i])){
            prev = digit;
        } else if (input[i] == ' '){
            prev = null;
        } else if (input[i] == '-'){
            if (prev != null) return false;
            prev = minus;
        } else if (input[i] == '.'){
            if (prev == dot) return false;
            prev = dot;
        } else return false;
    }
    
    return true;
}


// ************
// DIM-HANDLERS
// ************

bool UI::handleMatrixA(const string& input){
    return true;
}

bool UI::handleMatrixB(const string& input){
    return true;
}


// *********
// DIRECTORS
// *********

void UI::matrixOperationPrompt(){
    
}

void UI::verifyOperationPossible(){
    
}

void UI::allocateDependencies(){
    
}

void UI::performOperation(){
    
}

void UI::reinitializeForNextCycle(){
    
}











































