# include <stdio.h>
# include <stdlib.h>

void scan(int A[], int n )
{
    printf("Enter elements of the array\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
}
void display(int A[], int n)
{
    printf("The array is: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t",  A[i]);
        printf("\n");
    }
}
void insert(int A[], int *n)
{
    int element,item, p, s;
    printf("Enter the element after which to insert the new element\n");
    scanf("%d", &element);

    printf("Enter the new element to be inserted\n");
    scanf("%d", &item);

    for(int i = 0;i < *n; i++)//search for the index of the element after which to insert new ele
    {
        if(A[i] == element)
        {
            p = i;
            break;
        }
    }
    *n = *n +1;
    for(int i = *n; i > p; i--)
    {
        A[i] = A[i - 1];
        s = i;
    }
    A[s] = item;
}
int main()
{   
    int n;
    printf("Enter size of the array\n");
    scanf("%d", &n);
    int *A = (int *)malloc(sizeof(int) * n);
    scan(A, n);   display(A,n);
    insert(A, &n);
    printf("After inserting new element: \n");
    display(A, n);
}