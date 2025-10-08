#include <iostream>
using namespace std;
/*v.imp note since object - contiguous memory with padding if req, else can do arr of size 2 inside it*/
class sll;
class node{ //5x^2 
    int coeff; //coefficient (eg 5)
    int deg; // x^2 (eg 2)
    node* next;
    public:
    node(){
        coeff = 0;
        deg = 0;
        next = 0;
    }
    node(int d, int x, node* n = 0){
        coeff = d;
        deg = x;
        next = n;
    }
    friend class sll;
    friend void polynomial_addition(sll l1, sll l2,sll &result);
    friend void initialise(sll l1, sll l2, sll &result);
};
class sll{
    node* head;
    node* marker;
    public:
    sll(int l,int x){
        head = new node(l,x);
        marker = head;
    }
    void insert(int l,int x){
        node* nextNode = new node(l,x);
        marker->next = nextNode;
        marker = marker->next;
    }
    void insertstart(int l,int x){
        node* newhead = new node(l,x);
        newhead->next = head;
        head = newhead;
    }
    void insertafter(int l,int x,int poselem){
        node* walker = head;
        while (walker->coeff != poselem){
            walker = walker->next;
        }
        node* newNode = new node(l,x);
        newNode->next = walker->next;
        walker->next = newNode;
    }
    void insertbefore(int l,int x,int poselem){ 
        node* walker = head;
        while (walker->next->coeff != poselem){ 
            walker = walker->next;
        }
        node* newNode = new node(l,x);
        newNode->next = walker->next;
        walker->next = newNode;
    }
    void display(){
        cout << "Linked list:" << endl;
        node* walker = head;
        while (walker != 0){
            cout << walker->coeff; 
            if (walker->next != 0) cout << "-> "; 
            walker = walker->next;
        }
        cout << endl;
    }
    void deletion(){ 
        node *walker = head;
        while (walker->next->next != 0){
            walker = walker->next;
        }
        walker->next = 0;
        delete marker;
        while (walker!= 0){
            walker = walker->next;
        }
        marker = walker;
    }
    void deletionstart(){
        node* temp = head;
        head = head->next;
        delete temp;
    }
    void deletionelem(int l){
        node* del = head; 
        while(del->next->coeff != l){
            del = del->next;
        }
        node* temp = del;
        del=del->next; 
        delete del;
    }
    void reverse_ll(){
        node* left = nullptr;
        node* curr = head;
        node* right = curr->next;
    }
    void search(int l){
        node *searcher = head;
        while (searcher->coeff != l){
            searcher = searcher->next;
        }
        cout << "The entered element " << l << " is ";
    }
    friend void polynomial_addition(sll l1, sll l2,sll &result);
    friend void initialise(sll l1, sll l2, sll &result);
};
/*my logic: race to finish*/
void polynomial_addition(sll l1, sll l2, sll &result){//copy se kaam ho jaayega
    node* w1 = l1.head;
    node* w2 = l2.head;
    node* w3 = result.head;
    while (w1 != nullptr && w2 !=nullptr){
        if (w1->deg == w2->deg){ //if deg same, coeff add, advance both ptrs together
            w3->coeff = w1->coeff + w2->coeff; 
            w1 = w1->next;
            w2 = w2->next;
            w3 = w3->next; //resultant toh ek ek karke hi chalega, and jab equal honge tab hi aage
        }
        else{ //if deg not same, bring them together
            while ((w1->deg != w2->deg)){
                if (w1->deg < w2->deg){//check which is lagging, w2 ki deg zyada hai toh w2 is lagging here
                    w3->coeff = w2->coeff;   
                    w2 = w2->next;
                }
                else if (w1->deg > w2->deg){
                    w3->coeff = w1->coeff;
                    w1 = w1->next;
                }
                else if (w1 == nullptr){//if one ends, then automatically other direct add left in other
                    if (w2 != nullptr){
                    w3->coeff = w2->coeff;
                    w2 = w2->next;
                    }
                }
                else if (w2 == nullptr){ //beech me null ho skti hai list
                    if (w1 != nullptr){
                        w3->coeff = w1->coeff;
                        w1 = w1->next;
                    }
                }
            w3 = w3->next;
            }
        }
    }
}
void initialise(sll l1, sll l2, sll &result){ //highest deg in either of sll, jo front me hi hogi
    node* x = l1.head;
    node* y = l2.head;
    int highestdeg = (x->deg > y->deg) ? x->deg : y->deg; 
    int i;
    for (i=highestdeg; i>0;i--){ //ek pahle insert kar diya banate hue main me so i=0 wala hogya
        result.insertstart(0,i); 
    }
    /*base case of eg. 3 2 0 and 0 add pe hai deg toh 1 wala align nhi, but 1 deg ka coeff 0 toh okay no that
    shouldn't be a problem and would depend output format exact kaisa chahiye unko*/
}
int main(){
    sll l1(5,2);
    l1.insert(4,1);
    l1.insert(2,0);

    sll l2(5,1);
    l2.insert(5,0);

    sll result(0,0);
    initialise(l1,l2,result);

    polynomial_addition(l1,l2,result);

    result.display();
}
/*Linked list:
5-> 9-> 7
first try DAMN*/

/*yeh fwd declare line 114 pe na karne se inaccessible kyu show karta hai 
instead of batane ki fwd declare nhi kiya hai
if me assignment allowed hi kyu hai 
if (a=2) 
toh glt hai 2 a ko assign hora toh yeh allowed kyu hai ide error show kyu ni
logical error toh runtime error na? always?*/
/*kitne pointers use karre usse space cpxity pe pharak pdta h?
kitne bhi use karu mai?
kuch aisa cheeze hi na krdu har ek node pe pointers aur karte rho phir
kuch constraints rehte honge

why using nullptr and 0 interchangeably is working? 
i defined via 0 still nullptr works
is reverse true?
ternary 
result = (condition) ? exp1 : exp 2;
hota hai, toh : ? kar skte interchange T/F vaise act krega? cuz i glti se did
int highestdeg = (x->deg > y->deg) : x->deg ? y->deg;
doesn't show error for '?' part*/

/*current code subtle issues:
Where It’ll Break (Subtle Issues)

Incorrect degree alignment logic when degrees differ
You loop while (w1->deg != w2->deg) — but degrees aren’t guaranteed to “catch up” this way.
You may skip nodes incorrectly or dereference null at the end.
A better approach: merge like in merge-sort.

Result list isn’t guaranteed to have the same structure
You pre-initialize with dummy 0s, but you’re not updating deg properly during assignment.
You’re assuming w3 and (w1, w2) always align in terms of degrees — which may fail for uneven polynomials.

Missing base case when one polynomial ends early
After the main loop, if w1 or w2 still has remaining terms, you should copy them into result.*/

/*
The subtle problem I was hinting at

It’s not that your idea of filling all degrees is wrong.
It’s that your current traversal logic assumes the three linked lists (l1, l2, result) will always stay in sync by degree — but they might not if one of the polynomials skips an intermediate degree.

Let’s take an example that exposes it:
Example
l1 = 5x² + 2 (degrees: 2, 0)
l2 = 5x¹ (degree: 1)


You prefill result like this:
result = [0x², 0x¹, 0x⁰]

Now when your loop runs:
w1->deg = 2, w2->deg = 1 → mismatch

Inner while runs until they “match” — but they never actually do, because neither increments in a way that aligns them correctly with result.
So even though your intent is right, your pointer advancement logic doesn’t guarantee alignment.
That’s the mismatch I meant by:

“You’re assuming w3 and (w1, w2) always align in terms of degrees — which may fail for uneven polynomials.*/