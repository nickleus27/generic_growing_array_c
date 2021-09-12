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
    printf( "%d\n", *((int *)t.vptr[0]) );
    printf( "%c\n", *((char *)t.vptr[1] ));
    printf( "%s\n", (char *)t.vptr[2] );
    printf( "%f\n", *((float*)t.vptr[3] ));
    printf( "%c\n", *((char *)t.vptr[4] ));
    printf( "%s\n", (char *)t.vptr[5] );
    printf( "%f\n", *((float*)t.vptr[6] ));
    vFree(&t);

    printf("the size of t is %d\n", vSize(&t));

  return 0;
}
