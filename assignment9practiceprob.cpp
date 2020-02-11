#include<iostream>
#define max 50
using namespace std;

class stack
{
    int binary[max];
    int top;
public:
    stack()
    {
        top=-1;
    }
    int is_full();
    int is_emp();
    void push(int n);
    int pop();
};
int stack::is_full()
{
    if(top==max-1)
        return 1;
    else
        return 0;
}
int stack::is_emp()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void stack::push(int n)
{
    if(!is_full())
    {
        binary[++top]=n;
    }
    else
        cout<<"STACK OVERFLOW\n";
}
int stack::pop()
{
    if(!is_emp())
    {
        int num;
        num=binary[top];
        top--;
        return num;
    }
    else
        cout<<"EMPTY TACK\n";
}

int main()
{
    stack s;
    int n,r=0;
    cout<<"ENTER A NUMBER TO BE CONVERTED TO BINARY\n";
    cin>>n;

    while(n!=0)
    {
        r=n%2;
        s.push(r);
        n=n/2;

    }
    cout<<"EQUIVALENT BINARY NUMBER IS:";
    while(!(s.is_emp()))
    {
        cout<<s.pop();
    }
    cout<<"\n";
    return 0;
}


