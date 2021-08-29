//
//  gen_vect.h
//  c_generic_vector
//
//  Created by Nicholas Anderson on 8/28/21.
//

#ifndef gen_vect_h
#define gen_vect_h

#include <stdio.h>
//const size_t increment;
typedef struct
{
    size_t space_left;
    size_t size;
    void **vptr;
}T;

void vInit(T *);

void vPush( void *, T *);

void vFinalizeMemory(T *);

void vFree(T *);

int vSize(T *);

//void * atIndex(int, T *, void *); experimenting here

#endif /* gen_vect_h */
