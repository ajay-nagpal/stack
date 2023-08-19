#include<iostream>
#include<cstdlib>

using namespace std;

class Node{
    public:
    int val;
    Node *next;
}*top=NULL;

void push(int data){
    Node * temp=new Node;
    if(temp==NULL){
        cout<<"overflow"<<endl;
        return;
    }
    temp->val=data;
    temp->next=top;

    top=temp;
}

int pop(){
    int data;
    if(top==NULL){
        cout<<"stack underflow"<<endl;
        exit(1);
    }
    data=top->val;
    top=top->next;

    return data;
}

int peek(){
    if(top==NULL){
        cout<<"stack underflow"<<endl;
        exit(1);
    }
    return top->val;
}

void display(){
    if(top==NULL){
        cout<<"stack underflow"<<endl;
        return;
    }
    Node * temp=top;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main(){
    int choice,data,item;

    while(1){
        cout<<endl;
        cout<<"given choices "<<endl;
        cout<<"01 for push"<<endl;
        cout<<"02 for pop"<<endl;
        cout<<"03 for display top element"<<endl;
        cout<<"04 for display complete stack elements"<<endl;
        cout<<"05 for ending task"<<endl;

        cout<<"enter your choice"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"enter data to push"<<endl;
            cin>>data;
            push(data);
            break;

            case 2:
            item=pop();
            cout<<"pop item is "<<item<<endl;
            break;

            case 3:
            cout<<peek()<<endl;
            break;

            case 4:
            display();
            break;

            case 5:
            cout<<"you have choosen to exit "<<endl;
            exit(1);

            default:
            cout<<"wrong choice entered"<<endl;

        }
    }
}