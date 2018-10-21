//
// Created by hehas on 5/19/2018.
//
#ifndef COURSEWORK_SPARSEMATRIX_H
#define COURSEWORK_SPARSEMATRIX_H

#include <cstdlib>

class Sparse {
private:
    struct nonZero *pa;     // pointer to the array
    int length;             // the # of elements
    int nextIndex;          // the next highest index value
    struct nonZero {
        int row;
        int col;
        int val;
    };
public:
    Sparse();     // the constructor
    ~Sparse();    // the destructor
    struct nonZero &operator[](int index); // the indexing operation
    void add(int val);          // add a new value to the end
    int size();   // return length
};


#endif //COURSEWORK_SPARSEMATRIX_H
