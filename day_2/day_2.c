#include <stdio.h>
#include <stdbool.h>

// In data.txt each line is a round of Rock Paper Scissors.
// Scoring is determined by a draw (+3) or a win (+6) combined with points
// based on which choice you made that round:
// A, X = Rock (+1 point for choosing)
// B, Y = Paper (+2 points for choosing)
// C, Z = Scissors (+3 points for choosing)
//
// Sum the total points from every round in the file.
// Answer: 12740
bool is_rock(char choice);
bool is_paper(char choice);
bool is_scissors(char choice);

bool is_win(char opponent, char choice);
bool is_draw(char opponent, char choice);

int get_choice_points(char choice);

int main()
{
  FILE *pF = fopen("data.txt", "r");
  if (pF == NULL)
  {
    fprintf(stderr, "Error opening data.txt");
    return 1;
  }

  char opponent = 0;
  int total_score = 0;
  char buffer[3];
  while (fgets(buffer, 3, pF) != NULL)
  {
    char choice = buffer[0];

    // If opponent is unset, we're on a new round and the current choice is the opponent's
    if (opponent == 0)
    {
      opponent = choice;
      continue;
    }
    // Otherwise, the current choice is the players and we should compare to the opponent
    else
    {
      if (is_draw(opponent, choice))
      {
        total_score += 3;
      }
      else if (is_win(opponent, choice))
      {
        total_score += 6;
      }

      total_score += get_choice_points(choice);
      opponent = 0;
    }
  }

  printf("Total score is: %d", total_score);
  fclose(pF);

  return 0;
}

bool is_rock(char choice)
{
  return choice == 'A' || choice == 'X';
}
bool is_paper(char choice)
{
  return choice == 'B' || choice == 'Y';
}
bool is_scissors(char choice)
{
  return choice == 'C' || choice == 'Z';
}

bool is_win(char opponent, char choice)
{
  return is_rock(choice) && is_scissors(opponent) ||
         is_paper(choice) && is_rock(opponent) ||
         is_scissors(choice) && is_paper(opponent);
}
bool is_draw(char opponent, char choice)
{
  return is_rock(choice) && is_rock(opponent) ||
         is_paper(choice) && is_paper(opponent) ||
         is_scissors(choice) && is_scissors(opponent);
}

int get_choice_points(char choice)
{
  switch (choice)
  {
  case 'X':
    return 1;
  case 'Y':
    return 2;
  case 'Z':
    return 3;
  default:
    printf("Invalid choice: %c", choice);
  }
}