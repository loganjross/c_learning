#include <stdio.h>
#include <string.h>

// Each line of the input (data.txt) is a random string.
// The halves of each string will contain a duplicate.
// Each duplicate is given a value, a-z = 1-26, A-Z = 27-52.
//
// Sum the total values of the duplicate items from each string.
// Answer: 8088
#define LOWERCASE_A 97
#define LOWERCASE_MODIFIER 96
#define UPPERCASE_MODIFIER 38

int char_to_int(char input)
{
  return (int)input < LOWERCASE_A ? (int)input - UPPERCASE_MODIFIER : (int)input - LOWERCASE_MODIFIER;
}

int search_for_duplicate(char *first_half, char *second_half, int half_length)
{
  for (int i = 0; i < half_length; i++)
  {
    for (int j = 0; j < half_length; j++)
    {
      if (first_half[i] == second_half[j])
      {
        return char_to_int(first_half[i]);
      }
    }
  }

  printf("No duplicates found: %s, %s\n\n", first_half, second_half);
}

int main()
{
  FILE *pF = fopen("data.txt", "r");
  if (pF == NULL)
  {
    fprintf(stderr, "Error opening data.txt");
    return 1;
  }

  int total_duplicate_value = 0;
  char buffer[100];
  while (fgets(buffer, 100, pF) != NULL)
  {
    int str_length = strlen(buffer);
    if (buffer[str_length - 1] == '\n')
    {
      buffer[str_length - 1] = 0;
      str_length--;
    }

    total_duplicate_value += search_for_duplicate(buffer, &buffer[str_length / 2], str_length / 2);
  }

  printf("The total duplicate value is: %d", total_duplicate_value);

  return 0;
}