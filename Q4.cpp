#include <iostream>
#include <string>
using namespace std;
struct DNode{ char v; DNode* prev; DNode* next; DNode(char c):v(c),prev(nullptr),next(nullptr){} };
void append(DNode*& h,char c){
    DNode* t=new DNode(c);
    if(!h){ h=t; return; }
    DNode* p=h;
    while(p->next) p=p->next;
    p->next=t; t->prev=p;
}
bool isPalindrome(DNode* h){
    if(!h) return true;
    DNode* tail=h;
    while(tail->next) tail=tail->next;
    while(h!=tail && h->prev!=tail){
        if(h->v!=tail->v) return false;
        h=h->next; tail=tail->prev;
    }
    return true;
}
int main(){
    DNode* a=nullptr;
    string s1="radar";
    for(char c:s1) append(a,c);
    cout<<"List 1: radar\nIs palindrome: "<<(isPalindrome(a)?"Yes":"No")<<"\n";

    DNode* b=nullptr;
    string s2="hello";
    for(char c:s2) append(b,c);
    cout<<"List 2: hello\nIs palindrome: "<<(isPalindrome(b)?"Yes":"No")<<"\n";
    return 0;
}
