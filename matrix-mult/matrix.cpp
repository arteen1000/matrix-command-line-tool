//
//  matrix.cpp
//  matrix-mult

#include "matrix.h"
#include <vector>
using std::vector;

// **********
// OPERATIONS
// **********

void Matrix::performScalarMultiply(const Entries k, const vector< vector<Entries> >& A, Entries* C, const int32_t rows, const int32_t cols){
    
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            C[i*cols + j] = A[i][j] * k;
        }
    }
}

void Matrix::performMatrixAddition(const vector< vector<Entries> >& A, const vector< vector<Entries> >& B, Entries* C, const int32_t rows, const int32_t cols){
    
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            C[i*cols + j] = A[i][j] + B[i][j];
        }
    }
}

void Matrix::performMatrixMultiply(const std::vector< std::vector<Entries> >& A, const std::vector< std::vector<Entries> >& B, Entries* C, const int32_t rowsAC, const int32_t colsA_rowsB, const int32_t colsBC){
    Entries placeholder = 0;
    // can tile here
    for (int i = 0 ; i < rowsAC; i++){
        for (int k = 0 ; k < colsA_rowsB; k++){
            placeholder = A[i][k];
            for (int j = 0 ; j < colsBC; j++){
                C[i*colsBC + j] += placeholder * B[k][j];
            }
        }
    }
}
/*
 rowsA = rowsC
 colsA = rowsB
 colsC = colsB
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
