#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[26]);

int main(void)
{
    char word1[26];
    char word2[26];
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int compute_score(char word[26])
{
    int points = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 65 && word[i] <= 90)
        {
            for (int j = 0; j < 26; j++)
            {
                if (j == word[i] - 65)
                {
                    points = points + POINTS[j];
                    break;
                }
            }
        }
        else if (word[i] >= 97 && word[i] <= 122)
        {
            for (int j = 0; j < 26; j++)
            {
                if (j == word[i] - 97)
                {
                    points = points + POINTS[j];
                    break;
                }
            }
        }
    }
    return points;
}
