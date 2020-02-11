#include<iostream>
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
    void adddata();
    void deletedata();
    void display();


};

void list::adddata()
{
    node *curr;
    int d;

    cout<<"ENTER A NUMBER\n";
    cin>>d;
    curr=new node;
    curr->next=NULL;
    curr->data=d;


    if(front==NULL)
    {
        front=curr;
    }
    else
        rear->next=curr;

    rear=curr;
    rear->next=front;

}
void list::deletedata()
{

    if(front==NULL)
        cout<<"EMPTY QUEUE\n";

    if(front==rear)
    {
        cout<<"DELETED DATA:-"<<front->data<<endl;
        delete(front);
        front=NULL;
        rear=NULL;
    }
    else
    {
        cout<<"DELETED DATA:-"<<front->data<<endl;
        node *temp;
        temp=front->next;
        delete(front);
        front=temp;
        rear->next=front;
    }



}
void list::display()
{
    node *temp;

    temp=front;

    while(temp->next!=front)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<temp->data<<endl;

}
int main()
{
    list l;

    int ch,e=0;

    while(e==0)
    {

        cout<<"1.ADD DATA\n";
        cout<<"2.DELETE DATA\n";
        cout<<"3.DISPLAY\n";
        cout<<"4.EXIT\n";
        cout<<"ENTER YOUR CHOICE\n";
        cin>>ch;

        switch(ch)
        {

        case 1:
            l.adddata();
            break;

        case 2:
            l.deletedata();
            break;

        case 3:
            l.display();
            break;

        case 4:
            e=1;
        }

    }
}

