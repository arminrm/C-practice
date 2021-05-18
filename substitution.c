#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool userInput (int argc, char **argv);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (userInput(argc, argv) == false)
    {
        return 1;
    }

    char word[100];
    printf("plaintext:  ");
    fgets(word, 100, stdin);
    printf("ciphertext: ");

    for (int i = 0; i < strlen(word); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (*(*(argv + 1) + j) >= 65 && *(*(argv + 1) + j) <= 90 )
            {
                if (word[i] == j + 65)
                {
                    printf("%c", *(*(argv + 1) + j));
                    break;
                }
                else if (word[i] == j + 97)
                {
                    printf("%c", *(*(argv + 1) + j) + 32);
                    break;
                }
                else if (word[i] < 65)
                {
                    printf("%c", word[i]);
                    break;
                }
            }
            else if (*(*(argv + 1) + j) >= 97 && *(*(argv + 1) + j) <= 122 )
            {
                if (word[i] == j + 65)
                {
                    printf("%c", *(*(argv + 1) + j) - 32);
                    break;
                }
                else if (word[i] == j + 97)
                {
                    printf("%c", *(*(argv + 1) + j));
                    break;
                }
                else if (word[i] < 65)
                {
                    printf("%c", word[i]);
                    break;
                }
            }
        }
    }
}

bool userInput (int argc, char **argv)
{

    bool valid = true;
    for (int i = 0; i < 26; i++)
    {
        if (*(*(argv + 1) + i) < 65 || (*(*(argv + 1) + i) > 90 && *(*(argv + 1) + i) < 97))
        {
            if (i > 0 && *(*(argv + 1) + i) == 0)
            {
                printf("Key must contain 26 characters.\n");
                valid = false;
                break;
            }
            else
            {
                printf("Usage: ./substitution key\n");
                valid = false;
                break;
            }
        }
    }

    if (valid == true)
    {
        char common;
        for (int i = 0; i < 26; i++)
        {
            common = *(*(argv + 1) + i);
            for (int j = 0; j < 26; j++)
            {
                if (common == *(*(argv + 1) + i + 1))
                {
                    printf("Key must not contain repeated characters.\n");
                    valid = false;
                    break;
                }
            }
            if (valid == false)
            {
                break;
            }
        }
    }
    return valid;
}
