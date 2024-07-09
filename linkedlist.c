
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void create_ll() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter data: ");
    for(int i = 0; i < n; i++) {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &temp->data);
        if(head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        temp->next = NULL;
    }
}

void view_ll() {
    struct node *p = head;
    while(p!=NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int maxElement() {
    struct node *p = head;
    int max = p->data;
    while(p!=NULL) {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int minElement() {
    struct node *p = head;
    int min = p->data;
    while(p!=NULL) {
        if(p->data < min)
            min = p->data;
        p = p->next;
    }
    return min;
}

int sumofElements() {
    struct node *p = head;
    int sum = 0;
    while(p!=NULL) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

double avgofElements() {
    int size = 0;
    struct node *p = head;
    double sum = 0.0;
    while(p!=NULL) {
        sum += p->data;
        size++;
        p = p->next;
    }
    double avg = sum/size;
    return avg;
}

void varandSd() {
    int sum = 0, size = 0;
    struct node *p = head;
    double mean = avgofElements();
    double variance = 0.0;
    while(p!=NULL) {
        variance += pow((p->data - mean),2);
        size++;
        p = p->next;
    }
    variance = variance/size;
    printf("Variance = %.2f\n", variance);
    printf("Standard Deviation = %.2f\n", sqrt(variance));
}

int main() {
    create_ll();
    view_ll();
    printf("Max element of linked list is: %d\n", maxElement());
    printf("Min element of linked list is: %d\n", minElement());
    printf("Sum of elements of linked list is: %d\n", sumofElements());
    printf("Average of elements of linked list is: %.2f\n", avgofElements());
    varandSd();
    return 0;
}