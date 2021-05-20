#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <type.h>
#include <windows.h>
void loadinganimation();
void title();
void adminlogin();
int main()
{
    loadinganimation();
    system("cls");
    adminlogin();
}

void loadinganimation()
{
    int a, i, j;
    system("color 0A");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\Loading ");
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
    //system("pause");
    system("cls");
    printf("\n\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4 \n");
    printf("\t\4\t                                                   \t\4\n");
    printf("\t\4\tCollege Management Utility - version 0.0001 alpha \t\4\n");
    printf("\t\4\t                                                   \t\4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    printf("\n\n\n\n\t\t1. Option 1\n");
    printf("\t\t2. Option 2\n");
    printf("\t\t3. Option 3\n");
    printf("\t\t4. Option 4\n");
    printf("\t\t5. Option 5\n");
    system("pause");
}

void adminlogin()
{
    char username[20];
    char password[20];
    char rusername[20] = {"admin"};
    char rpassword[20] = {"admin"};
    L:
    title();
    printf("\n\n\t\tUsername: ");
    gets(username);
    printf("\n\t\tPassword: ");
    gets(password);

    if(strcmp(rusername, username)!=0 && strcmp(rpassword, password)!=0)
    {
        printf("Wrong Username Or Password, Please Try Again And\nInput Credentials Carefully.");
        system("pause");
        system("cls");
        goto L;
    }
    else if(strcmp(rusername, username)==0 && strcmp(rpassword, password)==0)
    {
        printf("Login Successful!.\n");
        //function for choise redirecting to a function by switch statement
    }
}
