//
//  matrix.hpp
//  matrix-mult

#ifndef matrix_h
#define matrix_h

#include <vector>
#include <cstdint>
using std::int32_t;

typedef double Entries;

class MatrixOps{
public:
    // **********
    // OPERATIONS
    // **********
    
    void scalarmult(const Entries, const std::vector< Entries >& , std::vector< Entries >&, const int32_t, const int32_t);
    void matrixadd(const std::vector< Entries >&, const std::vector< Entries >&, std::vector< Entries >&, const int32_t, const int32_t);
    void matrixmult(const std::vector< Entries >&, const std::vector< Entries >&, std::vector< Entries >&, const int32_t, const int32_t, const int32_t);
    Entries determinant(const std::vector< Entries >&, int32_t);
    
protected:
    void cofactor(const std::vector<Entries>&, std::vector<Entries>&, int32_t, int32_t);
};


#endif /* matrix_hpp */
