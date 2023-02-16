#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    //prompt user to the phrase
    string text = get_string("Text: ");

    //create ints for letters, words and sentences
    int letters = 0;
    int words = 1; //initialize in 1 cuz we are counting spaces and in a sentence words = spaces + 1
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i])) // function in ctype to count letters
        {
            letters++;
        }
        else if (text[i] == ' ') //if you find a space count a word
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') // if you find a . ! ? count a sentence
        {
            sentences++;
        }
    }

    //function to get L and S
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    //function to get index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //print the grade in each case
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}


