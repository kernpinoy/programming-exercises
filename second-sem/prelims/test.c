#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool key_valid(int n, char *text);

int main(int argc, char *argv[])
{
    char tmp_key[256]; strcpy(tmp_key, argv[1]);
    char plain[256];

    if (!key_valid(argc, tmp_key))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    printf("plaintext: ");
    fgets(plain, 256, stdin);
    plain[strcspn(plain, "\n")] = 0;

    return 0;
}

bool key_valid(int n, char *text)
{
    if (n != 2)
    {
        return false;
    }
    
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    
    return true;
}