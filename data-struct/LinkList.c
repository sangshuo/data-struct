#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1
#ifndef maxSize
#define maxSize 100
#endif

typedef int ELEMType;

typedef struct node {
	ELEMType data;
	struct node *next;
} LinkNode;
//位置
typedef int Position;

/**
 * 初始化单链表
 * 方案
 * 1. 申请内存空间
 * 2. 判断内存是否申请成功
 * 3. 初始化头节点
 * 4. 头节点指向NULL
 * 5. 返回TRUE
 */
int initLinkList(LinkNode **head)
{
    (*head) = (LinkNode*)malloc(sizeof(LinkNode));
    // 判断申请内存是否成功
    if(*head == NULL) {
    	return FALSE;
    }
    (*head)->data = 0;
    (*head)->next = NULL;
    return TRUE;
}

/*
 * 清空单链表
 * 方案
 * 1. 初始化LinkNode *p用来存储单链表开头
 * 2. 判断链表是否存在，head等于null说明不存在
 * 3. while循环查找单链表的每个节点，释放每个节点内存，直到结束
 * 4. 返回TRUE
*/
int clear(LinkNode **head)
{
	LinkNode *p;
	if(*head == NULL)
	{
		printf("链表错误\n");
		return FALSE;
	}
	p = (*head)->next;

	while(p!=NULL){
		(*head)->next= p->next;
		free(p);
		p = (*head)->next;
	}
	(*head)->data=0;
	return TRUE;
}
/*
 * 判断单链表是否为空
 * 1.首先判断单链表是否存在，不存在直接返回FALSE
 * 2. 判断单链表的头节点是否等于0，等于0则为空，否则不为空
*/
int isEmpty(LinkNode **head)
{
	if (*head == NULL)
	{
		printf("单链表不存在\n");
		return FALSE;
	}
	if ((*head)->data == 0)
	{
		return TRUE;
	}
	return FALSE;
}

int length(LinkNode **head)
{
	int i;
	LinkNode *p;
	if(*head == NULL)
	{
		printf("链表错误\n");
		return 0;
	}
	p = (*head)->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}

	printf("链表的长度为%d\n", i);
	return i;
}

LinkNode* setCurrentPos(LinkNode **head, int pos)
{
	LinkNode *p;
	p = (*head)->next;
	if (*head == NULL) {
		printf("头指针无效");
		return NULL;
	}
	while (p != NULL && pos >0)
	{
		/* code */
		p = p->next;
		pos--;
	}
	return p;
}

int insertList(LinkNode **head, ELEMType e, Position pos)
{
	LinkNode *temp, *curr;
	curr = setCurrentPos(head, pos);
	if(curr == NULL) {
		return FALSE;
	}
	temp = (LinkNode*)malloc(sizeof(LinkNode));
	if (temp == NULL) {
		return FALSE;
	}
	temp->data = e;
	temp->next = curr->next;
	curr->next = temp;
	(*head)->data++;
	return TRUE;
}
int main()
{
    LinkNode list;
    initLinkList(&list);
    int clearStatus = clear(&list);
	printf("清空的状态为%d", clearStatus);
    return 0;
}
