#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct list{
	char name[20];
	int amount;
	float price;
}list[20];
int i=0;
void displaylist(void);
void inlist(void);
void outlist(void);
void menu (void);
int main(int argc, char *argv[]) {
	menu();
	while(1){
		char c=NULL;
		c=getchar();
	switch(c){
		case '1':displaylist();break;
		case '2':inlist();break;
		case '3':outlist();break;
		case '4': exit(0);
	}  
}
	return 0;
}
void displaylist (void)
{
	int a;
	printf("����		����		����/Ԫ\n");
	for(a=0;a<i;a++)
	{
		if (i==0) {
		printf("�б�Ϊ��\n");}
		else {
		printf("%s 	         %d		  %.2f\n",list[a].name,list[a].amount,list[a].price);}
	}
	menu();
}
void inlist ()
{
	FILE *fp;
	fp=fopen("list","a");
	printf("�������������\n");
	scanf("%s",&list[i].name);
	printf("������û����������\n");
	scanf("%d",&list[i].amount);
	printf("������û��ﵥ��\n");
	scanf("%f",&list[i].price);
	fwrite(&list[i],sizeof(struct list),1,fp);
	fclose(fp);
	i++;
	menu();
}
void outlist(void)
{
	FILE *fpf;
	fpf=fopen("list","r+");
	printf("��������Ҫ�����������\n");
	char namel[20];
	scanf("%s",namel);
	printf("��������Ҫ���������\n");
	int n;
	scanf("%d",&n);
	int d;
	for(d=0;fread(&list[d],sizeof(struct list),1,fpf)!=0;d++)
	{
		if(strcmp(namel,list[d].name)==0) list[d].amount=list[d].amount-n;
	}
	fclose(fpf);
	menu();
}
void menu (void)
{
	printf("�˵��� \n");
	printf("\t1.��ʾ����б�\n");
	printf("\t2.���\n");
	printf("\t3.����\n");
	printf("\t4.�˳�����\n");
}
