#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (void)
{
    char name[20];
    int age;
    double address;
    int contactNo;


    printf("Name:");
    fgets(name,20,stdin);
    printf ("\nAge:");
    scanf ("%d", &age);
    printf ("\nAddress:");
    scanf ("%lf", &address);
    printf ("\nContactNo:");
    scanf("%s", &contactNo);
}