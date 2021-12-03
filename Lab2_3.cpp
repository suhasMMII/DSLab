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

            if(a[i] < 10){

                cout<<a[i];

            }

            else{

                cout<<char(a[i] + 55);

            }

        } cout<<endl;

    }

}
int main(){

    Stack st;

    int base;

    cout<<"Enter the base to which u want to convert the number to: "<<endl;

    cin>>base;

    int n;

    cout<<"Enter the number: "<<endl;

    cin>>n;

    int rem;
        do{

        rem = n%base;

        if(rem<10){

            st.push(rem);

        } else{

            st.push(rem);

        }
        n/=base;

        } while(n!=0);
    st.display();
    return 0;

}
