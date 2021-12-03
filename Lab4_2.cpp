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

void postfix_eval(string postfix)
{
    int i,p1,p2;
    Stack S1;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(postfix[i]>=48 && postfix[i]<=57)
        {
            S1.push(postfix[i]-'0');
        }
        else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='*' )
        {
            p2=S1.pop();
            p1=S1.pop();
            switch(postfix[i])
            {
            case '%' :
                {
                    S1.push(p1%p2);
                     break;
                }
            case '/' :
                {
                    S1.push(p1/p2);
                    break;
                }
            case '+' :
                {
                    S1.push(p1 + p2 );
                    break;
                }
            case '-':
                {
                    S1.push(p1- p2 );
                    break;
                }
            case '*' :
                {
                    S1.push(p1*p2);
                     break;
                }
            }
        }
        else // if alphabet
        {
            cout << "Enter value :" ;
            int val;
            cin >> val;
            S1.push(val);

        }
    }
    cout<<"Answer :"<<S1.pop();
}
int main()
{

   string postfix;
   cin>>postfix;
   postfix_eval(postfix);

}
