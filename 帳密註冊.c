#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <string.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8


struct user{
	char fullName[50];
	char email[50];
	char password[50];
	char username[50];
	char phone[50];

};

void takeinput(char ch[50]){
	fgets(ch,50,stdin);
	ch[strlen(ch)-1]=0;
}

void takepassword(char pwd[50]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if (ch == ENTER || ch == TAB){
			pwd[i]='\0';
			break;
		}else if(ch ==  BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++]=ch;
			printf("* \b");
		}
	}
}

char generateUsername(char email[50],char username[50]){
	int i;
	for ( i=0 ; i<strlen(email) ; i++){
		if(email[i] == '@') break;
		else{
			username[i] = email[i];
		}
	}
}

int main() {
	
	FILE *fp; 
	int opt,usrFound;
	struct user user;
	char password2[50];
	
	char username[50],pword[50];
	struct user usr;
	
	printf("\n\t\t\t\t-----Wellcome to Authentication System-----\n");	
	printf("\n請輸入您想進行的服務:\n");
	printf("1.註冊帳號\n");
	printf("2.登入帳號\n");
	printf("3.結束程式\n");
	
	printf("您的選擇：\t");
	scanf("%d",&opt);
	fgetc(stdin);
	
	switch(opt){
		
		case 1:
			printf("\n請輸入您的英文匿名:");
			takeinput(user.fullName);
			printf("\n請輸入您的email:");
			takeinput(user.email);
			printf("\n請輸入您的連絡電話:");
			takeinput(user.phone);
			printf("\n請輸入您的密碼:");
			takepassword(user.password);
			printf("\n\n請再次確認您的密碼:");
			takepassword(password2);
			
			if(!strcmp(user.password,password2)){
				generateUsername(user.email,user.username);
				fp = fopen("Users.dat","a+");
				fwrite(&user,sizeof(struct user),1,fp);
					if(fwrite !=0 )  {
					printf("\n\n註冊完成,您的帳號名稱是 %s",user.username);
					}
					else{
						printf("\n遇到未知錯誤，請重新註冊。");
					}	
				}
			else{
				printf("\n密碼驗證錯誤，請重新註冊。");
			}
			break;	
		
		
		case 2:
		
			printf("\n請輸入您的帳號名稱:");
			takeinput(username);
			printf("\n請輸入您的密碼:");
			takepassword(pword);
			
			fp = fopen("Users.dat","r");
			while(fread(&usr,sizeof(struct user),1,fp)){
				if(!strcmp(usr.username,username)){
					if(!strcmp(usr.password,pword)){
						printf("\n歡迎! %s",usr.fullName);
					}
					else{
						printf("\n密碼輸入錯誤!請重新登入!");
					}
				usrFound = 1;
				
				}
				
			}
			if(!usrFound){
				printf("\n使用者未註冊");
			}
			
						
			fclose(fp);
			break;
		
		case 3:
			printf("\n\t\t程式結束");
			return 0;
		
	}
			
	return 0;			
}

