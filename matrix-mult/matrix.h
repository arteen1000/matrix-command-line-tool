//
//  matrix.hpp
//  matrix-mult

#ifndef matrix_h
#define matrix_h

#include <vector>
typedef double Entries;

class MatrixOps{
public:
    // **********
    // OPERATIONS
    // **********
    
    void performScalarMultiply(const Entries, const std::vector< std::vector<Entries> >& A, Entries*, const int32_t, const int32_t);
    void performMatrixAddition(const std::vector< std::vector<Entries> >&, const std::vector< std::vector<Entries> >&, Entries*, const int32_t, const int32_t);
    void performMatrixMultiply(const std::vector< std::vector<Entries> >&, const std::vector< std::vector<Entries> >&, Entries*, const int32_t, const int32_t, const int32_t);
    
    Entries performDeterminant(const std::vector< std::vector<Entries> >&, int32_t);
    
//    int performDeterminant(Entries*, int, int){return -1;}
};


#endif /* matrix_hpp */
