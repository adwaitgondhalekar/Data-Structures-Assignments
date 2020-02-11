#include<iostream>
#include<string.h>
#define max 50
using namespace std;

class stack
{
    char str[max];
    int top;
public:
    char str1[max];
    stack()
    {
        top=-1;
    }
    int is_emp();
    int is_full();
    void push(char ch);
    char pop();
    void palindrome();
};
int stack::is_emp()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int stack::is_full()
{
    if(top==max-1)
        return 1;
    else
        return 0;
}

char stack::pop()
{
    if(!is_emp())
    {
        char ch;
        ch=str[top];
        top--;
        return ch;
    }
    else
        cout<<"EMPTY STACK\n";
}
void stack::push(char ch)
{
    if(!is_full())
    {
        str[++top]=ch;
    }
    else
        cout<<"STACK OVERFLOW\n";
}
void stack::palindrome()
{
    char rev[max];
    char str2[max];
    //strcpy(rev," ");
    int k=0,i=0,j=0;
    while(!is_emp())
    {
        rev[k]=pop();
        k++;
    }
    rev[k]='\0';

    while(str1[i])
    {
        if(str1[i]>=65&&str1[i]<=90||str1[i]>=97&&str1[i]<=122)
        {
            str2[j]=str1[i];
            j++;
        }
        i++;
    }


    str2[j]='\0';
    cout<<rev<<endl;
    cout<<str2<<endl;
    if(strcmp(rev,str2)==0)
        cout<<"PALINDROME\n";
    else
        cout<<"NOT PALINDROME\n";


}

int main()
{
    //char str1[max];
    //char rev[max];
    stack s1;
    int ch,e=0;
    while(e==0)
    {
        cout<<"1.CHECHK IF THE WORD IS PALINDROME\n";
        cout<<"2.CHECK IF THE SENTENCE IS PALINDROME\n";
        cout<<"3.PRINT REVERSE OF A STRING\n";
        cout<<"4.EXIT\n";
        cout<<"ENTER YOUR CHOICE\n";
        cin>>ch;


        switch(ch)
        {
        case 1:
        {
            cout<<"ENTER A STRING\n";
            cin>>s1.str1;
            int i=0;
            while(s1.str1[i])
            {
                s1.push(s1.str1[i]);
                i++;
            }
            s1.palindrome();
            break;
        }


        case 2:
        {

            cout<<"ENTER A SENTENCE\n";
            cin.ignore();
            cin.getline(s1.str1,max);

            int i=0;
            while(s1.str1[i])
            {
                if(s1.str1[i]>=97&&s1.str1[i]<=122)
                    s1.push(s1.str1[i]);
                else if(s1.str1[i]>=65&&s1.str1[i]<=90)
                    s1.push(s1.str1[i]+32);

                i++;
            }
            s1.palindrome();
            break;
        }

        case 3:
        {
            cout<<"ENTER STRING\n";
            cin>>s1.str1;
            int i=0;
            while(s1.str1[i])
            {
                s1.push(s1.str1[i]);
                i++;
            }
            cout<<"REVERSED STRING IS\n";
            while(!(s1.is_emp()))
                cout<<s1.pop();
            cout<<"\n";
            break;
        }
        case 4:
            e=1;
            break;



        }
    }

}
