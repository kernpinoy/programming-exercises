#include <stdio.h>

int main()
{
    FILE *fp;
    char str[] = "Hi, I'm Kern!";

    fp = fopen("file.txt", "w");
    fwrite(str, 1, sizeof(str), fp);

    fclose(fp);

    return (0);
}