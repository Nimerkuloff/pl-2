//
// Created by hehas on 5/19/2018.
//
#include "SparseMatrix.h"

Sparse::Sparse() {
    this->

             pa = new nonZero[10];
    for (int i = 0; i < 10; i++) {
        pa[i].row = -1;
        pa[i].col = -1;
        pa[i].val = -1;
    }
    this->length = 10;
    this->nextIndex = 0;
}

Sparse::~Sparse() {
    //надо ли удалять pa[i].row и т.д.?
    delete[] pa;
}

struct nonZero &Sparse::operator[](int index) {
    struct nonZero *pnewa;       // pointer for new array
    if (index >= length) {      // is element in the array?
        pnewa = new struct nonZero[index + 10];   // allocate a bigger array
        for (int i = 0; i < nextIndex; i++) {     // copy old values
            pnewa[i].row = pa[i].row;
            pnewa[i].col = pa[i].col;
            pnewa[i].val = pa[i].val;
        }
        for (int j = nextIndex; j < index + 10; j++) {// initialize remainder
            pnewa[j].row = -1;
            pnewa[j].col = -1;
            pnewa[j].val = -1;
        }

        length = index + 10;    // set length to bigger size
        delete[] pa;            // delete the old array
        pa = pnewa;             // reassign the new array
    }
    if (index > nextIndex)      // set nextIndex past index
        nextIndex = index + 1;

    return pa[index];  // a reference to the element
}