/*aim: to store diagonal matrix efficiently in memory*/
#include <iostream>
using namespace std;
int* diagonal_input(int *brr,int order){ /*diag matrix sq always isliye*/
    cout << "Enter the elements of the diagonal matrix: ";
    int i;
    for (i=0;i<order;i++){
        cin >> *(i+brr);
    }
    return brr;
}
void diagonal_matrix(int *brr,int order){
    int i,j;
    for (i=0;i<order;i++){
        for (j=0;j<order;j++){
            if (i==j) cout << brr[i];
            else cout << "0"; 
            cout << " ";
        }
        cout << endl;
    }
}
int main(){
    int i,j;
    cout << "Enter the order of diagonal matrix you want to create: ";
    int order;
    cin >> order; 
    
    int *brr;
    diagonal_input(brr,order);
    diagonal_matrix(brr,order);
    return 0;
}