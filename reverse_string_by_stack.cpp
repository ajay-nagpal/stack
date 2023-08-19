#include<iostream>
#include<cstring>
#include<cstdlib>

#define MAX 20

using namespace std;

char arr[MAX] ;
int top=-1;

void push(char s){
    if(top==MAX-1){
        cout<<"overflow"<<endl;
        return;
    }
    arr[++top]=s;
}

char pop(){
    char s;
    if(top==-1){
        cout<<"underflow"<<endl;
        exit(1);
    }
    s=arr[top--];
    return s;
}

int main(){
    char s[MAX];
    //char *s;
    //string s;
    cout<<"enter string"<<endl;
    cin>>s;
    cout<<"string is "<<s<<endl;

    for(int i=0;i<strlen(s);i++)
        push(s[i]);
    for(int i=0;i<strlen(s);i++)
        s[i]=pop();

    // int a=sizeof(s)/sizeof(char);

    //  for(int i=0;i<a;i++)
    //     push(s[i]);
    //  for(int i=0;i<a;i++)
    //     s[i]=pop();

    cout<<"reverse string is "<<s<<endl;
   
}