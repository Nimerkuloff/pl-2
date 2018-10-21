#include "SparseMatrix.h"
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    Sparse arr;
    int iter=0;
for(int i =0;i<7;i++){
    for(int j=0;j<7;j++){
        cout<<"["<<i<<"]";
        cout<<"["<<j<<"]"<<endl;
        int value;
        cin>>value;
        if(value!=0){
            arr[iter].row=i;
            arr[iter].col=j;
            arr[iter].val=value;
            iter++;
        }
    }
}
}
