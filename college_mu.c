#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void loadinganimation();
int main()
{
    loadinganimation();
    system("color 0f");
    system("cls");
    system("pause");
    system("cls");
    printf("\n\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4 \n");
    printf("\t\4\t                                                   \t\4\n");
    printf("\t\4\t College Management Utility - version 0.0001 alpha \t\4\n");
    printf("\t\4\t                                                   \t\4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    system("pause");
}

void loadinganimation()
{
    int a, i, j;
    system("color 0E");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\tLoading ");
    for (i = 0; i<=20; i++)
    {
        for (j = 0; j<10000000; j++)
        {
            a = j;
        }
            printf("%c", 219);
    }
    return 0;
}
