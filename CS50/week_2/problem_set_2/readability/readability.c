#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// L = average number of letters per 100 words in the text
// S = average number of sentences per 100 words in the text

// count letters function
float letters(string text);

// count words function
float words(string text);

// count sentences function
float sentences(string text);

// Coleman-Liau index formula
int formula(float word, float letter, float sentence);



int main(void)
{
    //get user input
    string text = get_string("Text: ");
    //count words, letters, sentences
    float word = (words(text) + 1);
    float letter = letters(text);
    float sentence = sentences(text);
    // find the index using the formula
    int index = formula(word, letter, sentence);

    //define appropriate grade of text
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// count words function definition
float words(string text)
{
    float space = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 32)
        {
            space++;
        }
    }
    return space;
}

// count letters function definition
float letters(string text)
{
    float letter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter++;
        }
    }
    return letter;
}

// count sentences function definition
float sentences(string text)
{
    float sentence = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentence++;
        }
    }
    return sentence;
}

// Coleman-Liau index formula definition
int formula(float word, float letter, float sentence)
{
    double L = letter * 100 / word;
    double S = sentence * 100 / word;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int result = (round(index));
    return result;
}



