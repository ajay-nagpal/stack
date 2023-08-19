#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#define MAX 15
char stackarr[MAX];
int top=-1;

void push(char data){
    if(top==MAX-1){
        cout<<"overflow"<<endl;
        return;
    }
    stackarr[++top]=data;
}

char pop(){
    if(top==-1){
        cout<<"underflow"<<endl;
        exit(1);
    }
    return stackarr[top--];
}

int match(char a, char b){
    if((a=='[' && b==']')||(a=='{' && b=='}')||(a=='(' && b==')'))
        return 1;
    return 0;
}

int main(){
    char exp[MAX];
    cout<<"enter exp"<<endl;
    cin>>exp;
    cout<<exp<<endl;

    char temp;

    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='[' || exp[i]=='{'|| exp[i]=='(' ){
            push(exp[i]);
        }

        if(exp[i]==']' || exp[i]=='}'|| exp[i]==')' ){
            if(top==-1){
                cout<<"invalid exp no left paranth only right paranth"<<endl;
            }

            temp=pop();

            if(match(temp,exp[i])){
                cout<<"paran matched "<<temp<<","<<exp[i]<<endl;
                continue;
            }
            else{
                cout<<"paran not matched "<<temp<<","<<exp[i]<<endl;
                cout<<"invalid exp"<<endl;
                exit(1);
            }

        }
    }
    if(top==-1){
        cout<<"valid expression"<<endl;
    }
}