//
//  ui.hpp
//  matrix-mult

#ifndef ui_h
#define ui_h


#include "matrix.h"
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>
using std::int32_t;

// ensure correct input received
enum InputType {operation, scalar, matrix, onezero, yesno};

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
    bool master();
    
    // responsible for initializing any constructs
    UI();
    
    // terminating message
    ~UI();
   
protected:
    // ********************
    // READ AND PARSE INPUT
    // ********************
    
    // read input from the user & coordinate destination
    void readInput(const InputType, const MatrixID);

    // valid input characters fit required scheme
    bool isValidInput(const std::string&, const InputType);
    
    // validate & coordinate non-matrix input
    bool otherInput(const std::string&, const InputType);
    
    // validate & coordinate matrix input
    bool matrixInput(const std::string&, const MatrixID);
    
    // ensure matrix input is white-space de-limitted numerical values
    bool validateMatrixInputFormat(const std::string&);
    
    // *******************
    // ALLOCATION-HANDLERS
    // *******************
    
    // handle validating & inputting m_k
    bool handleScalar(const std::string&);
    
    // handle additional type validation & allocating input into dynamic matrices
    bool handleMatrixA(const std::string&);
    // matrix B also handles checking for addition compatibility during user input (# of cols = # of cols)
    bool handleMatrixB(const std::string&);
    
    // ******************
    // OUTPUT && REFACTOR
    // ******************
    
    // output input matrices
    void outputMatrix(const std::vector< Entries >&, const int32_t, const int32_t);
    
//    // output output matrices
//    void outputMatrix(const Entries* M, const int32_t rows, const int32_t cols);
    
    // delete inputted matrix presentation
    void refactorMatrix(const int32_t);
    
    // delete inputted presentation of opcode/scalar (in case of bad input)
    void refactorOther();
    
    // reset shared read refactoring/prompt objects
    void resetRead();
    
    
    // ***************
    // USER INPUT FLOW
    // **************
    
    // MASTER
    // ------
    
    // prompt user to select wanted operation & handle the read
    void handleUserInput();
    
    // SLAVES
    // ------
    
    void readScalarMult();
    void readMatrixAdd();
    void readMatrixMult();
    void readDeterminant();
    
    
    // SLAVES ON SLAVES
    // ---------------
    
    // wrappers for common functionality
    void readMatrixA();
    void readMatrixB();
    void readMatrixAB();
    
    // individual matrix read (actual reading)
    void readMatrix(MatrixID);
    
    // ************
    // VERIFICATION
    // ************
    
    // verify operation possibility based on user input && set dims of output
    bool verifyPossibleAndSetDims();
    
    
    // **********
    // ALLOCATION
    // **********
    
//    // allocate output matrices
//    void allocateDependencies();
    
    // ****************
    // OPERATION OUTPUT
    // ****************
    
    // MASTER
    // ------
    
    // responsible for performing the m_operation && displaying result to user
    void performOperationAndOutput();
    
    // SLAVES
    // ------
    
    void outputMatrixC();
    
    // *************
    // DE-ALLOCATION
    // *************
    
//    // deallocate output matrices
//    void deallocateDependencies();
    
    // *******
    // RE-INIT
    // *******
    
    // responsible for resetting all constructs to default
    void reinitializeConstructs();
    
    
    // swap B and C if user desire
    void swapBC();
    
    
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
    
    // user input based
    std::vector< Entries > m_A;
    std::vector< Entries > m_B;
    
    // based on A and B (allocated after user input)
    std::vector< Entries> m_C;
    
    // scalar
    Entries m_k;
    
    // operation code
    int32_t m_operation;
    
    // matrix operations
    MatrixOps m_ops;
    
    // prompt another row
    bool m_prompt;
    
    // input errors
    int32_t m_errors;
    
    // continue to next program iteration
    bool m_continue;
    
    // how many ops performed
    int32_t m_count;
    
    // save C into B?
    std::string m_yesno;
    bool m_saved;
};

#endif /* ui_hpp */
