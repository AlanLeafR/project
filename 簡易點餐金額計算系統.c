#include <stdio.h> 
int main(){
	
	/*簡易點餐金額計算系統*/ 
	
	int total,id;
	
	printf("歡迎光臨蟹堡王，以下是我們的精選菜單：\n\n");
	
	printf("1.美味蟹堡-90元\n");
	printf("2.雙層美味蟹堡-120元\n");
	printf("3.起司漢堡-70元\n");
	printf("4.雞肉漢堡-70元\n");
	printf("5.魚排蟹堡-70元\n\n");

	printf("請輸入漢堡序號，輸入0開始結帳。\n");

	do{
	scanf("%d",&id);
	
	switch(id){
		
		case 1:
			total+=90;
			printf("目前金額是%d\n",total);
			break;
		
		case 2:
			total+=120;
			printf("目前金額是%d\n",total);
			break;
		case 3:
		case 4:
		case 5:
			total+=70;
			printf("目前金額是%d\n",total);
			break;
		case 0:
			break;
		default:
			printf("無這項商品，請再輸入一次。\n");
			break;
		}
	}while(id!=0);
	
	printf("總金額是：%d元，謝謝您的惠顧。\n",total);
return 0;
}

		
