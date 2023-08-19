#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

#define MAX 50
int top=-1;

// char stackarr[MAX];
int stackarr[MAX];


char infix[MAX];
char postfix[MAX];

#define BLANK ' '
#define TAB '\t'


int blank(char sym){
    if(sym==BLANK || sym==TAB)
        return 1;
    return 0;
}

// void push(char data){
//     if(top==MAX-1){
//         cout<<"overflow"<<endl;
//         exit(1);
//     }
//     stackarr[++top]=data;
// }

// char pop(){
//     if(top==-1){
//         cout<<"underflow"<<endl;
//         exit(1);
//     }
//     return stackarr[top--];
// }

void push(int data){
    if(top==MAX-1){
        cout<<"overflow"<<endl;
        exit(1);
    }
    stackarr[++top]=data;
}

int pop(){
    if(top==-1){
        cout<<"underflow"<<endl;
        exit(1);
    }
    return stackarr[top--];
}

int priority(char sym){
    if(sym=='+'||sym=='-')
        return 1;
    else if(sym=='*'||sym=='/'||sym=='%')
        return 2;
    else if(sym=='^')
        return 3;
    else
        return 0;
}

void infix_to_postfix(){
    char sym;
    int a=0;
    char popsym;

    for(int i=0;i<strlen(infix);i++){
        sym=infix[i];

        if(!blank(sym)){

            if(sym=='('){
                push(sym);
            }
            else if(sym==')'){
               
                while(( popsym=pop())!='('){
                    postfix[a++]=popsym;
                }
            }
            else if(sym=='+'||sym=='-'||sym=='*'||sym=='/'||sym=='^'){
                while(top!=-1 &&(priority(stackarr[top])>=priority(sym))){
                    postfix[a++]=pop();
                }
                push(sym);
            }
            else{
                postfix[a++]=sym;
            }  
        }
    }
    while(top!=-1){
        postfix[a++]=pop();
    }
    postfix[a]='\0';
}

int eval(){
    char sym;
    int j=0,b,a,result=0;
    for(int i=0;i<strlen(postfix);i++){
        sym=postfix[i];
        if(sym>='0' && sym<='9'){
            push(sym-'0');
        }
        else{
            a=pop();
            b=pop();
            
            switch(sym){
                case '+':
                result= b + a;
                break;

                case '-':
                result= b - a;
                break;

                case '*':
                result=b *a;
                break;

                case '/':
                result=b / a;
                break;

                case '^':
                result=pow(b,a);
                break;
            }
            push(result);
        }
    }
    result=pop();
    return result;
}

int main(){
    cout<<"enter infix exp"<<endl;
    cin>>infix;
    cout<<"infix exp is "<<infix<<endl;

    cout<<"convert thjis infiox exp to postfix "<<endl;

    infix_to_postfix();
    cout<<"postfix exp is "<<postfix<<endl;

    int val=eval();
    cout<<"value of postfix exp is "<< val<<endl;
}