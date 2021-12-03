#include<bits/stdc++.h>
#define STACK_SIZE 20

using namespace std;

class Stack{
 private:
     int top;
     int s[10];
 public:
    Stack(){
    top=-1;
    }
    int pop();
    void push(int item);
    void display();
    char topx();

};
void Stack:: push(int item)
{

    if(top== STACK_SIZE-1)
    {

        cout<<"Stack is Full";
        return;

    }

        top=top+1;
        s[top]=item;

}
int Stack::pop(){
  if(top==-1)
  {

      cout<<"Stack is empty";
      return -1;
  }
  else{
    int ele=s[top--];
    return ele;
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
    cout<<s[i];
}
char Stack:: topx(){
  if(top==-1)
  {
      return -1;
  }
  return s[top];
}
//Function to return precedence of characters
int precedence(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
void postfix(string infix)
{
    Stack S1;
    S1.push('k');
    int l=infix.length();
    string ans;
    for(int i=0;i<l;i++)
    {

        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
        {
            ans=ans+infix[i];
        }
        else if(infix[i]=='(')
        {

        S1.push('(');
        }
        else if(infix[i]==')')
        {

            while(S1.topx() != '(')
            {
                char c = S1.topx();
                S1.pop();
               ans += c;
            }
            if(S1.topx() == '(')
            {
                S1.pop();
            }
        }
        else{
            while( precedence(infix[i]) <= precedence(S1.topx()))
            {
                char c = S1.topx();
                S1.pop();
                ans += c;
            }
            S1.push(infix[i]);
        }

    }
     while(S1.topx() != 'k')
    {
        char c =S1.topx();
        S1.pop();
        ans += c;
    }

    cout << ans << endl;
}
int main()
{

   string infix;
   cout<<"Enter the infix expression : ";
   cin>>infix;
   cout<<"The postfix expression is : ";
   postfix(infix);
}
