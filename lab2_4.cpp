#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<process.h>
#include<dos.h>
#include<windows.h>
using namespace std;
int n;
class stack
{
    int top;
    int arr[];
    public:
    stack() //constructor
    {
        top=-1;
        for(int i=0;i<n;i++)
            arr[i]=0;
    }
    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(top==n-1)
            return true;
        else
            return false;
    }
    void push()
    {
         int val;
         if(isEmpty())
        {
             cout<<"Enter the number of elements of the stack:";
             cin>>n;
             cout<<"Enter the elements of the stack:\n";
             cin>>val;
             top++;
             arr[top]=val;
             push();
        }
        else if(isFull())
            cout<<"Stack overflow\n";
        else
        {
            for(int i=0;i<n;i++)
            {
                if(isFull())
                {
                    cout<<"\tStack is full";
                    break;
                }
                else
                {
                   cin>>val;
                   top++;
                   arr[top]=val;
                }

            }

        }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"stack underflow";
            return 0;
        }
        else
        {
            int popVal=arr[top];
            arr[top]=0;
            top--;
            cout<<"Element successfully removed";
            return popVal;
        }
    }
    void display()
    {
        if(isEmpty())
            cout<<"stack underflow,no elements to display";
        else
            for(int i=top;i>=0;i--)
                cout<<arr[i]<<"\n";
    }
}; //end of the class
int main()
{
int choice,num;
stack s[100];
    cout<<"Enter the number of stacks required:";
    cin>>num;

    for(int i=0;i<num;i++)
    {

        do
        {
            system("cls");
            cout<<"\t\tOperations on stack "<<i+1;
            cout<<"\n1.Push\n2.Pop\n3.Check if the stack is empty\n4.Check is the stack is full\n5.Display\n6.Exit\nEnter your choice:";
            cin>>choice;
            system("cls");
            switch(choice)
            {
                case 1:{ s[i].push();
                        sleep(3);
                        break;}
                case 2: {s[i].pop();
                        sleep(3);
                        break;}
                case 3:{bool emp=s[i].isEmpty();
                    if(emp==true)
                        cout<<"\nStack is empty";
                    else
                        cout<<"\nStack is not empty";
                    sleep(3);
                    break;}
                case 4:{bool full=s[i].isFull();
                    if(full==true)
                        cout<<"\nStack is Full";
                    else
                        cout<<"\nStack is not full";
                    sleep(3);
                    break;}
                case 5:{s[i].display();
                        sleep(3);
                        break;}
                case 6:break;
                default:cout<<"Invalid input";
            }
        }while(choice!=6);
    }
    return 0;
}
