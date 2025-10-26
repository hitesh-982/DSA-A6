#include <iostream>
using namespace std;
struct DNode{ int val; DNode* prev; DNode* next; DNode(int v):val(v),prev(nullptr),next(nullptr){} };
struct CNode{ int val; CNode* next; CNode(int v):val(v),next(this){} };

int sizeD(DNode* h){
    int c=0; DNode* p=h;
    while(p){ c++; p=p->next; }
    return c;
}
int sizeC(CNode* h){
    if(!h) return 0;
    int c=0; CNode* p=h;
    do{ c++; p=p->next; } while(p!=h);
    return c;
}

int main(){
    DNode* dh=nullptr;
    dh=new DNode(1); dh->next=new DNode(2); dh->next->prev=dh; dh->next->next=new DNode(3); dh->next->next->prev=dh->next;
    cout<<"Doubly linked list nodes: 1 2 3\nSize: "<<sizeD(dh)<<"\n";

    CNode* ch=nullptr;
    ch=new CNode(20); ch->next=new CNode(100); ch->next->next=new CNode(40);
    CNode* tail=ch->next->next; tail->next=ch;
    cout<<"Circular linked list nodes: 20 100 40\nSize: "<<sizeC(ch)<<"\n";
    return 0;
}
