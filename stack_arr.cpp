#include<iostream>
#include<cstdlib>

#define MAX 10

using namespace std;

int arr[MAX];
int top=-1;

void push(int data){
    if(top==MAX-1){
        cout<<"stack overflow"<<endl;
        return;
    }
    arr[++top]=data;
}

int pop(){
    int data;
    if(top==-1){
        cout<<"stack underflow"<<endl;
        exit(1);
    }
    data=arr[top--];
    return data;
}

int peek(){
    if(top==-1){
        cout<<"stack underflow"<<endl;
        exit(1);
    }
    return arr[top];
}

void display(){
    if(top==-1){
        cout<<"stack underflow"<<endl;
        return;
    }
    while(top!=-1){
        cout<<arr[top--]<<" ";
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