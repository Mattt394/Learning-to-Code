// Implement a program that encrypts messages using Vigenère’s cipher

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void encode(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("Please input 1 argument.\n");
        return 1;
    }
    if (argc ==2)
    {
        int len_key = strlen(argv[1]);
        for (int i = 0; i<len_key; i++)
        {

            if (isalpha(argv[1][i]) == 0)
            {
                printf("whoops not alphaha\n");

                return 1;
            }

        }
    }
    //prompt for string
    printf("plaintext: ");
    string plaintext = get_string();

    printf("ciphertext: ");
    encode(plaintext, argv[1]);
    printf("\n");
    return 0;
}

void encode(string plaintext, string key)
{
    int len_p = strlen(plaintext);
    int len_k = strlen(key);
    char a = 'a';
    char A = 'A';
    int j = 0;
    for (int i=0; i<len_p; i++)
    {
        //check if it is alphabet char
        if (isalpha(plaintext[i]) == 0)
        {
            printf("%c", plaintext[i]);
        }
        else
        {
            //check if it is uppercase
            if (isupper(plaintext[i]) != 0)
            {
                printf("%c", (((plaintext[i]-A)+(tolower(key[j%len_k])-a))%26)+A);
                j++;
            }
            else //if lowercase
            {
                printf("%c", (((plaintext[i]-a)+(tolower(key[j%len_k])-a))%26)+a);
                j++;
            }
        }
    }
}
