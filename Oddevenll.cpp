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
Node* convertarr2ll(vector<int> arr){
    Node* head=new Node(arr[0]);
Node* mover=head;
for(int i=1;i<arr.size();i++){
    Node* temp=new Node(arr[i]);
    mover->next=temp;
    mover=temp;
}
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
Node* oddevenindex(Node* head){
    Node* odd=head;
    Node* even=head->next;
    Node* evenhead=head->next;
    while(even!=NULL && even->next->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;

    }
    odd->next=evenhead;
    return head;
}
int main(){
     vector<int> ar={1,2,3,4,5};
     Node* head=convertarr2ll(ar);
     cout<<"original linked list is\n";
     print(head);
     cout<<"new linked list\n";
     head=oddevenindex(head);
     print(head);
}
