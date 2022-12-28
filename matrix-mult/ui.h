//
//  ui.hpp
//  matrix-mult

#ifndef ui_h
#define ui_h


#include "matrix.h"
#include <string>
#include <sstream>

// ensure correct input received
enum InputType {operation, scalar, matrix};

// ensure parsing for correct matrix -> NaM = Not a Matrix
enum MatrixID {A, B, NaM};

class UI{
public:
    // ******
    // MASTER
    // ******
    
    // main control flow of program
    void master();
    
    // responsible for initializing any constructs
    UI();
    
    // terminating message
    ~UI();
   
protected:
    // ********************
    // READ AND PARSE INPUT
    // ********************
    
    // read input from the user
    void readInput(const InputType, const MatrixID);

    // main input handler
    bool isValidInput(const std::string&, const InputType);
    
    // ensure is of correct form
    // also ensure does not contradict prior entries -> i.e, same # of cols
    bool parseInput(const std::string&, const MatrixID);
    
    // ************
    // DIM-HANDLERS
    // ************
    
    // handle dim-setting & updating for parseInput()
    bool handleMatrixA(const int);
    bool handleMatrixB(const int);
    
    // *********
    // DIRECTORS
    // *********
    
    // prompt user to select wanted operation
    // have sub-handlers handle each select operation
    void matrixOperationPrompt();
    
    // verify the operation is possible with user selections
    // input will be valid but not necessarily compatible
    void verifyOperationPossible();
    
    // set dimension of any dependencies and allocate them
    void allocateDependencies();
    
    // responsible for performing each respective operation
    void performOperation();
    
    // deallocate any dependencies, including input matrices
    void deallocateDependencies();
    
    // responsible for resetting all constructs to default
    void reinitializeForNextCycle();
    
private:
    // used to handle input allocation
    std::istringstream m_buffer;
    
    // used to handle dimensions of matrices
    int32_t m_rowsA;
    int32_t m_colsA;
    
    int32_t m_rowsB;
    int32_t m_colsB;
    
    int32_t m_rowsC;
    int32_t m_colsC;
    
};

#endif /* ui_hpp */
