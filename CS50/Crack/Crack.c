#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("please one hash at a time");
        return 1;
    }
    char charray[52];
    char a = 'a';
    char A = 'A';
    for (int i=0; i<26; i++)
    {
        charray[i] = a+i;
    }
    for (int i=26; i<52; i++)
    {
        charray[i] = A+(i-26);
    }

    char s[5] = "song";
    for (int i=0; i<52; i++)
    {
        s[0]=charray[i];
        s[1]=0;
        string hash = crypt(s, "50");
        if (strcmp(hash, argv[1]) == 0)
        {
            printf("pass = %s\n", s);
            return 0;
        }
    }

    for (int i=0; i<52; i++)
    {
        for (int j=0; j<52; j++)
        {
            s[0]=charray[i];
            s[1]=charray[j];
            s[2]=0;
            string hash = crypt(s, "50");
            if (strcmp(hash, argv[1]) == 0)
            {
                printf("pass = %s\n", s);
                return 0;
            }
        }
    }

    for (int i=0; i<52; i++)
    {
        for (int j=0; j<52; j++)
        {
            for (int l=0; l<52; l++)
            {
                s[0]=charray[i];
                s[1]=charray[j];
                s[2]=charray[l];
                s[3]=0;
                string hash = crypt(s, "50");
                if (strcmp(hash, argv[1]) == 0)
                {
                    printf("pass = %s\n", s);
                    return 0;
                }
            }
        }
    }

    for (int i=0; i<52; i++)
    {
        for (int j=0; j<52; j++)
        {
            for (int l=0; l<52; l++)
            {
                for (int m=0; m<52; m++)
                {
                    s[0]=charray[i];
                    s[1]=charray[j];
                    s[2]=charray[l];
                    s[3]=charray[m];
                    s[4]=0;
                    string hash = crypt(s, "50");
                    if (strcmp(hash, argv[1]) == 0)
                    {
                        printf("pass = %s\n", s);
                        return 0;
                    }
                }
            }
        }
    }
}
