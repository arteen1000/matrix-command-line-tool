//
//  ui.hpp
//  matrix-mult

#ifndef ui_h
#define ui_h


#include "matrix.h"
#include <string>
#include <sstream>
#include <vector>

// ensure correct input received
enum InputType {operation, scalar, matrix};

// ensure parsing for correct matrix -> NaM = Not a Matrix
enum MatrixID {A, B, NaM};

// used for input validation
enum previousInput {digit, dot, minus, null};

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
    
    // read input from the user & coordinate destination
    void coordinateInput(const InputType, const MatrixID);

    // general input validator for readInput()
    bool isValidInput(const std::string&, const InputType);
    
    // input destination coordinator for non-matrix inputs
    bool otherInput(const std::string&, const InputType);
    
    // if (scalar input of correct form) set scalar; else return false;
    bool handleScalar(const std::string&);
    
    // matrix input validator for isValidInput() & coordinator
    bool matrixInput(const std::string&, const MatrixID);
    
    // handle form-checking for matrixInput()
    // white-space de-limitted numerical values
    bool validateMatrixInputFormat(const std::string&);
    
    // ************
    // DIM-HANDLERS
    // ************
    
    // handle dim-setting & updating for parseInput()
    // ensure can enter input into matrix without bufer failing
    // for dynamic matrices
    bool handleMatrixA(const std::string&);
    bool handleMatrixB(const std::string&);
    
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
    
    // matrices
    std::vector< std::vector<Entries> > m_A;
    std::vector< std::vector<Entries> > m_B;
    std::vector< std::vector<Entries> > m_C;
    
    // scalar
    int64_t m_k;
    
    // operation code
    int32_t m_operation;
    
};

#endif /* ui_hpp */
