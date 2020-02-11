#include<iostream>
#include<stdlib.h>
#define max 50
using namespace std;

class stack
{
    char s[max];
    int top;
public:
    stack()
    {
        top=-1;
    }
    void push(char ch);
    char pop();
    int is_full();
    int is_emp();
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
void stack::push(char ch)
{
    if(!is_full())
    {
        s[++top]=ch;
    }
    else
        cout<<"STACK OVERFLOW\n";

}
char stack::pop()
{
    if(!is_emp())
    {
        char ch;
        ch=s[top];
        top--;
        return ch;
    }
    else
        cout<<"EMPTY STACK\n";
}

int main()
{
    stack s;
    char stream[max];
    cout<<"ENTER A STRING OF BRACKETS\n";
    cin>>stream;
    int i=0;
    while(stream[i])
    {
        if(stream[i]=='('||stream[i]=='{'||stream[i]=='[')
        {
            s.push(stream[i]);
        }
        else
        {
            char topchar;
            if(!s.is_emp())
            {
                topchar=s.pop();
            }
            else
            {
                cout<<"NOT WELL FORMED\n";
                exit(1);
            }
            switch(topchar)
            {
            case '(':
                if(stream[i]!=')')
                {
                    cout<<"NOT WELL FORMED\n";
                    exit(1);
                }
                break;
            case '{':
                if(stream[i]!='}')
                {
                    cout<<"NOT WELL FORMED\n";
                    exit(1);
                }
                break;
            case '[':
                if(stream[i]!=']')
                {
                    cout<<"NOT WELL FORMED\n";
                    exit(1);
                }
                break;
            }
        }
        i++;
    }

    if(s.is_emp())
        cout<<"WELL FORMED\n";
    else
        cout<<"NOT WELL FORMED\n";



}




