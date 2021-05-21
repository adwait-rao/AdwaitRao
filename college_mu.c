#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#include <type.h>
#include <windows.h>
void loading_animation();
void title();
void admin_login();
int main()
{
    loading_animation();
    system("cls");
    admin_login();
}

void loading_animation()
{
    int a, i, j;
    system("color 0A");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\tLoading Please Wait ");
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

void title()
{
    system("color 0f");
    system("cls");
    printf("\n\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4 \n");
    printf("\t\4\t                                                   \t\4\n");
    printf("\t\4\tCollege Management Utility - version 0.0001 alpha \t\4\n");
    printf("\t\4\t                                                   \t\4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
}

void admin_login()
{
    char username[20];
    char password[20];
    char rusername[20] = {"admin"};
    char rpassword[20] = {"admin"};
    title();
    system("color 71");

    for (int e = 4; e>=0; e--)
    {
        printf("\n\t-----------------------------------------------------------------\n");
        printf("\t\t                  Login Page\n");
        printf("\t-----------------------------------------------------------------\n");
        printf("\n\t\t\t Username: ");
        gets(username);
        printf("\n\t\t\t Password: ");
        gets(password);

        if(strcmp(username, rusername)==0 && strcmp(password, rpassword)==0)
        {
            printf("\n\n\t\t\t........Login Successfull........");
            getch();
        }
        else
        {
            printf("\n\t\t\tIncorrect Username Or Password\n\t\t\tPlease Try Again\n\n\t\t\t %d Attempt(s) Remaining", e);
            getch();
            system("cls");

        }
    }
    system("color 0c");
    printf("\n\n\t\tYou Have Used Maximum Number Of Attempts! Please Try Again Later");
    getch();
    exit(0);
}
