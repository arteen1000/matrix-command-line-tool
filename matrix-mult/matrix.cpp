//
//  matrix.cpp
//  matrix-mult

#include "matrix.h"
#include <vector>

// ***************
// CREATE MATRICES
// ***************

std::vector<std::vector<Entries>> Matrix::createMatrix(const int rows, const int cols){
    return {};
}

void Matrix::addRow(std::vector<std::vector<Entries>>& matrix, std::vector<Entries>& row) {
    matrix.push_back(std::move(row));
}

// ****************************************************
// OPERATORS (return nullptr if operation not possible)
// ****************************************************

void Matrix::performScalarMultiply(Entries k, Entries* A, Entries* C, int rows, int cols){
    
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            C[i*cols + j] = A[i*cols + j] * k;
        }
    }
}

void Matrix::performMatrixAddition(Entries* A, Entries* B, Entries* C, int rows, int cols){
    
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            C[i*cols + j] = A[i*cols + j] + B[i*cols +j];
        }
    }
}

void Matrix::performMatrixMultiply(Entries* A, Entries* B, Entries* C , int rowsA_rowsC, int colsA_rowsB, int colsB_colsC){
    
    Entries placeholder = 0;
    // can tile here
    for (int i = 0 ; i < rowsA_rowsC; i++){
        for (int k = 0 ; k < colsA_rowsB; k++){
            placeholder = A[i*colsA_rowsB + k];
            for (int j = 0 ; j < colsB_colsC; j++){
                C[i*colsB_colsC + j] += placeholder * B[k*colsB_colsC + j];
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
