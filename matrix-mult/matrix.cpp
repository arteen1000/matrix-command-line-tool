//
//  matrix.cpp
//  matrix-mult

#include "matrix.h"
#include <vector>
using std::vector;


// **********
// OPERATIONS
// **********

void MatrixOps::performScalarMultiply(const Entries k, const vector< Entries >& A, Entries* C, const int32_t rows, const int32_t cols){
    
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            C[i*cols + j] = A[i*cols+j] * k;
        }
    }
}

void MatrixOps::performMatrixAddition(const vector< Entries >& A, const vector< Entries >& B, Entries* C, const int32_t rows, const int32_t cols){
    
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            C[i*cols+j] = A[i*cols+j] + B[i*cols+j];
        }
    }
}
// equal dims

void MatrixOps::performMatrixMultiply(const std::vector< Entries >& A, const std::vector< Entries >& B, Entries* C, const int32_t rowsAC, const int32_t colsA_rowsB, const int32_t colsBC){
    Entries placeholder = 0;
    // can tile here
    for (int i = 0 ; i < rowsAC; i++){
        for (int k = 0 ; k < colsA_rowsB; k++){
            placeholder = A[i*colsA_rowsB+k];
            for (int j = 0 ; j < colsBC; j++){
                C[i*colsBC+j] += placeholder * B[k*colsBC+j];
            }
        }
    }
}
/*
 rowsA = rowsC
 colsA = rowsB
 colsC = colsB
 
 C[ij] = A[ik] * B[kj]; // ith row of A * jth col of B -> intuitive ordering (how I do it in my head) would be i j k, not cache efficient
*/

Entries MatrixOps::performDeterminant(const std::vector<Entries> & A, const int32_t n){
//    if (1 == n) return A[0][0];
//    if (2 == n) return ((A[0][0] * A[1][1]) - (A[0][1] * A[1][0]));
//
    Entries determinant = 0.0;
//    vector<Entries> firstRow = A[0];
//
//    for (int i = 0 ; i < n ; i++){  // go through first row's
//        Entries a = firstRow[i];
//        for (int j = 1 ; j < n ; j++){  // nothing in top row, remove column i
//
//        }
//    }
    
    return determinant;
}
/*
 square matrix
 cofactor expansion
 (-1)^i+j * det(the other columns and rows)
 
 algorithm, recursive:
 1 or 2 -> return base determin
 
 // for every element in row 1
 // start positive and alternate
 // determinant of the cofactor
 */













// *****
// OLD
// *****

//Entries** Matrix::createMatrix(int rows, int cols){
//    Entries** matrix = new Entries*[rows];
//    for (int i = 0 ; i < rows ; i++){
//        matrix[i] = new Entries[cols]();
//    }
//    return matrix;
//}   // cols would be allocated contiguously, becomes more like a multi-level array than a 2D -> slower

//void Matrix::freeMatrix(Entries** matrix, int rows, int cols){
//    for (int i = 0 ; i < rows ; i++)
//        delete [] matrix[i];
//    delete [] matrix;
//    matrix = nullptr;
//}


//void Matrix::performScalarMultiply(Entries** A, int rows, int cols, Entries k, Entries** C){
//
//    for (int i = 0 ; i < rows ; i++){
//        for (int j = 0 ; j < cols ; j++){
//            C[i][j] = A[i][j] * k;
//        }
//    }
//}

//void Matrix::performMatrixAddition(Entries** A, Entries** B, Entries** C, int rows, int cols){
//
//    for (int i = 0 ; i < rows ; i++){
//        for (int j = 0 ; j < cols ; j++){
//            C[i][j] = A[i][j] + B[i][j];
//        }
//    }
//}

//Entries* Matrix::createMatrix(int rows, int cols){
//    Entries* matrix = new Entries[rows * cols]();
//    return matrix;
//}
