#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float a, float b, float c);
int main (void)
{

       // Get each triangle length - must be positive
       float sidea = get_float("Length of side a: \n");
       float sideb = get_float("Length of side b: \n");
       float sidec = get_float("Length of side c: \n");

       //
        // valid_triangle(float sidea, float sideb, float sidec);
        bool (valid_triangle);
        {
            printf("Nice trippies, girl\n");
            return 0;
        }
        printf("Nah, sorry.\n");

}


bool valid_triangle(float a, float b, float c)
{
    if (a <= 0 || b <= 0 || c<= 0)
    {
        return false;
    }
    if (b + c <= a || a +c <= b || b + c <= 0)
    {
        return false;
    }
    return true;
}