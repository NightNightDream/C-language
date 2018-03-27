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
void Sort_price_HtoL();
void Sort_price_LtoH();
void Sort_number_LtoH();
void Save(FILE* );
int Menu(FILE* );
void Print_date();  //��ӡ���� 
void Clear_area(int ,int , int ,int ); //���ָ������   ǰ����������ָ�����꣬����������Ҫ���λ�ô�С
FILE* Read_file(); //��ȡ�ļ� 
FILE* Creat_file();
void Read_date(FILE *);  //��ȡ�ļ����� 
void Modify(FILE *);  //�޸���Ʒ���� 
void Change_cursor(int );  //�ı���״̬ 
void Color(int ); //�ı�������ɫ 
void Clear_file(FILE*); //����ļ����� 

typedef struct node{
	int comNumber; //��Ʒ���
	char comName[20]; //��Ʒ���� 
	char comType[20]; //��Ʒ����
	char supplier_name[20]; //���������� 
	float purchasePrice; //��Ʒ����
	float sellPrice; //��Ʒ�ۼ� 
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
	Color(12);//�ı�����Ϊ����ɫ 
	Posf(40,20);
	/*printf("5����Զ�����˵�");
	Sleep(1000);
	Posf(40,20);
	printf("4����Զ�����˵�");
	Sleep(1000);
    Posf(40,20);
	printf("3����Զ�����˵�");
	Sleep(1000);
	Posf(40,20);
	printf("2����Զ�����˵�");
	Sleep(1000);
	Posf(40,20);*/
	printf("1����Զ�����˵�");
	Sleep(1000);
	while(1)
    {
     	t = Menu(fp);
     	if(t == 0)
     	break;
    }
	
	Color(80);
	return 0;
}

void Change_cursor(int k)
{
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;  
        GetConsoleCursorInfo(hout, &CursorInfo);//��ȡ����̨�����Ϣ 
	if(k == 1) 
        {
        	CursorInfo.bVisible = true; //��ʾ����̨���  
	}
	else
	{
		CursorInfo.bVisible = false; //���ؿ���̨���  
	}
        SetConsoleCursorInfo(hout, &CursorInfo);//���ÿ���̨���״̬
}

void System_initilization()
{
	FILE* fp;
	Change_cursor(0);
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
	Posf(42,25);
	Color(13);
	printf("�����ˣ�����");
	
	
	
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
	Color(2);
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
	Color(7);
}

void Input(FILE* fp)
{ 
	system("cls");
	Print_interface();
	Change_cursor(1);
	
    char t;
    int n = 7;//����������
	int k = 1; // �ж��Ǹոս�������ϵͳ�� 
    
    
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
			printf("�Ƿ�������룿(y������n�˳�)");
		    t = getch();
		    if( t == 'n')
		    return;
		    p1 = (PNODE)malloc(SS);
		    Posf(11,++n);
		    printf("�����룺");
		    scanf("%s",p1->comType);
		    scanf("%s",p1->comName);            
		    scanf("%d",&p1->comNumber);
		    scanf("%f",&p1->purchasePrice);
		    scanf("%f",&p1->sellPrice);
		    scanf("%d",&p1->comQuantity);
		    scanf("%s",p1->supplier_name);
		    p2->next = p1;
		    k++;
		}
		
		p2 = p1;
		p1 = (PNODE)malloc(SS);
		Posf(11,++n);
		printf("�Ƿ�������룿(y������n�˳�)");
		t = getch();
		if( t == 'n')
		break;
		Posf(11,++n);
		printf("�����룺");
		scanf("%s",p1->comType);
		scanf("%s",p1->comName);
		scanf("%d",&p1->comNumber);
		scanf("%f",&p1->purchasePrice);
		scanf("%f",&p1->sellPrice);
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
	Change_cursor(1);
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
    	fwrite(p1,SS,1,fp);
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
	Color(10);
	fflush(stdin);
	
	
	
	
	char flag;
	Posf(42,3);
	printf("��e���˳���");
	Posf(11,22);
	printf("----------------------------------------------------------------------------");
	Color(14);
	Posf(24,23);
	printf("��[h]���۸�Ӹߵ���");
	Posf(52,23);
	printf("��[l]���۸�ӵ͵���");
	Posf(24,25);
	printf("��[n]����Ŵӵ͵���");
	Color(10);
	Print_date();
	while(1)
	{
		flag = getch();
	    switch(flag)
	    {
		    case 'h':
			    Sort_price_HtoL();
			    break;
		    case 'l':
			    Sort_price_LtoH();
			    break;
		    case 'n':
			    Sort_number_LtoH();
			    break;	
		    default :
			    return ;
	    }
	    Print_date();
    }
	return ;
	
	
}

int Menu(FILE* fp)
{
	system("cls"); //��ս��� 
	Print_interface();//��ӡ���
	Change_cursor(0); 
	
	fflush(stdin);//������뻺���� 
	
	Posf(44,4);
	Color(15);//����ĳ�����ɫ 
	printf("��e���˳���");
	char c;
	Color(14); //����ĳɻ�ɫ 
	Posf(20,8);
	printf("1����[i]��������Ʒ¼��"); 
	Posf(55,8);
	printf("2����[s]��������Ʒ��ѯ");
	Posf(20,16);
	printf("3����[d]��������Ʒɾ��");
	Posf(55,16);
	printf("4����[b]����Ʒ���ݱ���");
	Posf(20,24);
	printf("5����[m]����Ʒ�����޸�"); 
	Posf(55,24);
	printf("6����[q]������ļ�����");
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
		case 'm':
			Modify(fp);
			break;
		case 'q':
			//Clear_file(fp);
			return 0;
		default :
			return 0;  //0�����˳����� 
			
	}
	Color(7);
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
	Posf(60,14);
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
		Posf(42,10);
	        printf("û�����ݴ��棡");
	        return;
	}
	for(p1 = head->next; p1 != NULL; p1 = p1->next)
	{
		Posf(14,++n);
		printf("%-11s%-14s%-8d%-8.2f%-8.2f%-8d%-10s",p1->comType,p1->comName,p1->comNumber,p1->purchasePrice,p1->sellPrice,p1->comQuantity,p1->supplier_name);
	}
}

void Read_date(FILE *fp)
{
	PNODE p1;
	if(feof(fp))
	{
		return ;  //�ļ�Ϊ��ֱ�ӽ��� 
	}
	else
	{
		p1 = p2 = (PNODE)malloc(SS);
		head = p1;
		for(; feof(fp) == NULL;)
		{
			p2 = p1;
		    p1 = (PNODE)malloc(SS);
		    fread(p1,SS,1,fp);
		    p2->next  = p1;
		    
	    }
	}
	p2->next = NULL;
	free(p1);
}

void Sort_price_HtoL()
{
	PNODE p,p1,p3,endp;
	for(endp = NULL; endp != head; endp = p)
	{
		for(p = p1 = head; p1->next->next != endp; p1 = p1->next)
		{
			if(p1->next->purchasePrice < p1->next->next->purchasePrice)
			{
				p3 = p1->next->next;
				p1->next->next = p3->next;
				p3->next = p1->next;
				p1->next = p3;
				p = p1->next->next;
			}
		}
	}
}

void Sort_price_LtoH()
{
	PNODE p,p1,p3,endp;
	for(endp = NULL; endp != head; endp = p)
	{
		for(p = p1 = head; p1->next->next != endp; p1 = p1->next)
		{
			if(p1->next->purchasePrice > p1->next->next->purchasePrice)
			{
				p3 = p1->next->next;
				p1->next->next = p3->next;
				p3->next = p1->next;
				p1->next = p3;
				p = p1->next->next;
			}
		}
	}
}

void Sort_number_LtoH()
{
	PNODE p,p1,p3,endp;
	for(endp = NULL; endp != head; endp = p)
	{
		for(p = p1 = head; p1->next->next != endp; p1 = p1->next)
		{
			if(p1->next->comNumber > p1->next->next->comNumber)
			{
				p3 = p1->next->next;
				p1->next->next = p3->next;
				p3->next = p1->next;
				p1->next = p3;
				p = p1->next->next;
			}
		}
	}
}

void Modify(FILE *fp)
{
	system("cls"); //��ս��� 
	Print_interface();//��ӡ��� 
	Change_cursor(1);
	Color(11);//ǳ��ɫ 
	
	PNODE p1;
	int n,k,t;
	float t_;
	char t_str[20];
	Posf(14,4);
	printf("��������Ʒ��ţ�");
	scanf("%d",&n);
	for(p1 = head->next; p1 != NULL; p1 = p1->next)
	{
		if(p1->comNumber == n)
		{
			break;
		}
		else if(p1->next == NULL)
		{
			Posf(44,12);
			printf("û�д���Ʒ��");
			Sleep(1500);
			return ;
		}
	}
	
	Posf(14,6);
	printf("��Ʒ����   ��Ʒ����      ���    ����    �ۼ�    ����    ������");
	Color(10);//����ɫ 
	Posf(14,8);
	printf("%-11s%-14s%-8d%-8.2f%-8.2f%-8d%-10s",p1->comType,p1->comName,p1->comNumber,p1->purchasePrice,p1->sellPrice,p1->comQuantity,p1->supplier_name);
	Color(11);
	Posf(14,10);
	printf("��ѡ��Ҫ�޸ĵ����ԣ����Դ����ұ��Ϊ 1~7 )  ");
	scanf("%d",&k);
	Posf(14,12);
	printf("�������޸�ֵ��");
	switch(k)
	{
		case 1 :
			scanf("%s",t_str);
			strcpy(p1->comType,t_str);
		        break;
		case 2 :
			scanf("%s",t_str);
			strcpy(p1->comName,t_str);
		        break;
		case 3 :
			scanf("%d",&t);
			p1->comNumber = t;
			Posf(44,16);
			printf("�޸ĳɹ���");
			Sleep(1000);
		        break;
		case 4 :
			scanf("%f",&t_);
			p1->purchasePrice = t_;
			Posf(44,16);
			printf("�޸ĳɹ���");
			Sleep(1000);
		        break;
		case 5 :
			scanf("%f",&t_);
			p1->sellPrice = t_;
			Posf(44,16);
			printf("�޸ĳɹ���");
			Sleep(1000);
		        break;
		case 6 :
			scanf("%d",&t);
			p1->comQuantity = t;
			Posf(44,16);
			printf("�޸ĳɹ���");
			Sleep(1000);
		        break;
		case 7 :
			scanf("%s",t_str);
			strcpy(p1->supplier_name,t_str);
			Posf(44,16);
			printf("�޸ĳɹ���");
			Sleep(1000);
		        break;
		default :
			Posf(44,16);
			printf("û�и����ԣ�");
			Sleep(1000);
		        break;	
	}
	
}
void Clear_file(FILE *fp)
{
	system("cls");
	Posf(42,14);
	if((fp = fopen(fileName,"w")) != NULL)
	printf("����ļ��ɹ�!");
	else
	printf("����ļ�ʧ��!");
	fclose(fp);
	Posf(42,16);
	printf("ϵͳ����2����˳�");
	Sleep(2000);
}
void Color(int x) //�Զ��庯���ݲ����ı���ɫ   
{  
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);    //ֻ��һ���������ı�������ɫ   
    else//Ĭ�ϵ���ɫ��ɫ  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
}  
