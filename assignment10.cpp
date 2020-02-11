#include"stack.cpp"
#include<string.h>
#include<math.h>
class expression
{
    //string output;

public:
    char  output[50];
    expression()
    {
        for(int i=0; i<50; i++)
            output[i]='\0';
    }
    int olen=49;
    void intopost(char exp[50]);
    void intopre(char exp[50]);
    string posttoin();
    string pretoin();
    int precedence(char ch);
    int calcval(int op1,int op2,char oper);
    void posteval();
    void preeval();
};
int expression::precedence(char ch)
{

    if(ch=='^')
        return 4;
    if(ch=='*'||ch=='/')
        return 3;
    if(ch=='+'||ch=='-')
        return 2;
    if(ch=='(')
        return 1;
    else
        return -1;



}
string expression::posttoin()
{
    char exp[50];
    cout<<"ENTER THE EXPRESSION\n";
    cin>>exp;

    int i=0;
    stack<string>s1;
    while(exp[i])
    {
        if(exp[i]>=97&&exp[i]<=122)
        {
            string operand;
            operand=exp[i];
            s1.push(operand);
        }
        if(exp[i]=='^'||exp[i]=='/'||exp[i]=='*'||exp[i]=='-'||exp[i]=='+'||exp[i]=='-')
        {
            string operand2,operand1,operat,tempexp;

            operand2=s1.pop();
            operand1=s1.pop();
            operat=exp[i];
            //if(exp[i]=='/'||exp[i]=='*'||exp[i]=='^')
            tempexp="("+operand1+operat+operand2+")";


            s1.push(tempexp);

        }
        i++;
    }

    return s1.pop();

}
string expression::pretoin()
{
    char exp[50];
    cout<<"ENTER THE EXPRESSION\n";
    cin>>exp;
    int len=strlen(exp);
    int i=0;
    stack<string>s1;
    while(len!=-1)
    {
        if(exp[len]>=97&&exp[len]<=122)
        {
            string operand;
            operand=exp[len];
            s1.push(operand);
        }
        if(exp[len]=='^'||exp[len]=='/'||exp[len]=='*'||exp[len]=='-'||exp[len]=='+'||exp[len]=='-')
        {
            string operand2,operand1,operat,tempexp;

            operand1=s1.pop();
            operand2=s1.pop();
            operat=exp[len];
            //if(exp[i]=='/'||exp[i]=='*'||exp[i]=='^')
            tempexp="("+operand1+operat+operand2+")";


            s1.push(tempexp);

        }
        len--;
    }

    return s1.pop();

}

void expression::intopre(char exp[50])
{

    int length=strlen(exp);
    length--;
    stack<char>s1;
    while(length!=-1)
    {
        if(exp[length]=='^'||exp[length]=='*'||exp[length]=='/'||exp[length]=='+'||exp[length]=='-')
        {
            if((precedence(exp[length]))>=(precedence(s1.s[s1.top])))
            {
                s1.push(exp[length]);
            }
            else if((precedence(exp[length]))<(precedence(s1.s[s1.top])))
            {
                while((precedence(exp[length]))<(precedence(s1.s[s1.top]))&&s1.s[s1.top]!=')'&&!(s1.is_emp()))
                {
                    output[olen]=s1.pop();
                    olen--;
                }
                s1.push(exp[length]);
            }
        }
        else if(exp[length]==')')
        {
            s1.push(exp[length]);
        }
        else if(exp[length]=='(')
        {
            while(s1.s[s1.top]!=')')
            {
                output[olen]=s1.pop();
                olen--;
            }
            s1.top--;

        }
        else
        {
            output[olen]=exp[length];
            olen--;
        }
        length--;
    }
    while(!(s1.is_emp()))
    {
        output[olen]=s1.pop();
        olen--;
    }

}

void expression::intopost(char exp[50])
{

    int i=0,j=0;
    stack<char>s1;
    while(exp[i])
    {
        if(exp[i]=='^'||exp[i]=='*'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-')
        {
            if((precedence(exp[i]))>(precedence(s1.s[s1.top])))
            {
                s1.push(exp[i]);

            }
            else if((precedence(exp[i]))<=(precedence(s1.s[s1.top])))
            {
                while((precedence(exp[i]))<=(precedence(s1.s[s1.top]))&&s1.s[s1.top]!='('&&!(s1.is_emp()))
                {
                    output[j]=s1.pop();
                    j++;
                }
                s1.push(exp[i]);
            }
        }
        else if(exp[i]=='(')
        {
            s1.push(exp[i]);
        }
        else if(exp[i]==')')
        {
            while(s1.s[s1.top]!='(')
            {
                output[j]=s1.pop();
                j++;
            }
            s1.top--;
        }
        else
        {
            output[j]=exp[i];
            j++;
        }
        i++;
    }

    while(!(s1.is_emp()))
    {
        output[j]=s1.pop();
        j++;
    }

}
int expression::calcval(int op1,int op2,char oper)
{
    switch(oper)
    {
        case '^': return pow(op1,op2);
        case '/': return op1/op2;
        case '*': return op1*op2;
        case '+': return op1+op2;
        case '-': return op1-op2;
    }
}
void expression::posteval()
{
   char exp[50];
   cout<<"ENTER THE POSTFIX EXPRESSION\n";
   cin>>exp;
   stack<int>s;
   int i=0;

   while(exp[i])
   {
       int val=0;
       if(exp[i]>=97&&exp[i]<=122)
       {
           cout<<"enter the value of:"<<exp[i]<<endl;
           cin>>val;
           s.push(val);
       }
       if(exp[i]=='^'||exp[i]=='/'||exp[i]=='*'||exp[i]=='+'||exp[i]=='-')
       {
           int op2=s.pop();
           int op1=s.pop();
           int result=calcval(op1,op2,exp[i]);
           s.push(result);
       }
       i++;
   }
   cout<<"VALUE OF EXPRESSION IS:"<<s.pop()<<endl;
}
void expression::preeval()
{
    char exp[50];
    cout<<"ENTER THE PREFIX EXPRESSION\n";
    cin>>exp;
    //stack<int>s;
    int length=strlen(exp);
    length--;
    stack<int>t;
    while(length!=-1)
    {
        int val=0;
        if(exp[length]>=97&&exp[length]<=122)
        {
            cout<<"ENTER THE VALUE OF:"<<exp[length]<<endl;
            cin>>val;
            t.push(val);
        }
        if(exp[length]=='^'||exp[length]=='/'||exp[length]=='*'||exp[length]=='+'||exp[length]=='-')
        {
            int op1=t.pop();
            int op2=t.pop();
            int result=calcval(op1,op2,exp[length]);
            t.push(result);
        }
        length--;
    }
    cout<<"THE VALUE OF THE EXPRESSION IS:"<<t.pop()<<endl;
}
int main()
{
    expression e;
    char exp[50];
    int ch=0,g=0;
    while(g==0)
    {


        cout<<"1.INFIX TO POSTFIX\n";
        cout<<"2.INFIX TO PREFIX\n";
        cout<<"3.POSTFIX TO INFIX\n";
        cout<<"4.PREFIX TO INFIX\n";
        cout<<"5.POSTFIX TO PREFIX\n";
        cout<<"6.PREFIX TO POSTFIX\n";
        cout<<"7.EVALUATE POSTFIX EXPRESSION\n";
        cout<<"8.EVALUATE PREFIX EXPRESSION\n";
        cout<<"9.EXIT\n";
        cout<<"PLEASE ENTER YOUR CHOICE\n";
        cin>>ch;

        switch(ch)
        {
        case 1:

            //char exp[50];

            cout<<"ENTER THE EXPRESSION\n";
            cin>>exp;

            e.intopost(exp);
            cout<<"POSTFIX EXPRESSION IS\n";
            for(int k=0; k<50; k++)
            {
                cout<<e.output[k];
            }
            cout<<"\n";
            break;

        case 2:
            //char exp[50];

            cout<<"ENTER THE EXPRESSION\n";
            cin>>exp;

            e.intopre(exp);
            cout<<"PREFIX EXPRESSION IS\n";
            for(int k=e.olen; k<50; k++)
            {
                cout<<e.output[k];
            }
            cout<<"\n";
            break;


        case 3:
        {


            string in=e.posttoin();
            cout<<"INFIX EXPRESSION IS\n";
            cout<<in<<endl;

            break;
        }

        case 4:
        {


            string in=e.pretoin();
            cout<<"INFIX EXPRESSION IS\n";
            cout<<in<<endl;

            break;
        }

        case 5:
        {


            string infix=e.posttoin();
            char in[50];
            //string infix=s1.pop();
            infix.copy(in,infix.length(),0);
            e.intopre(in);
            cout<<"PREFIX EXPRESSION IS\n";
            for(int k=e.olen; k<50; k++)
            {
                cout<<e.output[k];
            }
            cout<<"\n";
            break;
        }
        case 6:
        {


            string infix=e.pretoin();
            char in[50];
            //string infix=s1.pop();
            infix.copy(in,infix.length(),0);
            e.intopost(in);
            cout<<"POSTFIX EXPRESSION IS\n";
            for(int k=0; k<50; k++)
            {
                cout<<e.output[k];
            }
            cout<<"\n";
            break;
        }
        case 7:
                e.posteval();
                break;
        case 8:
               e.preeval();
               break;

        case 9:
            g=1;

        }
    }


}
