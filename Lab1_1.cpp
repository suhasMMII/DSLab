#include <iostream>

using namespace std;

int length(char a[]){

    int i=0;

    for(i=0; a[i]!='\0'; i++);

    return i;

}

void concatenation(char a[50]){

    cout<<"Enter the second string: ";
    char b[50];
    cin>>b;

    int pos = 50;

    cout<<"Enter the position in which the second string should be inserted to the first: ";

    cin>> pos;

    char temp[100];

    for(int i=0; i<pos; i++){

            temp[i] = a[i];

    }

    int j=0;

    for(int i=pos; i<pos+50; i++){

        temp[i] = b[j];

        j++;

    }

    cout<<"The string after concatenation is: "<<temp<<endl;

}

void comparison(char a[50]){

    cout<<"Enter the second string: ";
    char b[50];
    cin>>b;

    bool flag = true;

    int m=length(a);

    int n=length(b);

    int mx = max(m, n);

    for(int i=0; i<mx; i++){

        if(a[i] != b[i]){

            flag = false;

            break;

        }

    }

    if(flag){

        cout<<"The strings are equal"<<endl;

    }

    else{

        cout<<"The strings are not equal"<<endl;

    }

}

void insertstr(char a[50]){

    cout<<"Enter the second string: ";
    char b[50];
    cin>>b;

    int pos=0;

    cout<<"Enter the position at which the string should be inserted: ";

    cin>>pos;

    char temp[100];

    int m=length(a);

    int n=length(b);

    int i=0;

    for(i=0; i<pos; i++){

        temp[i] = a[i];

    }

    for(int j=0; j<n; j++){

        temp[i] = b[j];

        i++;

    }

    for(int k=pos; k<m; k++){

        temp[i] = a[k];

        i++;

    }

    temp[i] = '\0';

    cout<<"The final string is "<<temp<<endl;

}

void deletestr(char a[50]){

    int pos1 = 0;
    int pos2 = 0;

    cout<<"Enter the position from which the array has to be deleted: ";
    cin>>pos1;
     cout<<"Enter the position till which the array has to be deleted: ";
    cin>>pos2;

    int m = length(a);
    //int n = length(b);

    int finalpos = m-(pos2-pos1);
    char ans[finalpos];

    int i = 0;
    for(i=0; i<pos1; i++){
        ans[i] = a[i];
    }

    for(int j=pos2; j<m; j++){
        ans[i] = a[j];
        i++;
    }

    for(int j=0; j<finalpos; j++){
        cout<<ans[j];
    }

}

int main(){

   char a[50];

   cout<<"Enter the first string: ";

   cin>>a;

   int question = 0;

   cout<<"What operation do you want to perform? Press"<<endl;
   cout<<"1 to find the length of the string"<<endl;
   cout<<"2 to concatenate 2 strings"<<endl;
   cout<<"3 to compare 2 strings"<<endl;
   cout<<"4 to insert a string to another string"<<endl;
   cout<<"5 to delete a substring"<<endl;

   cin>>question;

    switch(question){

        case 1:
        cout<<"The length of the string is "<<length(a)<<endl;
        break;

        case 2:
        concatenation(a);
        break;

        case 3:
        comparison(a);
        break;

        case 4:
        insertstr(a);
        break;

        case 5:
        deletestr(a);
        break;

        default:
        cout<<"Please enter a valid option";
    }

   return 0;

}
