#include<stdio.h>
#include<math.h>


struct poly
{
    int coeff,power;
};
void evaluate(struct poly p1[],int n1);
void addition(struct poly p1[],struct poly p2[],struct poly radd[],int n1,int n2);
void subtract(struct poly p1[],struct poly p2[],struct poly rsub[],int n1,int n2);
void multiply(struct poly p1[],struct poly p2[],struct poly rmul[],struct poly rmulf[],int n1,int n2);
void main()
{
    int ch,e=0,n1,n2;
    printf("ENTER THE NUMBER OF TERMS IN THE FIRST POLYNOMIAL\n");
    scanf("%d",&n1);
    struct poly p1[n1];
    for(int i=0; i<n1; i++)
    {
        printf("ENTER THE COEFFICIENT OF TERM%d IN POLYNOMIAL 1\n",i+1);
        scanf("%d",&p1[i].coeff);

        printf("ENTER THE POWER OF 'x' IN TERM%d OF POLYNOMIAL 1\n",i+1);
        scanf("%d",&p1[i].power);
    }
    while(e==0)
    {
        printf("MENU\n");
        printf("1.EVALUATE THE VALUE OF POLYNOMIAL\n");
        printf("2.ADD TWO POLYNOMIALS\n");
        printf("3.SUBTRACT TWO POLYNMIALS\n");
        printf("4.MULTIPLY TWO POLYNOMIALS\n");
        printf("5.EXIT\n");
        printf("PLEASE ENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        struct poly p2[100];

        if(ch==2||ch==3||ch==4)
        {
            printf("ENTER THE NUMBER OF TERMS IN THE SECOND POLYNOMIAL\n");
            scanf("%d",&n2);

            for(int i=0; i<n2; i++)
            {
                printf("ENTER THE COEFFICIENT OF TERM%d IN POLYNOMIAL 2\n",i+1);
                scanf("%d",&p2[i].coeff);

                printf("ENTER THE POWER OF 'x' IN TERM%d OF POLYNOMIAL 2\n",i+1);
                scanf("%d",&p2[i].power);
            }

            printf("THE POLYNOMIAL 1 ENTERED IS\n");
            for(int i=0; i<n1; i++)
            {

                if(p1[i].power!=0&&p1[i].power!=1)
                {
                    printf("%dx^%d",p1[i].coeff,p1[i].power);
                    if(i!=n1-1)
                        printf("+");
                }
                else
                {
                    if(p1[i].power==1)
                        printf("%dx",p1[i].coeff);
                    else
                        printf("%d",p1[i].coeff);
                    if(i!=n1-1)
                        printf("+");
                }

            }
            printf("\n");

            printf("THE POLYNOMIAL 2 ENTERED IS\n");
            for(int i=0; i<n2; i++)
            {

                if(p2[i].power!=0&&p2[i].power!=1)
                {
                    printf("%dx^%d",p2[i].coeff,p2[i].power);
                    if(i!=n1-1)
                        printf("+");
                }
                else
                {
                    if(p2[i].power==1)
                        printf("%dx",p2[i].coeff);
                    else
                        printf("%d",p2[i].coeff);
                    if(i!=n1-1)
                        printf("+");

                }
            }
            printf("\n");
        }
        struct poly radd[n1+n2],rsub[n1+n2],rmul[n1*n2],rmulf[n1*n2];

        switch(ch)
        {
        case 1:
            evaluate(p1,n1);
            break;
        case 2:
            addition(p1,p2,radd,n1,n2);
            break;
        case 3:
            subtract(p1,p2,rsub,n1,n2);
            break;
        case 4:
            multiply(p1,p2,rmul,rmulf,n1,n2);
            break;
        case 5:
            e=1;
        }
    }
}

void evaluate(struct poly p1[],int n1)
{
    printf("THE POLYNOMIAL 1 ENTERED IS\n");
    for(int i=0; i<n1; i++)
    {

        if(p1[i].power!=0&&p1[i].power!=1)
        {
            printf("%dx^%d",p1[i].coeff,p1[i].power);
            if(i!=n1-1)
                printf("+");
        }
        else
        {
            if(p1[i].power==1)
                printf("%dx",p1[i].coeff);
            else
                printf("%d",p1[i].coeff);
            if(i!=n1-1)
                printf("+");
        }

    }
    printf("\n");


    float x=0,val=0;
    printf("ENTER THE VALUE OF X TO EVALUATE THE POLYNOMIAL\n");
    scanf("%f",&x);
    for(int i=0; i<n1; i++)
    {
        val+=p1[i].coeff*(pow(x,p1[i].power));
    }
    printf("THE VALUE OF THE POLYNOMIAL IS-%f\n",val);

}
void addition(struct poly p1[],struct poly p2[],struct poly radd[],int n1,int n2)
{
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n1-1; j++)
        {
            int temp=0,temp2=0;
            if(p1[j].power<p1[j+1].power)
            {
                temp=p1[j].power;
                p1[j].power=p1[j+1].power;
                p1[j+1].power=temp;
                temp2=p1[j].coeff;
                p1[j].coeff=p1[j+1].coeff;
                p1[j+1].coeff=temp2;
            }
        }
    }
    for(int i=0; i<n2; i++)
    {
        for(int j=0; j<n2-1; j++)
        {
            int temp=0,temp2=0;
            if(p2[j].power<p2[j+1].power)
            {
                temp=p2[j].power;
                p2[j].power=p2[j+1].power;
                p2[j+1].power=temp;
                temp2=p2[j].coeff;
                p2[j].coeff=p2[j+1].coeff;
                p2[j+1].coeff=temp2;
            }
        }
    }
    printf("THE ARRANGED POLYNOMIAL 1 IS\n");
    for(int i=0; i<n1; i++)
    {

        if(p1[i].power!=0&&p1[i].power!=1)
        {
            printf("%dx^%d",p1[i].coeff,p1[i].power);
            if(i!=n1-1)
                printf("+");
        }
        else
        {
            if(p1[i].power==1)
                printf("%dx",p1[i].coeff);
            else
                printf("%d",p1[i].coeff);
            if(i!=n1-1)
                printf("+");
        }

    }
    printf("\n");

    printf("THE ARRANGED POLYNOMIAL 2 IS\n");
    for(int i=0; i<n2; i++)
    {

        if(p2[i].power!=0&&p2[i].power!=1)
        {
            printf("%dx^%d",p2[i].coeff,p2[i].power);
            if(i!=n2-1)
                printf("+");
        }
        else
        {
            if(p2[i].power==1)
                printf("%dx",p2[i].coeff);
            else
                printf("%d",p2[i].coeff);
            if(i!=n2-1)
                printf("+");
        }
    }
    printf("\n");
    int size=0,k=0,j=0,i=0;
    while(i<n1&&j<n2)
    {

        if(p1[i].power==p2[j].power)
        {
            radd[k].coeff=p1[i].coeff+p2[j].coeff;
            radd[k].power=p1[i].power;
            i++,k++,j++;
        }
        else if(p1[i].power>p2[j].power)
        {
            radd[k].coeff=p1[i].coeff;
            radd[k].power=p1[i].power;
            i++,k++;
        }
        else if(p1[i].power<p2[j].power)
        {
            radd[k].coeff=p2[j].coeff;
            radd[k].power=p2[j].power;
            j++,k++,i--;
        }
        //size=k;
    }
    while(i<n1)
    {
        radd[k].coeff=p1[i].coeff;
        radd[k].power=p1[i].power;
        i++,k++;
    }
    while(j<n2)
    {
        radd[k].coeff=p2[j].coeff;
        radd[k].power=p2[j].power;
        j++,k++;
    }
    size=k;

    printf("THE RESULTANT POLYNOMIAL IS\n");
    for(int i=0; i<size; i++)
    {

        if(radd[i].power!=0&&radd[i].power!=1)
        {
            printf("%dx^%d",radd[i].coeff,radd[i].power);
            if(i!=size-1)
                printf("+");
        }
        else
        {
            if(radd[i].power==1)
                printf("%dx",radd[i].coeff);
            else
                printf("%d",radd[i].coeff);
            if(i!=size-1)
                printf("+");
        }

    }
    printf("\n");
}

void subtract(struct poly p1[],struct poly p2[],struct poly rsub[],int n1,int n2)
{
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n1-1; j++)
        {
            int temp=0,temp2=0;
            if(p1[j].power<p1[j+1].power)
            {
                temp=p1[j].power;
                p1[j].power=p1[j+1].power;
                p1[j+1].power=temp;
                temp2=p1[j].coeff;
                p1[j].coeff=p1[j+1].coeff;
                p1[j+1].coeff=temp2;
            }
        }
    }
    for(int i=0; i<n2; i++)
    {
        for(int j=0; j<n2-1; j++)
        {
            int temp=0,temp2=0;
            if(p2[j].power<p2[j+1].power)
            {
                temp=p2[j].power;
                p2[j].power=p2[j+1].power;
                p2[j+1].power=temp;
                temp2=p2[j].coeff;
                p2[j].coeff=p2[j+1].coeff;
                p2[j+1].coeff=temp2;
            }
        }
    }
    printf("THE ARRANGED POLYNOMIAL 1 IS\n");
    for(int i=0; i<n1; i++)
    {

        if(p1[i].power!=0&&p1[i].power!=1)
        {
            printf("%dx^%d",p1[i].coeff,p1[i].power);
            if(i!=n1-1)
                printf("+");
        }
        else
        {
            if(p1[i].power==1)
                printf("%dx",p1[i].coeff);
            else
                printf("%d",p1[i].coeff);
            if(i!=n1-1)
                printf("+");
        }

    }
    printf("\n");

    printf("THE ARRANGED POLYNOMIAL 2 IS\n");
    for(int i=0; i<n2; i++)
    {

        if(p2[i].power!=0&&p2[i].power!=1)
        {
            printf("%dx^%d",p2[i].coeff,p2[i].power);
            if(i!=n2-1)
                printf("+");
        }
        else
        {
            if(p2[i].power==1)
                printf("%dx",p2[i].coeff);
            else
                printf("%d",p2[i].coeff);
            if(i!=n2-1)
                printf("+");
        }
    }
    printf("\n");
    int size=0;
    for(int i=0,j=0,k=0; i<n1; i++)
    {

        if(p1[i].power==p2[j].power)
        {
            rsub[k].coeff=p1[i].coeff-p2[j].coeff;
            rsub[k].power=p1[i].power;
            k++,j++;
        }
        else if(p1[i].power>p2[j].power)
        {
            rsub[k].coeff=p1[i].coeff;
            rsub[k].power=p1[i].power;
            k++;
        }
        else if(p1[i].power<p2[j].power)
        {
            rsub[k].coeff=p2[j].coeff*(-1);
            rsub[k].power=p2[j].power;
            j++,k++,i--;
        }
        size=k;
    }
    printf("THE RESULTANT POLYNOMIAL IS\n");
    for(int i=0; i<size; i++)
    {

        if(rsub[i].power!=0&&rsub[i].power!=1)
        {
            printf("%dx^%d",rsub[i].coeff,rsub[i].power);
            if(i!=size-1)
                printf("+");
        }
        else
        {
            if(rsub[i].power==1)
                printf("%dx",rsub[i].coeff);
            else
                printf("%d",rsub[i].coeff);
            if(i!=size-1)
                printf("+");
        }

    }
    printf("\n");
}

void multiply(struct poly p1[],struct poly p2[],struct poly rmul[],struct poly rmulf[],int n1,int n2)
{

    int k=0;
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            rmul[k].coeff=p1[i].coeff*p2[j].coeff;
            rmul[k].power=p1[i].power+p2[j].power;
            k++;
        }
    }

    int ctr=0;
    for(int i=0; i<n1*n2; i++)
    {
        for(int j=0; j<n1*n2-1; j++)
        {
            int temp=0,temp2=0;
            if(rmul[j].power<rmul[j+1].power)
            {
                temp=rmul[j].power;
                rmul[j].power=rmul[j+1].power;
                rmul[j+1].power=temp;
                temp2=rmul[j].coeff;
                rmul[j].coeff=rmul[j+1].coeff;
                rmul[j+1].coeff=temp2;
            }
        }
    }
    printf("THE RESULTANT POLYNOMIAL IS\n");
    for(int i=0; i<n1*n2; i++)
    {

        if(rmul[i].power!=0&&rmul[i].power!=1)
        {
            printf("%dx^%d",rmul[i].coeff,rmul[i].power);
            if(i!=n1*n2-1)
                printf("+");
        }
        else
        {
            if(rmul[i].power==1)
                printf("%dx",rmul[i].coeff);
            else
                printf("%d",rmul[i].coeff);
            if(i!=n1*n2-1)
                printf("+");
        }

    }
    printf("\n");

}










