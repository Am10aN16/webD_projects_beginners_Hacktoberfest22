#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }

};

void print(Node *head)
{
    Node *temp=head;
    while(temp)
    {
       cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* take_input_better()
{
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=head;
    while(data!=-1)
    {
        Node *newNode=new Node(data);
        if(!tail){
        head=newNode;
        tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
Node* insertNode(Node *head,int data,int i)
{
    if(i==0)
    {
        Node *newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        return head;
    }
    int count=0;
    Node *temp=head;
    while(temp&&count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp){
    Node *newNode=new Node(data);
    newNode->next=temp->next;
    temp->next=newNode;
    }
    return head;
}

int countNodes(Node *head)
{
    int count=0;
    Node *temp=head;
    while(temp)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
Node *deleteNode(Node *head, int pos)
{
    int count=countNodes(head);
    // cout<<count<<endl;
    if(pos<count){
    if(pos==0)
    {
        Node *p=head;
        head=head->next;
        delete p;
    }
    else{
    Node *temp=head;
    int count=0;
    while(temp!=NULL&&count<pos-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
    Node *p=temp->next;
    temp->next=p->next;
    delete p;}
    }
    }
    return head;

}

Node *midpoint(Node *head)
{
    if(!head)
    return head;
    Node *fast=head;
    Node *slow=head;
    while(fast->next&&fast->next->next)
    {
        
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
void reverseRecursive(Node *head)
{
    if(head==NULL)
    return ;
    reverseRecursive(head->next);
    cout<<head->data<<" ";
}
int main()
{
   Node *head=take_input_better();

    // print(head);
    int data,i;
    // cin>>i>>data;
    // head=insertNode(head,data,i);
    // print(head);




    // int pos;
    // cin>>pos;
    // head=deleteNode(head,pos);
    // print(head);
    reverseRecursive(head);
    Node *mid=midpoint(head);
    cout<<mid->data<<endl;
}


