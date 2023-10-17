#include <iostream>

using namespace std;
class node{
    public:
    int data;
    node* next;
    //constructor
    node(int data ){
        this->data = data;
        this->next=NULL;
    }
};
void insertattail(node * &tail , int d){
    node *temp=new node(d);
    tail->next=temp;
    tail=temp;
}
void insertathead(node* &head , int d){
    // new node
    node *temp=new node(d);
    temp->next=head;
    head=temp;
}
void insertatposition(node * &head,node * &tail,int position, int d){
    //insert at start/head postion;
    if(position ==1){
        insertathead(head , d);
        return;
    }
    node *temp=head;
    int count=1;
    while(count <position-1){
        temp=temp->next;
        count++;
    }
    //inserting at tail
    if(temp->next == NULL){
        insertattail(tail,d);
        return;
    }
    // create node for d;
    node *toinsert= new node(d);
    toinsert->next=temp->next;
    //change of pointing type
    temp->next=toinsert;
}
void print(node * &head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        // temp ko aage bada do
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    //dynamic memeory allocation
    //create node
    node *node1=new node(10);
  //  cout<< node1->data<<endl;
    //cout<<node1->next<<endl;
    
    // head point to node 1
    node* head=node1;
    //tail point to node 1
    node *tail=node1;
    //before inserting
    print(head);
    insertattail(tail,12);
     //after  inserting
    print(head);
    //after  inserting
insertattail(tail,15);
print(head);

// insert at position-3
insertatposition(head,tail,3,56);
print(head);
// checking that the head and tail ponter is at right position or not
cout<<head->data<<endl;
cout<<tail->data<<endl;
    return 0;
}
