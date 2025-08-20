#include<iostream>

#define MAX 50
#define MAX_DIM 10
using namespace std;

struct Triplet{
    int row;
    int col;
    int value;
};

void readSparseMatrix(Triplet a[]){
    int rows,cols,nonZeroCount,i;
    cout<<"Enter the no of rows: ";
    cin>>rows;
    cout<<"Enter the no of columns: ";
    cin>>cols;
    cout<<"Enter the no of non-zero elements: ";
    cin>>nonZeroCount;

    a[0].row=rows;
    a[0].col=cols;
    a[0].value=nonZeroCount;

    cout<<"Enter non-zero elements (row, column, value) (space separated values):"<<endl;
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
        cout<<a[i].row;
        cout<<"\t"<<a[i].col;
        cout<<"\t"<<a[i].value<<endl;
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

void multiplySparseMatrices(Triplet a[],Triplet b[],Triplet c[]){
    int i,j,k;
    
    if(a[0].col!=b[0].row){
        cout<<"Mult not possible."<<endl;
        c[0].row=0;
        c[0].col=0;
        c[0].value=0;
        return;
    }

    Triplet bTransposed[MAX];
    transpose(b,bTransposed);

    int tempResult[MAX_DIM][MAX_DIM];
    for(i=0;i<MAX_DIM;i++){
        for(j=0;j<MAX_DIM;j++){
            tempResult[i][j]=0;
        }
    }

    for(i=1;i<=a[0].value;i++){
        for(j=1;j<=bTransposed[0].value;j++){
            if(a[i].col == bTransposed[j].col){
                tempResult[a[i].row][bTransposed[j].row] += a[i].value * bTransposed[j].value;
            }
        }
    }

    k=1;
    for(i=0;i<a[0].row;i++){
        for(j=0;j<b[0].col;j++){
            if(tempResult[i][j]!=0){
                c[k].row=i;
                c[k].col=j;
                c[k].value=tempResult[i][j];
                k++;
            }
        }
    }
    
    c[0].row=a[0].row;
    c[0].col=b[0].col;
    c[0].value=k-1;
}

int main(){
    Triplet matrix1[MAX], matrix2[MAX], result[MAX];
    int choice;

    cout<<"Enter the details for the first sparse matrix:"<<endl;
    readSparseMatrix(matrix1);
    printSparseMatrix(matrix1);
    
    cout<<"\nEnter the details for the second sparse matrix:"<<endl;
    readSparseMatrix(matrix2);
    printSparseMatrix(matrix2);
    
    /*mult*/
    multiplySparseMatrices(matrix1,matrix2,result);
    cout<<"\nResult of Multiplication:"<<endl;
    printSparseMatrix(result);
    return 0;
}
