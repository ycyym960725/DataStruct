#include "stdlib.h"  
#include "stdio.h"  
#include <conio.h>
#include <ctype.h>
#include<windows.h>
#define NULL 0
#define OK 1
#define ERROR 0
#define LEN sizeof(struct student)  
#define Status int
typedef struct student Node;
struct student
{
	int num;//学号   
	float score;          //分数，其他信息可以继续在下面增加字段  
	struct student *next;       //指向下一节点的指针  
};

int n;  //节点总数   
/*
==========================
功能：创建n个节点的链表
返回：指向链表表头的指针
==========================
*/
struct student *Create()
{
	struct student *head;       //头节点  
	struct student *p1 = NULL;  //p1保存创建的新节点的地址  
	struct student *p2 = NULL;  //p2保存原链表最后一个节点的地址  

	n = 0;          //创建前链表的节点总数为0：空链表  
	p1 = (struct student *) malloc(LEN);   //开辟一个新节点  
	p2 = p1;            //如果节点开辟成功，则p2先把它的指针保存下来以备后用  

	if (p1 == NULL)        //节点开辟不成功  
	{
		printf("\nCann't create it, try it again in a moment!\n");
		return NULL;
	}
	else                //节点开辟成功  
	{
		head = NULL;        //开始head指向NULL  
		printf("请输入第 %d 个 学生的学号--分数:", n + 1);
		scanf_s("%d %f", &(p1->num), &(p1->score));    //录入数据  
	}
	while (p1->num != 0)      //只要学号不为0，就继续录入下一个节点  
	{
		n += 1;         //节点总数增加1个  
		if (n == 1)      //如果节点总数是1，则head指向刚创建的节点p1  
		{
			head = p1;
			p2->next = NULL;  //此时的p2就是p1,也就是p1->next指向NULL。  
		}
		else
		{
			p2->next = p1;   //指向上次下面刚刚开辟的新节点  
		}

		p2 = p1;            //把p1的地址给p2保留，然后p1产生新的节点  

		p1 = (struct student *) malloc(LEN);
		printf("请输入第 %d 个 学生的学号--分数:", n + 1);
		scanf_s("%d %f", &(p1->num), &(p1->score));
	}
	p2->next = NULL;     //此句就是根据单向链表的最后一个节点要指向NULL  

	free(p1);           //p1->num为0的时候跳出了while循环，并且释放p1  
	p1 = NULL;
	printf("创建成功! \n");
	//特别不要忘记把释放的变量清空置为NULL,否则就变成"野指针"，即地址不确定的指针  
	return head;        //返回创建链表的头指针   
}
//             1.增
Node *LinkedListInsert(Node *L, int i)
{
	Node *pre;                      //pre为前驱结点 
	pre = L;
	int tempi = 1;
	for (tempi = 1; tempi < i; tempi++)
		pre = pre->next;  //查找第i个位置的前驱结点 
	while (tempi<i)
	{
		tempi++;
		pre = pre->next;
	}
	Node *p;                                //插入的结点为p
	p = (Node *)malloc(sizeof(Node));
	printf("请输入待插入学生的 学号--总分\n");
	scanf_s("%d%f", &(p->num), &(p->score));
	p->next = pre->next;
	pre->next = p;
	printf("插入成功!\n");
	return L;
} 
//             2.删
struct student *dele(Node *L, int num){
	Node *pb, *pf, *head;
	head = L;
	pf = NULL;
	pb = head;
	if (head == NULL)
	{
		printf("\n该表为空表");
		return head;
	}
	while (pb->num != num&&pb != NULL){
		pf = pb;
		pb = pb->next;
	}
	if (pb->num == num)
	{
		if (pb == head)
		{
			head = pb->next;
		}
		else{
			pf->next = pb->next;
		}
		free(pb);
		printf("\n删除成功!");
	}
	else{
		printf("\n名单里面并没有找到该学号的学生");
	}
	return head;
}
//             3.查
boolean GetStudent(Node *L,int stu_num){
	Node *head, *pb;

}
void ShowLinkList(Node *L){
	Node *pointer, *head;
	head = L;
	pointer = head;
	printf("");
	if (pointer != NULL)
	{
		do
		{
			printf("\n\t#%d号学生的成绩为%f#", pointer->num, pointer->score);
			pointer = pointer->next;
		} while (pointer != NULL);
	}
	else
	{
		printf("\n该表为空表\n");
	}
	printf("\n\t\t\t\t\t\t\t**当前共有%d个学生**\n", Count_Node_Num(L));
}


int Count_Node_Num(Node *L){
	Node *head, *pointer;
	head = L;
	pointer = head;
	int count = 0;
	while (pointer!=NULL){
		count++;
		pointer = pointer->next;
	}
	return count;
}

void menu(){
	printf("\n\t\t\t                      学生信息管理系统\n");
	printf("\t\t\t#**************************************#\n");
	printf("\t\t\t#                   1.创建学生信息表   #\n");
	printf("\t\t\t#                   2.插入学生信息     #\n");
	printf("\t\t\t#                   3.删除学生信息     #\n");
	printf("\t\t\t#                   4.查看学生信息     #\n");
	printf("\t\t\t#                   0.退出             #\n");
}
void main(){
	system("COLOR 9f");
	Node *L=NULL;
	int select;
	int dele_num;
	int insert_position;
	while (1){
		menu();
		printf("按数字键选择要进行的操作\n");
		scanf_s("%d", &select);
		printf("\n");
		if (select==0){
			break;
		}
		else{
			switch (select){
			case 1:L = Create(); break;
			case 2:printf("请输入待添加的学生的插入位置\n"); scanf_s("%d", &insert_position);L = LinkedListInsert(L,insert_position); break;
			case 3:printf("请输入待删除节点的学生的学号: "); scanf_s("%d", &dele_num); L = dele(L, dele_num); break;
			case 4:ShowLinkList(L); break;
			}
		}
	}
}

