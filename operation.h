/*
This file defines the Operation base class which represents an operation
performed on one or more tensors.
*/

#ifndef __OP_H_INCLUDED__   
#define __OP_H_INCLUDED__   

#include "common.h"
#include "matrix.h"

//Forward Declaration
template<typename T>
class Tensor;

template<typename T>
class Operation {
    public:
    Tensor<T> *t1 = NULL, *t2 = NULL; // generally an operation had two operands
    
    Operation() {

    }
    Operation(Tensor<T> *t1) {
        this->t1 = t1;
    }

    Operation(Tensor<T> *t1, Tensor<T> *t2) {
        this->t1 = t1;
        this->t2 = t2;
    }

    virtual void backward(Matrix<T> grad) = 0;
    virtual Tensor<T> forward() = 0;
};

#endif

