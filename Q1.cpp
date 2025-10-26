#include <iostream>
using namespace std;

struct CNode{ int val; CNode* next; CNode(int v):val(v),next(this){} };
struct DNode{ int val; DNode* prev; DNode* next; DNode(int v):val(v),prev(nullptr),next(nullptr){} };

void cInsertEnd(CNode*& head,int v){
    if(!head){ head=new CNode(v); return; }
    CNode* t=new CNode(v);
    CNode* p=head;
    while(p->next!=head) p=p->next;
    p->next=t; t->next=head;
}
void cInsertFront(CNode*& head,int v){
    if(!head){ head=new CNode(v); return; }
    CNode* t=new CNode(v);
    CNode* p=head;
    while(p->next!=head) p=p->next;
    t->next=head; p->next=t; head=t;
}
bool cInsertAfter(CNode* head,int after,int v){
    if(!head) return false;
    CNode* p=head;
    do{
        if(p->val==after){ CNode* t=new CNode(v); t->next=p->next; p->next=t; return true; }
        p=p->next;
    }while(p!=head);
    return false;
}
bool cDelete(CNode*& head,int v){
    if(!head) return false;
    if(head->val==v && head->next==head){ delete head; head=nullptr; return true; }
    CNode* p=head; CNode* prev=nullptr;
    do{
        if(p->val==v){
            if(p==head){
                CNode* tail=head;
                while(tail->next!=head) tail=tail->next;
                head=head->next; tail->next=head; delete p; return true;
            } else {
                prev->next=p->next; delete p; return true;
            }
        }
        prev=p; p=p->next;
    }while(p!=head);
    return false;
}
bool cSearch(CNode* head,int v){
    if(!head) return false;
    CNode* p=head;
    do{ if(p->val==v) return true; p=p->next; } while(p!=head);
    return false;
}
void cDisplayRepeat(CNode* head){
    if(!head){ cout<<"Circular list empty\n"; return; }
    CNode* p=head;
    do{ cout<<p->val<<" "; p=p->next; }while(p!=head);
    cout<<head->val;
    cout<<"\n";
}

void dInsertEnd(DNode*& head,int v){
    DNode* t=new DNode(v);
    if(!head){ head=t; return; }
    DNode* p=head;
    while(p->next) p=p->next;
    p->next=t; t->prev=p;
}
void dInsertFront(DNode*& head,int v){
    DNode* t=new DNode(v);
    if(!head){ head=t; return; }
    t->next=head; head->prev=t; head=t;
}
bool dInsertAfter(DNode* head,int after,int v){
    DNode* p=head;
    while(p){
        if(p->val==after){ DNode* t=new DNode(v); t->next=p->next; t->prev=p; if(p->next) p->next->prev=t; p->next=t; return true; }
        p=p->next;
    }
    return false;
}
bool dInsertBefore(DNode*& head,int before,int v){
    DNode* p=head;
    while(p){
        if(p->val==before){
            if(p==head){ dInsertFront(head,v); return true; }
            DNode* t=new DNode(v);
            t->prev=p->prev; t->next=p; p->prev->next=t; p->prev=t;
            return true;
        }
        p=p->next;
    }
    return false;
}
bool dDelete(DNode*& head,int v){
    DNode* p=head;
    while(p){
        if(p->val==v){
            if(p==head){
                head=head->next;
                if(head) head->prev=nullptr;
                delete p;
                return true;
            } else {
                if(p->prev) p->prev->next=p->next;
                if(p->next) p->next->prev=p->prev;
                delete p;
                return true;
            }
        }
        p=p->next;
    }
    return false;
}
bool dSearch(DNode* head,int v){
    DNode* p=head;
    while(p){ if(p->val==v) return true; p=p->next; }
    return false;
}
void dDisplay(DNode* head){
    if(!head){ cout<<"Doubly empty\n"; return; }
    DNode* p=head;
    while(p){ cout<<p->val<<" "; p=p->next; }
    cout<<"\n";
}

int main(){
    cout<<"--- Circular Linked List demo ---\n";
    CNode* ch=nullptr;
    cInsertEnd(ch,20);
    cInsertEnd(ch,100);
    cInsertEnd(ch,40);
    cInsertFront(ch,10);
    cInsertAfter(ch,100,80);
    cout<<"After insertions (expected sequence start 10): ";
    cDisplayRepeat(ch);
    cout<<"Search 80: "<<(cSearch(ch,80)?"Found":"Not Found")<<"\n";
    cDelete(ch,100);
    cout<<"After deleting 100: ";
    cDisplayRepeat(ch);

    cout<<"\n--- Doubly Linked List demo ---\n";
    DNode* dh=nullptr;
    dInsertEnd(dh,5);
    dInsertEnd(dh,15);
    dInsertFront(dh,1);
    dInsertAfter(dh,5,10);
    dInsertBefore(dh,15,12);
    cout<<"After insertions (expected 1 5 10 12 15): ";
    dDisplay(dh);
    cout<<"Search 12: "<<(dSearch(dh,12)?"Found":"Not Found")<<"\n";
    dDelete(dh,10);
    cout<<"After deleting 10 (expected 1 5 12 15): ";
    dDisplay(dh);
    return 0;
}
