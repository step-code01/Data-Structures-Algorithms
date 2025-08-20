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

void addSparseMatrices(Triplet a[],Triplet b[],Triplet c[]){
    int i=1,j=1,k=1; //pahla toh reserved for info of matrix r,c,v

    if(a[0].row!=b[0].row || a[0].col!=b[0].col){
        cout<<"Addition is not possible. Matrices have different dimensions."<<endl;
        c[0].row=0;
        c[0].col=0;
        c[0].value=0;
        return;
    }

    c[0].row=a[0].row;
    c[0].col=a[0].col;

    while(i<=a[0].value && j<=b[0].value){
        //row col values comparing to decide kaunsa copy kare
        if(a[i].row<b[j].row || (a[i].row==b[j].row && a[i].col<b[j].col)){
            c[k].row=a[i].row;
            c[k].col=a[i].col;
            c[k].value=a[i].value;
            i++;
            k++;
        }
        else if(a[i].row>b[j].row || (a[i].row==b[j].row && a[i].col>b[j].col)){
            c[k].row=b[j].row;
            c[k].col=b[j].col;
            c[k].value=b[j].value;
            j++;
            k++;
        }
        else{ // Both row and column are the same, so add the values.
            int sum=a[i].value+b[j].value;
            if(sum!=0){
                c[k].row=a[i].row;
                c[k].col=a[i].col;
                c[k].value=sum;
                k++;
            }
            i++;
            j++;
        }
    }

    while(i<=a[0].value){
        c[k].row=a[i].row;
        c[k].col=a[i].col;
        c[k].value=a[i].value;
        i++;
        k++;
    }

    while(j<=b[0].value){
        c[k].row=b[j].row;
        c[k].col=b[j].col;
        c[k].value=b[j].value;
        j++;
        k++;
    }

    c[0].value=k-1;
}

int main(){
    Triplet matrix1[MAX], matrix2[MAX], result[MAX];

    cout<<"Enter the details for the 1st sparse matrix:"<<endl;
    readSparseMatrix(matrix1);
    printSparseMatrix(matrix1);
    
    cout<<"\nEnter the details for the 2nd sparse matrix:"<<endl;
    readSparseMatrix(matrix2);
    printSparseMatrix(matrix2);
    
    addSparseMatrices(matrix1,matrix2,result);
    cout<<"\nAddition of sparse 1 and 2:"<<endl;
    printSparseMatrix(result);
    
    return 0;
}
