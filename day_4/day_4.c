#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Each line of the input (data.txt) containts a pair of number ranges
// Some of these pairs overlap (ex: 1-5, 2-7) and some completely overlap (ex: 1-5, 2-4)
//
// Find the amount of pairs from the input that completely overlap
// Answer:
int main()
{
  FILE *pF = fopen("data.txt", "r");
  if (pF == NULL)
  {
    fprintf(stderr, "Error opening data.txt");
    return 1;
  }

  int total_overlaps = 0;
  char buffer[25];
  while (fgets(buffer, 25, pF) != NULL)
  {
    int range_values[4];
    int range_index = 0;
    // char *range = strtok(buffer, ",");
    // while (range != NULL)
    // {
    //   char *range = strtok(range, "-");
    //   while (range != NULL)
    //   {
    //     char *ptr;
    //     range_values[range_index] = strtol(range, &ptr, 10);
    //   }
    // }

    if (range_values[0] <= range_values[2] && range_values[1] >= range_values[3] || range_values[0] >= range_values[2] && range_values[1] <= range_values[3])
    {
      total_overlaps++;
    }
  }

  printf("Total number of overlaps is: %d", total_overlaps);

  return 0;
}