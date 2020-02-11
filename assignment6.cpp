#include<iostream>
#include<string.h>

using namespace std;

struct node
{

    int prn;
    char name[30];
    node *next;

};

class list
{

    node *head,*tail;
    int ctr1,ctr2;
public:

    list()
    {
        head=NULL;
        tail=NULL;
        ctr1=0;
        ctr2=0;
    }

    void create();
    void display();
    void insert();
    void deleted();
    void count();
    void concate(list l1,list l2);
    //void reversed(node *temp);
};

void list::create()
{

    node *curr,*prev;
    int pr;
    char n[30],ch;





    do
    {
        cout<<"PLEASE ENTER THE PRN OF THE STUDENT\n";
        cin>>pr;
        cout<<"PLEASE ENTER THE NAME OF THE STUDENT\n";
        cin.ignore();
        cin.getline(n,30);
        curr=new node;
        curr->next=NULL;
        curr->prn=pr;
        strcpy(curr->name,n);

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
        ctr1++;

        cout<<"DO YOU WNAT TO ADD MORE MEMBERS?(Y/N)\n";
        cin>>ch;
    }
    while(ch=='Y'||ch=='y');
    tail=curr;


}

void list::display()
{


    node *temp;
    temp=head;


    while(temp!=NULL)
    {
        if(temp==head)
        {
            cout<<"NAME:"<<temp->name<<"(PRESIDENT)"<<endl;
            cout<<"PRN:"<<temp->prn<<endl;
            temp=temp->next;
        }
        else if(temp==tail)
        {
            cout<<"NAME:"<<temp->name<<"(SECRATARY)"<<endl;
            cout<<"PRN:"<<temp->prn<<endl;
            temp=temp->next;
        }

        else
        {
            cout<<"NAME:"<<temp->name<<"(MEMBER)"<<endl;
            cout<<"PRN:"<<temp->prn<<endl;
            temp=temp->next;
        }
    }



}

void list::insert()
{





    node *nexn,*curr,*temp;
    int pos,pr,ctr=0;
    char n[30];
    cout<<"PLEASE ENTER THE POSITION AT WHICH YOU WANT TO ADD NEW MEMBER\n";
    cin>>pos;


    temp=head;
    cout<<"PLEASE ENTER THE PRN OF THE STUDENT\n";
    cin>>pr;
    cout<<"PLEASE ENTER THE NAME OF THE STUDENT\n";
    cin.ignore();
    cin.getline(n,30);


    while(temp!=NULL)
    {
        ctr++;

        if(pos==1)
        {
            curr=new node;
            curr->prn=pr;
            curr->next=NULL;
            strcpy(curr->name,n);
            nexn=temp;
            curr->next=temp;
            head=curr;
            ctr1++;
            break;
        }
        else if(ctr==pos-1&&pos!=ctr1)
        {
            curr=new node;
            curr->prn=pr;
            curr->next=NULL;
            strcpy(curr->name,n);
            nexn=temp->next;
            temp->next=curr;
            curr->next=nexn;
            ctr1++;
        }
        else if(pos==ctr1)
        {
            curr=new node;
            curr->prn=pr;
            curr->next=NULL;
            strcpy(curr->name,n);
            tail->next=curr;
            tail=curr;
            ctr1++;
            break;
        }
        temp=temp->next;
    }
}



void list::deleted()
{

    int prnd,ctr=0,flag=0;
    node *temp,*curr,*nexn;

    cout<<"ENTER THE PRN OF MEMBER WHOM YOU WANT TO REMOVE\n";
    cin>>prnd;
    temp=head;

    while(temp!=NULL)
    {
        if(temp->prn==prnd)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }


    if(flag==1)
    {

        while(temp!=NULL)
        {
            if(head->prn==prnd)
            {
                nexn=temp->next;
                delete(temp);
                head=nexn;
                ctr1--;
                cout<<"DELETION DONE SUCCESSFULLY\n";
                flag=1;
                break;
            }

            else if(temp->next->prn==prnd&&temp->next!=tail)
            {
                nexn=temp->next->next;
                curr=temp->next;
                delete(curr);
                temp->next=nexn;
                cout<<"DELETION DONE SUCCESSFULLY\n";
                flag=1;
                ctr1--;
                break;
            }
            else if(temp->next==tail&&prnd==tail->prn)
            {
                nexn=temp->next;
                delete(nexn);
                temp->next=NULL;
                tail=temp;
                ctr1--;
                cout<<"DELETION DONE SUCCESSFULLY\n";
                flag=1;
                break;
            }
            temp=temp->next;
        }
    }

    /*else
    {
    cout<<"ONLY TWO MEMBERS ARE LEFT SO CANNOT REMOVE ANY OF THEM!\n";
    flag=1;
    }*/

    else
        cout<<"THE SAID PRN IS NOT PRESENT IN THE LIST\n";
}

void list::count()
{

    cout<<"TOTAL MEMBERS ARE:"<<ctr1<<endl;
}

void list::concate(list l1,list l2)
{


    node *temp,*temp1;
    temp=l1.tail;
    temp1=l1.head;
    temp->next=l2.head;
    while(temp1!=NULL)
    {
        if(temp1==l1.head)
        {
            cout<<"NAME:"<<temp1->name<<"(PRESIDENT)"<<endl;
            cout<<"PRN:"<<temp1->prn<<endl;
            temp1=temp1->next;
        }
        else if(temp1==l2.tail)
        {
            cout<<"NAME:"<<temp1->name<<"(SECRATARY)"<<endl;
            cout<<"PRN:"<<temp1->prn<<endl;
            temp1=temp1->next;
        }

        else
        {
            cout<<"NAME:"<<temp1->name<<"(MEMBER)"<<endl;
            cout<<"PRN:"<<temp1->prn<<endl;
            temp1=temp1->next;
        }
    }

}


int main()
{

    list l1,l2,l3;
    int choice,e=0;

    l1.create();



    while(e==0)
    {
        cout<<"MENU\n";
        cout<<"1.DISPLAY DETAILS OF ALL THE MEMBERS IN CLASS 1\n";
        cout<<"2.DISPLAY DETAILS OF ALL MEMBERS IN CLASS 2\n";
        cout<<"3.INSERT A MEMBER\n";
        cout<<"4.DELETE A MEMBER\n";
        cout<<"5.COUNT OF TOTAL MEMBERS\n";
        cout<<"6.CREATE LIST OF MEMBERS IN OTHER CLASS\n";
        cout<<"7.CONCATENATE LIST OF BOTH CLASSES AND DISPLAY\n";

        cout<<"8.EXIT\n";

        cin>>choice;

        switch(choice)
        {
        case 1:
            l1.display();
            break;

        case 2:
            l2.display();
            break;

        case 3:
            l1.insert();
            break;

        case 4:
            l1.deleted();
            break;

        case 5:
            l1.count();
            break;

        case 6:
            l2.create();
            break;

        case 7:
            l3.concate(l1,l2);
            break;

        case 8:
            e=1;
        }
    }


    return 0;
}








