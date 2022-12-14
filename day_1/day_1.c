#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sum each group of numbers in data.txt and find the highest sum.
//
// Answer: 74198
int main()
{
    FILE *pF = fopen("data.txt", "r");
    if (pF == NULL)
    {
        fprintf(stderr, "Error opening data.txt");
        return 1;
    }

    int current_total = 0;
    int highest_total = 0;
    char buffer[10];
    while (fgets(buffer, 10, pF) != NULL)
    {
        // If it's not an empty line, keep summing the current group
        if (strlen(buffer) > 1)
        {
            char *ptr;
            current_total += strtol(buffer, &ptr, 10);
        }
        // Otherwise, check if the total is our highest so far and reset the current group's total
        else
        {
            if (current_total > highest_total)
            {
                highest_total = current_total;
            }

            current_total = 0;
        }
    }

    printf("The highest total is: %d", highest_total);
    fclose(pF);

    return 0;
}