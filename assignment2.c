#include<stdio.h>
int r1,c1,r2,c2,a[10][10],b[10][10],c[10][10];
void upper();
void transpose();
void add();
void sub();
void mul();

void main()
{
    int e=0;

    printf("ENTER THE ROWS AND COLUMN OF FIRST MATRIX\n");
    scanf("%d %d",&r1,&c1);
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            printf("ENTER THE ELEMENT A%d%d\n",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    while(e==0)
    {

        int ch;
        printf("MENU\n");
        printf("1.FIND WHETHER MATRIX IS UPPER TRIANGULAR OR NOT\n");
        printf("2.FIND THE TRANSPOSE OF THE MATRIX\n");
        printf("3.ADDITION OF TWO MATRICES\n");
        printf("4.SUBTRACTION OF TWO MATRICES\n");
        printf("5.MULTIPLICATION OF TWO MATRICES\n");
        printf("6.EXIT\n");
        scanf("%d",&ch);

        if(ch>2 && ch!=6)
        {
            printf("ENTER THE ROWS AND COLUMN OF SECOND MATRIX\n");
            scanf("%d %d",&r2,&c2);
            for(int i=0; i<r2; i++)
            {
                for(int j=0; j<c2; j++)
                {
                    printf("ENTER THE ELEMENT B%d%d\n",i+1,j+1);
                    scanf("%d",&b[i][j]);
                }
            }
        }

        switch(ch)
        {
        case 1:
            upper();
            break;
        case 2:
            transpose();
            break;
        case 3:
            add();
            break;
        case 4:
            sub();
            break;
        case 5:
            mul();
            break;
        case 6:
            e=1;
            break;
        }
    }
}

void upper()
{
    int flag=1;
    for(int i=1; i<r1; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[i][j]!=0)
                flag=0;
            break;
        }
    }


    if(flag==0)
        printf("THE GIVEN MATRIX IS NOT UPPER TRIANGULAR\n");
    else
        printf("THE GIVEN MATRIX IS UPPER TRIANGULAR\n");
}

void transpose()
{
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            printf("%d\t",a[j][i]);
        }
        printf("\n");
    }
}

void add()
{
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }

    printf("THE RESULTANT MATRIX AFTER ADDITION IS\n");
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}

void sub()
{
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    }

    printf("THE RESULTANT MATRIX AFTER SUBTRACTION IS\n");
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}

void mul()
{
    int sum=0;
    for(int k=0; k<r1; k++)
    {
        for(int i=0; i<c2; i++)
        {
            for(int j=0; j<r2; j++)
            {
                sum=sum+a[k][j]*b[j][i];
            }
            c[k][i]=sum;
            sum=0;
        }
    }
    printf("THE RESULTANT MATRIX AFTER MULTIPLICATION IS\n");
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c2; j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}




