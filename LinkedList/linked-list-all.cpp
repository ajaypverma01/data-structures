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

void removeDuplicates(Node*& head){
    Node* p = head;
    Node* q = head->next;
    
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
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
    
    int a[]={1,2,3,3,4,4,5};
    int n = sizeof(a)/sizeof(a[0]);
    
    Node* head = new Node();
    create(head,a,n);
    display(head);
    removeDuplicates(head);
    display(head);
    
    return 0;
}