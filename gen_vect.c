//
//  gen_vect.c
//  c_generic_vector
//
//  Created by Nicholas Anderson on 8/28/21.
//

#include "gen_vect.h"
#include <stdlib.h>
const size_t increment = 2;

void vInit(T *vector){
    size_t init_size = 4;
    vector->vptr = malloc(init_size * sizeof(void *));
    vector->size = 0;
    vector->space_left = init_size;
    if(vector->vptr){
        printf("initialized successfully\n");
    }else{
        printf("unitialized vector\n");
    }
}

void vPush( void *data, T *vector){
    void *vptrTemp;
    size_t maxLength;

    if( vector->space_left == 0 ){
        maxLength = vector->size<<1;
        printf("this is maxlength %zu\n", maxLength);
        vptrTemp = realloc(vector->vptr, maxLength * sizeof(void *) );
        if( vptrTemp == NULL ){
            printf( "Failed realloc");
            exit(1);
        }
        vector->space_left = maxLength - vector->size;
        printf("this is new space left after growing %zu\n", vector->space_left);
        vector->vptr = vptrTemp;
    }

    vector->vptr[vector->size++] = data;
    vector->space_left--;
   // printf("this is in vStoreData %d", *(int*)vector.vptr[vector.size]);
}

//This will make the memory efficient.
void vFinalizeMemory(T *vector){
    vector->vptr = realloc(vector->vptr, vector->size * sizeof(void *));
}

void vFree(T *vector){
    free(vector->vptr);
}

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
