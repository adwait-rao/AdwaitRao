#include <stdio.h>
#include <string.h>
#include <conio.h>
void title();
void add_rec();
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
struct student 
{
    int age;
    char Gender[2];
    char First_Name[20];
    char Last_Name[20];
    char Contact_no[15];
    char email[35];
    char address[40];
    int Rollno;
    char class[15];
    char branch[20];
};
struct student p,temp_c;
int b,valid,ok=0;
char ans;
int main(){
    system("cls");
    int choose;
    title();
    printf("\n\n\n\n\n\n\t\t\t 1. Add New Student Record \n");
    printf("\n\t\t\t 2. List Student Record \n");
    printf("\n\t\t\t 3. Search Student Record \n");
    printf("\n\t\t\t 4. Edit Student Record \n");
    printf("\n\t\t\t 5. Delete Student Record \n");
    printf("\n\t\t\t 6. Exit \n");
    printf("\n\n\n \n\t\t\t Choose From 1 to 6 :- ");
    scanf("%d",&choose);

    switch (choose)
    {
    case 1:
        add_rec(); 
        break;
    // case 2:
    //     func_list();
    //     break;
    // case 3:
    //     search_rec();
    //     break;        
    // case 4:
    //     edit_rec();
    //     break;
    // case 5:
    //     del_rec();
    //     break;
    case 6:
        system("cls");
        title();
        printf("\n\n\n\t\t\t Thanks For Visiting :) :)");
        getch();      
    default:
        printf("\t\t\tInvalid Entry Please Try Agian");
        getch();
    }
    
}
void add_rec(){
    // **************************************** First Name *********************************************************
    system("cls"); 
    char ans;
    FILE *fp;
    fp = fopen("college.dat","a");
    A:
    title();
    printf("\n\n\t\t\t!!!!!!!!!!!!!!! Add Student Record !!!!!!!!!!!!!!!\n\n");
    printf("\n\t\t\t Enter First Name :- ");
    gets(p.First_Name);
  
    if(strlen(p.First_Name)>20 || strlen(p.First_Name)<2){
        printf("\n\t Invalid \t Sorry The Maximum And Minimum Range Of First Name is 20 & 2 \t Try Again");
        getch(); 
        system("cls");
        goto A;
    }
    else{
        for(b =0;b<strlen(p.First_Name);b++){
            if(isalpha(p.First_Name[b])){
                valid=1;
            }else{
                valid=0;
                break;
            }
        }
        if(!valid){
            printf("\n\t The First Name Contains Invalid Characters (Numbers,Symbols,etc) (Enter Again)");
            getch();
            system("cls");
            goto A;
        }
    }
      p.First_Name[0] = toupper(p.First_Name[0]);
    // **************************************** Last Name *****************************************************

    B:
    printf("\n\t\t\t Enter Last Name :- ");
    gets(p.Last_Name);
    p.Last_Name[0] = toupper(p.Last_Name[0]);
    if(strlen(p.Last_Name)>20 || strlen(p.Last_Name)<2){
        printf("\n\t Invalid  Sorry The Maximum And Minimum Range Of Last Name is 20 & 2 \t Try Again");
        getch();
        goto B;
    }else{
        for(b=0;b<strlen(p.Last_Name);b++){
            if(isalpha(p.Last_Name[b])){
                valid =1;
            }else{
                valid =0;
                break;
            }
        }if(!valid){
            printf("\n\t The Last Name Contains Invalid Characters (Numbers,Symbols,etc) (Enter Again)");
            goto B;
        }
    }

    //***************************************************** Gender **********************************************

        printf("\n\t\t\tGender[M/F] :- "); 
        gets(p.Gender);
        p.Gender[0] = toupper(p.Gender[0]);
     
    //**************************************************************** AGE *************************************************************
    
    printf("\n\t\t\t Age :- ");
    scanf("%d",&p.age);
    if(isalpha(p.age)){
        printf("\n\t Wrong Input Enter Again!!!");
    }
     //*************************************************************** ADDRESS *************************************************************

    C:
    printf("\n\t\t\t Address :- ");
    gets(p.address);
      if(strlen(p.address)>40 || strlen(p.address)<2){
        printf("\n\t Invalid \t Sorry The Maximum And Minimum Range Of Address is 40 & 2 \t Try Again");
        getch();
        goto C;
    }
    p.address[0] = toupper(p.address[0]);
  

    //*****************************************************************Contact NO**************************************************

    D:
    printf("\n\t\t\t Contact NO :- ");
    gets(p.Contact_no);

    if(strlen(p.Contact_no)==10){
        for(b=0;b<strlen(p.Contact_no);b++){
            if(!isalpha(p.Contact_no[0])){
                valid=1;
            }else{
                valid =0;
                break;
            }if(!valid){
                printf("\n\t Contact NO Contains Invalid Character \t TRY AGAIN");
                getch();
                goto D;
            }
        }
    }else{
        printf("\n\t Sorry Contact No Must Contain 10 Numbers !!!!"); getch(); goto D;
    }

    //*********************************** Email ***********************************************************

    E:
    printf("\n\t\t\t Email :- ");
    gets(p.email);
    if(strlen(p.email)>35 || strlen(p.email)<8){
        printf("\n\t Invalid The Maximum and Minimum Range Of Email is 35 & 8 (Enter Again)"); goto E;
    }

    //********************************ROLL NO****************************************************************
    F:
    printf("\n\t\t\t Roll No :- ");
    scanf("%d",&p.Rollno);
        if(isalpha(p.Rollno)){
           printf("\n\t ERROR :- Roll number Cannot be a Alphabet or Symbol");
           getch(); 
           goto F;
    }
    

    //********************************CLASS**********************************************************************

    G:
    printf("\n\t\t\t Class (first year) :- ");
    gets(p.class);
    p.class[0] = toupper(p.class[0]);
    if(strlen(p.class)>20 || strlen(p.class)<0){
        printf("\n\t Invalid The Maximum and Minimum Range Of Class is 20 & 0 (Enter Again)"); 
        goto G;
    }


    //*************************************Branch********************************************************************

    H:
    printf("\n\t\t\t Branch :- ");
    gets(p.branch);
    if(strlen(p.branch)>20 || strlen(p.branch)<1){
        printf("\n\t Invalid The Maximum and Minimum Range Of Branch is 20 & 0 (Enter Again)"); 
        goto H;
    }
    p.branch[0] = toupper(p.branch[0]);
    fprintf(fp,"%s %s %s %d %s %s %s %d %s %s",p.First_Name, p.Last_Name, p.Gender, p.age, p.address, p.Contact_no, p.email, p.Rollno , p.class, p.branch);
    printf("\n\n\t\t\t Information Filled Successfully !!!!!!!");
    fclose(fp);
    sd:
    printf("\n\t\t\t Do You Want to Add More Info [Y/N] :- ");
    scanf("%c",&ans);
    if(toupper(ans)=='Y'){
        add_rec();
    }else if(toupper(ans)=='N'){
        printf("\n\t\t\t Thank You SO Much For Using This Software !!!!!!!!!!");
        getch();
        main();
    }else{
        printf("\n\t\t\t Invalid Input !!!!!!!!!!\n");
        goto sd;
    }
}
