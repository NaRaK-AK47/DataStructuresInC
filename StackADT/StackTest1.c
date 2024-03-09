#include <stdlib.h>
#include <stdio.h>


typedef struct node {
    int data;
    struct node * next;
}Node;

Node * createNode (void){

    Node *t;
    t = (Node *)malloc(sizeof(Node));
    t->data =0;
    t->next = NULL;

    return t;

}

void StackPush(Node **top,int val){

    Node *t;
    t = createNode();
    if(t == NULL){
       printf(" Node not initalized\n");
       return; 
    }
    else {
        t->data = val;
        t->next = *top;
        *top = t;
    }
}

int StackPop(Node **top){

    int t;
    Node *r;
    if(*top == NULL){
        printf("Stack underflow");
        return (-1);
    }
    else{
        r = *top;
        t = r->data;
        *top = r->next;
        free(r);
        return t;
    }
}

int StackPeek(Node **top){

    if(*top == NULL){
        printf("Stack is empty");
        return -1;
    }
    else{
        return ((*top)->data);
    }
}

void StackDisplay(Node **top){

    Node *t;
    t = *top;
    while(t!= NULL){
        printf(" %d ",t->data);
        t=t->next;
    }
    printf("\n");
}

void EmptyStack(Node **top){

    if(*top ==NULL){
        printf("Stack is empty");
        return;
    }
    Node  *t;
    while(*top != NULL){
        t=*top;
        *top = t->next;
        free(t);
    }
}

int StackCount(Node **top){
    int count =0;
    Node *t;
    if(*top == NULL){
        printf("Stack empty");
        return 0;
        }
    else{
        t =*top;
        while(t != NULL){
            count++;
            t=t->next;
         // printf("count =%d\n",count);
        }
       // printf("count =%d\n",count);
        return count;
    }
}

int main(void){

    Node *arr =NULL;
    StackPush(&arr,10);
    StackPush(&arr,20);
    StackPush(&arr,30);
    StackPush(&arr,40);
    
    printf("%d\n",StackCount(&arr));
    StackDisplay(&arr);

    StackPop(&arr);
    printf("%d\n",StackCount(&arr));
    StackDisplay(&arr);
}