#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *pF = fopen("data.txt", "r");
    if (pF == NULL)
    {
        fprintf(stderr, "Error opening data.txt");
        return 1;
    }

    // TODO: work with dynamic byte space
    unsigned long numbers[2500];
    int number_of_groups = 0;
    int current_number_index = 0;

    char buffer[10];
    while (fgets(buffer, 10, pF) != NULL)
    {
        unsigned long num;
        if (strlen(buffer) - 1 > 0)
        {
            char *ptr;
            num = strtol(buffer, &ptr, 10);
        }
        else
        {
            number_of_groups++;
            num = 0;
        }

        numbers[current_number_index] = num;
        current_number_index++;
    }

    current_number_index = 0;
    unsigned long highest = 0;
    for (int i = 0; i < number_of_groups; i++)
    {
        // This is where I fail:
        unsigned int sum = 0;
        while (numbers[current_number_index] != 0)
        {
            sum += numbers[current_number_index];
            current_number_index++;
        }
        if (sum > highest)
        {
            highest = sum;
        }
    }

    printf("The highest sum is: %lu", highest);
    fclose(pF);

    return 0;
}