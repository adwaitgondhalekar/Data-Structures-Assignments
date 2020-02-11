#include<iostream>
using namespace std;

class sparse
{
public:
    int row,colm,nval1,nval2;
    int spar1[100][3];
    int spar2[100][3];
    int sparres[100][3];
    int sparres1[100][3];
public:
    void getdata();
    void add(sparse s1);
    void simpletranspose(sparse s1);
};

void sparse::getdata()
{
    cout<<"PLEASE ENTER THE NUMBER OF ROWS AND COLUMN AND NONZERO VALUES IN THE MATRIX\n";
    cin>>row>>colm>>nval1;
    spar1[0][0]=row;
    spar1[0][1]=colm;
    spar1[0][2]=nval1;

    cout<<"ENTER THE DATA\n";

    for(int i=1; i<=nval1; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>spar1[i][j];
        }
    }

    cout<<"THE SPARSE MATRIX IS\n";

    for(int i=0; i<=nval1; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<spar1[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void sparse::add(sparse s1)
{

    cout<<"ENTER THE NUMBER OF NONZERO VALUES IN SECOND SPARSE MATRIX\n";
    cin>>nval2;
    cout<<"ENTER THE DATA\n";
    spar2[0][0]=row;
    spar2[0][1]=colm;
    spar2[0][2]=nval2;
    sparres[0][0]=row;
    sparres[0][1]=colm;

    for(int i=1; i<=nval2; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>spar2[i][j];
        }
    }
    cout<<"THE SPARSE MATRIX 2 IS\n";

    for(int i=0; i<=nval2; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<spar2[i][j]<<"\t";
        }
        cout<<"\n";
    }

    int i=1,j=1,k=1,ctr=0;

    while(i<=nval1 && j<=nval2)
    {
        if(s1.spar1[i][0]==spar2[j][0])
        {
            if(s1.spar1[i][1]==spar2[j][1])
            {
                sparres[k][0]=s1.spar1[i][0];
                sparres[k][1]=s1.spar1[i][1];
                sparres[k][2]=s1.spar1[i][2]+spar2[j][2];
                i++,j++,k++,ctr++;
            }
            else if(s1.spar1[i][1]<spar2[j][1])
            {
                sparres[k][0]=s1.spar1[i][0];
                sparres[k][1]=s1.spar1[i][1];
                sparres[k][2]=s1.spar1[i][2];
                i++,k++,ctr++;
            }
            else if(s1.spar1[i][1]>spar2[j][1])
            {
                sparres[k][0]=spar2[j][0];
                sparres[k][1]=spar2[j][1];
                sparres[k][2]=spar2[j][2];
                j++,k++,ctr++;
            }
        }
        else
        {
            if(s1.spar1[i][0]<spar2[j][0])
            {
                sparres[k][0]=s1.spar1[i][0];
                sparres[k][1]=s1.spar1[i][1];
                sparres[k][2]=s1.spar1[i][2];
                i++,k++,ctr++;
            }
            else if(s1.spar1[i][0]>spar2[j][0])
            {
                sparres[k][0]=spar2[j][0];
                sparres[k][1]=spar2[j][1];
                sparres[k][2]=spar2[j][2];
                j++,k++,ctr++;
            }
        }
    }
    while(i<=nval1)
    {
        sparres[k][0]=s1.spar1[i][0];
        sparres[k][1]=s1.spar1[i][1];
        sparres[k][2]=s1.spar1[i][2];
        i++,k++,ctr++;
    }
    while(j<=nval2)
    {
        sparres[k][0]=spar2[j][0];
        sparres[k][1]=spar2[j][1];
        sparres[k][2]=spar2[j][2];
        j++,k++,ctr++;
    }
    sparres[0][2]=ctr;

    cout<<"THE RESULTANT SPARSE MATRIX IS\n";

    for(int i=0; i<k; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<sparres[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void sparse::simpletranspose(sparse s1)
{


    sparres1[0][0]=colm;
    sparres1[0][1]=row;
    sparres1[0][2]=nval1;
    int chkr=-1,chkc=-1,j=1,ctr=1,pos=0;
    while(j<=nval1)
    {
        int min=99999,corr=0;

        for(int i=1; i<=nval1; i++)
        {

            if(s1.spar1[i][1]<min&&s1.spar1[i][1]!=-2)
            {
                min=s1.spar1[i][1];

                pos=i;

            }
        }
        sparres1[j][0]=s1.spar1[pos][1];
        sparres1[j][1]=s1.spar1[pos][0];
        sparres1[j][2]=s1.spar1[pos][2];
        j++;
        s1.spar1[pos][1]=-2;



    }

    for(int i=0; i<=nval1; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<sparres1[i][j]<<"\t";
        }
        cout<<"\n";
    }
}



int main()
{
    int ch,e=0;
    sparse s1;
    s1.getdata();

    while(e==0)
    {
        cout<<"MENU\n";
        cout<<"1.ADD TWO SPARSE MATRICES\n";
        cout<<"2.SIMPLE TRANSPOSE\n";
        cout<<"3.FAST TRANSPOSE\n";
        cout<<"4.EXIT\n";
        cin>>ch;

        switch(ch)
        {
        case 1:
            s1.add(s1);
            break;
        case 2:
            s1.simpletranspose(s1);
            break;

        // case 3:

        case 4:
            e=1;
        }
    }

    return 0;
}

