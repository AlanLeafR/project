#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CreditCardNumberChecker();

int main(){
	
	printf("Wellcome to use Credit Card Number Validation Program\n");
	CreditCardNumberChecker();
	
    return 0 ;

}

void CreditCardNumberChecker(){
	
	printf("Please Enter Your Credit Card Number�G\n");
	
	char *CardNumber = (char*)malloc(sizeof(char)*17);
	scanf("%s",CardNumber);

	int length;		//�ˬd��J���d������// 
	length=strlen(CardNumber);

	if(length>16){
		printf("�H�Υd����J�W�L16��A�Э��s��J\n");	
	}else if(length<16){
		printf("�H�Υd����J����16��A�Э��s��J\n");
	}

	if(length==16){ //�p�G����16��h�~�����// 
	
		int i=0;	//�Nchar�ഫ��int(with ASCII)// 
		int *CardNumberChange = (int*)malloc(sizeof(int)*16);
		
		for(i;i<16;i++){
			CardNumberChange[i]=CardNumber[i]-'0';
		}
	
		if(CardNumberChange[0]==3){		//�T�{�d�O�OJCB�BVISA�٬OMasterCard// 
			printf("�z���H�Υd�O�GJCB\n");
		}else if(CardNumberChange[0]==4){
			printf("�z���H�Υd�O�GVISA\n");
		}else if(CardNumberChange[0]==5){
			printf("�z���H�Υd�O�GMasterCard\n"); 
		}else{
			printf("�d���������~�A�Э��s��J\n");
		}
	
	//�p�ⳡ�����ҥd��//
		
		if(CardNumberChange[0]==3 || CardNumberChange[0]==4 || CardNumberChange[0]==5){
		
			i=0;
			int d=0;
			
			for(i;i<16;i++){
				if(i%2==0){
				CardNumberChange[i]=CardNumberChange[i]*2;			
					}
				if(i%2==0 && CardNumberChange[i]>9){
				CardNumberChange[i]=CardNumberChange[i]-9;	
				}
				d+=CardNumberChange[i];
			}
			
			if(d%10==0){
				printf("�H�Υd�����T�AWellcome!\n");
			}else{
				printf("�d�����ҿ��~�A�Э��s��J\n");	
			}
		}
		free(CardNumberChange);
	}
	 
	free(CardNumber);

}

