#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* del(Node* head){
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
   Node* mid=slow->next;
    slow->next=slow->next->next;
    free(mid);
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data;
        cout<<"-->";
        head=head->next;
    }
    cout<<"NULL";
}
int main(){
     Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
    print(head);
    del(head);
    cout<<"\n";
    print(head);
}
