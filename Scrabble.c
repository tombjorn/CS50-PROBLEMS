#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

// compare scores

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else

    {
        printf("Tie!\n");
    }

}

int compute_score(string word)
{
    //* difference between aski lower and upper > 26 so should be abele to check
    //*     if ascii between a<=z or A<=Z, -97 and -65 respectively

    // get length of word
    int length = strlen(word);

    int total = 0;

    char *arr[length];

    // for every character in string
    for (int i = 0; i < length; i++)
    {
        // convert to askii
        word[i] = toascii(word[i]);
    }
    //? can i put these two strings together in one?
    //figure out if upper or lower, then convert to point[index]
    // could have used isupper/islower but this seemed more satisfying, despite more stink!
    for (int j = 0; j < length; j++)
    {
        if (word[j] >= 97 && word[j] <= 122)
        {
            word[j] -= 97;
            total += POINTS[word[j]];
        }
        else if (word[j] >= 65 && word[j] <= 90)
        {
            word[j] -= 65;
            total += POINTS[word[j]];
        }
        else
        {
            word[j] = 0;
        }

    }

    return total;

}

