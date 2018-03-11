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
void Input(); // ¼������ 
void Delete();
void Search();
void Addition();
void Menu();
void Back_to_menu();
void Clear_area(int ,int , int ,int ); //���ָ������   ǰ����������ָ�����꣬����������Ҫ���λ�ô�С 
void Creat_file();
 
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



int main()
{
	
	char t;
	System_initilization();
    t = getch();
    if(t == 'y')
	Menu();
	else
	exit(0);
}


void System_initilization()
{
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
	Posf(36,20);
	printf("�밴y����˵����������˳���");
	
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

void Input()
{
	system("cls");
	Print_interface();
	FILE *fp;
	fp = fopen("myFile.txt","a+");
	
    char t;
    int n = 7;//���������� 
    
    //Back_to_menu();
    
	Posf(11 ,4);
	printf("�����ʽ��   ����    ����    ���    ����    �ۼ�    ����    ������"); 
	
	PNODE p1,p2,p3;
	

    while(1)
    {
    	if(head == NULL)
    	{
    		p1 = (PNODE)malloc(SS);
    		head = p1;
		}
		else
		{
			p2->next = p1;
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
	}
	p2->next = NULL;
	free(p1);
	for(p3 = head->next; p3 != NULL; p3 = p3->next)
	fprintf(fp,"%16s%16s%16d%16d%16d%16d%16s\n",p3->comType,p3->comName,p3->comNumber,p3->purchasePrice,p3->sellPrice,p3->comQuantity,p3->supplier_name);
	fclose(fp);
	
	Menu();

	
        
}
	

void Delete()
{
	system("cls");
	Print_interface();
	Back_to_menu();
	
	PNODE p1, p2;
	int n, i = 6;
	Posf(18,++i);
	printf("��ֱ��������Ʒ���(������ĸ���˳�)��");
	
	while(scanf("%d",n) != 0)
	{
		
	    for(p1 = head->next; p1 != NULL; p1 = p1->next)
	    {
		    if(p1->comNumber == n)
		    {
			    if(p1 = head)
		        {
		        	head = head->next;
		        	break;   //ɾ�����˳�ѭ����ѯ���Ƿ����ɾ�� 
				} 
			    else
			    p2->next = p1->next;
				break;	
		    }
		p2 = p1;
	    }
	    Posf(18,++i);
	    printf("��ֱ��������Ʒ���(������ĸ���˳�)��");
	}
	
	Posf(38,15);
	printf("3����Զ����ز˵�");
	Sleep(1000);
	Posf(38,15);
	printf("2����Զ����ز˵�");
	Sleep(1000);
	Posf(38,15);
	printf("1����Զ����ز˵�");
	Sleep(1000);
	Menu();
}

void Addition()
{
	system("cls");
	Print_interface();
	
	
}

void Search()
{
	system("cls");
	Print_interface();
	
	
}

void Menu()
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
			Input();
			break;
		case 's':
			//Serach();
			break;
		case 'd':
			Delete();
			break;
		case 'a':
			//Addition();
			break;
		default :
			exit(0);
			
	}
    /*
	Posf(20,18);
	
	Posf(55,10);
	
	*/
}

void Back_to_menu()
{
	char t;
	Posf(20,3); 
	printf("�����ˣ��Ƿ�ֱ���˻ز˵��� ���������������y �˻ص��˵���");
	t = getch();
	if(t == 'y')
	{
	    Menu();
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
/*
void Creat_file()
{
	char filename[20];
    printf("�������ļ���:");
    scanf("%s", filename);
    strcat(filename, ".txt");//���������ַ��� 
    if((fp = fopen(filename, "w")))
    {
        printf("�����ļ��ɹ�\n"); 
    }
}*/
