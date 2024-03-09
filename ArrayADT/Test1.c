#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int size;
    int lastindex;
    int *ptr;
}arrayADT;

// Creaion of array speficifed by size and type 
arrayADT * createArrayADT(int size);

// Reterive a item at specified index 
int getitem(arrayADT *arr,int  index);

// Store an item at a given index 
int insertitem(arrayADT * arr,int index,int value);

// modify an item at a given index 
int edititem(arrayADT *arr,int index,int newvalue);

// count items 
int countitems(arrayADT *arr);

// remove an item from a particular index 
int removeitem(arrayADT * arr, int index);

// search an item 
int searchitem (arrayADT *arr, int item);

// sort the array in ascending order or descending order by mentioing 
// second parameter as 0 = ascending 1 = descending 
arrayADT * sortArray(arrayADT *arr,int sortOrder);

arrayADT * createArrayADT(int size){

    arrayADT *arr = (arrayADT *)malloc(sizeof(arrayADT));
    arr->size = size;
    arr->lastindex = -1;
    arr->ptr = (int *)malloc(arr->size * sizeof(int));
    return arr;
}

int getitem(arrayADT *arr,int  index){
    
        if(arr->lastindex < index || index <0){
            return (-1);
        }
        else {
        return (arr->ptr[index]);
        }
}

int insertitem(arrayADT * arr,int index,int value){
    // array is full
    if(arr->lastindex == (arr->size - 1)){  
        printf("Array is full\n");
        return (-1);
    }
    // index less zero or index is not the valid next index
    else if ( index < 0 || ((arr->lastindex +1) < index)){ 
        printf("Invalid index\n");
        return (-1);
    }
    // want to insert in between or at the
    // last index thus sifting of values needs to done
    else if(index <= arr->lastindex){  
        arr->lastindex++;
        for(int i = arr->lastindex; i != index;i--){
        arr->ptr[i] = arr->ptr[i-1];
        } 
        arr->ptr[index] = value;    
        return 1;
    }
    // insert after the lastindex
    else if(index == (arr->lastindex)+1){
        arr->lastindex++;   
        arr->ptr[index] = value;
        return 1; 
    }

}

int edititem(arrayADT *arr,int index,int newvalue){

    if(index<0 || index > arr->lastindex ){
        return (-1);
    }
    else {
        arr->ptr[index] = newvalue;
        return 1;
    }
}

int countitems(arrayADT *arr){
    return arr->lastindex + 1;
}

int removeitem(arrayADT * arr, int index){

     if(index < 0 || index > arr->lastindex){
        printf("invalid index");
        return (-1);
     }
     else if(index < arr->lastindex){
        for(int i = index;i<arr->lastindex;i++){
            arr->ptr[i] = arr->ptr[i+1];
        }
        arr->lastindex--;
        return 1;
     }
     else if(index == arr->lastindex){
        arr->lastindex --;
        return 1;
     }

}


int searchitem (arrayADT *arr, int item){

    if(arr->lastindex == -1){
        printf(" Arrya is empty");
    }
        for(int i = 0; i<=arr->lastindex;i++){

            if(arr->ptr[i] == item){
                printf("Item found %d",i);
                return i;
            }
        }
    printf("Item not found\n");
    return -1;
}

arrayADT * sortArray(arrayADT *arr, int sortOrder){

    if(arr->lastindex == -1 || arr->lastindex == 1){
        return arr;
    }

    for(int i =0; i<countitems(arr);i++){
        for(int j = 0;j<countitems(arr)-i;j++){
            if(arr->ptr[j]>arr->ptr[j+1]){
                arr->ptr[j] = arr->ptr[j]+arr->ptr[j+1]-(arr->ptr[j+1] = arr->ptr[j]);
            }
        }
    }
   // a=a+b-(b=a);
   return arr;
}

void printarrayAdt(arrayADT *arr){

    if(arr->lastindex == -1){
        printf("array is emppty");
         return;
    }
    for(int i = 0;i<countitems(arr);i++){
        printf("%d  ",arr->ptr[i]);
    }
    printf("\n");
}

int main(void){


    arrayADT * arr;
    arr = createArrayADT(5);
    insertitem(arr,0,1);
    insertitem(arr,1,10);
    insertitem(arr,2,20);
    insertitem(arr,3,30);
    insertitem(arr,4,40);

    printarrayAdt(arr);

    edititem(arr,2,100);

    printarrayAdt(arr);
    
    printf("item at index 2 = %d\n",getitem(arr,2));

    removeitem(arr,2);

    printarrayAdt(arr);

    searchitem(arr,100);

    sortArray(arr,1);

    printarrayAdt(arr);

    return 0;
}