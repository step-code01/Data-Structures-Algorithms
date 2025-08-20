/*aim: to store tri-diagonal matrix efficiently in memory*/
#include <iostream>
using namespace std;
int* tridiagonal_input(int *brr,int order){ /*diag matrix sq always isliye*/
    cout << "Enter the non-zero elements of the tri-diagonal matrix (row-major order): ";
    int i;
    for (i=0;i<3*order-2;i++){ /*total size of arr = n-1 + n + n-1 = 3*n-2 */
        cin >> *(i+brr);
    }
    return brr;
}
void tridiagonal_matrix(int *brr,int order){
    int i,j;
    int k=0;
    for (i=0;i<order;i++){
        for (j=0;j<order;j++){
            if (i==j || i==j-1 || i==j+1) {cout << brr[k]; k++;}
            else cout << "0";
            cout << " ";
        }
        cout << endl;
    }
}
int main(){
    int i,j;
    cout << "Enter the order of tri-diagonal matrix you want to create: ";
    int order;
    cin >> order; 
    
    int *brr;
    tridiagonal_input(brr,order);
    tridiagonal_matrix(brr,order);
    return 0;
}
/*break on basis on n-1,n,n-1 ele (that's just for diag major though) from start or just i=j,j-1,j+1 */
/*implement col major order, diagonal major*/

/*Enter the order of tri-diagonal matrix you want to create: 4
Enter the non-zero elements of the tri-diagonal matrix (row-major order): 1
3
5
2
4
2
3
5
7
4
1 3 0 0 
5 2 4 0 
0 2 3 5 
0 0 7 4 */