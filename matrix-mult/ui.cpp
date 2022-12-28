//
//  ui.cpp
//  matrix-mult

#include "ui.h"
#include <string>
#include <sstream>
#include <iostream>

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
UI::UI() : m_rowsA(1 << 31), m_colsA(1 << 31), m_rowsB(1 << 31), m_colsB(1 << 31), m_rowsC(1 << 31), m_colsC(1 << 31){
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

bool UI::isValidInput(const std::string& input, const InputType inputType){
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


bool UI::parseInput(const std::string& input, const MatrixID matrixID){
    m_buffer = istringstream(input);
    Entries test = 0.0; int count = 0;
    
    while (m_buffer >> test){
        count++;
    }
    
    if (!m_buffer.eof()) return false;
    
    switch(matrixID){
        case A:
            return handleMatrixA(count);
        case B:
            return handleMatrixB(count);
        case NaM:
            cout << "Input type cannot be NaM if parsing input." << endl;
            exit(-1);
    }
    
    return true;
}


// ************
// DIM-HANDLERS
// ************

bool UI::handleMatrixA(const int colEntries){
    return false;
}

bool UI::handleMatrixB(const int colEntries){
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











































