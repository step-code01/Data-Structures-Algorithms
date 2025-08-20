#include<iostream>
#define MAX 50
using namespace std;

struct Triplet{
    int row;
    int col;
    int value;
};

void readSparseMatrix(Triplet a[]){
    int rows,cols,nonZeroCount,i;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    cout<<"Enter the number of columns: ";
    cin>>cols;
    cout<<"Enter the number of non-zero elements: ";
    cin>>nonZeroCount;

    a[0].row=rows;
    a[0].col=cols;
    a[0].value=nonZeroCount;

    cout<<"Enter non-zero elements (row, column, value) (space separated value for each):"<<endl;
    for(i=1;i<=nonZeroCount;i++){
        cin>>a[i].row;
        cin>>a[i].col;
        cin>>a[i].value;
    }
}

void printSparseMatrix(Triplet a[]){
    int i;
    int nonZeroCount=a[0].value;
    cout<<"\nSparse Matrix (Triplet Representation):"<<endl;
    cout<<"Row\tColumn\tValue"<<endl;
    for(i=0;i<=nonZeroCount;i++){
        cout<<a[i].row<<"\t"<<a[i].col<<"\t"<<a[i].value<<endl;
    }
}

void transpose(Triplet a[],Triplet b[]){
    int i,j,k;
    int nonZeroCount=a[0].value;

    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].value=nonZeroCount;

    if(nonZeroCount>0){
        k=1;
        for(i=0;i<a[0].col;i++){
            for(j=1;j<=nonZeroCount;j++){
                if(a[j].col==i){
                    b[k].row=a[j].col;
                    b[k].col=a[j].row;
                    b[k].value=a[j].value;
                    k++;
                }
            }
        }
    }
}

int main(){
    Triplet original[MAX];
    Triplet transposed[MAX];
    
    readSparseMatrix(original);
    printSparseMatrix(original);
    transpose(original,transposed);
    printSparseMatrix(transposed);
    
    return 0;
}
