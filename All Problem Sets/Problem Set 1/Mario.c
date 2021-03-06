// Implement a program that prints out a double half-pyramid of a specified height, per the below.

// $ ./mario
// Height: 4
//    #  #
//   ##  ##
//  ###  ###
// ####  ####


#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - i - 1; j++)
            printf(" ");
        for (int j = 0; j < i + 1; j++)
            printf("#");
        printf("  ");
        for (int j = 0; j < i + 1; j++)
            printf("#");
        printf("\n");
    };
}
