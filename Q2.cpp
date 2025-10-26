#include <iostream>
using namespace std;
struct CNode{ int val; CNode* next; CNode(int v):val(v),next(this){} };
void append(CNode*& h,int v){
    if(!h){ h=new CNode(v); return; }
    CNode* p=h;
    while(p->next!=h) p=p->next;
    CNode* t=new CNode(v);
    p->next=t; t->next=h;
}
void displayRepeat(CNode* h){
    if(!h){ cout<<"Empty\n"; return; }
    CNode* p=h;
    do{ cout<<p->val<<" "; p=p->next; } while(p!=h);
    cout<<h->val<<"\n";
}
int main(){
    CNode* head=nullptr;
    append(head,20);
    append(head,100);
    append(head,40);
    append(head,80);
    append(head,60);
    cout<<"Input: 20 -> 100 -> 40 -> 80 -> 60\nOutput: ";
    displayRepeat(head);
    return 0;
}
