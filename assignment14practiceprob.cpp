#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct student
{
    string name;
    float cgpa;
} s[10];

void sortname()
{

    for(int i=0; i<10; i++)
    {
        int minindex=i;
        for(int j=i+1; j<10; j++)
        {
            if((s[j].name)<(s[minindex].name))
                minindex=j;
        }
        if(minindex!=i)
        {
            string n=s[minindex].name;
            s[minindex].name=s[i].name;
            s[i].name=n;
            float c=s[minindex].cgpa;
            s[minindex].cgpa=s[i].cgpa;
            s[i].cgpa=c;
        }

    }
}

void sortcgpa()
{

    for(int i=0; i<10; i++)
    {
        int maxindex=i;
        for(int j=i+1; j<10; j++)
        {
            if((s[j].cgpa)>(s[maxindex].cgpa))
                maxindex=j;
        }
        if(maxindex!=i)
        {
            string n=s[maxindex].name;
            s[maxindex].name=s[i].name;
            s[i].name=n;
            float c=s[maxindex].cgpa;
            s[maxindex].cgpa=s[i].cgpa;
            s[i].cgpa=c;
        }

    }


}
void display()
{
    cout<<"NAME\t"<<"CGPA"<<endl;

    for(int i=0; i<10; i++)
    {
        cout<<s[i].name<<"\t"<<s[i].cgpa<<endl;
    }
}

int main()
{
    cout<<"ENTER THE STUDENT DATA\n";
    for(int i=0; i<10; i++)
    {
        cout<<"NAME OF STUDENT"<<i+1<<":";
        cin>>s[i].name;
        cout<<"\n";
        cout<<"CGPA:";
        cin>>s[i].cgpa;
        cout<<"\n";
    }

    int ch,e=0;

    while(e==0)
    {
        cout<<"1.SORT ACCORDING TO NAME(ASCENDING)\n";
        cout<<"2.SORT ACCORDING TO CGPA(DESCENDING)\n";
        cout<<"3.DISPLAY\n";
        cout<<"4.EXIT\n";
        cout<<"ENTER CHOICE\n";
        cin>>ch;



        switch(ch)
        {
        case 1:
            sortname();
            break;
        case 2:
            sortcgpa();
            break;
        case 3:
            display();
            break;
        case 4:
            e=1;

        }

    }
    return 0;

}

