#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int size;
    int front;
    int end;
    int *arr;
}QueueADT;

QueueADT * CreateQueue(int size);

int isEmptyQueue(QueueADT * q);

int isFullQueue(QueueADT * q);

int queueCapacity(QueueADT *q);

void IncreaseQueueto(QueueADT *q,int incsize);

void DeceaseQueueto(QueueADT*q,int decsize,int noOfElementsinQueue);

void displayQueue(QueueADT *q);

void enQueue(QueueADT *q,int data);

int deQueue(QueueADT *q);

int main (void){

    QueueADT * test = NULL;
    test = CreateQueue(4);
    
    // if(isEmptyQueue(test)){
    //     printf("Queue is empty\n");
    // }

    printf("Capacity of Queue %d\n",queueCapacity(test));

    enQueue(test,1);
    enQueue(test,2);
    enQueue(test,3);
    enQueue(test,4);
    displayQueue(test);
    deQueue(test);
    displayQueue(test);
    deQueue(test);
    displayQueue(test);
    deQueue(test);
    displayQueue(test);
    enQueue(test,5);
    displayQueue(test);
    //printf("front = %d value = %d end = %d\n",test->front,test->arr[test->end],test->end);
    enQueue(test,6);
    displayQueue(test);
    //printf("front = %d value = %d end = %d\n",test->front,test->arr[test->end],test->end);
    deQueue(test);
    displayQueue(test);
    //printf("front = %d value = %d end = %d\n",test->front,test->arr[test->end],test->end);
    enQueue(test,10);
    displayQueue(test);
    //printf("Capacity of Queue %d\n",queueCapacity(test));

    return 0;
}


QueueADT * CreateQueue(int size){

    if(size <= 0 ){
        printf("Not a valid size\n");
        return NULL;
    }
    else {
        QueueADT * q = NULL;
        q = (QueueADT *)malloc(sizeof(QueueADT));
        if(q!= NULL){
            q->front = -1;
            q->end = -1;
            q->size = size;
            q->arr = (int *)malloc(sizeof(int)*q->size);
            return q;
        }

    }

}

int isEmptyQueue(QueueADT * q){

    if(q->front == -1 && q->end == -1){
        return 1;
    }
    else 
    return 0;
}

int isFullQueue(QueueADT * q)
{
    if(q->front == 0 &&  (q->end == q->size -1)){
        return 1;
    }
    else if(q->front == q->end + 1){
        return 1;
    }
    else 
    return 0;
}

int queueCapacity(QueueADT *q){
    
    return q->size;
}

void IncreaseQueueto(QueueADT *q,int incsize){

        int * temp;
        temp = (int *)malloc(sizeof(int)*incsize);
        if(temp != NULL){
        for(int i = 0, j = q->front;i<incsize;i++){

            temp[i] = q->arr[j];
            if(j>q->end && j == q->size-1){
                j = 0;
            }
            else 
            j++;
            }

            q->front = 0;
            q->end = q->size - 1;
            q->size = incsize;
            free(q->arr);
            q->arr = temp;

        }
}

void DeceaseQueueto(QueueADT*q,int decsize,int noOfElementsinQueue){

    if(decsize < noOfElementsinQueue){
        printf("Decrease size to small\n");
        return;
    }

    int *temp = NULL;
    temp = (int *)malloc(sizeof(int)*decsize);
    for(int i = 0,j=q->front;i<decsize;i++){
        temp[i] = q->arr[j];
        if(j>q->end && j==q->size -1){
            j = 0;
        }else
        j++;
    }

    q->front = 0;
    q->end = decsize -1;
    q->size  = decsize;
    free(q->arr);
    q->arr = temp;

}

// void displayQueue(QueueADT *q){

//     if(q->front == -1){
//         printf("Queue is Empty cannot display\n");
//         return;
//     }
//     for(int i = q->front;i<q->size;i++){
//        // printf(" %d ",q->arr[i]);
//         printf(" display front = %d value = %d, end = %d\n",q->front,q->arr[i%q->size],q->end);
//     }
//     printf("\n");
// }

// void displayQueue(QueueADT *q) {
//     if (isEmptyQueue(q)) {
//         printf("Queue is Empty, cannot display\n");
//         return;
//     }

//     int i;
//     for (i = q->front; i != (q->end + 1) % q->size; i = (i + 1) % q->size) {
//         printf(" display front = %d value = %d, end = %d\n", q->front, q->arr[i], q->end);
//     }
//     printf("\n");
// }

void displayQueue(QueueADT *q) {
    if (isEmptyQueue(q)) {
        printf("Queue is Empty, cannot display\n");
        return;
    }

    int i;
    if (q->front <= q->end) {
        for (i = q->front; i <= q->end; i++) {
            printf(" display front = %d value = %d, end = %d\n", q->front, q->arr[i], q->end);
        }
    } else {
        for (i = q->front; i < q->size; i++) {
            printf(" display front = %d value = %d, end = %d\n", q->front, q->arr[i], q->end);
        }
        for (i = 0; i <= q->end; i++) {
            printf(" display front = %d value = %d, end = %d\n", q->front, q->arr[i], q->end);
        }
    }
    printf("\n");
}


void enQueue(QueueADT *q,int data){

    if(q==NULL){
        printf("Queue is not valid\n");
        return;
    }
    else if(isEmptyQueue(q)){
        q->arr[0] = data;
        q->front = 0;
        q->end = 0;
    }
    else if(isFullQueue(q)){
        IncreaseQueueto(q,q->size*2);
        q->end++;
        q->arr[q->end] = data;
    }else {
        if(q->end == q->size -1){
            q->end = 0;   
        }
        else{
            q->end++;
        }
       // printf("end = %d\n",q->end);
        q->arr[q->end] = data;
    }

}

int deQueue(QueueADT *q){

        int t = 0;
        if(isEmptyQueue(q)){
            printf("Queue is empty cannot dequeue\n");
            return -1;
        }
        else{
            t = q->arr[q->front];
            if(q->front >= q->size -1){
            q->front = 0;
            }
            else if(q->front == q->end)
            { 
                q->front =-1;
                q->end = -1;
            }else{
                q->front++;
            }
            return t;
        } 
}