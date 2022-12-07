#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Types
typedef char player_name[25];

// Structs
struct Player
{
    player_name name;
    int score;
};

typedef struct
{
    char name[20];
    int age;
} User;

// Enums
enum Day
{
    Sun = 1,
    Mon = 2,
    Tue = 3,
    Wed = 4,
    Thu = 5,
    Fri = 6,
    Sat = 7
};

// Function prototype (ensures that functions are called with correct args)
void example_function(char[], int);

int main()
{
    short a = 3;              // 2 bytes (-32k - 32k) %d (short for "short int")
    unsigned short b = 4;     // 2 bytes (0 - 65k) %d
    int c = 1;                // 4 bytes (-2bil - 2bil) %d (short for "long int")
    unsigned int d = 2;       // 4 bytes (0 - 4bil) %u
    long long e = 5;          // 8 bytes (-9 quint - 9 quint) %lld
    unsigned long long f = 6; // 8 bytes (0 - 18 quint) %llu

    float g = 7.1;  // 4 bytes (32 precision bits, 6-7 sig digits) %f / %0.{digits}f
    double h = 8.1; // 9 bytes (64 precision bits, 15-16 sig digits) %lf / %0.{digits}lf

    char i = "i";     // 1 byte %c (can be used to store 1 byte numbers (and unsigned) as ASCII, ex: 120 === "x")
    char j[] = "jkl"; // array of chars %s

    bool k = true; // 1 byte (true or false) %d

    const float l = 3.14159; // constants

    float m = a / (float)b; // need to be careful with arithmetic

    /////////////////////////////////////////////////////////////////////////////

    for (int i = 1; i <= 10; i++)
    {
        // printf("Current index is %d\n", i);
    }

    int x = 0;
    while (x > 10)
    {
        x++;
        // printf("Current iteration is %d\n", x);
    }

    int y = 0;
    do
    {
        // printf("Do while loops always execute the code once, then check the condition");
    } while (y > 0);

    /////////////////////////////////////////////////////////////////////////////

    int num_array[] = {1, 2, 3, 4, 5};

    double array_with_size[2];
    array_with_size[0] = 1.1;
    array_with_size[1] = 2.2;
    // printf("Index 0 is %.2lf", array_with_size[0]);
    // printf("Size of array is %d bytes", sizeof(array_with_size));
    // printf("Length of array is %d elements", sizeof(array_with_size) / sizeof(array_with_size)[0]);

    int two_dimensional_array[2][1] = {{1, 2}, {1}};

    char array_of_strings[][20] = {"Array", "of", "strings"};
    strcpy(array_of_strings[0], "Reassigning element"); // Anytime you reassign a string you must use strcpy()

    /////////////////////////////////////////////////////////////////////////////

    struct Player player_1;
    strcpy(player_1.name, "Player 1");
    player_1.score = 0;

    struct Player player_2 = {"Player 2", 0};

    struct Player player_array[] = {player_1, player_2};

    User user_1 = {"User 1", 28};

    /////////////////////////////////////////////////////////////////////////////

    // Bitwise operators
    int q = 6;  //      6 = 00000110
    int r = 12; //     12 = 00001000
    int s = 0;

    s = q & r;  // add rows 00000100 = 4 (AND)
    s = q | r;  // add rows 00001110 = 14 (OR)
    s = q ^ r;  // add rows 00001010 = 10 (XOR) (only 1 side can be true, not both)
    s = q << 1; // left shift by 1 bit = 12 (multiply by 2)
    s = r >> 1; // right shift by 1 bit = 6 (divide by 2)

    /////////////////////////////////////////////////////////////////////////////
    // Memory = an array of bytes within RAM
    // Block = a single unit (byte) within memory, used to hold some value
    // Address = the address of a block within memory

    char one_memory_block = "x";
    short two_memory_blocks = 1;
    // printf("%p", &one_memory_block); // addresses are in hexadecimal

    // Pointers = a "variable-like" reference that holds a memory address to another value, array, etc.
    // * = indirection ("value at address") operator
    // Benefits of pointers:
    //  - less time in program execution
    //  - working on the original variables
    //  - with the help of pointers we can create data structures (linked-list, stack, queue)
    //  - returning multiple values from functions
    //  - searching and sorting large data very easily
    //  - dynamic memory allocation

    int variable_a = 1;
    int *pVariable_a = &variable_a;
    // printf("value at stored address: %d", *pVariable_a); // dereferencing

    /////////////////////////////////////////////////////////////////////////////
    // Files (w = write, r = read, a = append)
    if (remove("text.html") == 0)
    {
        printf("File deleted successfully");
    }

    FILE *pF = fopen("test.html", "w");

    fprintf(pF, "<html><head></head><body>TEST</body>");

    FILE *pF_append = fopen("test.html", "a");
    fprintf(pF_append, "</html>");

    FILE *pF_read = fopen("test.html", "r");
    char buffer[255]; // container to hold one line of our document, one line at a time
    while (fgets(buffer, 255, pF_read) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(pF);
    fclose(pF_append);
    fclose(pF_read);

    return 0;
}

// Function assignment
void example_function(char x[], int y)
{
    printf("x was passed as %s\n", x);
    printf("y was passed as %d", y);
}