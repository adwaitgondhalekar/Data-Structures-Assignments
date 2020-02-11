#include<iostream>
#include<string.h>
using namespace std;

struct node
{
   int data;
   node *next;
};
class list
{
    node *front,*rear;
public:
    list()
    {
        front=NULL;
        rear=NULL;
    }
    void addjob();
    void deletejob();
    void display();
};

void list::addjob()
{
    node *curr;
    int d;
    cout<<"ENTER DATA\n";
    cin>>d;
    if(rear==NULL)
    {
        curr=new node;
        curr->next=NULL;
        curr->data=d;
        rear=curr;
        front=rear;
    }
    else
    {
        curr=new node;
        curr->next=NULL;
        curr->data=d;
        rear->next=curr;
        rear=curr;
    }

}
void list::display()
{
    node *f;
    f=front;

    if(f==NULL&&rear==NULL)
        cout<<"EMPTY QUEUE\n";
        else
        {

    while(f!=rear)
    {
        cout<<f->data<<"\t";
        f=f->next;
    }
    if(f==rear)
        cout<<f->data;
        cout<<"\n";
        }
}
void list::deletejob()
{
    node *f=front;
    if(front==rear)
        cout<<"EMPTY QUEUE\n";
    else
    {
        if(f->next!=NULL)
        {
            cout<<"DELETED DATA:-"<<f->data<<endl;
            f=f->next;
            delete(front);
            front=f;
        }
        else
        {
            cout<<"DELETED DATA:-"<<f->data<<endl;
            delete(front);
            front=NULL;
            rear=NULL;
        }

    }
}
int main()
{
    list l;
    int ch,e=0;

    while(e==0)
    {
          cout<<"1.ADD DATA\n";
          cout<<"2.DELETE DATA\n";
          cout<<"3.DISPLAY QUEUE\n";
          cout<<"4.EXIT\n";
          cout<<"ENTER YOUR CHOICE\n";
          cin>>ch;


            switch(ch)
            {
                case 1: l.addjob();
                        break;

                case 2: l.deletejob();
                        break;

                case 3: l.display();
                        break;

                case 4: e=1;
            }
    }
    return 0;
}






