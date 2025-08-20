#include <iostream>
using namespace std;
void symmetric_matrix(int order){
    int elements = (order*(order+1))/2;
    int a[elements];
    
    int i,j;
    cout << "Enter elements in Row-major order (Upper Half): \n";
    for (i=0;i<elements;i++) cin >> a[i];
    
    /*printing the matrix*/
    int k=0,l=1;
    for (i=0;i<order;i++){
        for (j=0;j<order;j++){
            if (j>=i) {cout << a[k] << " "; k++;}
            else{
                if (i!=j){
                    cout << a[l] << " ";
                }
                l++; //increment outside, chalne do, diag ele auto skip
            } 
        }
        cout << "\n";
    }
}
int main(){
    int order,choice;
    cout << "Enter the order of triangular matrix you want to produce: ";
    cin >> order;

    symmetric_matrix(order);
}
/*better algo i think but not able to write is that ek l lelo which also traverses the same array
and else wale part me it accessses that element acc to a formula 
ki (i,j) to single 1d no to (j,i) kar paaye

now 'l' would tell jitne element aage hai apne symmetric correspondant se.
its smth like -> 
(0,2) -> symm correspondant -> (2,0) 
now (2,0) upper triangular matrix pr ->
apni current row me usse aage 1 element hai
1 poori row in between -> (2nd row me 3 ele of upper triangular)

so 1+3+0 = 4 aage jump

symm partner = no of ele in 0 row + 1st row + .. order-kth row + no of ele before j
i,j se relate krke

sum wale se relate krne par unique mapping nhi mil rhi thi
*/