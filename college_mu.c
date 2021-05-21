#include <stdio.h>
#include <string.h>
void welcome_screen();
void loading_animation();
void main(){
    loading_animation();
    login();
}
void login(){
    
    int e=5;
    char username[20];
    char password[20];
    char real_username[20]="heramb";
    char real_password[20]="4270";
    for(e=5;e>=0;e--){
    system("cls");
    welcome_screen();
    system("color 3C");
    printf("\n\n\t\t\t Enter UserName :- ");
    scanf("%s",username);
    printf("\n\n\t\t\t Enter Password :- ");
    scanf("%s",password);
       if(strcmp(username,real_username)==0  &&  strcmp(password,real_password)==0){
           printf("\n\n\n\n\t\t\t\t ........Login Successfull........");
           getch();
           break;
       }else{
           printf("\n\n\n\t\t\t Password Is Incorrect (Try Again) ");
           printf("\n\n\n\t\t\t\t\t Tries Remaining :-  %d (Press Any Key to Continue)",e);
           getch();
       }
    }
}
void welcome_screen(){
    system("color 0f");
    system("cls");
    printf("\n\n\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4 \n");
    printf("\t\4\t                                                   \t\4\n");
    printf("\t\4\t College Management Utility - version 0.0001 alpha \t\4\n");
    printf("\t\4\t                                                   \t\4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4 \n");
}
void loading_animation(){
    int i=0,a,j;
    system("color 0A");
    printf("\n\n\n\n\n\n\n\n\n\n\t\tLoading Please Wait ");
    for( i=0;i<=20;i++){
       for(j=0;j<=100000000;j++){
         a=j;
       }
    printf("%c",219);
    }
}
