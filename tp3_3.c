#include <stdio.h>
#include <string.h>
#define TAMA 5
int main()
{
    char buffer[50];
    int len, nombresTodos[TAMA];
    for (int i = 0; i < TAMA; i++)
    {
        printf("\nIngrese nombre N%d: ", i+1);
        gets(buffer);
        len = strlen(buffer) + 1;
        nombresTodos[i] = (char *)malloc(len * sizeof(char));
        strcat(buffer, "\0");
        strcpy(nombresTodos[i], buffer);
    }
    for (int j = 0; j < TAMA; j++)
    {
        printf("\n%d) %s", j+1, nombresTodos[j]);
        free(nombresTodos[j]);
    }
    return 0;
}