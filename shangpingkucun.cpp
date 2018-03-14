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
void Addition(FILE* );
void Menu(FILE* );
void Back_to_menu(FILE*);
void Clear_area(int ,int , int ,int ); //���ָ������   ǰ����������ָ�����꣬����������Ҫ���λ�ô�С
FILE* Read_file();
FILE* Creat_file();
 
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
FILE* system_fp;



int main()
{
	system_fp = fopen("systemFile.txt","a+"); 
	FILE* fp;
	
	char t;
	System_initilization();
	fp = Read_file();
	Posf(40,20);
	printf("5����Զ����ز˵�");
	Sleep(1000);
	Posf(40,20);
	printf("4����Զ����ز˵�");
	Sleep(1000);
    Posf(40,20);
	printf("3����Զ����ز˵�");
	Sleep(1000);
	Posf(40,20);
	printf("2����Զ����ز˵�");
	Sleep(1000);
	Posf(40,20);
	printf("1����Զ����ز˵�");
	Sleep(1000);
	Menu(fp);
	exit(0);
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
	int k = 1, b = 2; // �ж��Ǹոս�������ϵͳ�� 
    
    //Back_to_menu();
    
	Posf(11 ,4);
	printf("�����ʽ��   ����    ����    ���    ����    �ۼ�    ����    ������"); 
	
	PNODE p1,p3;
	static PNODE p2;
	

    while(1)
    {
    	if(head == NULL)
    	{
    		p1 = (PNODE)malloc(SS);
    		head = p1;
    		k++;
    		b--;
		}
		else if( k == 1) //�ж��Ǹոս�������ϵͳ�� 
		{
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
	if (b == 2)//�Ƿ��ǵ�һ�ν������� 
	p3 = p2;
	else
	p3 = head->next;
	for(p3; p3 != NULL; p3 = p3->next)
	fprintf(fp,"%16s%16s%16d%16d%16d%16d%16s\n",p3->comType,p3->comName,p3->comNumber,p3->purchasePrice,p3->sellPrice,p3->comQuantity,p3->supplier_name);
	Menu(fp);
}
	

void Delete(FILE *fp)
{
	system("cls");
	Print_interface();
	Back_to_menu(fp);
	
	PNODE p1, p2;
	int n, i = 6;
	Posf(18,++i);
	printf("��ֱ��������Ʒ���(������ĸ���˳�)��");
	
	while(scanf("%d",n) != 0)
	{
		
	    for(p2 = head,p1 = head->next; p1->next != NULL; p1 = p1->next)
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
	Menu(fp);
}

void Addition(FILE* fp)
{
	system("cls");
	Print_interface();
	
	
}

void Search(FILE* fp)
{
	system("cls");
	Print_interface();
	
	
}

void Menu(FILE* fp)
{
	system("cls"); //��ս��� 
	Print_interface();//��ӡ��� 
	
	char c;
	Posf(20,10);
	printf("1����[i]��������Ʒ¼��"); 
	Posf(55,10);
	printf("2����[s]��������Ʒ��ѯ");
	Posf(20,18);
	printf("3����[d]��������Ʒɾ��");
	Posf(55,18);
	printf("4����[a]��������Ʒ���");
	c = getch();
	switch(c)
	{
		case 'i':
			Input(fp);
			break;
		case 's':
			//Serach(fp);
			break;
		case 'd':
			Delete(fp);
			break;
		case 'a':
			//Addition(fp);
			break;
		default :
			fclose(fp);
			exit(0);
			
	}
    /*
	Posf(20,18);
	
	Posf(55,10);
	
	*/
}

void Back_to_menu(FILE* fp)
{
	char t;
	Posf(20,3); 
	printf("�����ˣ��Ƿ�ֱ���˻ز˵��� ���������������y �˻ص��˵���");
	t = getch();
	if(t == 'y')
	{
	    Menu(fp);
    }
    Clear_area(20,3,56,1); //���������ʾ������ 
}

void Clear_area(int x,int y,int len,int wid)
{
	Posf(x,y);
	for(int i = 0; i < wid; i++)
	{
		for(int j = 0; j < len; j++)
		printf(" ");
	}
}


FILE* Read_file()
 {
 	FILE* fp;
 	char fileName[16];
 	system_fp =fopen("systemFile.txt","rw+");
 	fscanf(system_fp,"%s",fileName);
 	if((fp = fopen(fileName,"a+")) == NULL )
 	{
 		system("cls");
 		Posf(34,10);
 		printf("ϵͳδ��⵽�ļ����봴������ļ���"); 
 		Sleep(1500);
 		fp = Creat_file();
 		fclose(system_fp);
 		//fclose(fp);
 		return fp;
	 }
	 fclose(system_fp);
	 //fclose(fp);
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
	Posf(60,14);
	printf("��");
	char fileName[16];
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

