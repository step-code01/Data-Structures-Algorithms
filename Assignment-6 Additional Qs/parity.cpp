#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;
    node(int d){data=d;next=nullptr;prev=nullptr;}
};

int parity(int x){
    int c=0;
    while(x){c+=x&1; x>>=1;}
    return c;
}

node* cleanDLL(node* h){
    node* c=h;
    while(c){
        if(parity(c->data)%2==0){
            node* t=c;
            if(c->prev) c->prev->next=c->next;
            if(c->next) c->next->prev=c->prev;
            if(t==h) h=c->next;
            c=c->next;
            delete[] t;
        } else c=c->next;
    }
    return h;
}

node* cleanCLL(node* h){
    if(!h) return h;
    node* c=h;
    node* p=nullptr;
    do{
        if(parity(c->data)%2==0){
            node* t=c;
            if(p) p->next=c->next;
            if(t==h) h=c->next;
            c=c->next;
            delete[] t;
        } else{p=c; c=c->next;}
    } while(c!=h && h);
    return h;
}

void printDLL(node* h){
    while(h){cout<<h->data<<" "; h=h->next;}
}
void printCLL(node* h){
    if(!h) return;
    node* c=h;
    do{cout<<c->data<<" "; c=c->next;}while(c!=h);
}

int main(){
    int n;
    cin>>n;
    node* dh=nullptr;
    node* dt=nullptr;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        node* t=new node(x);
        if(!dh){dh=t;dt=t;}
        else{dt->next=t;t->prev=dt;dt=t;}
    }
    int m;
    cin>>m;
    node* ch=nullptr;
    node* ct=nullptr;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        node* t=new node(x);
        if(!ch){ch=t;ct=t;}
        else{ct->next=t;ct=t;}
    }
    if(ch && ct) ct->next=ch;
    dh=cleanDLL(dh);
    ch=cleanCLL(ch);
    printDLL(dh);
    cout<<"\n";
    printCLL(ch);
}
