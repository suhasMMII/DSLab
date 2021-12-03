#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;
class Stack
{
private:
    int top;
    char s[MAX][MAX]; //Private variables
public :
    Stack(){top = -1;}
    void push(char a[]);
    char *pop();            //Public members
};
void Stack::push(char a[])
{
    top++;
    strcpy(s[top], a);   //Push if not full
}
char* Stack :: pop()
{
    if(top == -1)
    {
        return "x";  //Pop some character
    }
    else
    {
        return s[top--];  //Pop if not empty
    }
}
void postfix_infix(char postfix[])
{
    Stack S1;
    char op1[20], op2[20], operator1[20];
    char symbol[20];

    for(int i = 0; i < strlen(postfix); i++)
    {
        char temp1[20], temp2[20];
        temp1[0] = postfix[i];  //Store expression in temp1
        temp1[1] =  '\0';   //Add null character at end
        strcpy(symbol, temp1);  //Copy temp to symbol
        if(!isalpha(postfix[i]))  //If not an alphabet
        {
        strcpy(op2, S1.pop());
        strcpy(op1, S1.pop());
        strcpy(temp2, "(");
        strcat(temp2, op1);
        strcat(temp2, symbol);
        strcat(temp2, op2);
        strcat(temp2, ")");
        S1.push(temp2);       //Make required expression by popping and pushing
        }
        else{S1.push(symbol);

        }
    }
    cout << "Result : " << S1.pop();
}
int main()
{
	char postfix[20];
	cout << "Please enter a postfix expression:";
    gets(postfix);
    postfix_infix(postfix);
    return 0;
}
