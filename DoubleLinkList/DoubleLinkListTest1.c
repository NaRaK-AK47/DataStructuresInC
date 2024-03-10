#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}node;

void InsertStart(node **start,int data);

void InsertLast(node **start,int data);

void InsertAfter(node **start,node *ptr, int data);

void DeleteBetween(node **start,node *ptr);

node * find (node **start,int data);

void deleteStart(node **start);

void deleteLast(node **start);

void Displaylist(node **start);

int main(void){

    node * p = NULL,*ptr =NULL;
    InsertStart(&p,10);
    InsertStart(&p,20);
    InsertStart(&p,30); 
    InsertStart(&p,40);
    InsertLast(&p,15);

    Displaylist(&p);
    ptr = find(&p,20);
    InsertAfter(&p,ptr,60);
    Displaylist(&p);
    deleteStart(&p);
    Displaylist(&p);

    ptr = find(&p,30);
    DeleteBetween(&p,ptr);
    Displaylist(&p);
    return 0;
}


void InsertStart(node **start,int data){

    node *t = NULL;
    t = (node *) malloc(sizeof(node));
    if(t != NULL){ // to check is malloc worked or not 
        t->data = data;
        t->prev = NULL;
        if(*start != NULL){ // is node is already present than the prev of last node should point to new node 
            (*start)->prev = t;
        }

        t->next = *start;
        *start = t;

    }
}

void InsertLast(node **start,int data){

    node *t = NULL,*r = NULL;
    t = (node *) malloc(sizeof(node));
    if(t != NULL){ // to check is malloc worked or not
        t->next = NULL; 
        t->data = data;

        if(*start == NULL){ // if its the first node to insert 
            t->prev = NULL;
            *start = t;
        }
        else {
        r = *start;
        while(r->next !=NULL){ //loop till the last node 
            r = r->next;
        }
        t->prev = r;
        r->next = t;
        
        }

    }
}

void InsertAfter(node **start,node *ptr, int data){

    if(*start == NULL){
        printf("List is empty cannot insert after\n");
        return;
    }
    else if (ptr ==NULL){
        printf("Node not found");
        return;
    }else{
        node *t = NULL;
        t = (node *)malloc(sizeof(node));
        if(t != NULL){

            t->data = data;
            t->next = ptr->next;
            t->prev = ptr;
            ptr->next = t;
            ptr=t; 
            if(ptr->next != NULL) 
                ptr->next->prev = t;

        }
    }

}

node * find (node **start,int data){

    node *t = NULL;
    if(*start == NULL){
        printf("List is empty cannot find\n");
        return (NULL);
    }else{
        t = *start;
        while(t != NULL){
            if(t->data == data){
                return (t);
            }
            t=t->next;
        }
        return (NULL);
    }

}

void Displaylist(node **start){

    if(*start != NULL){
        node *t = NULL;
        t =*start;
        while(t!=NULL){
            printf(" %d ",t->data);
           //printf(" %p %d %p\n",t->prev,t->data,t->next);
            t=t->next;
        }
    printf("\n");
    }else{
        printf("List is empty cannot disply\n");
    }
}

void deleteStart(node **start){
    if(*start == NULL){
        printf("List is empty cannot delete start\n");
        return;
    }
    else{
        node *t = NULL;
        t = *start;
        *start = t->next;
        (*start)->prev = NULL;
        free(t);
    }
}

void deleteLast(node **start){
    if(*start ==NULL){
        printf("List is empty cannot delete last\n");
        return;
    }else{
        node *t  =NULL;
        t = *start;
        while(t->next !=NULL){
            t=t->next;
            //printf(" %x \n",t);
        }
        if(t->prev == NULL){
            *start = NULL;
           // printf("Start  null");
            free(t);
        }else{
        t->prev->next = NULL;
        //printf(" %p %d %p\n",t->prev,t->data,t->next);
        t->prev = NULL;
        free(t);
        }
    }
}

void DeleteBetween(node **start,node *ptr){

        if(*start == NULL){
            printf("List is empty cannot delete after\n");
            return;
        }
        else if(ptr == NULL){
            printf("Node not found cannot delete after\n");
            return;
        }
        else{
     
           
           if( ptr->prev ==NULL){ 
                *start = (*start)->next; 
                (*start)->prev = NULL;
                free(ptr);
            }
            else if(ptr->next == NULL && ptr->prev !=NULL){
                ptr->prev->next = NULL;
                free(ptr);
            }else{
                 ptr->prev->next = ptr->next;
                 ptr->next->prev = ptr->prev;
                 free(ptr);
            }
        }
}