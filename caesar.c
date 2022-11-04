#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        //if user uses invalid input we have a message to try again
        printf("Usage: ./caesar key");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        //Check if the input is a number
        if (!isdigit(argv[1][i]))
        {
            //if not a number return message again
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    //convert the key from a string to an actual integer
    //atoi converst string to int
    int key = atoi(argv[1]);

    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");

    //Convert into ciphertext by sorting through the index
    for (int j = 0; j < strlen(plaintext); j++)
    {
        //rest the alphabet 0 and make sure it can loop back through based on letter value
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + key) % 26 + 65);
        }

        //if letter is now lowe case instead of upper case
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + key) % 26 + 97);
        }

        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}
