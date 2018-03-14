/***********************************************

商品库存管理系统

创建日期：2018/3/6   



部分函数介绍 :



**************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>

#define SS sizeof(NODE)

void System_initilization(); //系统初始化 
void Posf(int ,int );  //移动光标 
void Print_interface(); //打印界面 
void Input(FILE* );// 录入数据 
void Delete(FILE* );
void Search(FILE* );
void Addition(FILE* );
void Menu(FILE* );
void Back_to_menu(FILE*);
void Clear_area(int ,int , int ,int ); //清空指定区域   前两个参数是指定坐标，后两个是需要清空位置大小
FILE* Read_file();
FILE* Creat_file();
 
typedef struct node{
	int comNumber; //商品编号
	char comName[20]; //商品名称 
	char comType[20]; //商品类型
	char supplier_name[20]; //供货商名称 
	int purchasePrice; //商品进价
	int sellPrice; //商品售价 
	int comQuantity; //商品数量
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
	printf("5秒后自动返回菜单");
	Sleep(1000);
	Posf(40,20);
	printf("4秒后自动返回菜单");
	Sleep(1000);
    Posf(40,20);
	printf("3秒后自动返回菜单");
	Sleep(1000);
	Posf(40,20);
	printf("2秒后自动返回菜单");
	Sleep(1000);
	Posf(40,20);
	printf("1秒后自动返回菜单");
	Sleep(1000);
	Menu(fp);
	exit(0);
}


void System_initilization()
{
	FILE* fp;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;  
    GetConsoleCursorInfo(hout, &CursorInfo);//获取控制台光标信息  
    CursorInfo.bVisible = false; //隐藏控制台光标  
    SetConsoleCursorInfo(hout, &CursorInfo);//设置控制台光标状态
	system("mode con cols=100 lines=30");
	Print_interface();
	Posf(25,4);
	printf("/**************商品库存管理系统**************/");
	Posf(36,8);
	printf("欢迎使用商品库存管理系统");
	Posf(45,13);
	printf("功能介绍：");
	Posf(20,17);
	printf("所有的库存商品都能按照品名进行显示、查找、增加、删除、修改");
	
	
	
}

void Posf(int x,int y)  //移动光标位置 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,coord);
}

void Print_interface()  //打印框框 
{
	Posf(10,2);
	for(int i = 0; i < 39 ; i++)
	{
		printf("―");
	}
	Posf(10,28);
	for(int i = 0; i < 39 ; i++)
	{
		printf("―");
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
    int n = 7;//控制输入行
	int k = 1, b = 2; // 判断是刚刚进入输入系统吗 
    
    //Back_to_menu();
    
	Posf(11 ,4);
	printf("输入格式：   类型    名称    编号    进价    售价    数量    供货商"); 
	
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
		else if( k == 1) //判断是刚刚进入输入系统吗 
		{
			p1 = (PNODE)malloc(SS);
			Posf(11,++n);
		    printf("请输入：");
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
		printf("是否继续输入？");
		t = getch();
		if( t != 'y')
		break;
		Posf(11,++n);
		printf("请输入：");
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
	if (b == 2)//是否是第一次进入输入 
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
	printf("请直接输入商品编号(任意字母键退出)：");
	
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
	    printf("请直接输入商品编号(任意字母键退出)：");
	}
	
	Posf(40,20);
	printf("3秒后自动返回菜单");
	Sleep(1000);
	Posf(40,20);
	printf("2秒后自动返回菜单");
	Sleep(1000);
	Posf(40,20);
	printf("1秒后自动返回菜单");
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
	system("cls"); //清空界面 
	Print_interface();//打印框框 
	
	char c;
	Posf(20,10);
	printf("1、按[i]键进入商品录入"); 
	Posf(55,10);
	printf("2、按[s]键进入商品查询");
	Posf(20,18);
	printf("3、按[d]键进入商品删除");
	Posf(55,18);
	printf("4、按[a]键进入商品添加");
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
	printf("按错了？是否直接退回菜单？ （按任意键继续，y 退回到菜单）");
	t = getch();
	if(t == 'y')
	{
	    Menu(fp);
    }
    Clear_area(20,3,56,1); //清除上面提示的内容 
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
 		printf("系统未检测到文件，请创建你的文件！"); 
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
    printf("请输入文件名：");
	Posf(48,13);
	printf("┈┈┈┈┈┈");
	Posf(48,15);
	printf("┈┈┈┈┈┈");
	Posf(46,14); 
	printf("┆");
	Posf(60,14);
	printf("┆");
	char fileName[16];
	Posf(48,14);
    scanf("%s", fileName);
    strcat(fileName, ".txt");//连接两个字符串 
    if((fp = fopen(fileName, "a+")))
    {
    	Posf(40,18);
        printf("创建文件成功!");
        fprintf(system_fp,"%s\n",fileName);
        return fp;
    }
}

