#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get user height input
    int height;
    do
    {
        height = get_int("What do you want the height to be? ");

    }
    while (height < 1 || height > 8);

    // create side of pyramid
    for (int i = 0; i < height; i++)
    {
        for (int j = height - i; j > 1; j--)
        {
            //creating the spaces by substracting from height
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            //creating hashes that increase going down rows
            printf("#");
        }
        printf("\n");
    }
}
