#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


bool key_int_check(string s);


int main(int argc, string argv[])
{
    if (argv[1] && key_int_check(argv[1]))
    {
        int key = atoi(argv[1]);
        if (argc == 2 && key > 0 )
        {
            string text = get_string("plaintext: ");
            int length = strlen(text);
            char chiper[length];
            printf("ciphertext: ");
            for (int i = 0; i < length; i++)                      // focusing only the encryption to lower and upper characters, checking for each character if it is one of those groups and does encryption.
            {
                if (isupper(text[i]))
                {
                    chiper[i]=((text[i]+key)-65)%26+65;
                }
                else if (islower(text[i]))
                {
                    chiper[i]=((text[i]+key)-97)%26+97;
                }
                else
                {
                    chiper[i]=text[i];
                }
                printf("%c", chiper[i]);
            }
            printf("\n");
            return 0;

        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}


bool key_int_check(string s)
{
    for(int i=0;i<strlen(s);i++)
    {
        char c = s[i];
        if(!isdigit(c))
        {
            return false;
        }
    }

return true;
}
