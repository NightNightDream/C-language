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
void Sort_price_HtoL();
void Sort_price_LtoH();
void Sort_number_LtoH();
void Save(FILE* );
int Menu(FILE* );
void Print_date();  //打印数据 
void Clear_area(int ,int , int ,int ); //清空指定区域   前两个参数是指定坐标，后两个是需要清空位置大小
FILE* Read_file(); //获取文件 
FILE* Creat_file();
void Read_date(FILE *);  //读取文件数据 
void Modify(FILE *);  //修改商品数据 
void Change_cursor(int );  //改变光标状态 
void Color(int ); //改变字体颜色 
void Clear_file(FILE*); //清空文件数据 

typedef struct node{
	int comNumber; //商品编号
	char comName[20]; //商品名称 
	char comType[20]; //商品类型
	char supplier_name[20]; //供货商名称 
	float purchasePrice; //商品进价
	float sellPrice; //商品售价 
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
	Color(12);//改变字体为亮红色 
	Posf(40,20);
	/*printf("5秒后自动进入菜单");
	Sleep(1000);
	Posf(40,20);
	printf("4秒后自动进入菜单");
	Sleep(1000);
    Posf(40,20);
	printf("3秒后自动进入菜单");
	Sleep(1000);
	Posf(40,20);
	printf("2秒后自动进入菜单");
	Sleep(1000);
	Posf(40,20);*/
	printf("1秒后自动进入菜单");
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
        GetConsoleCursorInfo(hout, &CursorInfo);//获取控制台光标信息 
	if(k == 1) 
        {
        	CursorInfo.bVisible = true; //显示控制台光标  
	}
	else
	{
		CursorInfo.bVisible = false; //隐藏控制台光标  
	}
        SetConsoleCursorInfo(hout, &CursorInfo);//设置控制台光标状态
}

void System_initilization()
{
	FILE* fp;
	Change_cursor(0);
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
	Posf(42,25);
	Color(13);
	printf("制作人：冯轩");
	
	
	
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
	Color(2);
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
	Color(7);
}

void Input(FILE* fp)
{ 
	system("cls");
	Print_interface();
	Change_cursor(1);
	
    char t;
    int n = 7;//控制输入行
	int k = 1; // 判断是刚刚进入输入系统吗 
    
    
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
			printf("是否继续输入？(y继续，n退出)");
		    t = getch();
		    if( t == 'n')
		    return;
		    p1 = (PNODE)malloc(SS);
		    Posf(11,++n);
		    printf("请输入：");
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
		printf("是否继续输入？(y继续，n退出)");
		t = getch();
		if( t == 'n')
		break;
		Posf(11,++n);
		printf("请输入：");
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
    	fwrite(p1,SS,1,fp);
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
	Color(10);
	fflush(stdin);
	
	
	
	
	char flag;
	Posf(42,3);
	printf("按e键退出！");
	Posf(11,22);
	printf("----------------------------------------------------------------------------");
	Color(14);
	Posf(24,23);
	printf("按[h]键价格从高到低");
	Posf(52,23);
	printf("按[l]键价格从低到高");
	Posf(24,25);
	printf("按[n]键编号从低到高");
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
	system("cls"); //清空界面 
	Print_interface();//打印框框
	Change_cursor(0); 
	
	fflush(stdin);//清空输入缓冲区 
	
	Posf(44,4);
	Color(15);//字体改成亮白色 
	printf("按e键退出！");
	char c;
	Color(14); //字体改成黄色 
	Posf(20,8);
	printf("1、按[i]键进入商品录入"); 
	Posf(55,8);
	printf("2、按[s]键进入商品查询");
	Posf(20,16);
	printf("3、按[d]键进入商品删除");
	Posf(55,16);
	printf("4、按[b]键商品数据保存");
	Posf(20,24);
	printf("5、按[m]键商品属性修改"); 
	Posf(55,24);
	printf("6、按[q]键清空文件数据");
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
			return 0;  //0代表退出程序 
			
	}
	Color(7);
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
	Posf(60,14);
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
		Posf(42,10);
	        printf("没有数据储存！");
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
		return ;  //文件为空直接结束 
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
	system("cls"); //清空界面 
	Print_interface();//打印框框 
	Change_cursor(1);
	Color(11);//浅绿色 
	
	PNODE p1;
	int n,k,t;
	float t_;
	char t_str[20];
	Posf(14,4);
	printf("请输入商品编号：");
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
			printf("没有此商品！");
			Sleep(1500);
			return ;
		}
	}
	
	Posf(14,6);
	printf("商品类型   商品名称      编号    进价    售价    数量    供货商");
	Color(10);//亮绿色 
	Posf(14,8);
	printf("%-11s%-14s%-8d%-8.2f%-8.2f%-8d%-10s",p1->comType,p1->comName,p1->comNumber,p1->purchasePrice,p1->sellPrice,p1->comQuantity,p1->supplier_name);
	Color(11);
	Posf(14,10);
	printf("请选择要修改的属性（属性从左到右编号为 1~7 )  ");
	scanf("%d",&k);
	Posf(14,12);
	printf("请输入修改值：");
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
			printf("修改成功！");
			Sleep(1000);
		        break;
		case 4 :
			scanf("%f",&t_);
			p1->purchasePrice = t_;
			Posf(44,16);
			printf("修改成功！");
			Sleep(1000);
		        break;
		case 5 :
			scanf("%f",&t_);
			p1->sellPrice = t_;
			Posf(44,16);
			printf("修改成功！");
			Sleep(1000);
		        break;
		case 6 :
			scanf("%d",&t);
			p1->comQuantity = t;
			Posf(44,16);
			printf("修改成功！");
			Sleep(1000);
		        break;
		case 7 :
			scanf("%s",t_str);
			strcpy(p1->supplier_name,t_str);
			Posf(44,16);
			printf("修改成功！");
			Sleep(1000);
		        break;
		default :
			Posf(44,16);
			printf("没有该属性！");
			Sleep(1000);
		        break;	
	}
	
}
void Clear_file(FILE *fp)
{
	system("cls");
	Posf(42,14);
	if((fp = fopen(fileName,"w")) != NULL)
	printf("清空文件成功!");
	else
	printf("清空文件失败!");
	fclose(fp);
	Posf(42,16);
	printf("系统将在2秒后退出");
	Sleep(2000);
}
void Color(int x) //自定义函根据参数改变颜色   
{  
    if(x>=0 && x<=15)//参数在0-15的范围颜色  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);    //只有一个参数，改变字体颜色   
    else//默认的颜色白色  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
}  
