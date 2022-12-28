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
    
    readInput(matrix, A);
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

void UI::readInput(const InputType inputType, const MatrixID matrixID){
    string s; bool valid;
    do {
        getline(cin, s);
        if (!(valid = isValidInput(s, inputType)) || (inputType == matrix && !parseInput(s, matrixID))){
            cout << "Invalid input. Try again: ";
        }
    } while (!valid);
    
    if (inputType == matrix) parseInput(s, matrixID);
    m_buffer = istringstream(s);
}

bool UI::isValidInput(const string& input, const InputType inputType){
    switch(inputType){
        case operation:
            return input.find_first_not_of("0123") == std::string::npos;
            break;
        case scalar:
            return input.find_first_not_of("0123456789-.") == std::string::npos;
            break;
        case matrix:
            return input.find_first_not_of("0123456789-. ") == std::string::npos;
            break;
    }
}


bool UI::parseInput(const string& input, const MatrixID matrixID){
    m_buffer = istringstream(input);
    
    if (!validateInputFormat(input)) return false;
    
    switch(matrixID){
        case A:
            return handleMatrixA(input);
        case B:
            return handleMatrixB(input);    // if (!m_buffer.eof()) return false;
        case NaM:
            cout << "Input type cannot be NaM if parsing input." << endl;
            exit(-1);
    }
        
    return true;
}

enum previousInput {digit, dot, minus, null};

bool UI::validateInputFormat(const string& input){
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
    return false;
}

bool UI::handleMatrixB(const string& input){
    return false;
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

void UI::deallocateDependencies(){
    
}


void UI::reinitializeForNextCycle(){
    
}











































