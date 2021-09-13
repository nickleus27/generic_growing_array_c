# generic_growing_array_c

I am new to C and coming from C++ and Java I miss having a data structure, such as, vectors and arraylists.  So I thought I would experiment with this in C so that I could utilize the benefits of a dynamic growing array.  I tried to go further and make it work generically with any data type.  However, this seems to have made this data structure error prone.  I would like to continue to develop this to have more useful functions.

Example usage: //Also look at main.c

To declare Vector type:
Vector v; //use whatever variable name you want.  Following examples will stike with v

To initialize:
vInit(&v);

To push back value:
vPush(&data, &v); //value is whatever data type

To access data:
*((int *)vGet(0, &t)) //access an integer value stored at index 0

Return size of array:
vSize(&v);

Free memory used by Vector:
vFree(&v);
