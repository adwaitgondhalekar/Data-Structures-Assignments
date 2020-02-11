#include<iostream>
using namespace std;

struct node
{

    int bit;
    node *next;
    node *back;

};

class list
{

    node *head;
    node *tail;
public:
    list()
    {
        head=NULL;
        tail=NULL;
    }

    void accept();
    void display();
    void onec();
    void twoc(list l1);
    void add(list l1,list l2);
};

void list::accept()
{
    node *curr=NULL,*prev=NULL;

    int b;
    char ch;
    do
    {
        cout<<"ENTER THE BIT\n";
        cin>>b;

        curr=new node;
        curr->next=NULL;
        curr->back=NULL;
        curr->bit=b;

        if(head==NULL)
        {
            head=curr;
            prev=curr;
        }
        else
        {
            prev->next=curr;
            curr->back=prev;
            prev=curr;
        }
        cout<<"DO YOU WANT TO ADD ANOTHER BIT?(Y/N)\n";
        cin>>ch;

    }
    while(ch=='y'||ch=='Y');
    tail=curr;
}

void list::display()
{
    //cout<<"ENTERED NUMBER IS:-  ";
    node *temp;
    temp=head;

    while(temp!=NULL)
    {

        cout<<temp->bit;
        temp=temp->next;
    }
    cout<<"\n";
}

void list::onec()
{

    cout<<"ONE'S COMPLEMENT IS:-  ";
    node *temp;
    temp=head;

    while(temp!=NULL)
    {

        if(temp->bit==0)
            cout<<"1";
        else
            cout<<"0";

        temp=temp->next;
    }
    cout<<"\n";
}

void list::twoc(list l1)
{

    node *prev,*curr,*temp1;
    temp1=l1.tail;

    while(temp1->bit!=1)
    {
        curr=new node;
        curr->next=NULL;
        curr->back=NULL;
        curr->bit=temp1->bit;
        if(tail==NULL)
        {
            tail=curr;
            prev=curr;
        }
        else
        {
            curr->next=prev;
            prev->back=curr;
            prev=curr;
        }
        head=curr;
        temp1=temp1->back;

    }
    curr=new node;
    curr->next=NULL;
    curr->back=NULL;
    curr->bit=temp1->bit;
    if(tail==NULL)
    {
        tail=curr;
        prev=curr;
    }
    else
    {
        curr->next=prev;
        prev->back=curr;
        prev=curr;
    }
    temp1=temp1->back;
    head=curr;
    while(temp1!=NULL)
    {

        if(temp1->bit==1)
        {
            curr=new node;
            curr->next=NULL;
            curr->back=NULL;
            curr->bit=0;

        }
        else if(temp1->bit==0)
        {
            curr=new node;
            curr->next=NULL;
            curr->back=NULL;
            curr->bit=1;
        }
        if(tail==NULL)
        {
            tail=curr;
            prev=curr;
        }
        else
        {
            curr->next=prev;
            prev->back=curr;
            prev=curr;
        }
        temp1=temp1->back;

    }
    head=curr;

}


void list::add(list l1,list l2)
{
    int carry=0,sum=0,res=0;
    node *temp1,*temp2,*prev,*curr;
    temp1=l1.tail;
    temp2=l2.tail;

    while(temp1!=NULL && temp2!=NULL)
    {

        sum=carry+temp1->bit+temp2->bit;
        res=sum%2;
        carry=sum/2;
        //cout<<"sum-"<<sum<<endl;
        //cout<<"carry-"<<carry<<endl;
        //cout<<"res-"<<res<<endl;
        curr=new node;
        curr->next=NULL;
        curr->back=NULL;
        curr->bit=res;
        if(tail==NULL)
        {
            tail=curr;
            prev=curr;
        }
        else
        {
            prev->back=curr;
            curr->next=prev;
            prev=curr;
        }
        head=curr;

        temp1=temp1->back;
        temp2=temp2->back;
    }

    while(temp1!=NULL)
    {
        sum=carry+temp1->bit;
        res=sum%2;
        carry=sum/2;
        curr=new node;
        curr->next=NULL;
        curr->back=NULL;
        curr->bit=res;
        if(tail==NULL)
        {
            tail=curr;
            prev=curr;
        }
        else
        {
            prev->back=curr;
            curr->next=prev;
            prev=curr;
        }
        temp1=temp1->back;
    }

    while(temp2!=NULL)
    {
        sum=carry+temp2->bit;
        res=sum%2;
        carry=sum/2;
        curr=new node;
        curr->next=NULL;
        curr->back=NULL;
        curr->bit=res;
        if(tail==NULL)
        {
            tail=curr;
            prev=curr;
        }
        else
        {
            prev->back=curr;
            curr->next=prev;
            prev=curr;
        }
        temp2=temp2->back;
    }
    if(carry==1)
    {
        curr=new node;
        curr->next=NULL;
        curr->back=NULL;
        curr->bit=carry;
        if(tail==NULL)
        {
            tail=curr;
            prev=curr;
        }
        else
        {
            prev->back=curr;
            curr->next=prev;
            prev=curr;
        }
    }
    head=curr;
}
int main()
{
    int ch,e=0;

    list l1,l2,l3,l4;
    l1.accept();

    while(e==0)
    {

        cout<<"1.DISPLAY THE ENTERED NUMBER\n";
        cout<<"2.DISPLAY THE ONE'S COMPLEMENT\n";
        cout<<"3.DISPLAY THE TWO'S COMPLEMENT\n";
        cout<<"4.PERFORM ADDITION\n";
        cout<<"5.EXIT\n";
        cin>>ch;

        switch(ch)
        {

        case 1:
            l1.display();
            break;

        case 2:
            l1.onec();
            break;

        case 3:
            l4.twoc(l1);
            l4.display();
            break;

        case 4:
            l2.accept();
            l3.add(l1,l2);
            cout<<"RESULT IS\n";
            l3.display();
            break;

        case 5:
            e=1;

        }
    }

    return 0;

}





