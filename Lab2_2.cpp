#include<iostream>
#include<stdlib.h>
using namespace std;

#define max_size 1000

class Stack{

    public:
    int top;
    Stack(){top = -1;}
    int a[max_size];

    bool isFull();
    bool isEmpty();
    int push(int);
    int pop();
    void display();
};

bool Stack::isFull(){
    if(top == max_size-1){
        return true;
    }
    return false;
}

bool Stack::isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

int Stack::push(int ele){
    if(!isFull()){
        a[++top] = ele;
    } else{
        cout<<"Stack is empty"<<endl;
    }
}

int Stack::pop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return -1;
    } else{
        return a[top--];
    }
}

void Stack::display(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
    } else{
        cout<<"Stack content: ";
        for(int i=top; i>=0; i--){
            cout<<a[i]<<" ";
        } cout<<endl;
    }
}


int main(){
    Stack s;
    cout<<"Enter the string: ";
    char a[50];
    cin>>a;

    int n=0;

    for(int i=0; a[i]!='\0'; i++){
        n++;
    }

    int count = 0;


    for(int i=0; i<n; i++){
        s.push(a[i]);
    }
    for(int i=0; i<n; i++){
        if(a[i] == s.pop()){
            count++;

        }
    }

    if(count == n){
        cout<<"Palindrome"<<endl;
    } else{
        cout<<"Not a palindrome"<<endl;
    }
    return 0;
}

