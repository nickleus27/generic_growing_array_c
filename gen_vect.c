//
//  gen_vect.c
//  c_generic_vector
//
//  Created by Nicholas Anderson on 8/28/21.
//

#include "gen_vect.h"
#include <stdlib.h>
const size_t increment = 2;

void vInit(T *vector){//TODO: make initial size larger...16?
    size_t init_size = 4;//initialize array to size 4...
    vector->vptr = malloc(init_size * sizeof(void *));//initialize to array of void pointers
    if(vector->vptr){
        printf("initialized successfully\n");
    }else{
        printf("Failed malloc\n");
        exit(1);
    }
    vector->size = 0;//array is empty
    vector->space_left = init_size;//space left is initial size (4)
}

void vPush( void *data, T *vector){
    void *vptrTemp;
    size_t maxLength;

    if( vector->space_left == 0 ){//if array is full
        maxLength = vector->size<<1;//double the size of array (maxLength x 2)
        vptrTemp = realloc(vector->vptr, maxLength * sizeof(void *) );//have vptrTemp = realloc incase not succesful
        if( vptrTemp == NULL ){//exit it realloc failed
            printf( "Failed realloc");
            exit(1);
        }
        vector->space_left = maxLength - vector->size;//space left after growing
        printf("this is new space left after growing %zu\n", vector->space_left);
        vector->vptr = vptrTemp;//have vector point to realloc array
    }

    vector->vptr[vector->size++] = data;//now that we have space push data to next available spot
    vector->space_left--;
}

//This will make the memory efficient.
void vFinalizeMemory(T *vector){
    vector->vptr = realloc(vector->vptr, vector->size * sizeof(void *));
}

//free memory back to heap
void vFree(T *vector){
    free(vector->vptr);
}

//return amount of elements in array
int vSize(T *vector){
    return (int)vector->size;
}

/* experimenting here on how to return value
void * atIndex(int index, T *vector, void * ptr){
    void * vptr;
    vptr = ptr;
    return (vptr *)vector[index];
}
 */
