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

    // valid input characters fit required scheme
    bool isValidInput(const std::string&, const InputType);
    
    // validate & coordinate non-matrix input
    bool otherInput(const std::string&, const InputType);
    
    // validate & coordinate matrix input
    bool matrixInput(const std::string&, const MatrixID);
    
    // ensure matrix input is white-space de-limitted numerical values
    bool validateMatrixInputFormat(const std::string&);
    
    // ********
    // HANDLERS
    // ********
    
    // handle validating & inputting m_k
    bool handleScalar(const std::string&);
    
    // handle additional type validation & allocating input into dynamic matrices
    bool handleMatrixA(const std::string&);
    bool handleMatrixB(const std::string&);
    
    // *****************
    // OPERATION VERIFIER
    // *****************
    
    // verify operation possibility based on current user input
    bool verifyOperations();
    
    // *********
    // DIRECTORS
    // *********
    
    // prompt user to select wanted operation
    // have sub-handlers handle each select operation
    void matrixOperationPrompt();
    
    // set dims of necessary dependencies and allocate for size
    void allocateDependencies();
    
    // responsible for performing the m_operation
    void performOperation();
    
    // responsible for resetting all constructs to default
    void reinitializeConstructs();
    
    
    // idea: format matrix C output nicely by taking a look at the largest row size and adjusting the rest with spaces for it? I love this idea. If there's decimals, maybe go as far as lining up above correct decimal point?
    // very difficult to implement
    
    // *******
    // DEBUG
    // ******
    
    void outputMatrixA();
    
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
    
    // matrix operations
    Matrix m_matrix;
};

#endif /* ui_hpp */
