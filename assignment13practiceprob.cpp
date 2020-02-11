#include<iostream>
#define max 10
using namespace std;

int main()
{
    int num[max];
    for(int i=0;i<max;i++)
    {
        cout<<"ENTER A NUMBER:";
        cin>>num[i];
    }

    int ffibo=0,sfibo=1;
    int sumfibo=ffibo+sfibo;

    while(sumfibo<max)
    {
        ffibo=sfibo;
        sfibo=sumfibo;
        sumfibo=ffibo+sfibo;
    }
    int offset=-1;

    while(sumfibo>1)
    {
        int i=min(offset+sfibo,max-1);
    }
}

