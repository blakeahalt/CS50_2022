#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
       int hundo_array[100];
       for (int i = 0;  i < 100; i++)
       {
              hundo_array[i] = i + 1;
       }
              printf("Index 0 is %i,\nIndex 1 is %i,\nIndex 99 is %i.\n", hundo_array[0], hundo_array[1], hundo_array[99]);
              printf("%i%i%i\n%i", hundo_array[3], hundo_array[19], hundo_array[68], hundo_array[99]);
}

       // int hundo_array[100];
       // hundo_array[0] = 1;
       // hundo_array[1] = 2;
       // hundo_array[2] = 3;
       // hundo_array[3] = 4;