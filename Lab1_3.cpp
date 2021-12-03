#include<iostream>
using namespace std;

class time{
    public:
    int h,m,s=0;
    void read(){
        cout<<"Enter time in HH:MM:SS format (Press enter after every measure of time) "<<endl;
        cin>>h>>m>>s;
    }


    void add(time t1, time t2){
         int insec1 = (t1.h*60*60) + (t1.m*60) + t1.s;
         int insec2 = (t2.h*60*60) + (t2.m*60) + t2.s;

         int addedsec = insec1 + insec2;

         int addedh = addedsec / (60*60);
         addedsec = addedsec % (60*60);
         int addedm = addedsec / 60;
         addedsec = addedsec % 60;
         int addedsecfinal = addedsec;

         cout<<"The added time is "<<addedh<<": "<<addedm<<": "<<addedsecfinal<<endl;
    }

    void subtract(time t1, time t2){
        int insec1 = (t1.h*60*60) + (t1.m*60) + t1.s;
        int insec2 = (t2.h*60*60) + (t2.m*60) + t2.s;

        int subtractedsec = insec1 - insec2;

        int subtractedh = subtractedsec/(60*60);
        subtractedsec = subtractedsec % (60*60);

        int subtractedm = subtractedsec / 60;
        subtractedsec = subtractedsec % 60;

        int subtractedsecfinal = subtractedsec;

        cout<<"The time difference is "<<subtractedh<<": "<<subtractedm<<": "<<subtractedsecfinal<<endl;
    }

};

int main(){
    time t1;
    time t2;
    time t3;

    t1.read();
    t2.read();

    int userq = 0;

    cout<<"Press 1 for addition or 2 for subtraction: ";
    cin>>userq;

    if(userq == 1){
        t3.add(t1, t2);
    }
    else if(userq == 2){
        t3.subtract(t1, t2);
    }
    else{
        cout<<"Please enter a valid option"<<endl;
    }

    return 0;
}
