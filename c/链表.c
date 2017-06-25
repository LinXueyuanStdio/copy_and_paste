/***
���Ա�˳��洢�ṹ��
������
���ݲ��롢
���ݻ�ȡ��
��ȡ���ȡ�
ɾ�����ݡ�
������ݡ�
����
˳��洢�ṹ������ʵ��
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
//�����ڵ�
//��e��p������һ���ڵ�p��p��ֵΪe
void MakeNode(Link &p,ElemType e){
	p=(Link)malloc(sizeof(Link));
	if(!p) exit(-1);
	p->data=e;
	p->next=null;
}
//�ͷŽڵ�
void FreeNode(Link &p){
	if(p) free(p);
}
//��ʼ������
void InitList(LinkList &List){
	List.head=List.tail=(Link)malloc(sizeof(LNode));
	if(!List.head) exit(1);
	List.head->next=null;
	List.length=0;
}
//��������
//List���ٴ���
void DestroyList(LinkList &List){
	if(List) ClearList(List);
	free(List);
}
//�������
//List������
void ClearList(LinkList &List){
	Link p1,p2;
	p1=List.head->next;//p1��ʼ��List.head����һ�ڵ�
	while(p1){//ֻҪp1����
		p2=p1->next;//������һ�ڵ�
		free(p1);//�ͷŵ�ǰ�ڵ�
		p1=p2;//ָ����һ�ڵ�
	}
	List.head->next=null;
	List.tail=List.head;
	List.length=0;
}
//��s����List�׶�
void InsertFirst(LinkList &List,Link s){
	if(!s) exit(1);
	s->next=List.head->next;
	List.head->next=s;
	List.length++;
}
//��s����Listβ��
void InsertLast(LinkList &List,Link s){
	if(!s) exit(1);
	List.tail->next=s;
	List.tail=s;
	List.tail->next=null;
	List.length++;
}
//ɾ��List�׶�Ԫ�أ���s������ɾ����Ԫ��
void DeleteFirst(LinkList &List,Link &s){
	s=List.head;
	s->next=null;
	List.head=List.head->next;
}
//׷��
//s�����ж���ڵ�
void Append(LinkList &List,Link s){
	Link p;
	int m;
	if(!s) exit(1);
	List.tail->next=s;//����s
	p=s;//����
	m=1;
	while(p->next){
		p=p->next;//һֱ�Ƶ�s���
		m++;//���ȼ���+1
	}
	List.length+=m;
	List.tail=p;//ָ��s�����
}
//�Ƴ����һλԪ��
void Remove(LinkList &List,Link &s){
	Link temp;
	temp=List.head;//�ӱ�ͷ�ڵ㿪ʼ
	while(temp->next != List.tail){//ֻҪtemp����һ�ڵ㲻�Ǳ�β
		temp=temp->next;//tempָ�����
	}
	List.tail=temp;//��ʱtemp��List.tailǰ����List.tailָ��temp��ʵ���Ƴ�
	List.tail->next=null;//�Ƴ�����Ԫ��
	temp=temp->next;//tempָ�����
	free(temp);//�ͷű��Ƴ���Ԫ��
}
//ǰ����
//��֪pָ��List�е�һ���ڵ㣬��s����p֮ǰ��Ȼ����pָ��s
void InsertBefore(LinkList &List,Link &p,Link s){
	Link temp;
	temp=List.head;
	while(temp->next != p){
		temp=temp->next;
	}
	//��ʱtemp��pǰ
	temp->next=s;//����s
	s->next=p;//�Ӻ�p
	p=temp;//p�Ƶ�s��
}
//�����
//��֪pָ��List�е�һ���ڵ㣬��s����p֮��Ȼ����pָ��s
void InsertAfter(LinkList &List,Link &p,Link s){
	s->next=p->next;
	p->next=s;
	p=s;
}
//�޸�Ԫ��ֵ
//�޸�p��dataΪe
void SetElem(Link &p,ElemType e){
	p->data=e;
}
//��ȡԪ��ֵ
ElemType GetElem(Link p){
	return p->data;
}
//�Ƿ�Ϊ��
bool ListIsEmpty(LinkList List){
	if(List.length<=0) return true;
	return false;
}
//��ȡ����
int GetListLength(LinkList List){
	return List.length;
}
//����Listͷ�ڵ�λ��
Position GetHead(LinkList List){
	return List.head;
}
//����Listβ�ڵ�λ��
Position GetLast(LinkList List){
	return List.tail;
}
//����List��p��ǰ��
Position PriorPos(LinkList List,Link p){
	Link temp;
	temp=List.head;
	while(temp.next != p)
		temp=temp->next;
	return temp;
}
//����List��p�ĺ��
Position NextPos(LinkList List,List p){
	if(!p->next) return null;
	return p->next;
}
//��λ
//��λ��i��Ԫ�أ���p���ظ�Ԫ��
void LocatePos(LinkList List,int i,Link &p){
	int m=1;//������
	p=List.head;
	while(m++<i)
		p=p->next;
}
//��λ
//��λ��һ����e����*compare��Ԫ�ص�λ��
Position LocateElem(LinkList List,ElemType e,void(*compare)(ElemType,ElemType)){
	Link temp;
	temp=List.head;
	while((*compare)(e,temp->data))
		temp=temp->next;
	return temp;
}
//��������
void ListTraverse(LinkList List,void(*visit)(Link)){
	Link temp=List.head;
	while(temp->next){
		(*visit)(temp);
		temp=temp->next;
	}
}
//�鲢
//��a,b��compare�鲢Ϊc
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