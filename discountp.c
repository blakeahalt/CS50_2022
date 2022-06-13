// #include <cs50.h>
// #include <stdio.h>

// int main(void)
// {
//     float price = get_float("Regular Price: ");
//     int sale = get_int("Percent off: ");
//     // float sale = discount(regular * (100 - percentoff)/100);
// //     float sale = discount(regular, percentoff);

//     // printf("Regular Price: %.2f\n", regular);
//     printf("Sale Price: %.2f\n", price * (100 - sale)/100);
// }


// float discount(float price, int percentage)
// {
//     // float sale = price *.85;
//     // return sale;
//     //If declaring a variable to store a value then returning with this keyword - DON'T NEED THAT VARIABLE and just return the argument being passed in times .85
//     return price * (100 - percentage)/100;
// }




#include <cs50.h>
#include <stdio.h>

float discount(float price, int percentage);
int main(void)
{
    float price = get_float("Regular Price: ");
    int percentoff = get_int("Percent off: ");
    float sale = discount(price, percentoff);

    printf("Sale Price %.2f\n", sale);
}

float discount(float price, int percentage)
{
    return price * (100 - percentage) / 100;
}