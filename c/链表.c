/***
线性表顺序存储结构的
创建、
数据插入、
数据获取、
获取长度、
删除数据、
清空数据、
销毁
顺序存储结构方法的实现
***/

#include<stdio.h>
#include<stdlib.h>
#include<sring.h>

typedef struct ElemType{
	int data;
}ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
} *Link,*Position;
typedef struct LinkList{
	Link head,tail;
	int length;
}LinkList;
{
void MakeNode(Link &p,ElemType e);
void FreeNode(Link &p);
void InitList(LinkList &List);
void DestroyList(LinkList &List);
void ClearList(LinkList &List);
void InsertFirst(LinkList &List,Link s);
void InsertLast(LinkList &List,Link s);
void DeleteFirst(LinkList &List,Link &s);
void Append(LinkList &List,Link s);
void Remove(LinkList &List,Link &s);
void InsertBefore(LinkList &List,Link &p,Link s);
void InsertAfter(LinkList &List,Link &p,Link s);
void SetElem(Link &p,ElemType e);
ElemType GetElem(Link p);
void ListIsEmpty(LinkList List);
int GetListLength(LinkList List);
Position GetHead(LinkList List);
Position GetLast(LinkList List);
Position PriorPos(LinkList List);
Position NextPos(LinkList List);
void LocatePos(LinkList List,int i,Link &p);
Position LocateElem(LinkList List,ElemType e,void(*compare)(ElemType,ElemType));
void ListTraverse(LinkList List,void(*visit)(Link));
void MergeList(LinkList &a,LinkList &b,LinkList &c,int(*compare)(ElemType,ElemType));
}
//创建节点
//将e给p，创建一个节点p，p的值为e
void MakeNode(Link &p,ElemType e){
	p=(Link)malloc(sizeof(Link));
	if(!p) exit(-1);
	p->data=e;
	p->next=null;
}
//释放节点
void FreeNode(Link &p){
	if(p) free(p);
}
//初始化链表
void InitList(LinkList &List){
	List.head=List.tail=(Link)malloc(sizeof(LNode));
	if(!List.head) exit(1);
	List.head->next=null;
	List.length=0;
}
//销毁链表
//List不再存在
void DestroyList(LinkList &List){
	if(List) ClearList(List);
	free(List);
}
//清空链表
//List还存在
void ClearList(LinkList &List){
	Link p1,p2;
	p1=List.head->next;//p1起始在List.head的下一节点
	while(p1){//只要p1不空
		p2=p1->next;//缓存下一节点
		free(p1);//释放当前节点
		p1=p2;//指向下一节点
	}
	List.head->next=null;
	List.tail=List.head;
	List.length=0;
}
//将s插入List首端
void InsertFirst(LinkList &List,Link s){
	if(!s) exit(1);
	s->next=List.head->next;
	List.head->next=s;
	List.length++;
}
//将s插入List尾端
void InsertLast(LinkList &List,Link s){
	if(!s) exit(1);
	List.tail->next=s;
	List.tail=s;
	List.tail->next=null;
	List.length++;
}
//删除List首端元素，用s返回所删除的元素
void DeleteFirst(LinkList &List,Link &s){
	s=List.head;
	s->next=null;
	List.head=List.head->next;
}
//追加
//s可能有多个节点
void Append(LinkList &List,Link s){
	Link p;
	int m;
	if(!s) exit(1);
	List.tail->next=s;//接上s
	p=s;//缓存
	m=1;
	while(p->next){
		p=p->next;//一直移到s最后
		m++;//长度计数+1
	}
	List.length+=m;
	List.tail=p;//指向s的最后
}
//移除最后一位元素
void Remove(LinkList &List,Link &s){
	Link temp;
	temp=List.head;//从表头节点开始
	while(temp->next != List.tail){//只要temp的下一节点不是表尾
		temp=temp->next;//temp指针后移
	}
	List.tail=temp;//此时temp在List.tail前，让List.tail指向temp，实现移除
	List.tail->next=null;//移除后面元素
	temp=temp->next;//temp指针后移
	free(temp);//释放被移除的元素
}
//前插入
//已知p指向List中的一个节点，将s插入p之前，然后用p指向s
void InsertBefore(LinkList &List,Link &p,Link s){
	Link temp;
	temp=List.head;
	while(temp->next != p){
		temp=temp->next;
	}
	//此时temp在p前
	temp->next=s;//接入s
	s->next=p;//接好p
	p=temp;//p移到s上
}
//后插入
//已知p指向List中的一个节点，将s插入p之后，然后用p指向s
void InsertAfter(LinkList &List,Link &p,Link s){
	s->next=p->next;
	p->next=s;
	p=s;
}
//修改元素值
//修改p的data为e
void SetElem(Link &p,ElemType e){
	p->data=e;
}
//获取元素值
ElemType GetElem(Link p){
	return p->data;
}
//是否为空
bool ListIsEmpty(LinkList List){
	if(List.length<=0) return true;
	return false;
}
//获取表长度
int GetListLength(LinkList List){
	return List.length;
}
//返回List头节点位置
Position GetHead(LinkList List){
	return List.head;
}
//返回List尾节点位置
Position GetLast(LinkList List){
	return List.tail;
}
//返回List中p的前驱
Position PriorPos(LinkList List,Link p){
	Link temp;
	temp=List.head;
	while(temp.next != p)
		temp=temp->next;
	return temp;
}
//返回List中p的后继
Position NextPos(LinkList List,List p){
	if(!p->next) return null;
	return p->next;
}
//定位
//定位第i个元素，用p返回该元素
void LocatePos(LinkList List,int i,Link &p){
	int m=1;//计数器
	p=List.head;
	while(m++<i)
		p=p->next;
}
//定位
//定位第一个与e满足*compare的元素的位置
Position LocateElem(LinkList List,ElemType e,void(*compare)(ElemType,ElemType)){
	Link temp;
	temp=List.head;
	while((*compare)(e,temp->data))
		temp=temp->next;
	return temp;
}
//遍历调用
void ListTraverse(LinkList List,void(*visit)(Link)){
	Link temp=List.head;
	while(temp->next){
		(*visit)(temp);
		temp=temp->next;
	}
}
//归并
//把a,b按compare归并为c
void MergeList(LinkList &a,LinkList &b,LinkList &c,int(*compare)(ElemType,ElemType)){
	if(!InitList(c)) exit (-1);
	Link aNode=GetHead(a);
	Link bNode=GetHead(b);
	Link workNode;
	while(aNode&&bNode){
		if((*compare)(aNode->data,bNode->data) >= 0){
			workNode=aNode;
			aNode=aNode->next;
		}else{
			workNode=bNode;
			bNode=bNode->next;
		}
		InsertLast(c,workNode);
	}
	if(aNode)
		Append(c,aNode);
	else
		Append(c,bNode);
	FreeNode(aNode);
	FreeNode(bNode);
}

main(){
	LinkList L;
	InitList(L);
}