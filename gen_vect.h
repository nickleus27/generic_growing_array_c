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
}Vector;

void vInit(Vector *);

void vPush( void *, Vector *);

void vFinalizeMemory(Vector *);

void vFree(Vector *);

int vSize(Vector *);

void * vGet(int, Vector *); //experimenting here

#endif /* gen_vect_h */
