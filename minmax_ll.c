#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next ;
};
struct node *head=NULL;
struct node *tail=NULL;
int main(){
 create_ll();
 view_ll();
 minmax_ll();
}
void create_ll(){
int n;
printf("enter the size of the linked list");
scanf("%d",&n);
for (int i = 0; i < n; i++)
{   
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d",&temp->data);
    if (head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
    temp->next=NULL;
}
}
void view_ll(){
    struct node* trav=head;
    while (trav!=NULL)
    {
        printf("%d \t ",trav->data);
        trav=trav->next;
    }
    printf("\n");
}
void minmax_ll(){
    struct node*a=head;
    int min=a->data;
    int max=a->data;
    while (a!=NULL)
    {
       if(min > a->data)
            min=a->data;
       if (max < a->data)
            max=a->data;
            a=a->next;  
    }
    printf("min value is %d \n max value is %d \n",min,max);
}
