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
	
	printf("Please Enter Your Credit Card Number：\n");
	
	char *CardNumber = (char*)malloc(sizeof(char)*17);
	scanf("%s",CardNumber);

	int length;		//檢查輸入的卡號長度// 
	length=strlen(CardNumber);

	if(length>16){
		printf("信用卡號輸入超過16位，請重新輸入\n");	
	}else if(length<16){
		printf("信用卡號輸入未滿16位，請重新輸入\n");
	}

	if(length==16){ //如果長度16位則繼續執行// 
	
		int i=0;	//將char轉換成int(with ASCII)// 
		int *CardNumberChange = (int*)malloc(sizeof(int)*16);
		
		for(i;i<16;i++){
			CardNumberChange[i]=CardNumber[i]-'0';
		}
	
		if(CardNumberChange[0]==3){		//確認卡別是JCB、VISA還是MasterCard// 
			printf("您的信用卡是：JCB\n");
		}else if(CardNumberChange[0]==4){
			printf("您的信用卡是：VISA\n");
		}else if(CardNumberChange[0]==5){
			printf("您的信用卡是：MasterCard\n"); 
		}else{
			printf("卡片種類錯誤，請重新輸入\n");
		}
	
	//計算部位檢證卡號//
		
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
				printf("信用卡號正確，Wellcome!\n");
			}else{
				printf("卡片驗證錯誤，請重新輸入\n");	
			}
		}
		free(CardNumberChange);
	}
	 
	free(CardNumber);

}

