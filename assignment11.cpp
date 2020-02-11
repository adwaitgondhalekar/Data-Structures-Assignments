#include<iostream>
#include<string.h>
using namespace std;


struct job
{

    char jobname[30];
    job *next;
};

class queue
{

    job *head;
    job *curr,*prev;
public:
    queue()
    {
        head=NULL;
    }
    void addjob();
    void deletejob();
    void displayjob();
};

void queue::addjob()
{


    //cout<<"prev"<<prev<<endl;
    //cout<<"curr"<<curr<<endl;
    char jname[30];

    cout<<"PLEASE ENTER THE JOB NAME\n";
    cin.ignore();
    cin.getline(jname,30);
    curr=new job;
    curr->next=NULL;
    strcpy(curr->jobname,jname);

    if(head==NULL)
    {
        head=curr;
        prev=curr;
    }
    else
    {
        prev->next=curr;
        prev=curr;
    }
    //cout<<"prev"<<prev<<endl;
    //cout<<"curr"<<curr<<endl;
    cout<<"JOB SUCCESSFULLY ADDED\n";
}
void queue::displayjob()
{

    job *temp;
    temp=head;
    int ctr=1;
    if(head!=NULL)
    {
        while(temp!=NULL)
        {
            //cout<<"in while\n";
            cout<<ctr<<"."<<temp->jobname<<endl;
            ctr++;
            temp=temp->next;
        }
    }
    else
        cout<<"NO JOBS ASSIGNED!!!\n";
}
void queue::deletejob()
{
    if(head!=NULL)
    {
        job *succ;
        succ=head->next;
        delete(head);
        head=succ;
        cout<<"JOB DELETED SUCCESSFULLY\n";
    }
    else
    {
        cout<<"NO JOBS TO DELETE!!!\n";
    }
}


int main()
{
    int ch,e=0;
    queue q;

    while(e==0)
    {
        cout<<"MENU\n";
        cout<<"1.ADD JOB\n";
        cout<<"2.DISPLAY JOB\n";
        cout<<"3.DELETE JOB\n";
        cout<<"4.EXIT\n";
        cout<<"PLEASE ENTER YOUR CHOICE\n";
        cin>>ch;

        switch(ch)
        {
        case 1:
            q.addjob();
            break;


        case 2:
            q.displayjob();
            break;

        case 3:
            q.deletejob();
            break;

        case 4:
            e=1;
        }
    }

    return 0;
}


