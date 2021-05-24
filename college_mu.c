#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#include <type.h>
#include <windows.h>


void loading_animation();
void title();
void admin_login();
void main_menu();

void add_rec();
void view_records();

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

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
    system("color 0F");

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
            system("cls");
            main_menu();
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

struct student
{
    int age;
    char Gender[2];
    char First_Name[20];
    char Last_Name[20];
    char Contact_no[15];
    char email[35];
    //char address[40];
    //char clas[15];
    unsigned int enr_num;
    char branch[20];
};
struct student p;

void main_menu()
{
    int choise;
    system("cls");
    //title();
    r:
        printf("\n\t-----------------------------------------------------------------\n");
        printf("\t\t                   Main Menu\n");
        printf("\t-----------------------------------------------------------------\n");
        printf("\n\t\t\t1. Add Records");
        printf("\n\t\t\t2. View Records");
        printf("\n\t\t\t3. Delete Record");
        printf("\n\t\t\t4. Edit Record");
        printf("\n\t\t\t5. Sort Records List");
        printf("\n\t\t\t6. Exit");

        printf("\n\n\t\t\tEnter The Option: ");
        scanf("%d", &choise);
        switch(choise)
        {
        case 1:
            add_rec();
            break;

        case 2:
            view_records();
            break;


        default:
            printf("\n\t\t\tInvalid Option!");
            getch();
            system("cls");
            goto r;
            break;
        }
}


void add_rec()
{
    FILE *data;
    data = fopen("studnt.dat", "a");
    int valid;
    char ans;
    system("cls");
//************************************First Name******************************************
    name:
        printf("\n\t-----------------------------------------------------------------\n");
        printf("\t\t                   Add Record\n");
        printf("\t-----------------------------------------------------------------\n");

        printf("\n\t\t\tFirst Name: ");
        scanf("%s", &p.First_Name);

        if(strlen(p.First_Name)>20 || strlen(p.First_Name)<2)
        {
            printf("\n\t\t\tPlease Enter Your first name minimum 3 characters \n\t\t\tOr Maximum 20 characters long");
            getch();
            system("cls");
            goto name;
        }
        else
        {
            for(int i = 0; i<strlen(p.First_Name); i++)
            {
                if(isalpha(p.First_Name[i]))
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }

            if(!valid)
            {
                printf("\n\t\t\tThe First Name Contains Invalid Characters (Numbers, Symbols, etc)\nPlease try Again.");
                system("cls");
                goto name;
            }
        }
        p.First_Name[0] = toupper(p.First_Name[0]);

//**********************************Last Name***************************************
    lastname:
        printf("\n\t\t\tLast Name: ");
        scanf("%s", &p.Last_Name);

        if (strlen(p.Last_Name)>20 || strlen(p.Last_Name)<2)
        {
            printf("\n\t\t\tPlease Enter Your last name minimum 3 characters \nOr Maximum 20 characters long");
            getch();
            system("cls");
            goto lastname;
        }
        else
        {
            for(int i = 0; i<strlen(p.Last_Name); i++) {
                if(isalpha(p.Last_Name[i]))
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }

            if(!valid)
            {
                printf("\n\t\t\tThe Last Name Contains Invalid Characters (Numbers, Symbols, etc)\nPlease try Again.");
                getch();
                system("cls");
                goto lastname;
            }
        }
        p.Last_Name[0] = toupper(p.Last_Name[0]);


//******************************Gender************************************************
    gender:
        printf("\n\t\t\tGender(M/F): ");
        scanf("%s", &p.Gender);
        p.Gender[0]= toupper(p.Gender[0]);

//******************************AGE************************************
    age:
        printf("\n\t\t\tAge: ");
        scanf("%d", &p.age);

        if(isalpha(p.age))
        {
            printf("\n\t Wrong Input Enter Again!!!");
        }

//***************************************Contact Number*********************************************
    contact:
        printf("\n\t\t\tContact Number: ");
        scanf("%s", &p.Contact_no);

        if(strlen(p.Contact_no)!=10)
        {
            printf("\n\t\t\tPlease Enter Atleast 10 digit for contact number");
            getch();
            system("cls");
            goto contact;
        }
        else if(strlen(p.Contact_no)==10)
        {
            for(int i = 0; i<strlen(p.Contact_no); i++)
            {
                if(!isalpha(p.Contact_no[i]))
                {
                    valid = 1;

                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (valid == 0)
            {
                printf("\n\t\t\tContact Number Contains Invalid Characters\nPlease Try Again");
                getch();
                system("cls");
                goto contact;
            }
        }

//*************************emali***********************************************
    email:
        printf("\n\t\t\tEmail ID: ");
        scanf("%s", &p.email);

        if(strlen(p.email)>35 || strlen(p.email)<8)
        {
            printf("\n\t Invalid The Maximum and Minimum Range Of Email is 35 & 8 (Enter Again)");
            goto email;
        }

//**************************branch**********************************************
    branch:
        printf("\n\t\t\tBranch: ");
        scanf("%s", &p.branch);

        if(strlen(p.branch)>20 || strlen(p.branch)<1)
        {
            printf("\n\t Invalid The Maximum and Minimum Range Of Branch is 20 & 0 (Enter Again)");
            p.branch[0] = toupper(p.branch[0]);
            getch();
            goto branch;
        }

//***************************Enrollment Number*****************************************

    Enrollment:
        printf("\n\t\t\tEnrollment Number: ");
        scanf("%u", &p.enr_num);

        if(isalpha(p.enr_num))
        {
            printf("\n\t\t\tPlease Enter Valid Number.\tTry Again");
            getch();
            goto Enrollment;
        }


        fprintf(data,"%s %s %s %d %s %s %s %u",p.First_Name, p.Last_Name, p.Gender, p.age, p.Contact_no, p.email, p.branch, p.enr_num );
        printf("\n\t\t\tInformation Filled Successfully!");
		fclose(data);
        getch();
        while(1)
        {
            printf("\n\t\tDo You Want To Add More Record?(Y/N): ");
            fflush(stdin);
            scanf("%c", &ans);
            switch(ans)
            {
            case 'y': case 'Y':
                system("cls");
                add_rec();
                break;

            case 'n': case 'N':
                system("pause");
                main_menu();
                break;

            default:
                printf("\n\t\t\tInvalid Input, Please Try Again.");
                break;

            }
        }
}

void view_records()
{
    int row;
    system("cls");
    printf("\n\t-----------------------------------------------------------------\n");
    printf("\t\t                   View Records\n");
    printf("\t-----------------------------------------------------------------\n");

    FILE *data;
    data = fopen("studnt.dat", "r");
    gotoxy(1, 10);
    printf("Name");

    gotoxy(20, 10);
    printf("Gender");

    gotoxy(32, 10);
    printf("Age");

    gotoxy(37, 10);
    printf("Contact Number");

    gotoxy(49, 10);
    printf("Email");

    gotoxy(64, 10);
    printf("Branch");

    gotoxy(88, 10);
    printf("Enrollment Number\n");
    printf("**********************************************************************************************************************\n");
    row = 17;
    while(fscanf(data, "%s %s %s %d %s %s %s %u", p.First_Name, p.Last_Name, p.Gender, p.age, p.Contact_no, p.email, p.branch, p.enr_num))
    {
        gotoxy(1, row);
        printf("%s %s", p.First_Name, p.Last_Name);
        gotoxy(20, row);
        printf("%s", p.Gender);
        gotoxy(32, row);
        printf("%d", p.age);
        gotoxy(37, row);
        printf("%s", p.Contact_no);
        gotoxy(49, row);
        printf("%s", p.email);
        gotoxy(64, row);
        printf("%s", p.branch);
        gotoxy(88, row);
        printf("%u", p.enr_num);
        row++;
    }
    fclose(data);
    printf("\n\t\t");
    system("pause");
    main_menu();
}
