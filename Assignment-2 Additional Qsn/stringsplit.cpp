/*String Split Challenge
You are given a string consisting of lowercase English alphabets. Your task is to determine if
it's possible to split this string into three non-empty parts (substrings) where one of these
parts is a substring of both remaining parts*/
/*reusing the freq code i wrote from q3 here*/

/*problem is when i do freq=2, then positions dependent ho jaata hai vo,vo kaise kru*/

/*freq>=3 always hoga
3 se neeche wali string divide nhi hogi non-empty me
freq=1 all uniqueness kills it
freq=2 is interesting, may not maynot be hai yeh*/
#include <iostream>
using namespace std;
class map{ 
    char key[25]; 
    int value[25]; 

    public:
    void initialise(){  
    for (int i=0;i<25;i++) key[i] = '9';
    for (int i=0;i<25;i++) value[i] = 0; 
    }

    int map_fn(int asc){
        int ind = asc - 97;  
        return ind;
    }
    void map_add(char ch, int ind){ 
        key[ind] = ch;
        value[ind] = 1;
    }
    void map_get(int ind){
        cout << "\tKey: " << key[ind] <<endl;
        cout << "\tValue: " << value[ind] <<endl;
    }
    void map_freq(int ind){
        value[ind]++;
    }
    void print(){
        int i;
        cout << "Keys: ";
        for (i=0;i<25;i++) if (key[i] != '9') {cout << key[i];}
        cout << "\nValues: ";
        for (i=0;i<25;i++) if (value[i] != 0){cout << value[i];} 
        cout << endl;
    }
    int emptycheck(int ind){
        if (key[ind] == '9') return 3;
        else return -3;
    }
    friend void string_split(string str, map &m);
};
string input(){
    string str;
    cout << "Enter the input string: ";
    cin >> str;
    return str;
}
void freq_elem(string str,map &m){ /*unique elem and freq via map*/
    int i;
    m.initialise();
    for (i=0;i<str.length();i++){
        int ind = m.map_fn((int)str[i]);
        if (m.emptycheck(ind) == -3){
            m.map_freq(ind);
        }
        else {
            m.map_add((char)str[i],ind);
        } 
    } 
    cout <<endl; 
    m.print();
}
void string_split(string str,map &m){
    freq_elem(str,m); 
    if (str.length() < 3) {cout << "Equal substring division not possible, one'll be empty\n"; return;}
    int i;
    int count_freq_one = 0;
    for (i=0;i<25;i++){
        if (m.value[i] >= 3) {cout << "Substring split possible."; break;}
        if (m.value[i] == 1) {count_freq_one++;} //abcdef - 1,1,1,1,1,1 -sum - 6 = str.length() which is 6
        if (m.value[i] == 2) {}//idk what here. think here, posn how
    }
    if (count_freq_one == str.length()){//uniqueness kills it, 1 ALL chahiye
        cout << "Substring split division not possible. ";
    }
    return;
}
int main(){ 
    map m;
    string str = input();
    
    string_split(str,m);
}