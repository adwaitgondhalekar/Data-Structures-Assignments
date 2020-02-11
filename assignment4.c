#include<stdio.h>

char str1[100],str2[100],str3[100];
int len,len2;
void leng();
void copy();
void concat();
void substr();
void revs();

void main()
{
    int ch,e=0;
    printf("PLEASE ENTER A STRING\n");
    scanf("%s",str1);
    while(e==0)
    {
        printf("MENU\n");
        printf("1.FIND THE LENGTH OF THE STRING\n");
        printf("2.COPY THE STRING TO OTHER\n");
        printf("3.CONCATENATE THE STRING\n");
        printf("4.FIND SUBSTRING\n");
        printf("5.REVERSE THE STRING\n");
        printf("6.EXIT\n");
        printf("PLEASE ENTER YOUR CHOICE\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            leng();
            break;
        case 2:
            copy();
            break;
        case 3:
            concat();
            break;
        case 4:
            substr();
            break;
        case 5:
            revs();
            break;

        case 6:
            e=1;
        }
    }
}

void leng()
{
    for(int i=0; str1[i]!='\0'; i++)
    {
        len++;
    }
    printf("THE LENGTH OF THE ENTERED STRING IS-%d \n",len);
}

void copy()
{
    char temp[100];
    int i=0;
    for(i=0; str1[i]!='\0'; i++)
    {
        temp[i]=str1[i];
    }
    temp[i]='\0';
    printf("THE COPIED STRING IS-%s\n",temp);
}

void concat()
{
    len=0;
    for(int i=0; str1[i]!='\0'; i++)
    {
        len++;
    }
    printf("ENTER THE SECOND STRING TO CONCATENATE WITH THE FIRST\n");
    scanf("%s",str2);

    for(int i=0; str2[i]!='\0'; i++)
    {
        str1[len]=str2[i];
        len++;
    }
    printf("THE STRING AFTER CONCATENATION IS-%s\n",str1);
}

void substr()
{
    int p1,p2;
    char temp[100];
    printf("ENTER THE INTIAL AND FINAL POSITIONS FOR SUBSTRING\n");
    scanf("%d %d",&p1,&p2);
    int k=0;
    for(int i=p1; i<=p2; i++)
    {
        temp[k]=str1[i];
        k++;
    }
    temp[k]='\0';
    printf("THE OBTAINED SUBSTRING IS-%s\n",temp);
}
void revs()
{
    char temp[100];
    len=0;
    for(int i=0; str1[i]!='\0'; i++)
    {
        len++;
    }
    int k=len-1;
    for(int i=0; str1[i]!='\0'; i++)
    {
        temp[k]=str1[i];
        k--;

    }
    temp[k]='\0';
    printf("REVERSE OF THE STRING IS-%s\n",temp);
}

