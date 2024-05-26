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
Node* convert2ll(vector<int> &a){
Node* head=new Node(a[0]);
Node* mover=head;
for(int i=1;i<a.size();i++){
    Node* temp=new Node(a[i]);
    mover->next=temp;
    mover=temp;
}
return head;
}
void print(Node* head){
    while(head!=NULL){
         cout<<head->data;
         cout<<" ";
         head=head->next;
    }
    cout<<"NULL";
}
Node* findmiddle(Node* head){

    Node* slow;
    Node* fast;
    slow=head;
    fast=head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convert2ll(arr);
    Node* head1=findmiddle(head);
    cout<<"middle element is --> "<<head1->data;
    return 0;
}
