/***
线性表顺序存储结构的
创建、
数据插入、
数据查找、
获取长度、
删除数据、
清空数据、
销毁顺序存储结构方法的实现
***/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct _SeqList
{
	unsigned int*  node;
	int length;
	int capacity;
}TSeqList;
typedef void SeqList;
typedef void SeqListNode;


//线性表顺序存储结构的创建
SeqList* SeqList_Create(int capacity)
{
	//为结构体分配内存
	/*第一种内存分配方式
	TSeqList* list = (TSeqList *)malloc(sizeof(TSeqList));
	////为结构体中的数组分配内存
	list->node = (unsigned int *)malloc(sizeof(unsigned int)*capacity);
	*/

	/*第二种内存分配方式
	TSeqList* list = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(unsigned int)*capacity);
	list->node = (unsigned int*)list++;
	*/
	TSeqList* ret = NULL;
	if (capacity <= 0)
	{
		return NULL;
	}
	ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(unsigned int)*capacity);;
	if (ret == NULL)
	{
		return NULL;
	}
	ret->node = (unsigned int*)(ret + 1);
	if (ret->node == NULL)
	{
		return NULL;
	}
	//对其初始化
	ret->capacity = capacity;
	ret->length = 0;
	memset(ret->node, 0, sizeof(unsigned int)*capacity);
	return ret;
}

//在线性表顺序存储结构的指定位置插入数据
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList *tList = NULL;
	//判断指针是否为空
	if (list == NULL)
	{
		return -1;
	}
	tList = (TSeqList*)(list);
	if (node == NULL)
	{
		return -1;
	}
	//判断是否满了
	if (tList->length >= tList->capacity)
	{
		return -2;
	}
	//判断位置是否越界
	if (pos < 0 || pos >= tList->capacity)
	{
		return -2;
	}
	if (pos >= tList->length)
	{
		pos = tList->length;
	}
	//插入算法
	for (int i = tList->length; i > pos; i--)
	{
		//将第pos个元素到最后一个元素向后移动一格
		tList->node[i] = tList->node[i - 1];
	}
	tList->node[pos] = (unsigned int)node;
	tList->length++;
	return 0;
}

//删除线性表顺序存储结构指定位置的数据
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList *tList = NULL;
	SeqListNode* ret = NULL;
	//判断指针是否为空
	if (list == NULL)
	{
		return NULL;
	}
	tList = (TSeqList*)(list);
	//判断位置是否越界
	if (pos < 0 || pos >= tList->length)
	{
		return NULL;
	}
	ret = (SeqListNode*)tList->node[pos];
	for (int i = pos; i < tList->length; i++)
	{
		//将第pos个元素到最后一个元素向后移动一格
		tList->node[i] = tList->node[i + 1];
	}
	tList->length--;
	return ret;
}

//获取线性表顺序存储结构指定位置的数据
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList *tList = NULL;
	SeqListNode* ret = NULL;
	//判断指针是否为空
	if (list == NULL)
	{
		return NULL;
	}
	tList = (TSeqList*)(list);
	//判断位置是否越界
	if (pos < 0 || pos >= tList->length)
	{
		return NULL;
	}
	ret = (SeqListNode*)tList->node[pos];
	return ret;
}

//初始化线性表顺序存储结构
void SeqList_Clear(SeqList* list)
{
	TSeqList *tList = NULL;
	//判断指针是否为空
	if (list == NULL)
	{
		return;
	}
	tList = (TSeqList*)(list);
	tList->length = 0;
	memset(tList->node, 0, sizeof(unsigned int)*tList->capacity);
	return;
}

//获取线性表顺序存储结构的长度
int SeqList_Length(SeqList* list)
{
	TSeqList *tList = NULL;
	//判断指针是否为空
	if (list == NULL)
	{
		return 0;
	}
	tList = (TSeqList*)(list);
	return tList->length;
}
//获取线性表顺序存储结构的容量
int SeqList_Capacity(SeqList* list)
{
	TSeqList *tList = NULL;
	//判断指针是否为空
	if (list == NULL)
	{
		return 0;
	}
	tList = (TSeqList*)(list);
	return tList->capacity;
}

//销毁线性表顺序存储结构
int SeqList_Destory(SeqList* list)
{
	//判断指针是否为空
	if (list == NULL)
	{
		return 0;
	}
	free(list);
	list = NULL;
	return 0;
}