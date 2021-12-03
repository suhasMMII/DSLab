#include<iostream>
#include<stdlib.h>
using namespace std;

#define max_size 1000

class Stack{
    int top;
    public:
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

    int option;
    do{
        cout<<"Please enter the operation you want to perform"<<endl;
        cout<<" 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n";
        cout<<"Enter option: ";
        cin>>option;

        switch (option)
        {
        case 1:
            cout<<"Enter the element to be pushed: "; int ele; cin>>ele; s.push(ele); break;

        case 2:
            cout<<s.pop()<<" "<<endl; break;

        case 3: s.display(); break;

        case 4: exit(0);

        default:
            cout<<"Please enter a valid option";
            break;
        }
    }
    while(1);
    return 0;
}
