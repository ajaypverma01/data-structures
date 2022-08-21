/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void create(Node*& head, int a[], int n){
    Node* temp;
    head->data = a[0];
    head->next = NULL;
    temp = head;
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node();
        newNode->data = a[i];
        newNode->next = NULL;
        
        temp->next = newNode;
        temp = newNode;
    }
}

void display(Node* head){
    Node* p = head;
    while(p!=NULL){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    cout<<"Linked list tutorial"<<endl;
    
    int a[]={2,10,19,7,18,16};
    int n = sizeof(a)/sizeof(a[0]);
    
    Node* head = new Node();
    create(head,a,n);
    display(head);
    
    return 0;
}