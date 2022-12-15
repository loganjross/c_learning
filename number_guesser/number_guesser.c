#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define SLEEP_DURATION 2
#define GUESSES_PER_ROUND 5

int computer_hp = GUESSES_PER_ROUND;
int player_hp = GUESSES_PER_ROUND;
bool computer_is_guessing = false;

bool is_in_array(int val, int arr[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        if (arr[i] == val)
        {
            return true;
        }
    }

    return false;
}

void request_confirmation(bool *affected_value)
{
    char answer;
    scanf(" %c", &answer);
    *affected_value = answer == 'y';
    printf("\n");
}

int play_computer_round()
{
    printf("It's the computer's turn to guess. Think of a number between 1-%d...\n\n", GUESSES_PER_ROUND);
    sleep(SLEEP_DURATION);

    bool guessed_correctly = false;
    int numbers_guessed[GUESSES_PER_ROUND] = {0, 0, 0, 0, 0};
    int remaining_guesses = computer_hp;
    while (!guessed_correctly && remaining_guesses > 0)
    {
        int guess;
        while (is_in_array(guess, numbers_guessed, GUESSES_PER_ROUND))
        {
            guess = rand() % GUESSES_PER_ROUND + 1;
        }
        numbers_guessed[GUESSES_PER_ROUND - remaining_guesses] = guess;

        printf("Is your number %d? (y/n) ", guess);
        request_confirmation(&guessed_correctly);
        if (!guessed_correctly)
            remaining_guesses--;

        sleep(SLEEP_DURATION);
    }

    return remaining_guesses;
}

int play_player_round()
{
    printf("It's your turn to guess. The computer is generating a number between 1-%d...\n\n", GUESSES_PER_ROUND);
    sleep(SLEEP_DURATION);

    bool guessed_correctly = false;
    int number_to_guess = rand() % GUESSES_PER_ROUND;
    int remaining_guesses = player_hp;
    while (!guessed_correctly && remaining_guesses > 0)
    {
        remaining_guesses--;

        int guess;
        printf("Make a guess between 1-%d: ", GUESSES_PER_ROUND);
        scanf("%d", &guess);

        guessed_correctly = guess == number_to_guess;
        if (guessed_correctly)
        {
            printf("\nThat's right!\n\n");
        }
        else
        {
            printf("\nThat's wrong, guess again..\n\n");
            remaining_guesses--;
        }

        sleep(SLEEP_DURATION);
    }

    return remaining_guesses;
}

int play_round()
{
    int hp_damage = 0;
    if (computer_is_guessing)
    {
        hp_damage = GUESSES_PER_ROUND - play_computer_round();
    }
    else
    {
        hp_damage = GUESSES_PER_ROUND - play_player_round();
    }

    return hp_damage;
}

void play_intro()
{
    printf(".\n..\n...\n....\n.....\n......\n.......\n........\n.........\n..........");
    printf("\n\nWelcome to the number guessing game!\n\n");
    sleep(SLEEP_DURATION);

    bool player_knows_rules = false;
    printf("Do you know the rules? (y/n) ");
    request_confirmation(&player_knows_rules);
    if (player_knows_rules)
    {
        printf("Sweet, good luck!\n\n");
        sleep(SLEEP_DURATION);
        return;
    }

    printf("The rules of the game are simple, you and the computer each start with %d HP.\n\n", GUESSES_PER_ROUND);
    sleep(SLEEP_DURATION);
    printf("Each round, you and the computer take turns guessing the other's number (between 1-%d).\n\n", GUESSES_PER_ROUND);
    sleep(SLEEP_DURATION);
    printf("You get 5 guesses per round, and however many wrong guesses you give, you lose in HP!\n\n");
    sleep(SLEEP_DURATION);
    printf("Whoever runs out of HP first loses...\n\n");
    sleep(SLEEP_DURATION);

    bool player_is_ready = false;
    printf("Ready? (y/n) ");
    request_confirmation(&player_is_ready);
    if (player_is_ready)
    {
        printf("Sweet, good luck!\n\n");
        sleep(SLEEP_DURATION);
        return;
    }
    else
    {
        printf("No problem, let's start over..\n\n");
        sleep(SLEEP_DURATION);
        play_intro();
    }
}

int main()
{
    srand(time(NULL));
    play_intro();

    while (computer_hp > 0 && player_hp > 0)
    {
        computer_is_guessing = !computer_is_guessing;
        int hp_damage = play_round();
        if (computer_is_guessing)
        {
            computer_hp -= hp_damage;
        }
        else
        {
            player_hp -= hp_damage;
        }

        if (computer_hp > 0 && player_hp > 0)
        {
            printf("Good round, the computer has %d HP and you have %d HP...\n\n", computer_hp, player_hp);
            sleep(SLEEP_DURATION);
        }
    }

    int remaining_hp = computer_is_guessing ? player_hp : computer_hp;
    printf("Game over! %s won with %d HP remaining. %s\n\n",
           computer_is_guessing ? "you" : "the computer",
           remaining_hp,
           remaining_hp > 3 ? "Incredible!" : "Pretty cool.");

    bool play_again;
    printf("Play again? (y/n) ");
    request_confirmation(&play_again);
    if (play_again)
    {
        main();
    }

    return 0;
}