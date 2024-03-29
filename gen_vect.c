//
//  gen_vect.c
//  c_generic_vector
//
//  Created by Nicholas Anderson on 8/28/21.
//

#include "gen_vect.h"
#include <stdlib.h>

void vInit(Vector *vector){//TODO: make initial size larger...16?
    size_t init_size = 4;//initialize array to size 4...
    vector->vptr = malloc(init_size * sizeof(void *));//initialize to array of void pointers
    if(vector->vptr){
        printf("initialized successfully\n");
    }else{
        printf("Failed malloc\n");
        exit(EXIT_FAILURE);
    }
    vector->size = 0;//array is empty
    vector->space_left = init_size;//space left is initial size (4)
}

void vPush( void *data, Vector *vector){
    void *vptrTemp;
    size_t maxLength;

    if( vector->space_left == 0 ){//if array is full
        maxLength = vector->size<<INCREMENT;//1;//double the size of array (maxLength x 2)
        vptrTemp = realloc(vector->vptr, maxLength * sizeof(void *) );//have vptrTemp = realloc incase not succesful
        if( vptrTemp == NULL ){//exit it realloc failed
            printf( "Failed realloc");
            exit(EXIT_FAILURE);
        }
        vector->space_left = maxLength - vector->size;//space left after growing
        printf("this is new space left after growing %zu\n", vector->space_left);
        vector->vptr = vptrTemp;//have vector point to realloc array
    }

    vector->vptr[vector->size++] = data;//now that we have space push data to next available spot
    vector->space_left--;
}

//This will make the memory efficient.
void vFinalizeMemory(Vector *vector){
    vector->vptr = realloc(vector->vptr, vector->size * sizeof(void *));
}

//free memory back to heap
void vFree(Vector *vector){
    free(vector->vptr);
}

//return amount of elements in array
int vSize(Vector *vector){
    return (int)vector->size;
}

/* experimenting here on how to return value*/
void * vGet(int index, Vector *vector){
    void ** tempptr;
    tempptr = vector->vptr;
    return tempptr[index];
}
 
