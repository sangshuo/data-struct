ADT LinearList {
    data part:
        L: // LinearList
    operation part:
        int init(LinearList *L); // 初始化线性表  完成
        int clear(LinearList *L); // 清空线性表 完成
        int isEmpty(LinearList *L); // 判断线性表是否为空 完成
        int isFull(LinearList *L); // 判断线性表是否已满 完成
        int length(LinearList *L); // 获取线性表长度 完成
        int insertList(LinearList *L, Position pos, ELEMType x); // 向线性表中插入元素 完成
        int removeList(LinearList *L, Position pos, ELEMType *x); // 从线性表中删除元素 完成
        int setValue(LinearList *L, Position pos, ELEMType x); // 设置线性表中指定位置的元素值
        int getValue(LinearList *L, Position pos, ELEMType *x); // 获取线性表中指定位置的元素值
        Position find(LinearList *L, ELEMType x); // 返回元素x在表中第一次出现的位置
}

ADT LinkList {
    data part:
        ELEMType data;
        struct node *next;
    operation part:
        int initList(LinkList *head);
        int clear(LinkList *head);
        int isEmpty(LinkList *head);
        int length(LinkList *head);
        
}