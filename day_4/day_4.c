#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Each line of the input (data.txt) containts a pair of number ranges
// Some of these pairs overlap (ex: 1-5, 2-7) and some completely overlap (ex: 1-5, 2-4)
//
// Find the amount of pairs from the input that completely overlap
// Answer: 547
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
    char ranges[2][10];
    int parsed_range_values[4];
    int parsed_range_iteration = 0;

    // First we split the input string into 2 range strings,
    // and track them in our 'ranges' array (ex: "1-5,3-4" => ["1-5", "3-4"])
    char *range = strtok(buffer, ",");
    strcpy(ranges[0], range);
    range = strtok(NULL, ",");
    strcpy(ranges[1], range);

    for (int i = 0; i < 2; i++)
    {
      // Then for each range, we split and parse the values
      // and track the in our 'parsed_range_values' array (ex: ["1-5", "3-4"] => [1, 5, 3, 4])
      char *range_value = strtok(ranges[i], "-");
      char *ptr;
      parsed_range_values[i + parsed_range_iteration] = strtol(range_value, &ptr, 10);
      range_value = strtok(NULL, "-");
      parsed_range_values[i + parsed_range_iteration + 1] = strtol(range_value, &ptr, 10);
      parsed_range_iteration++;
    }

    // Finally we check for complete outer or inner overlaps of the ranges, and increment total
    bool outer_overlap = parsed_range_values[0] <= parsed_range_values[2] &&
                         parsed_range_values[1] >= parsed_range_values[3];
    bool inner__overlap = parsed_range_values[0] >= parsed_range_values[2] &&
                          parsed_range_values[1] <= parsed_range_values[3];
    if (outer_overlap || inner__overlap)
    {
      total_overlaps++;
    }
  }

  printf("Total number of overlaps is: %d", total_overlaps);

  return 0;
}