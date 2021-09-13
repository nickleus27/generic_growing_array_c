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
int main(void){
    Vector t;
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
    vPush( &c, &t );
    vPush( cp, &t );
    vPush( &d, &t );
    vPush( &c, &t );
    vPush( cp, &t );
    vPush( &d, &t );

    vFinalizeMemory(&t);
    printf( "%d\n", *((int *)vGet(0, &t)) );
    printf( "%c\n", *((char *)vGet(1, &t)) );
    printf( "%s\n", (char *)vGet(2, &t) );
    printf( "%f\n", *((float*)vGet(3, &t)) );
    printf( "%c\n", *((char *)vGet(4, &t)) );
    printf( "%s\n", (char *)vGet(5, &t) );
    printf( "%f\n", *((float*)vGet(6, &t)) );
    vFree(&t);

    printf("the size of t is %d\n", vSize(&t));

  return 0;
}
