#include<bits/stdc++.h>
#define STACK_SIZE 20

using namespace std;

class Stack{
 private:
     int top;
     int s[10];  //Private variables
 public:
    Stack(){
    top=-1;
    }
    int pop();
    void push(int item);
    void display();
    char topx();  //Public members

};
void Stack:: push(int item)
{

    if(top== STACK_SIZE-1)
    {

        cout<<"Stack is Full";
        return;

    }

        top=top+1;
        s[top]=item; //Pushing elements to stack if it is not full

}
int Stack::pop(){
  if(top==-1)
  {

      cout<<"Stack is empty";
      return -1;
  }
  else{
    int ele=s[top--];
    return ele;  //Popping elements from Stack if it is not empty
  }
 }
 void Stack:: display()
 {

     int i;
     if(top==-1)
     {
            cout<<"Empty Stack \n";
            return;
      }
       cout<<"Contents of stack\n";
    for(i=0;i<=top;i++)
    cout<<s[i];   //Displaying the contents of Stack
}
char Stack:: topx(){
  if(top==-1)
  {
      return -1;
  }
  return s[top];   //Obtaining the top element of stack
}

void prefix_evaluation()
{

    Stack S1 ;
    int digit, op1, op2, res;
    char token, prefix[50] ;
    cout << "Enter the prefix expression:" ;
    cin>>prefix;
    for(int i = strlen(prefix) - 1 ; i >=0 ; i--)
    {

        token = prefix[i];

        if(token >= 48 && token <= 57)
        {

            S1.push(token - '0'); //Checking if digit
        }
        else if(token == '+' || token == '-' || token == '*' || token == '/' || token == '%')
        {
            op1 = S1.pop();
            op2 = S1.pop();

        switch(token)  //Making required calculations
        {
            case '%' :
            {
                S1.push(op1%op2);
                break;
            }
            case '/' :
            {
                S1.push(op1/op2);
                break;
            }
            case '+' :
            {
                S1.push(op1 + op2 );
                break;
            }
            case '-':
            {
                S1.push(op1- op2 );
                break;
            }
            case '*' :
            {
                S1.push(op1*op2);
                break;
            }
        }
        }
        else // if alphabet
        {
            cout << "Enter " << token << " 's value:" ;
            int val;
            cin >> val;
            S1.push(val);

        }
    }
    cout << "Result: " << S1.pop() ;
}
int main()
{

    prefix_evaluation();
    return 0;

}
