//
//  main.c
//  c_generic_vector
//
//  Created by Nicholas Anderson on 6/5/21.
//


//https://stackoverflow.com/questions/43750302/how-may-i-implement-a-generic-dynamically-growing-array-in-c
#include <stdio.h>
#include <stdlib.h>
#include "gen_vect.h"
/*
const size_t stIncrement = 2;

typedef struct
{
   size_t space_left;
   size_t size;
   void **vptrX;
}T;

T t;

void
vStoreData( void *data )
{
   void *vptrTemp;
   size_t stMaxLength;

  if( t.space_left == 0 )
  {
      stMaxLength = t.size + stIncrement;
      vptrTemp = realloc(t.vptrX, stMaxLength * sizeof(void *) );
      if( vptrTemp == NULL ){
         printf( "Failed realloc");
        exit(1);
      }
      t.space_left = stIncrement;
      t.vptrX = vptrTemp;
  }

  t.vptrX[t.size++] = data;
  t.space_left--;
}

//This will make the memory efficient.
void
vFinalizeMemory(void)
{
  t.vptrX = realloc(t.vptrX, t.size * sizeof(void *));
}
void vFree(void){
    free(t.vptrX);
}
*/int
main(void)
{
    T t;
    vInit(&t);
    int i;
    char c;
    float d;
    char *cp = "How are you";
    i = 10;
    c ='O';
    d = 40.12345;
    printf("we made it this far\n");
    
    if(t.vptr){
        printf("still have memory\n");
    }else{
        printf("we dont have memory\n");
    }
    vPush( &i, &t );
    //printf("%d\n", *((int*)t.vptr[0]));
    
    vPush( &c, &t );
    
    //printf( "%c\n", *((char *)t.vptr[1] ));
    vPush( cp, &t );
    vPush( &d, &t );
    vPush( &c, &t );
    vPush( cp, &t );
    vPush( &d, &t );
    
    //printf("after storing data\n");
    vFinalizeMemory(&t);
    printf( "%d\n", *((int *)t.vptr[0]) );
    //printf("after printing first value");
    printf( "%c\n", *((char *)t.vptr[1] ));
    printf( "%s\n", (char *)t.vptr[2] );
    printf( "%f\n", *((float*)t.vptr[3] ));
    printf( "%c\n", *((char *)t.vptr[4] ));
    printf( "%s\n", (char *)t.vptr[5] );
    printf( "%f\n", *((float*)t.vptr[6] ));
    vFree(&t);
    size_t test = 8;
    size_t test2 = 8;
    test = (test<<1)-test2;
   // printf("%zu\n", test);
    printf("the size of t is %d\n", vSize(&t));

  return 0;
}
