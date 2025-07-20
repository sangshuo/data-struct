#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1
#ifndef maxSize
#define maxSize 100
#endif

typedef int ELEMType;
typedef struct {
    // 线性表元素最大个数
    ELEMType element[maxSize];
    // 线性表当前长度
    int length;
} SeqList;
typedef SeqList LinearList;
typedef int Position;

// 初始化线性表
int initList(SeqList *L)
{
    L->length = 0;
    return TRUE;
}

// 清空线性表
int clearList(SeqList *L)
{
    L->length = 0;
    return TRUE;
}

// 判断线性表是否为空
int isEmpty(SeqList *L)
{
    if (L->length == 0) {
        return TRUE;
    }
    return FALSE;
}

// 判断线性表是否满状态
int isFull(SeqList *L)
{
    if (L->length == maxSize) {
        return TRUE;
    }
    return FALSE;
}

// 获取线性表Length

int length(SeqList *L)
{
    return L->length;
}

// 线性表插入元素
/*
 ****实现方案****
 1. 判断线性表是否为满状态，如果满，则返回FALSE
 2. 判断 插入位置 是否 小于 0 或者 大于 线性表当前长度（因为线性表地址是连续的），是的话 返回 FALSE
 3. 循环移动元素
    3.1 下标i项 移动到 下标 i + 1项，直到移动到pos位置
 4. 长度++
 5. 返回 TRUE
*/
int insertList(SeqList *L, Position pos, ELEMType x)
{
    //初始化值为零，考虑线性表为空的情况
    int i = 0;
    if(isFull(L)){
        printf("线性表已满");
        return FALSE;
    }
    if (pos < 0 || pos > L->length) {
        printf("position 输入异常，please check it");
        return FALSE;
    }
    for(i = L->length; i < pos; i--)
    {
        L->element[i] = L->element[i - 1];
    }
    L->element[i] = x;
    L->length++;
    return TRUE;
}

// 线性表移除元素
/*
 ****实现方案****
 1. 判断线表当前是否为空，如果当前为空，直接返回FALSE
 2. 判断线性表移除位置是否大于线性表当前长度 或者 小于 0，如果是 则返回 FALSE
 3. 如果移除的直接是最后一个元素，直接length--
 3. 循环移动元素
    3.1 pos位置元素等于pos位置后一个元素
 4. 长度- -
 5. 返回 TRUE
*/
int removeList(SeqList *L, Position pos)
{
    int i;
    if(isEmpty(L)) {
        return FALSE;
    }
    if(pos <0 || pos > L->length)
    {
        printf("position 输入异常，please check it");
        return FALSE;
    }
    if(pos == L->length - 1)
    {
        L->length--;
        return TRUE;
    }
    for(i = pos; i<L->length -1; i++)
    {
        L->element[i] = L->element[i + 1];
    }
    L->length--;
    return TRUE;
}

//设置指定位置元素
/*
 ****实现方案****
 1. 判断线表当前是否为空，如果当前为空，直接返回FALSE
 2. 判断线性表设置元素位置是否大于线性表当前长度 或者 小于 0，如果是 则返回 FALSE
 3. 直接设置元素
 4. 返回TRUE
*/
int setValue(SeqList *L, Position pos, ELEMType x)
{
    if (isEmpty(L)) {
        return FALSE;
    }
    if(pos < 0 || pos > L->length) {
        printf("position 输入异常，please check it");
        return FALSE;
    }
    L->element[pos] = x;
    return TRUE;
}

//获取指定位置元素
/*
 ****实现方案****
 1. 判断线表当前是否为空，如果当前为空，直接返回FALSE
 2. 判断线性表获取元素位置是否大于线性表当前长度 或者 小于 0，如果是 则返回 FALSE
 3. 直接返回元素
 4. 返回TRUE
*/
int getValue(SeqList *L, Position pos)
{
    if (isEmpty(L)) {
        return FALSE;
    }
    if(pos < 0 || pos > L->length) {
        printf("position 输入异常，please check it");
        return FALSE;
    }
    return L->element[pos];
}

// 辅助函数 display
void display(SeqList *L)
{
    for(int i=0; i<L->length;i++)
    {
        printf("%d\n", L->element[i]);
    }
}

void swap(ELEMType *x, ELEMType *y)
{
    ELEMType temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// reverse 线性表
int reverse(SeqList *L)
{
    int i;
    int length = L->length;
    if(isEmpty(L)) {
        printf("当前线性表为空，无需逆转");
        return FALSE;
    }
    for(i = 0; i < length/2; i++)
    {
        swap(&(L->element[i]), &(L->element[length - i - 1]));
    }
    return TRUE;
}


int main()
{
    LinearList list;
    int listLength = 10;
    initList(&list);
    for(int i =0; i < listLength; i++)
    {
        insertList(&list, i, i);
    }
    removeList(&list, 0);
    setValue(&list, 0, 100);
    printf("%d\n", getValue(&list, 0));
    display(&list);
    reverse(&list);
    printf("********reverse*********\n");
    display(&list);
    return 0;
}


