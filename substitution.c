#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
// conditions for key
    // only accepts single command-line arg
    if (argc != 2)
    {
        printf("Error.\n");
        return 1;
    }

    // define length of key string
    int la = strlen(argv[1]);

    // only accepts 26 characters
    if (la != 26)
    {
        printf("Error.\n");
        return 1;
    }

    for (int i = 0; i < la; i++)
    {
        // only accepts alphabets
        if (!isalpha(argv[1][i]))
        {
            printf("Error.\n");
            return 1;
        }
    }

    // each alphabet is unique
    for (int i = 0; i < la; i++)
    {
        for (int j = i + 1; j < la; j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
        {
            printf("Error.\n");
            return 1;
        }
        }
    }

// using cipher
    // prompt for "plaintext:  "
    string plain = get_string("plaintext:  ");
    // output "ciphertext: "
    printf("ciphertext: ");

    for (int i = 0, lp = strlen(plain); i < lp; i++)
    {
        // maintain uppercase
        if (isupper(plain[i]))
        {
            printf("%c", (toupper(argv[1][plain[i] - 'A'])));
        }
        // lowercase
        else if (islower(plain[i]))
        {
            printf("%c", (tolower(argv[1][plain[i] - 'a'])));
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}