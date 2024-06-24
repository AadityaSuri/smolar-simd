#ifndef SMOLAR_H
#define SMOLAR_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <assert.h>
// #include <omp.h>

typedef float (*ArrayFunc)(float);
// our hero
typedef struct {
    float* data;        // holds the actual data in continuous way

    int* shape;         // shape of the array
    int* strides;       // number of bytes to skip for each dimension
    int* backstrides;   // reverse of strides; how many bytes to skip to go reverse

    int ndim;           // number of dimensions
    int itemsize;       // size of one element in the array
    int totalsize;      // total size to allocate

    bool C_ORDER;       // flag if array is c-order
    bool F_ORDER;       // flag if array is f-order
} Array;

/*
free all the memory allocated by an Array
*/
void smCleanup(Array* arr);
Array* smCreate(const int* shape, int ndim);
void smFromValues(Array* arr, float* values);
Array* smRandom(const int* shape, int ndim);
Array* smArange(float start, float end, float step);
Array* smReshapeNew(Array* arr, const int* shape, int ndim);
void smReshapeInplace(Array* arr, const int* shape, int ndim);
Array* smTransposeNew(Array* arr, const int* axes);
Array* smAdd(Array* a, Array* b);
Array* smMul(Array* a, Array* b);
void smApply(Array *arr, ArrayFunc func);
int smCheckShapesEqual(Array* a, Array* b);
void smShow(Array* arr);
void smPrintInfo(Array* arr);


#endif