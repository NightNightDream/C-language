/***********************************************

��Ʒ������ϵͳ

�������ڣ�2018/3/6   



���ֺ������� :



**************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>


#define SS sizeof(NODE)

void System_initilization(); //ϵͳ��ʼ�� 
void Posf(int ,int );  //�ƶ���� 
void Print_interface(); //��ӡ���� 
void Input(FILE* );// ¼������ 
void Delete(FILE* );
void Search(FILE* );
void Save(FILE* );
int Menu(FILE* );
void Print_date();
void Clear_area(int ,int , int ,int ); //���ָ������   ǰ����������ָ�����꣬����������Ҫ���λ�ô�С
FILE* Read_file();
FILE* Creat_file();
void Read_date(FILE *);
 
typedef struct node{
	int comNumber; //��Ʒ���
	char comName[20]; //��Ʒ���� 
	char comType[20]; //��Ʒ����
	char supplier_name[20]; //���������� 
	int purchasePrice; //��Ʒ����
	int sellPrice; //��Ʒ�ۼ� 
	int comQuantity; //��Ʒ����
	struct node *next;
}*PNODE,NODE; 

HANDLE hout;
PNODE head = NULL;
PNODE p2 = NULL;
FILE* system_fp; //�����û����� 
char fileName[16]; //ȫ�ֱ��� �����ļ���  һ��ʼ�ҵ��ļ���ȡ����   ��   �ڴ��溯�����ҵ������ļ������������е����ݸ����ļ� 


int main()
{
	FILE* fp;
	int t = 1;
	System_initilization();
	fp = Read_file();  //��ȡ�ļ��е����ݵ������� 
	/*Posf(40,20);
	printf("5����Զ�����˵�");
	Sleep(1000);
	Posf(40,20);
	printf("4����Զ�����˵�");
	Sleep(1000);
    Posf(40,20);
	printf("3����Զ�����˵�");
	Sleep(1000);
	Posf(40,20);
	printf("2����Զ�����˵�");
	Sleep(1000);*/
	Posf(40,20);
	printf("1����Զ�����˵�");
	Sleep(1000);
	while(1)
    {
     	t = Menu(fp);
     	if(t == 0)
     	break;
    }
	
	
	return 0;
}


void System_initilization()
{
	FILE* fp;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;  
    GetConsoleCursorInfo(hout, &CursorInfo);//��ȡ����̨�����Ϣ  
    CursorInfo.bVisible = false; //���ؿ���̨���  
    SetConsoleCursorInfo(hout, &CursorInfo);//���ÿ���̨���״̬
	system("mode con cols=100 lines=30");
	Print_interface();
	Posf(25,4);
	printf("/**************��Ʒ������ϵͳ**************/");
	Posf(36,8);
	printf("��ӭʹ����Ʒ������ϵͳ");
	Posf(45,13);
	printf("���ܽ��ܣ�");
	Posf(20,17);
	printf("���еĿ����Ʒ���ܰ���Ʒ��������ʾ�����ҡ����ӡ�ɾ�����޸�");
	
	
	
}

void Posf(int x,int y)  //�ƶ����λ�� 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,coord); 
	
}

void Print_interface()  //��ӡ��� 
{
	Posf(10,2);
	for(int i = 0; i < 39 ; i++)
	{
		printf("�D");
	}
	Posf(10,28);
	for(int i = 0; i < 39 ; i++)
	{
		printf("�D");
	}
	for(int i = 3; i < 28 ; i++)
	{
		Posf(10,i);
		printf("|");
	}
	for(int i = 3; i < 28 ; i++)
	{
		Posf(87,i);
		printf("|");
	}
}

void Input(FILE* fp)
{ 
	system("cls");
	Print_interface();
	/*
	FILE *fp;
	fp = fopen("myFile.txt","a+");*/
	
    char t;
    int n = 7;//����������
	int k = 1; // �ж��Ǹոս�������ϵͳ�� 
    
    //Back_to_menu();
    
	Posf(11 ,4);
	printf("�����ʽ��   ����    ����    ���    ����    �ۼ�    ����    ������"); 
	
	PNODE p1,p3;
	

    while(1)
    {
    	if(head == NULL) //����ļ�û��������headΪ��   �û���һ������ 
    	{
    		p1 = (PNODE)malloc(SS);
    		head = p1;
    		k++;
		}
		else if( k == 1) //�ж��ǵ�һ�ν�������ϵͳ��  ���������������ݵ��ϴε�����β 
		{
			Posf(11,++n);
			printf("�Ƿ�������룿");
		    t = getch();
		    if( t != 'y')
		    break;
			p1 = (PNODE)malloc(SS);
			Posf(11,++n);
		    printf("�����룺");
		    scanf("%s",p1->comType);
		    scanf("%s",p1->comName);            
		    scanf("%d",&p1->comNumber);
		    scanf("%d",&p1->purchasePrice);
		    scanf("%d",&p1->sellPrice);
		    scanf("%d",&p1->comQuantity);
		    scanf("%s",p1->supplier_name);
		    p2->next = p1;
		    k++;
		}
		
		p2 = p1;
		p1 = (PNODE)malloc(SS);
		Posf(11,++n);
		printf("�Ƿ�������룿");
		t = getch();
		if( t != 'y')
		break;
		Posf(11,++n);
		printf("�����룺");
		scanf("%s",p1->comType);
		scanf("%s",p1->comName);
		scanf("%d",&p1->comNumber);
		scanf("%d",&p1->purchasePrice);
		scanf("%d",&p1->sellPrice);
		scanf("%d",&p1->comQuantity);
		scanf("%s",p1->supplier_name);
		p2->next = p1;
	}
	p2->next = NULL;
	free(p1);
	
	return ; 
}
	

void Delete(FILE *fp)
{
	system("cls");
	Print_interface();
	//Back_to_menu(fp);
	fflush(stdin);//������뻺���� 
	
	
	PNODE p1, p2;
	int n, i = 6;
	Posf(18,++i);
	printf("��ֱ��������Ʒ���(������ĸ���˳�)��");
	
	while(scanf("%d",&n) != 0)
	{
		
	    for(p2 = head,p1 = head->next; p1 != NULL; p1 = p1->next)
	    {
		    if(p1->comNumber == n)
		    {
			    p2->next = p1->next;
				break;	
		    }
		p2 = p1;
	    }
	    Posf(18,++i);
	    printf("��ֱ��������Ʒ���(������ĸ���˳�)��");
	}
	
	Posf(40,20);
	printf("3����Զ����ز˵�");
	Sleep(1000);
	Posf(40,20);
	printf("2����Զ����ز˵�");
	Sleep(1000);
	Posf(40,20);
	printf("1����Զ����ز˵�");
	Sleep(1000);
	return ;
}

void Save(FILE* fp)
{
	system("cls");
	Print_interface();
	
	system("cls");
    Posf(40,7);
    if((fp = fopen(fileName,"w")) == NULL)
    {
		printf("�����ļ�ʧ�ܣ�");
		Sleep(1000);
		return ;
	}
	/*
	�����ļ� 
	*/
    PNODE p1;
    p1 = head->next;
    for(; p1 != NULL; p1 = p1->next)
    {
    	fwrite(p1,sizeof(NODE),1,fp);
	}
	fclose(fp);
	printf("�����ļ��ɹ���");
	Sleep(1000);
	
	return ;
}

void Search(FILE* fp)
{
	system("cls");
	Print_interface();
	
	Posf(12,5);
	Print_date();
	
	Posf(11,22);
	printf("----------------------------------------------------------------------------");
	Posf(24,23);
	printf("��[h]���۸�Ӹߵ���");
	Posf(52,23);
	printf("��[l]���۸�ӵ͵���");
	//getchar();
	Sleep(3000);
	return ;
	
	
}

int Menu(FILE* fp)
{
	system("cls"); //��ս��� 
	Print_interface();//��ӡ��� 
	fflush(stdin);//������뻺���� 
	
	Posf(44,6);
	printf("��q���˳���");
	char c;
	Posf(20,10);
	printf("1����[i]��������Ʒ¼��"); 
	Posf(55,10);
	printf("2����[s]��������Ʒ��ѯ");
	Posf(20,18);
	printf("3����[d]��������Ʒɾ��");
	Posf(55,18);
	printf("4����[b]����Ʒ���ݱ���");
	c = getch();
	switch(c)
	{
		case 'i':
			Input(fp);
			break;
		case 's':
			Search(fp);
			break;
		case 'd':
			Delete(fp);
			break;
		case 'b':
			Save(fp);
			break;
		default :
			return 0;  //0�����˳����� 
			
	}
    return 1; //���½���˵� 
}



void Clear_area(int x,int y,int len,int wid)
{
	for(int i = 0; i < wid; i++)
	{
		Posf(x,++y);
		for(int j = 0; j < len; j++)
		printf(" ");
	}
}


FILE* Read_file()
 {
 	FILE* fp;
 	char ch;
 	system_fp =fopen("systemFile.txt","a+");
 	fseek(system_fp,0L,SEEK_END);  
 	
 	
 	if(ftell(system_fp) == 0)
 	{
 		system("cls");
 		Posf(34,10);
 		printf("ϵͳδ��⵽�ļ����봴������ļ���"); 
 		Sleep(1500);
 		fp = Creat_file();
 		fclose(system_fp);
 		return fp;
	 }
	 else
	 {
	 	fseek(system_fp,0L,SEEK_SET);
	 	fscanf(system_fp,"%s",fileName);
	 	
	    if((fp = fopen(fileName,"a+")) == NULL)
	    {
	    	Posf(40,15);
	    	printf("���ļ�ʧ�ܣ�");
	    	Sleep(1500);
	    	return NULL;
		}
		else
		{
			Read_date(fp);
		}
	 }
	 fclose(system_fp);
	 return fp;
 }

FILE* Creat_file()
{
	FILE* fp;
    Posf(34,14);
    printf("�������ļ�����");
	Posf(48,13);
	printf("������������");
	Posf(48,15);
	printf("������������");
	Posf(46,14); 
	printf("��");
	Posf(54,14);
	printf("��");
	
	Posf(48,14);
    scanf("%s", fileName);
    strcat(fileName, ".txt");//���������ַ��� 
    if((fp = fopen(fileName, "a+")))
    {
    	Posf(40,18);
        printf("�����ļ��ɹ�!");
        fprintf(system_fp,"%s\n",fileName);
        return fp;
    }
}

void Print_date()
{
	PNODE p1,p2;
	Posf(14,5);
	printf("��Ʒ����   ��Ʒ����      ���    ����    �ۼ�    ����    ������");
	int n = 5;
	if(head == NULL || head->next == NULL)  //���ͷָ�����һ��Ϊ�գ�˵��û������ 
	{
	    printf("û�����ݴ��棡");
	    return;
	}
	for(p1 = head->next; p1 != NULL; p1 = p1->next)
	{
		Posf(14,++n);
		printf("%-10s%-10s\t%-8d%-8d%-8d%-8d%-10s",p1->comType,p1->comName,p1->comNumber,p1->purchasePrice,p1->sellPrice,p1->comQuantity,p1->supplier_name);
	}
}

void Read_date(FILE *fp)
{
	PNODE p1;
	if(feof(fp))
	{
		return ;
	}
	else
	{
		p1 = p2 = (PNODE)malloc(SS);
		head = p1;
		for(; feof(fp) == NULL;)
		{
			p2 = p1;
		    p1 = (PNODE)malloc(SS);
		    fread(p1,sizeof(NODE),1,fp);
		    p2->next  = p1;
		    
	    }
	}
	p2->next = NULL;
	free(p1);
}
/*
void Sort_price_HtoL()
{
	PNODE
}*/
