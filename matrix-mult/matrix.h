//
//  matrix.hpp
//  matrix-mult

#ifndef matrix_h
#define matrix_h

typedef double Entries;

class Matrix{
public:
    // *********
    // ALLOCATOR
    // *********
    Entries* createMatrix(int rows, int cols);
    
    // ************
    // DE-ALLOCATOR
    // ************
    
    void freeMatrix(Entries* matrix, int rows, int cols);
    
    // ****************************************************
    // OPERATORS (return nullptr if operation not possible)
    // ****************************************************
    
    void performScalarMultiply(Entries, Entries*, Entries*, int, int);
    void performMatrixAddition(Entries*, Entries*, Entries*, int, int);
    void performMatrixMultiply(Entries*, Entries*, Entries*, int, int, int);
    
    int performDeterminant(Entries*, int, int){return -1;}
    
    
    // ***************************************************
    // OUTPUT DIM-SETTERS (What should dims of output be?)
    // ***************************************************
    
    void outputScalarMultiply(int, int, int &, int &);
    void outputMatrixAddition(int, int, int &, int &);
};


#endif /* matrix_hpp */
