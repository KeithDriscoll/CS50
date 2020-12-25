#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool isNumber(char number[]);

int main(int argc, string argv[])
{
    // Check that a command line argument is valid
    if (argc != 2 || !(isNumber(argv[1])))
    {
        printf("You did not enter a valid key.\n");
        return 1;
    }

    int key = atoi(argv[1]);

    // Get string to cipher
    string p = get_string("plaintext: ");

    printf("ciphertext: ");

    for(int i=0; i < strlen(p); i++)
    {

        // Uppercase alpha
        if (isupper(p[i]))
        {
            printf("%c", 'A' + (p[i] - 'A' + key) % 26);
        }
        // Lowercase alpha
        else if (islower(p[i]))
        {
            printf("%c", 'a' + (p[i] - 'a' + key) % 26);
        }
        else
        // All other characters
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}

// Returns True if is number
bool isNumber(char number[])
{
    int i = 0;

    //check for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}
