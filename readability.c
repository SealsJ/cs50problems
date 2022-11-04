#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Get input words from the user
    string text = get_string("Text: ");

    //conveting all the variables from user input to be converted to integers
    int let = 0;
    int word = 1;
    int sent = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        //Counting the Number of Letters
        if (isalpha(text[i]))
        {
            let++;
        }

        //Counting the Number of Words based on amount of spaces
        else if (text[i] == ' ')
        {
            word++;
        }

        //Counting the Number of sentences based on the possible endings
        else if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sent++;
        }
    }

    //Since both variables are integers, we need to float one to get a float result
    float L = (float) let / word * 100;
    float S = sent / (float) word * 100;

    //Round the function so that we can have the index of the expected grade values
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //creating grade values based on guide
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}
