#include<iostream>
#include<vector>
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
int finder(Node* sl,Node* fa){
    int cnt=1;
    fa=fa->next;
    while(sl!=fa){
        cnt++;
        fa=fa->next;
    }
    return cnt;
}
int checkloop(Node *head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast){
            return finder(slow,fast);
        }
        
    }
    return 0;
    
}
int main(){
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
    
   cout<<checkloop(head);

    
}
