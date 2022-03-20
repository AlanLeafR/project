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
	printf("\n�п�J�z�Q�i�檺�A��:\n");
	printf("1.���U�b��\n");
	printf("2.�n�J�b��\n");
	printf("3.�����{��\n");
	
	printf("�z����ܡG\t");
	scanf("%d",&opt);
	fgetc(stdin);
	
	switch(opt){
		
		case 1:
			printf("\n�п�J�z���^��ΦW:");
			takeinput(user.fullName);
			printf("\n�п�J�z��email:");
			takeinput(user.email);
			printf("\n�п�J�z���s���q��:");
			takeinput(user.phone);
			printf("\n�п�J�z���K�X:");
			takepassword(user.password);
			printf("\n\n�ЦA���T�{�z���K�X:");
			takepassword(password2);
			
			if(!strcmp(user.password,password2)){
				generateUsername(user.email,user.username);
				fp = fopen("Users.dat","a+");
				fwrite(&user,sizeof(struct user),1,fp);
					if(fwrite !=0 )  {
					printf("\n\n���U����,�z���b���W�٬O %s",user.username);
					}
					else{
						printf("\n�J�쥼�����~�A�Э��s���U�C");
					}	
				}
			else{
				printf("\n�K�X���ҿ��~�A�Э��s���U�C");
			}
			break;	
		
		
		case 2:
		
			printf("\n�п�J�z���b���W��:");
			takeinput(username);
			printf("\n�п�J�z���K�X:");
			takepassword(pword);
			
			fp = fopen("Users.dat","r");
			while(fread(&usr,sizeof(struct user),1,fp)){
				if(!strcmp(usr.username,username)){
					if(!strcmp(usr.password,pword)){
						printf("\n�w��! %s",usr.fullName);
					}
					else{
						printf("\n�K�X��J���~!�Э��s�n�J!");
					}
				usrFound = 1;
				
				}
				
			}
			if(!usrFound){
				printf("\n�ϥΪ̥����U");
			}
			
						
			fclose(fp);
			break;
		
		case 3:
			printf("\n\t\t�{������");
			return 0;
		
	}
			
	return 0;			
}

