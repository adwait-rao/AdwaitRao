#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
void loading_animation();
void title();
void admin_login();
void main_menu();
void add_rec();
void search_rec();
void view_records();

void gotoxy(int x, int y)
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
    gotoxy(50, 17);
    printf("Loading Please Wait ");
    gotoxy(50, 19);
    for (i = 0; i <= 22; i++)
    {
        for (j = 0; j < 10000000; j++)
        {
            a = j;
        }
        printf("%c", 178);
    }
}

void title()
{
    system("color 0f");
    system("cls");
    printf("\n\n");
    printf("\t\t\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    printf("\t\t\t\4\t                                                  \t\4\n");
    printf("\t\t\t\4\t College Management Utility - version 0.0001 alpha \t\4\n");
    printf("\t\t\t\4\t                                                  \t\4\n");
    printf("\t\t\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
}

void admin_login()
{
    char username[20];
    char password[20];
    char rusername[20] = {"admin"};
    char rpassword[20] = {"admin"};
    title();
    system("color 79");
    int e;
    for (e = 4; e >= 0; e--)
    {
        printf("\n\t-----------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t                  Login Page\n");
        printf("\t-----------------------------------------------------------------------------------------------------\n");
        printf("\n\n\t\t\t USERNAME: ");
        gets(username);
        printf("\n\n\n\n\t\t\t PASSWORD: ");
        gets(password);

        if (strcmp(username, rusername) == 0 && strcmp(password, rpassword) == 0)
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
    char Enrollment[10];
    char department1[30];
};
struct student p;

void main_menu()
{
    int choise;
    system("cls");
    system("color 3E");
r:
    printf("\n\t\t\t-----------------------------------------------------------------\n");
    printf("\t\t\t\t                   Main Menu\n");
    printf("\t\t\t-----------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t1. Add Records");
    printf("\n\n\n\t\t\t\t\t2. View Records");
    printf("\n\n\n\t\t\t\t\t3. Search Record");
    printf("\n\n\n\t\t\t\t\t4. Exit");
    printf("\n\n\n\t\t\t\t Note :- PLease Veiw The Screen In a  Maximize Mode !!!!!!!!!");
    printf("\n\n\n\n\t\t\t\t\tEnter The Option: ");
    scanf("%d", &choise);
    switch (choise)
    {
    case 1:
        add_rec();
        break;

    case 2:
        view_records();
        break;

    case 3:
        search_rec();
        break;

    case 4:
        printf("\n\n\t\t\t\t\t Thanks You For Using Our Software !!!!!!!");
        getch();
        exit (0);   

    default:
        printf("\n\t\t\t\t\tInvalid Option!");
        getche();
        system("cls");
        goto r;
        break;
    }
}

void add_rec()
{
    system("color 5F");
    FILE *data;
    data = fopen("studnt.bin", "ab");
    int valid;
    char ans;
    system("cls");
    //*************First Name***************
name:
    printf("\n\t-----------------------------------------------------------------\n");
    printf("\t\t                   Add Record\n");
    printf("\t-----------------------------------------------------------------\n");

    printf("\n\t\t\tFirst Name: ");
    scanf("%s", &p.First_Name);

    if (strlen(p.First_Name) > 20 || strlen(p.First_Name) < 2)
    {
        printf("\n\t\t\tPlease Enter Your first name minimum 3 characters \n\t\t\tOr Maximum 20 characters long");
        getch();
        system("cls");
        goto name;
    }
    else

    {
        int i;
        for (i = 0; i < strlen(p.First_Name); i++)
        {
            if (isalpha(p.First_Name[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }

        if (!valid)
        {
            printf("\n\t\t\tThe First Name Contains Invalid Characters (Numbers, Symbols, etc)\nPlease try Again.");
            system("cls");
            goto name;
        }
    }
    p.First_Name[0] = toupper(p.First_Name[0]);

    //***********Last Name**************
lastname:
    printf("\n\n\t\t\tLast Name: ");
    scanf("%s", &p.Last_Name);
    int i;
    if (strlen(p.Last_Name) > 20 || strlen(p.Last_Name) < 2)
    {
        printf("\n\t\t\tPlease Enter Your last name minimum 3 characters \nOr Maximum 20 characters long");
        getch();
        system("cls");
        goto lastname;
    }
    else
    {
        for (i = 0; i < strlen(p.Last_Name); i++)
        {
            if (isalpha(p.Last_Name[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }

        if (!valid)
        {
            printf("\n\t\t\tThe Last Name Contains Invalid Characters (Numbers, Symbols, etc)\nPlease try Again.");
            getch();
            system("cls");
            goto lastname;
        }
    }
    p.Last_Name[0] = toupper(p.Last_Name[0]);

    //***********Gender*****************
gender:
    printf("\n\n\t\t\tGender(M/F): ");
    scanf("%s", &p.Gender);
    p.Gender[0] = toupper(p.Gender[0]);

    //***********AGE*************
age:
    printf("\n\n\t\t\tAge: ");
    scanf("%d", &p.age);

    if (isalpha(p.age))
    {
        printf("\n\t Wrong Input Enter Again!!!");
    }

    //**************Contact Number****************
contact:
    printf("\n\n\t\t\tContact Number: ");
    scanf("%s", &p.Contact_no);

    if (strlen(p.Contact_no) != 10)
    {
        printf("\n\t\t\tPlease Enter Atleast 10 digit for contact number");
        getch();
        system("cls");
        goto contact;
    }
    else if (strlen(p.Contact_no) == 10)
    {
        for (i = 0; i < strlen(p.Contact_no); i++)
        {
            if (!isalpha(p.Contact_no[i]))
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

    //********emali****************
email:
    printf("\n\n\t\t\tEmail ID: ");
    scanf("%s", &p.email);

    if (strlen(p.email) > 35 || strlen(p.email) < 8)
    {
        printf("\n\t Invalid The Maximum and Minimum Range Of Email is 35 & 8 (Enter Again)");
        goto email;
    }

    //**********Enrollment Number**************

enrollment:
    printf("\n\n\t\t\tEnrollment No: ");
    scanf("%s", &p.Enrollment);
    int b;
    if (strlen(p.Enrollment) == 10)
    {
        for (b = 0; b < strlen(p.Enrollment); b++)
        {
            if (!isalpha(p.Enrollment[0]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
            if (!valid)
            {
                printf("\n\t Enrollment NO Contains Invalid Character \t TRY AGAIN");
                getch();
                goto enrollment;
            }
        }
    }
    else
    {
        printf("\n\t Sorry Enrollment no No Must Contain 10 Numbers !!!!");
        getch();
        goto enrollment;
    }

    /// ************************************** Department ***********************************

department:
    printf("\n\n\t\t\t Department :- ");
    scanf("%s", &p.department1);
    p.department1[0] = toupper(p.department1[0]);
    char pp;
    noni:
    printf("\n\n\n \t\t\t  ARE YOU SURE YOU WANT TO ENTER THIS DETAILS [Y/N] :- ");
    pp = getche();
    if (pp == 'y' || pp == 'Y')
    {
        fwrite(&p, sizeof(struct student), 1, data);
        printf("\n\n\n\t\t\tInformation Filled Successfully!");
        fclose(data);
        getch();
    }
    else{
        if(pp == 'n'|| pp == 'N'){
              printf("\n\n\t\t\t Ok !!! Enter Information AGain\n\n");
              system("pause");
              add_rec();
        }else{
            printf("\n\n\t\t\t Please Enter Valid Charecter !!!!!");
            getch();
            goto noni;
        }
    }

    while (1)
    {
        printf("\n\n\n\t\tDo You Want To Add More Record?(Y/N): ");
        fflush(stdin);
        scanf("%c", &ans);
        switch (ans)
        {
        case 'y':
        case 'Y':
            system("cls");
            add_rec();
            break;

        case 'n':
        case 'N':
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
    system("color 7D");
    int row;
    system("cls");
    printf("\n\t------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t                                                           View Records\n");
    printf("\t-------------------------------------------------------------------------------------------------------------------------------------------\n");

    FILE *data;
    data = fopen("studnt.bin", "rb");
    gotoxy(1, 10);
    printf("Name");
    gotoxy(20, 10);
    printf("Gender");
    gotoxy(32, 10);
    printf("Age");
    gotoxy(45, 10);
    printf("Contact Number");
    gotoxy(79, 10);
    printf("Email");
    gotoxy(100, 10);
    printf("Enrollment");
    gotoxy(130, 10);
    printf("Department\n");
    printf("***********************************************************************************************************************************************\n");
    row = 13;
    //while(fscanf(data, "%s %s %s %d %s %s %s %u", p.First_Name, p.Last_Name, p.Gender, p.age, p.Contact_no, p.email, p.branch, p.enr_num))
    while (fread(&p, sizeof(struct student), 1, data))
    {
        gotoxy(1, row);
        printf("%s %s", p.First_Name, p.Last_Name);
        gotoxy(22, row);
        printf("%s", p.Gender);
        gotoxy(32, row);
        printf("%d", p.age);
        gotoxy(45, row);
        printf("%s", p.Contact_no);
        gotoxy(68, row);
        printf("%s", p.email);
        gotoxy(100, row);
        printf("%s", p.Enrollment);
        gotoxy(130, row);
        printf("%s", p.department1);
        row++;
        row++;
    }
    fclose(data);
    printf("\n\t\t");
    getch();
    main_menu();
}
void search_rec()
{   system("cls");
    title();
    char name[30];
    system("color F0");
    FILE *data;
    data = fopen("studnt.bin", "rb");
    printf("\n\n\n\t\t\t ******************* Search Student Record *******************\n\n");
    printf("\n\n\t\t\tEnter Student's First Name :- ");
    scanf("%s", name);
    fflush(stdin);  
	
    name[0] = toupper(name[0]);
    while (fread(&p, sizeof(struct student), 1, data))
    {
        if (strcmp(p.First_Name, name) == 0)
        {
            gotoxy(1, 20);
            printf("Name");
            gotoxy(20, 20);
            printf("Gender");
            gotoxy(32, 20);
            printf("Age");
            gotoxy(45, 20);
            printf("Contact Number");
            gotoxy(79, 20);
            printf("Email");
            gotoxy(100, 20);
            printf("Enrollment");
            gotoxy(130, 20);
            printf("Department\n");
            printf("***************************************************************************************************************************************\n");
            gotoxy(1, 24);
            printf("%s %s", p.First_Name, p.Last_Name);
            gotoxy(22, 24);
            printf("%s", p.Gender);
            gotoxy(32, 24);
            printf("%d", p.age);
            gotoxy(45, 24);
            printf("%s", p.Contact_no);
            gotoxy(68, 24);
            printf("%s", p.email);
            gotoxy(100, 24);
            printf("%s", p.Enrollment);
            gotoxy(130, 24);
            printf("%s", p.department1);
            printf("\n");
            break;
            
        }
    }
    if (strcmp(p.First_Name, name) != 0)
    {
    	system("cls");
    	title();
        gotoxy(15, 10);    
		system("color F0"); 
        printf("Record Not Found");
        getch();
    }
    fclose(data);
L:
    getch();
    char and;
    printf("\n\n\n\t\t Do You Want TO Veiw More[Y/N]? :- ");
    scanf("%c", &and);
    switch (and)
    {
    case 'y':
    case 'Y':
        system("cls");
        search_rec();
        break;

    case 'n':
    case 'N':
        system("pause");
        main_menu();
        break;

    default:
        printf("\n\t\t\tInvalid Input, Please Try Again.");
        break;
    }
}
