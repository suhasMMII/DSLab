#include <iostream>
using namespace std;

class Student{
    public:
    char name[20];
    int roll;
    double cgpa;

    void read(){
        cout<<"Enter the name of the student: "<<endl;
        cin>>name;
        cout<<"Enter the roll number of the student: "<<endl;
        cin>>roll;
        cout<<"Enter the CGPA of the student: "<<endl;
        cin>>cgpa;
    }

    void display(){
        cout<<"Roll number: "<<roll<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"CGPA: "<<cgpa<<endl;
    }
};

int main(){
   Student s[20];
   int n;
   cout<<"Enter the number of students: "<<endl;
   cin>>n;

   for(int i=0; i<n; i++){
       cout<<"Enter the details of student "<<i+1<<endl;
       s[i].read();
   }

   for(int i=0; i<n; i++){
       for(int j=i+1; j<n; j++){
           if(s[j].roll < s[i].roll){
               swap(s[j], s[i]);
           }
       }
   }

   for(int i=0; i<n; i++){
       cout<<endl;
       s[i].display();
   }

   return 0;
}
