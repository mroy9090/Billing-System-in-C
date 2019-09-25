#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include <time.h>

struct node
{
    char id[15];
    char name[100];
    char price[10];
    struct node *next;
    struct node *prev;
}*head,*item,*temp,*tail,*p,*q,*s;

char idd = 0;

void addItem()
{

    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t   Add Products\n\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");


    char name[100],id[15], price[10];

    printf("\n\t\t\t\tEnter Product Id: ");
    scanf("%s",id);

    printf("\n\t\t\t\tEnter Product name: ");
    scanf("%s",name);


    printf("\n\t\t\t\tEnter Product Price: ");
    scanf("%s",price);



    FILE *fp;
    fp=fopen("product.txt","a+");

    fprintf(fp,"%s ",id);
    fprintf(fp,"%s ",name);
    fprintf(fp,"%s \n",price);

    fclose(fp);
    system("cls");

     printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tItem Added successfully\n");
     printf("----------------------------------------------------------------------------------------------------------------------\n");

    char another, choice;

    printf("\t\t\t\tpress  1 to go main menu & 2 to go exit.");
    choice  = getche();
    switch(choice)
    {
    case '1':
        system("cls");
        another = 'y';
        while(another == 'y')
        {
            main();

            another = getche();
        }
        break;
    case '2':
        system("cls");
        another = 'y';
        while(another == 'y')
        {
            exit(0);
            another = getche();
        }
        break;
    }


}




void input()
{

    head=(struct node *)malloc(sizeof(struct node));
    tail = head;
    FILE *fp;
    fp=fopen("product.txt","r");
    int node_no = 1;
    while(1)
    {
        if( feof(fp) )
        {
            break ;
        }
        item=(struct node *)malloc(sizeof(struct node));

       fscanf(fp,"%s",&item->id);
       fscanf(fp,"%s",&item->name);
       fscanf(fp,"%s",&item->price);

        item->next=NULL;
        item->prev=tail;
        tail->next=item;
        tail=item;
        if(node_no ==1)
        {
           head=item;
        }


        node_no++;
    }
    if(tail==head)
    {
        tail=NULL;
    }
    else
    {
        tail=tail->prev;
        tail->next=NULL;
    }
    fclose(fp);



}




void all_Item()
{

    input();
    q=head;

    FILE *fp;
    fp=fopen("product.txt","r");
    printf("\t\tProduct Id\t\t\tProduct Name\t\t    Product Price\n");
    while(head!=NULL)
    {

        printf("\n\t\t ");
        printf("%s",head->id);
        printf("\t\t-");
        printf("\t\t");
        printf("%s",head->name);
        printf("\t\t-");
        printf("\t\t");
        printf("%s",head->price);

        /* printf("\n\n")*/;

        head=head->next;


    }
    printf("\n");


}

void inttostring(char str[], int total)
{

    int i, rem, len = 0, n;



    n = total;

    while (n != 0)

    {

        len++;

        n /= 10;

    }

    for (i = 0; i < len; i++)

    {

        rem = total % 10;

        total = total / 10;

        str[len - (i + 1)] = rem + '0';

    }

    str[len] = '\0';

}



int toString(char a[])
{
    int c, sign, offset, n;

    if (a[0] == '-')    /* Handle negative integers*/
    {
        sign = -1;
    }

    if (sign == -1)    /* Set starting position to convert*/
    {
        offset = 1;
    }
    else
    {
        offset = 0;
    }

    n = 0;

    for (c = offset; a[c] != '\0'; c++)
    {
        n = n * 10 + a[c] - '0';
    }

    if (sign == -1)
    {
        n = -n;
    }

    return n;
}



void punchItem()
{

    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tProduct List\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n\n");
    all_Item();
    int gtotal=0,total=0,totalquantity=0,gtotalDiscount=0;
    printf("\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tProduct Cart\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");


    while(1)
    {
        int quantity=0;
        input();
        q=head;
        char s_n[100];

        printf("\n\t\t\t\tEnter Product Id(write 'end' then stop buy more): ");
        scanf("%s",s_n);


        if(strcmp(s_n,"end")==0)
            break;

        while(head!=NULL)
        {
            if(strcmp(s_n, head->id) == 0)
            {
                int n;
                idd = head->id;

                printf("\n\t\t\t\tEnter Quantity: ");
                scanf("%d",&quantity);

                totalquantity = totalquantity+quantity;

                /* quantityy = quantity;*/
                n = toString(head->price);

                int total= n*quantity;

                int v ;

                gtotal = gtotal+total;

                printf("\t\t\t\tTotal Price is: %d\n\n",total);



            }

            head=head->next;

        }

    }
    printf("\n\n");

    if(gtotal!=0)
    {

        printf("\t\t\t\tTOTAL AMOUNT = %d Taka",gtotal);


        char str[10];

        inttostring(str, gtotal);

        int disprice =0;


        if(gtotal<10000)
        {
            FILE *fp;
            fp=fopen("paymentData.txt","a+");


            fprintf(fp,"        %d     \t",totalquantity);
            fprintf(fp,"        %s     \t",str);
            fprintf(fp,"%d\n",disprice);

            fclose(fp);
        }


    }
    printf("\n\n");

    if(gtotal>10000)
    {
        int discount;
        discount = 5*gtotal;
        int percent = discount/100;

        int totalDiscount = gtotal-percent;
        gtotalDiscount = totalDiscount;
        printf("\t\t\t\tTotal Discount Price is: %d Taka\n",totalDiscount);

        char str[10];

        inttostring(str, gtotal);


        FILE *fp;
        fp=fopen("paymentData.txt","a+");


        fprintf(fp,"        %d     ",totalquantity);
        fprintf(fp,"        %s     ",str);
        fprintf(fp,"%d\n",totalDiscount);

        fclose(fp);


    }









    char another, choice;

    printf("\t\t\tPress 1 to Buy Item & 2 to go Main Menu.\n");

    printf("\t\t\t\t\tYour Choice: ");
    choice  = getche();
    switch(choice)
    {
    case '1':
        system("cls");
        another = 'y';
        while(another == 'y')
        {
            printf("\n\t\t\t\t\t\tCash Memo\n\n");
            printf("\n\t\t\t\t\tTotal Quantity - %d ",totalquantity);
            printf("\n\t\t\t\t\tTotal Price - %d Taka",gtotal);
            printf("\n\t\t\t\t\tTotal Discount Price - %d Taka\n",gtotalDiscount);
            if(gtotalDiscount>0)
            {
                printf("\n\t\t\t\t\tPayment Total - %d Taka\n\n\n",gtotalDiscount);
            }
            else
            {
                printf("\n\t\t\t\t\tPayment Total - %d Taka\n\n\n",gtotal);
            }


            printf("\n\n\n\n\t\t\t\t\tThank You For Shoping :-) ");

            getchar();
            getchar();


            main();

            another = getche();
        }
        break;
    case '2':
        system("cls");
        another = 'y';
        while(another == 'y')
        {
            main();
            another = getche();
        }
        break;


    }

}


void main()
{
    system("cls");
    system("COLOR 3F");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t       Welcome To Super Shop\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t1.Add Product\n");
    printf("\t\t\t\t\t2.Punch Item\n");
    printf("\t\t\t\t\t3.Exit\n");
    char another, choice;

    printf("\t\t\t\t\tYour Choice: ");
    choice  = getche();
    switch(choice)
    {
    case '1':
        system("cls");
        another = 'y';
        while(another == 'y')
        {
            addItem();
            another = getche();
        }
        break;
    case '2':
        system("cls");
        another = 'y';
        while(another == 'y')
        {
            punchItem();
            another = getche();
        }
        break;
    case '3':
        system("cls");
        another = 'y';
        while(another == 'y')
        {
            exit(0);/* exit from the program*/
            another = getche();
        }
        break;


    }
}
