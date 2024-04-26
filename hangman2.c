// Program to play the Game
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//                      Hangman
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_GUESSES 6

void print_hangman(int num_wrong_guesses)
{
    switch (num_wrong_guesses)
    {
    case 0:
        printf("\n\n\n\n\n");
        break;
    case 1:
        printf("\n\n\n\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        break;
    case 2:
        printf("\n\n\n\n");
        printf(" |/\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        break;
    case 3:
        printf("\n\n\n\n");
        printf(" |/\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\\\n");
        break;
    case 4:
        printf("\n\n\n\n");
        printf(" |/\n");
        printf(" |\n");
        printf(" |-\n");
        printf(" |\\\n");
        break;
    case 5:
        printf("\n\n\n\n");
        printf(" |/\n");
        printf(" |\n");
        printf(" |-/\n");
        printf(" |\\\n");
        break;
    case 6:
        printf("\n\n\n\n");
        printf(" |/\n");
        printf(" |\n");
        printf(" |-/ \\ \n");
        printf(" |\\\n");
        break;
    }
}

int main()
{
    char word_list[][MAX_WORD_LENGTH] = {"apple", "banana", "orange", "grape", "watermelon", "pear", "pineapple", "strawberry", "kiwi", "peach"};
    int num_words = sizeof(word_list) / sizeof(word_list[0]);
    int random_index = rand() % num_words;
    char word[MAX_WORD_LENGTH + 1];
    strcpy(word, word_list[random_index]);
    int word_length = strlen(word);
    char hidden_word[MAX_WORD_LENGTH + 1];
    for (int i = 0; i < word_length; i++)
    {
        hidden_word[i] = '_';
    }
    hidden_word[word_length] = '\0';
    int num_wrong_guesses = 0;
    int num_guesses = 0;
    char guess;
    int already_guessed[MAX_GUESSES] = {0};
    srand(time(NULL));

    printf("Welcome to Hangman!\n");
    printf("The word has %d letters. You have %d guesses to get it right.\n", word_length, MAX_GUESSES);

    do
    {
        printf("\n\n%s\n", hidden_word);
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);
        int found = 0;
        for (int i = 0; i < word_length; i++)
        {
            if (word[i] == guess)
            {
                hidden_word[i] = guess;
                found = 1;
            }
        }
        if (!found)
        {
            printf("\nSorry, %c is not in the word.\n", guess);
            num_wrong_guesses++;
            print_hangman(num_wrong_guesses);
        }
        else
        {
            printf("\nGood guess!\n");
        }
        num_guesses++;
        already_guessed[guess - 'a'] = 1;
        // printf("
        printf("Letters already guessed: ");
        for (int i = 0; i < 26; i++)
        {
            if (already_guessed[i])
            {
                printf("%c ", 'a' + i);
            }
        }
        printf("\n");
    } while (num_wrong_guesses < MAX_GUESSES && strcmp(word, hidden_word) != 0);

    if (strcmp(word, hidden_word) == 0)
    {
        printf("\nCongratulations, you won!\n");
    }
    else
    {
        printf("\nSorry, you lost. The word was %s.\n", word);
        print_hangman(num_wrong_guesses);
    }
    return 0;
}
