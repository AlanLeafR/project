#include <stdio.h> 
int main(){
	
	/*²���I�\���B�p��t��*/ 
	
	int total,id;
	
	printf("�w����{�ɳ����A�H�U�O�ڭ̪������G\n\n");
	
	printf("1.�����ɳ�-90��\n");
	printf("2.���h�����ɳ�-120��\n");
	printf("3.�_�q�~��-70��\n");
	printf("4.���׺~��-70��\n");
	printf("5.�����ɳ�-70��\n\n");

	printf("�п�J�~���Ǹ��A��J0�}�l���b�C\n");

	do{
	scanf("%d",&id);
	
	switch(id){
		
		case 1:
			total+=90;
			printf("�ثe���B�O%d\n",total);
			break;
		
		case 2:
			total+=120;
			printf("�ثe���B�O%d\n",total);
			break;
		case 3:
		case 4:
		case 5:
			total+=70;
			printf("�ثe���B�O%d\n",total);
			break;
		case 0:
			break;
		default:
			printf("�L�o���ӫ~�A�ЦA��J�@���C\n");
			break;
		}
	}while(id!=0);
	
	printf("�`���B�O�G%d���A���±z���f�U�C\n",total);
return 0;
}

		
