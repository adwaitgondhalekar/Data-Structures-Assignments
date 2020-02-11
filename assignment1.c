#include<stdio.h>

void main()
{

    int n,ch,ctr=0,sum=0,max=0,ctr2=0,min,p,max1=0,ctr3=0,e=0;
    double avg;
    printf("ENTER THE NUMBER OF STUDENTS IN CLASS\n");
    scanf("%d",&n);
    int marks[n];

    for(int i=0; i<n; i++)
    {
        printf("ENTER THE MARKS OBTAINED BY STUDENT %d \n",i+1);
        scanf("%d",&marks[i]);
        if(marks[i]>=0)
        {
            ctr++;
            sum=sum+marks[i];
        }
    }


    while(e==0)
    {
        printf("MENU\n");
        printf("1.AVERAGE MARKS OBTAINED BY THE CLASS\n");
        printf("2.MAXIMUM MARKS OBTAINED IN THE CLASS\n");
        printf("3.MINIMUM MARKS OBTAINED IN THE CLASS\n");
        printf("4.LIST OF STUDENTS ABSENT FOR THE TEST\n");
        printf("5.MODE MARKS OF THE CLASS\n");
        printf("6.EXIT\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            if(sum!=0)
            {
                avg=(double)sum/ctr;
                printf("THE AVERAGE MARKS OBTAINED ARE- %lf\n",avg);
            }
            else
                printf("THE AVERAGE MARKS OBTAINED ARE- 0\n");

            break;

        case 2:
            for(int i=0; i<n; i++)
            {
                if(marks[i]>max)
                    max=marks[i];
            }
            printf("THE MAXIMUM MARKS OBTAINED ARE- %d\n",max);
            break;
        case 3:

            for(int i=0; i<n; i++)
            {
                if(marks[i]!=-1 && ctr2!=1)
                {
                    min=marks[i];
                    ctr2++;
                }
            }
            for(int i=0; i<n; i++)
            {
                if(marks[i]<min && marks[i]!=-1)
                    min=marks[i];
            }
            printf("THE MINIMUM MARKS OBTAINED ARE- %d\n",min);
            break;
        case 4:
            printf("STUDENTS ABSENT FOR THE TEST ARE ROLL NO-\n");
            for(int i=0; i<n; i++)
            {
                if(marks[i]==-1)
                    printf("\t%d\n",i+1);
            }
            break;
        case 5:
            for(int i=0; i<n; i++)
            {
                ctr3=0;
                for(int j=0; j<n; j++)
                {
                    if(marks[i]==marks[j] && marks[i]!=-1)
                        ctr3++;
                }
                if(ctr3>max1)
                {
                    max1=ctr3;
                    p=i;
                }
            }
            if(max1>1)
                printf("THE MARKS %d WERE OBTAINED BY %d STUDENTS\n",marks[p],max1);
            else
                printf("EVERY STUDENT SCORED DIFFERENT MARKS\n");
            break;
        case 6:
            e=1;
        }
    }
}







