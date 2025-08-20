#include <iostream>
using namespace std;
void lower_triangular(int order){
    int elements = (order*(order+1))/2;
    int a[elements];
    
    int i,j;
    cout << "Enter elements in Row-major order: \n";
    for (i=0;i<elements;i++) cin >> a[i];

    /*printing the matrix*/
    cout << "Lower Triangular Matrix: \n";
    int k=0;
    for (i=0;i<order;i++){
        for (j=0;j<order;j++){
            if (j<=i) {cout << a[k] << " "; k++;}
            else cout << "0 ";
        }
        cout << "\n";
    }
}
void upper_triangular(int order){
    int elements = (order*(order+1))/2;
    int a[elements];
    
    int i,j;
    cout << "Enter elements in Row-major order: \n";
    for (i=0;i<elements;i++) cin >> a[i];

    /*printing the matrix*/
    cout << "Upper Triangular Matrix: \n";
    int k=0;
    for (i=0;i<order;i++){
        for (j=0;j<order;j++){
            if (j>=i) {cout << a[k] << " "; k++;}
            else cout << "0 ";
        }
        cout << "\n";
    }
}
int main(){
    int order,choice;
    cout << "Enter the order of triangular matrix you want to produce: ";
    cin >> order;

    cout << "Enter type of triangular matrix you would like: \n";
    cout << "\t1. Lower Triangular Matrix\n\t2. Upper Triangular Matrix\n (Press 1 or 2): ";
    cin >> choice;
    switch (choice){
        case 1:
            lower_triangular(order);
            break;
        case 2:
            upper_triangular(order);
            break;
        default:
            cout << "Invalid input, try again";
            break; //default me break - optional break if its the last one
    }
}
/*if elements poore na ho uska usecase?*/