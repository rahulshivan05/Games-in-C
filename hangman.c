#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_GUESSES 6

int main()
{
    char word[MAX_WORD_LENGTH + 1], guess[MAX_WORD_LENGTH + 1];
    int length, i, j, guessesLeft = MAX_GUESSES, lettersFound = 0;
    char usedLetters[MAX_GUESSES];
    int wordComplete = 0;

    printf("Welcome to Hangman!\n");
    printf("Enter a word to be guessed: ");
    scanf("%s", word);

    length = strlen(word);

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    while (guessesLeft > 0 && !wordComplete)
    {
        printf("\n\n");

        for (i = 0; i < length; i++)
        {
            if (guess[i])
            {
                printf("%c ", guess[i]);
            }
            else
            {
                printf("_ ");
            }
        }

        printf("\n\n");
        printf("Guess a letter: ");
        char letter;
        scanf(" %c", &letter);

        if (!isalpha(letter))
        {
            printf("Invalid input! Please enter a letter.\n");
            continue;
        }

        letter = tolower(letter);

        for (i = 0; i < length; i++)
        {
            if (word[i] == letter && !guess[i])
            {
                guess[i] = letter;
                lettersFound++;
            }
        }

        int letterUsed = 0;
        for (i = 0; i < MAX_GUESSES; i++)
        {
            if (usedLetters[i] == letter)
            {
                letterUsed = 1;
                break;
            }
        }

        if (letterUsed)
        {
            printf("You have already guessed the letter %c!\n", letter);
        }
        else if (lettersFound == 0)
        {
            printf("There are no %c's in the word.\n", letter);
            guessesLeft--;
            usedLetters[MAX_GUESSES - guessesLeft - 1] = letter;
        }
        else
        {
            printf("You found %d %c's!\n", lettersFound, letter);
            lettersFound = 0;
        }

        if (strcmp(word, guess) == 0)
        {
            printf("\nCongratulations, you guessed the word \"%s\"!\n", word);
            wordComplete = 1;
        }
        else if (guessesLeft == 0)
        {
            printf("\nYou ran out of guesses! The word was \"%s\".\n", word);
        }
        else
        {
            printf("You have %d guesses left.\n", guessesLeft);
        }
    }

    return 0;
}
