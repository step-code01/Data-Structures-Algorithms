#include <iostream>
using namespace std;
/*concept of unique elements via map-for each char check if already in hashmap. If it is increment value by 1, if 
not then add as key-val pair with val of 1*/

/*work for all now, bas 25 ki limit hai? but haan abhi lower k liye cuz function hi vaisa hai*/
class map{ /*implementing map/dict without stl*/
    char key[25]; 
    int value[25]; // a-z , 0 to 25, 26 elements

    public:
    void initialise(){ //initialise with random ele 
    for (int i=0;i<25;i++) key[i] = '9'; //character
    for (int i=0;i<25;i++) value[i] = 0; //default 0 kardi freq
    } //isko private rkhna hai but ek baar initliase karni hai kaise kru

    int map_fn(int asc){
        int ind = asc - 97;  
        return ind;
    }
    void map_add(char ch, int ind){ /*key value pair add*/
        key[ind] = ch;
        value[ind] = 1;
    }
    void map_get(int ind){
        cout << "\tKey: " << key[ind] <<endl;
        cout << "\tValue: " << value[ind] <<endl;
    }
    void map_freq(int ind){
        //value[ind] = ; //set 0 then inc, otherwise garbage ++ hori not empty par toh 1 hoga hi tab kyu ni hora
        value[ind]++;
    }
    void print(){ //print only filled ones
        int i;
        cout << "Keys: ";
        for (i=0;i<25;i++) if (key[i] != '9') {cout << key[i];}
        cout << "\nValues: ";
        for (i=0;i<25;i++) if (value[i] != 0){cout << value[i];} //dono ki same hi rakhi
        cout << endl;
    }
    int emptycheck(int ind){
        if (key[ind] == '9') return 3; //empty
        else return -3; //not empty
    }
    friend void anagram_check(map &m1, map &m2);
};
string input(){
    string str;
    cout << "Enter the input string: ";
    cin >> str;
    return str;
}
void unique_elem(string str,map &m){ /*unique elem and freq via map*/
    int i;
    m.initialise();
    for (i=0;i<str.length();i++){
        int ind = m.map_fn((int)str[i]); //get the index
        cout << "letter: "<< str[i] << endl <<"\tindex is: " << ind <<endl;
        if (m.emptycheck(ind) == -3){ //not empty
            m.map_freq(ind);//increase the freq count
            //m.map_get(ind); 
        }
        else { //if empty
            m.map_add((char)str[i],ind); //add the key value as new thing at that index
            //m.map_get(ind); 
        } 
    } 
    cout <<endl; 
    m.print();
}
void anagram_check(map &m1, map &m2){
    for (int i = 0; i < 25; i++){
        if (m1.value[i] != m2.value[i]){  // frequency mismatch only check sufficient condn imp
            cout << "not anagrams" << endl;
            return;
        }
    }
    cout << endl;
    cout << "anagrams yes" << endl;
}
//when you write function as friend inside class, then no need of :: to tell its for that class - imp v.imp
int main(){
    map m1,m2;
    string str1 = input();
    string str2 = input();
    unique_elem(str1,m1);
    unique_elem(str2,m2);

    anagram_check(m1,m2);
    return 0;
}
/*found error! - was passing by value! 
it is comparing two maps empty anagram_check me!!! omg */

/*error 2:
failed for hello, world
cuz - condition check wrong, only need tocompare the frequency arrays directly, no need for key[] at all,
This works cuz already mapped letters a–z to indices. 
If both maps have the same frequencies for all 26 slots, the strings are anagrams.

void anagram_check(map &m1, map &m2){ //pass objects now into fn, by ref or by val pass? phrk kya check
        int i;
        for (i=0;i<25;i++){
        if ((m1.key[i] != '9' && m1.value[i] != 0) && (m2.key[i] != '9' && m2.value[i] != 0)){
            if (m1.key[i] != m2.key[i] && m1.value[i] != m2.value[i]){ //letter and freq both same req
                cout << "not anagrams" << endl;
                return;
            }
        }}
        cout << "anagrams yes" << endl;
        return;
}*/