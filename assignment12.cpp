#include<iostream>
#define max 10
using namespace std;

class pizza
{

    int order[max];
    int front,rear;
public:
    pizza()
    {
        for(int i=0; i<max; i++)
            order[i]=0;
        front=-1;
        rear=-1;
    }
    int is_empty();
    int is_full();
    void placeorder(int ordno);
    void clearorder();
    void display();

};

int pizza::is_empty()
{

    if(front==rear)
        return 1;
    else
        return 0;
}

int pizza::is_full()
{
    if(((front==0)&&(rear==max-1))||(front==rear+1))
        return 1;
    else
        return 0;
}

void pizza::placeorder(int ordno)
{


    if(!is_full())
    {
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            if(rear==max-1)
            {
                rear=0;
            }
            else
            {
                rear=rear+1;
            }

        }
        order[rear]=ordno;

    }
    else
    {
        cout<<"QUEUE OVERFLOW\n";
    }
}

void pizza::clearorder()
{

    if(!is_empty())
    {
        cout<<"DELIVERED ORDER IS:"<<order[front]<<endl;

        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            if(front==max-1)
                front=0;
            else
                front=front+1;
        }
    }
    else
        cout<<"QUEUE UNDERFLOW\n";
}

void pizza::display()
{
    int f=front,r=rear;
    if(front==0)
    {
        cout<<"ORDERED PLACED ARE:\n";
        int i=1;
        if(f<=r)
        {
            while(f<=r)
            {

                cout<<order[f++]<<endl;
            }
        }
    }
    else
    {
        int i=1;
        if(r<=f)
        {
            while(f<=max-1)
            {
                cout<<order[f++]<<endl;
            }


            f=0;
            while(f<=r)
            {
                cout<<order[f++]<<endl;
            }
        }
        else
        {
            while(f<=r)
            {
                cout<<order[f++]<<endl;
            }
        }
    }
}

int main()
{

    pizza p;
    int ch,e=0,ordno=0;
    while(e==0)
    {

        cout<<"1.PLACE ORDER\n";
        cout<<"2.CLEAR ORDER\n";
        cout<<"3.DISPLAY ORDERS\n";
        cout<<"4.EXIT\n";
        cout<<"PLEASE ENTER YOUR CHOICE\n";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"ENTER ORDER ID\n";
            cin>>ordno;
            p.placeorder(ordno);
            break;
        case 2:
            p.clearorder();
            break;
        case 3:
            p.display();
            break;
        case 4:
            e=1;
        }
    }
    return 0;
}









