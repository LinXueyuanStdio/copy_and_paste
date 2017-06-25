/***
���Ա�˳��洢�ṹ��
������
���ݲ��롢
���ݲ��ҡ�
��ȡ���ȡ�
ɾ�����ݡ�
������ݡ�
����˳��洢�ṹ������ʵ��
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


//���Ա�˳��洢�ṹ�Ĵ���
SeqList* SeqList_Create(int capacity)
{
	//Ϊ�ṹ������ڴ�
	/*��һ���ڴ���䷽ʽ
	TSeqList* list = (TSeqList *)malloc(sizeof(TSeqList));
	////Ϊ�ṹ���е���������ڴ�
	list->node = (unsigned int *)malloc(sizeof(unsigned int)*capacity);
	*/

	/*�ڶ����ڴ���䷽ʽ
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
	//�����ʼ��
	ret->capacity = capacity;
	ret->length = 0;
	memset(ret->node, 0, sizeof(unsigned int)*capacity);
	return ret;
}

//�����Ա�˳��洢�ṹ��ָ��λ�ò�������
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList *tList = NULL;
	//�ж�ָ���Ƿ�Ϊ��
	if (list == NULL)
	{
		return -1;
	}
	tList = (TSeqList*)(list);
	if (node == NULL)
	{
		return -1;
	}
	//�ж��Ƿ�����
	if (tList->length >= tList->capacity)
	{
		return -2;
	}
	//�ж�λ���Ƿ�Խ��
	if (pos < 0 || pos >= tList->capacity)
	{
		return -2;
	}
	if (pos >= tList->length)
	{
		pos = tList->length;
	}
	//�����㷨
	for (int i = tList->length; i > pos; i--)
	{
		//����pos��Ԫ�ص����һ��Ԫ������ƶ�һ��
		tList->node[i] = tList->node[i - 1];
	}
	tList->node[pos] = (unsigned int)node;
	tList->length++;
	return 0;
}

//ɾ�����Ա�˳��洢�ṹָ��λ�õ�����
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList *tList = NULL;
	SeqListNode* ret = NULL;
	//�ж�ָ���Ƿ�Ϊ��
	if (list == NULL)
	{
		return NULL;
	}
	tList = (TSeqList*)(list);
	//�ж�λ���Ƿ�Խ��
	if (pos < 0 || pos >= tList->length)
	{
		return NULL;
	}
	ret = (SeqListNode*)tList->node[pos];
	for (int i = pos; i < tList->length; i++)
	{
		//����pos��Ԫ�ص����һ��Ԫ������ƶ�һ��
		tList->node[i] = tList->node[i + 1];
	}
	tList->length--;
	return ret;
}

//��ȡ���Ա�˳��洢�ṹָ��λ�õ�����
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList *tList = NULL;
	SeqListNode* ret = NULL;
	//�ж�ָ���Ƿ�Ϊ��
	if (list == NULL)
	{
		return NULL;
	}
	tList = (TSeqList*)(list);
	//�ж�λ���Ƿ�Խ��
	if (pos < 0 || pos >= tList->length)
	{
		return NULL;
	}
	ret = (SeqListNode*)tList->node[pos];
	return ret;
}

//��ʼ�����Ա�˳��洢�ṹ
void SeqList_Clear(SeqList* list)
{
	TSeqList *tList = NULL;
	//�ж�ָ���Ƿ�Ϊ��
	if (list == NULL)
	{
		return;
	}
	tList = (TSeqList*)(list);
	tList->length = 0;
	memset(tList->node, 0, sizeof(unsigned int)*tList->capacity);
	return;
}

//��ȡ���Ա�˳��洢�ṹ�ĳ���
int SeqList_Length(SeqList* list)
{
	TSeqList *tList = NULL;
	//�ж�ָ���Ƿ�Ϊ��
	if (list == NULL)
	{
		return 0;
	}
	tList = (TSeqList*)(list);
	return tList->length;
}
//��ȡ���Ա�˳��洢�ṹ������
int SeqList_Capacity(SeqList* list)
{
	TSeqList *tList = NULL;
	//�ж�ָ���Ƿ�Ϊ��
	if (list == NULL)
	{
		return 0;
	}
	tList = (TSeqList*)(list);
	return tList->capacity;
}

//�������Ա�˳��洢�ṹ
int SeqList_Destory(SeqList* list)
{
	//�ж�ָ���Ƿ�Ϊ��
	if (list == NULL)
	{
		return 0;
	}
	free(list);
	list = NULL;
	return 0;
}