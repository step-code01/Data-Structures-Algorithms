/*String Anagrams
Given two strings str1 and str2, determine if they form an anagram pair.
Note: Two strings are considered anagrams if one string can be rearranged to form the other
string.*/

/*examples:
listen & silent
cat & act
race & care
earth & heart
triangle & integral 
*/

#include <iostream>
using namespace std;

void anagram_check(string str1, string str2){
    /*check if length same or not*/
    if (str1.length() != str2.length()) {cout << "not anagrams" <<endl; return;}
    int i,j;
    int temp=0; //imp 
    /*sort in alphabetical order*/
    for (i=0;i<str1.length();i++){ /*use any str length since both same honge*/
        for (j=i+1;j<str1.length();j++){ //cpp strings are mutable letters shift can
            if (str1[i] > str1[j]){
            temp = str1[i];            
            str1[i] = str1[j];
            str1[j] = temp;}

            temp = 0; //reset temp (switching via 1 temp in 2 strings)
            
            if (str2[i] > str2[j]){ // independent hit ek hi loop me dono hogye
            temp = str2[i];            
            str2[i] = str2[j];
            str2[j] = temp;}
        }
    }
    cout << "string 1 base: " << str1 << endl;
    cout << "string 2 base: " << str2 << endl;

    /*directly compare now exact same hai ya nhi*/
    for (i=0;i<str1.length();i++){ //member fn hai imp rem s.length(), () dont forget
        if (str1[i] != str2[i]) {cout << "not anagrams" << endl; return;}
    }
    cout << "anagrams yes" <<endl; //only hits if above return doesn't hit, else inside loop printing 5 times, and else me break not making sense won't check all ek check karke break kar dega
    return;
}
void input(){
    string str1,str2;
    cout << "Enter the 1st string: ";
    cin >> str1;
    cout << "Enter the 2nd string: ";
    cin >> str2;
    anagram_check(str1,str2);
    return;
}
int main(){
    input();
}