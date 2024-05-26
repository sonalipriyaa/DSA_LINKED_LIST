#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(Node* next1,int data1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* addtwonos(Node* num1,Node* num2){
    Node* dummyhead=new Node(-1);
    Node* curr=dummyhead;
    Node* t1=num1;
    Node* t2=num2;
    int carry=0;
    while(t1!=NULL || t2!=NULL){
        int sum=carry;
        if(t1) sum+=t1->data;
        if(t2) sum+=t2->data;
        Node* newnode=new Node(sum%10);
        carry=sum/10;
        curr->next=newnode;
        curr=curr->next;
        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
        if(carry){
            Node* newnode=new Node(carry);
            curr->next=newnode;
        }
       
    }
     return dummyhead->next;
}
Node* convertarr2ll(vector<int> &arr){
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
int main(){
    vector<int> arr={3,5};
    Node* num1=convertarr2ll(arr);
    vector<int> arr2={4,5,9,9};
    Node* num2=convertarr2ll(arr2);
    Node* head=addtwonos(num1,num2);
    print(head);
}
