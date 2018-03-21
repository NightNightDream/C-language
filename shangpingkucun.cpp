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
void Save(FILE* );
int Menu(FILE* );
void Print_date();
void Clear_area(int ,int , int ,int ); //清空指定区域   前两个参数是指定坐标，后两个是需要清空位置大小
FILE* Read_file();
FILE* Creat_file();
void Read_date(FILE *);
 
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
PNODE p2 = NULL;
FILE* system_fp; //储存用户数据 
char fileName[16]; //全局变量 储存文件名  一开始找到文件读取数据   或   在储存函数中找到数据文件并按照链表中的数据更新文件 


int main()
{
	FILE* fp;
	int t = 1;
	System_initilization();
	fp = Read_file();  //读取文件中的数据到链表中 
	/*Posf(40,20);
	printf("5秒后自动进入菜单");
	Sleep(1000);
	Posf(40,20);
	printf("4秒后自动进入菜单");
	Sleep(1000);
    Posf(40,20);
	printf("3秒后自动进入菜单");
	Sleep(1000);
	Posf(40,20);
	printf("2秒后自动进入菜单");
	Sleep(1000);*/
	Posf(40,20);
	printf("1秒后自动进入菜单");
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
	int k = 1; // 判断是刚刚进入输入系统吗 
    
    //Back_to_menu();
    
	Posf(11 ,4);
	printf("输入格式：   类型    名称    编号    进价    售价    数量    供货商"); 
	
	PNODE p1,p3;
	

    while(1)
    {
    	if(head == NULL) //如果文件没有数据且head为空   用户第一次输入 
    	{
    		p1 = (PNODE)malloc(SS);
    		head = p1;
    		k++;
		}
		else if( k == 1) //判断是第一次进入输入系统吗  用来连接输入数据到上次的链表尾 
		{
			Posf(11,++n);
			printf("是否继续输入？");
		    t = getch();
		    if( t != 'y')
		    break;
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
	
	return ; 
}
	

void Delete(FILE *fp)
{
	system("cls");
	Print_interface();
	//Back_to_menu(fp);
	fflush(stdin);//清空输入缓冲区 
	
	
	PNODE p1, p2;
	int n, i = 6;
	Posf(18,++i);
	printf("请直接输入商品编号(任意字母键退出)：");
	
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
		printf("保存文件失败！");
		Sleep(1000);
		return ;
	}
	/*
	保存文件 
	*/
    PNODE p1;
    p1 = head->next;
    for(; p1 != NULL; p1 = p1->next)
    {
    	fwrite(p1,sizeof(NODE),1,fp);
	}
	fclose(fp);
	printf("保存文件成功！");
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
	printf("按[h]键价格从高到低");
	Posf(52,23);
	printf("按[l]键价格从低到高");
	//getchar();
	Sleep(3000);
	return ;
	
	
}

int Menu(FILE* fp)
{
	system("cls"); //清空界面 
	Print_interface();//打印框框 
	fflush(stdin);//清空输入缓冲区 
	
	Posf(44,6);
	printf("按q键退出！");
	char c;
	Posf(20,10);
	printf("1、按[i]键进入商品录入"); 
	Posf(55,10);
	printf("2、按[s]键进入商品查询");
	Posf(20,18);
	printf("3、按[d]键进入商品删除");
	Posf(55,18);
	printf("4、按[b]键商品数据保存");
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
			return 0;  //0代表退出程序 
			
	}
    return 1; //重新进入菜单 
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
 		printf("系统未检测到文件，请创建你的文件！"); 
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
	    	printf("打开文件失败！");
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
    printf("请输入文件名：");
	Posf(48,13);
	printf("┈┈┈┈┈┈");
	Posf(48,15);
	printf("┈┈┈┈┈┈");
	Posf(46,14); 
	printf("┆");
	Posf(54,14);
	printf("┆");
	
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

void Print_date()
{
	PNODE p1,p2;
	Posf(14,5);
	printf("商品类型   商品名称      编号    进价    售价    数量    供货商");
	int n = 5;
	if(head == NULL || head->next == NULL)  //如果头指针或下一节为空，说明没有数据 
	{
	    printf("没有数据储存！");
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
