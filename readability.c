#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int letters; int sentences;

int words = 1;



int main(void)
{

    string text = get_string("Text:");
    for (int i = 0; i <= strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            letters ++;
        }
        if(isspace(text[i]))
        {    
            words ++;
        }
        if(text[i]== '.' ||text[i]== '!'||text[i]== '?' )
        {
            sentences ++;
        }
    }


float L = (letters *100.0f) / words;
float S = (sentences *100.0f) / words;
int index = round(0.0588 * L - 0.296 * S - 15.8);
if (index <1){
    printf("Before Grade 1\n");
    
}
else if (index >16){
    printf("Grade 16+\n");
}
else
{
    printf("Grade %i\n",index);
}
}
