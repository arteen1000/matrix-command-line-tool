//
//  matrix.hpp
//  matrix-mult

#ifndef matrix_h
#define matrix_h

#include <vector>
typedef double Entries;

class Matrix{
public:
    // ***************
    // CREATE MATRICES
    // ***************
    
    // static
    std::vector< std::vector<Entries> > createMatrix(const int32_t, const int32_t);
    
    // dynamic
    void addRow(std::vector<std::vector<Entries>>&, std::vector<Entries>&);
    
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
