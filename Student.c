#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

void loading();
void newrec();
void delete();
void display();
void modify();
void search();

void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void clrscr()
{
	system("cls");
}

struct student
{
	char fname[20];
	char lname[20];
	int rollno;
	char sec[10];
	char regno[10];
}s;

int main()
{
	int op;
	loading();
	clrscr();

	while(1)
	{
		clrscr();
		printf("\n\t\t%c%c%c%c STUDENT MANAGEMENT PROGRAM %c%c%c%c\n\n\n", 178, 178, 178, 178, 178, 178, 178, 178);
		printf("\t1. Add Record\n");
		printf("\t2. View Record\n");
		printf("\t3. Delete Record\n");
		printf("\t4. Modify Record\n");
		printf("\t5. Search Record\n\n");
		printf("\t6. Exit\n\n");
		printf("\t ENTER YOUR CHOISE: ");
		scanf("%d", &op);

		switch(op)
		{
			case 1:
			clrscr();
			newrec();
			break;

			case 2:
			clrscr();
			display();
			break;

			case 3:
			clrscr();
			delete();
			break;

			case 4:
			clrscr();
			modify();
			break;
			
			case 5:
			clrscr();
			search();
			break;
			
			case 6:
			exit(0);
			break;
			
			default:
			printf("Enter Valid Option!\n");
			getch();
			break;
		}
		getch();
	}
	//return 0;
}

void loading()
{
	int i,j, a;
	gotoxy(10, 10);
	printf("\n\tLoading ");
	 for (i = 0; i <= 20; i++)
    {
        for (j = 0; j < 10000000; j++)
        {
            a = j;
        }
        printf("%c", 178);
    }
}

void newrec()
{
	FILE *fp;
	fp = fopen("student.bin", "ab+");
	if(fp==NULL)
	{
		printf("ERROR: FILE NOT FOUND\n");
	}
	printf("\n\t\t\%c%c%c%c Add NEW RECORD %c%c%c%c\n\n\n", 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\tFIRST NAME: ");
	scanf("%s", &s.fname);
	printf("\tLAST NAME: ");
	scanf("%s", &s.lname);
	fflush(stdin);
	printf("\tROLL NUMBER: ");
	scanf("%d", &s.rollno);
	printf("\tSECTION: ");
	scanf("%s", &s.sec);
	printf("\tREGISTER NO: ");
	scanf("%s", &s.regno);

	fwrite(&s, sizeof(s), 1, fp);

	printf("\n\t\tRECORD SAVED SUCCESSFULLY!\n");
	

	fclose(fp);
	clrscr();
	printf("\n\t\t\%c%c%c%c UPDATED RECORDS %c%c%c%c\n\n\n", 178, 178, 178, 178, 178, 178, 178, 178);
	display();
}

void display()
{
	FILE *fp;
	fp = fopen("student.bin", "rb");
	if(fp==NULL)
	{
		printf("ERROR: FILE NOT FOUND\n");
	}
	int row = 13;
	printf("\t\t\%c%c%c%c LISTED RECORDS %c%c%c%c\n\n\n", 178, 178, 178, 178, 178, 178, 178, 178);
		gotoxy(1, 10);
        printf("NAME");
        gotoxy(22, 10);
        printf("ROLL NO.");
        gotoxy(32, 10);
        printf("SECTION");
        gotoxy(45, 10);
        printf("REGISTER NO.\n");
        printf("____________________________________________________________");
	while(fread(&s, sizeof(s), 1, fp)==1)
	{
		gotoxy(1, row);
        printf("%s %s", &s.fname, &s.lname);
        gotoxy(22, row);
        printf("%d", s.rollno);
        gotoxy(32, row);
        printf("%s", s.sec);
        gotoxy(45, row);
        printf("%s", s.regno);
        row++;
	}

	fclose(fp);
	getch();
}

void delete()
{
	int roll, valid = 0;
	FILE *fp, *ft;
	fp = fopen("student.bin", "rb");
	ft = fopen("student1.bin", "ab+");
	if(fp==NULL)
	{
		printf("ERROR: FILE NOT FOUND");
		return;
	}
	printf("\n\t\t\%c%c%c%c PREVIOUS RECORDS %c%c%c%c\n\n\n", 178, 178, 178, 178, 178, 178, 178, 178);
	display();
	printf("\n\n\tENTER THE ROLL NO YOU WANT TO REMOVE: ");
	scanf("%d", &roll);
	while(fread(&s, sizeof(s), 1, fp)>0 && valid==0)
	{
		if(s.rollno==roll)
		{
			valid = 1;
			printf("\n\tRECORD DELETED SUCCESSFULLY!");
		}
		else
		{
			fwrite(&s, sizeof(s), 1, ft);
		}
	}
	if (valid == 0)
	{
		printf("\n\tNO RECORD FOUND!\n");
		getch();
		clrscr();
		main();
	}
	fclose(fp);
	fclose(ft);

	remove("student.bin");
	rename("student1.bin", "student.bin");
	printf("\t\tRECORD UPDATED SUCCESSFULLY\n");
	display();
}

void modify()
{
	int roll;
	int valid = 0;
	FILE *fp;
	fp = fopen("student.bin", "rb+");
	if(fp==NULL)
	{
		printf("ERROR: FILE NOT FOUND!");
	}
	display();
	printf("\n\t\tENTER THE ROLL NO. YOU WANT TO MODIFY: ");
	scanf("%d", &roll);
	
	while(fread(&s, sizeof(s), 1, fp)>0 && valid==0)
	{
		if(s.rollno==roll)
		{
			clrscr();
			valid = 1;
			gotoxy(1, 10);
        	printf("NAME");
        	gotoxy(22, 10);
        	printf("ROLL NO.");
        	gotoxy(32, 10);
        	printf("SECTION");
        	gotoxy(45, 10);
        	printf("REGISTER NO.\n");
        	printf("____________________________________________________________");
        	gotoxy(1, 13);
        	printf("%s %s", &s.fname, &s.lname);
        	gotoxy(22, 13);
        	printf("%d", s.rollno);
        	gotoxy(32, 13);
        	printf("%s", s.sec);
        	gotoxy(45, 13);
        	printf("%s\n\n", s.regno);
        	
        	printf("\n\tNEW FIRST NAME: ");
        	scanf("%s", s.fname);
        	printf("\n\tNEW LAST NAME: ");
        	scanf("%s", s.lname);
        	printf("\n\tNEW ROLL NO: ");
        	scanf("%d", &s.rollno);
        	fflush(stdin);
        	printf("\n\tNEW SECTION: ");
        	scanf("%s", s.sec);
        	printf("\n\tNEW REGISTER NUMBER: ");
        	scanf("%s", s.regno);
        	
        	fseek(fp,-(long)sizeof(s),1);
        	fwrite(&s,sizeof(s),1,fp);
        	printf("\n\tRECORD UPDATED SUCCESSFULLY!(CHECK VIEW RECORDS)");
		}
		else
		{
			printf("\nNO RECORD FOUND!\n");
		}
	}
	if(valid==0)
	{
		printf("\n\tOops! Something Went Wrong!");
	}
	fclose(fp);
}

void search()
{
	FILE *fp;
	fp = fopen("student.bin", "rb");
	if(fp == NULL)
	{
		printf("ERROR: FILE NOT FOUND!");
		return;
	}
	
	int valid = 0, rolln;
	printf("\n\tSEARCH BY ROLL NO:  ");
	scanf("%d", &rolln);
	while(fread(&s, sizeof(s), 1, fp)>0 && valid==0)
	{
		if(rolln == s.rollno)
		{
			valid = 1;
			clrscr();
			gotoxy(1, 10);
        	printf("NAME");
        	gotoxy(22, 10);
        	printf("ROLL NO.");
        	gotoxy(32, 10);
        	printf("SECTION");
        	gotoxy(45, 10);
        	printf("REGISTER NO.\n");
        	printf("____________________________________________________________");
        	gotoxy(1, 13);
        	printf("%s %s", &s.fname, &s.lname);
        	gotoxy(22, 13);
        	printf("%d", s.rollno);
        	gotoxy(32, 13);
        	printf("%s", s.sec);
        	gotoxy(45, 13);
        	printf("%s\n\n", s.regno);
		}
	}
}
