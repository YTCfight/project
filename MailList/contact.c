#define _CRT_SECURE_NO_WARNINGS 
#include"contact.h" 
void InitContact(Contact* pCon)
{
	assert(pCon != NULL);
	pCon->usedSize = 0;
	memset(pCon->per, 0, sizeof(pCon->per));
}
void AddContact(Contact* pCon)
{
	if (pCon->usedSize == MAX_person)
	{
		printf("满了\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", pCon->per[pCon->usedSize].name);
	printf("请输入性别：");
	scanf("%s", pCon->per[pCon->usedSize].sex);
	printf("请输入年龄:");
	scanf("%d", &(pCon->per[pCon->usedSize].age));
	printf("请输入电话:");
	scanf("%s", pCon->per[pCon->usedSize].tele);
	printf("请输入地址：");
	scanf("%s", pCon->per[pCon->usedSize].addr);
	pCon->usedSize++;
	printf("添加成功\n");
}
int SearchContact(Contact* pCon)
{
	printf("请输入姓名：");
	int i = 0;
	char name[10] = { 0 };
	if (pCon->usedSize == 0)
	{
		printf("通讯录为空");
		return -1;
	}
	scanf("%s", name);
	for (i = 0; i < pCon->usedSize; i++)
	{
		if (strcmp(pCon->per[i].name, name) == 0)
		{
			printf("%-10s%-10s%-10s%-15s%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
			printf("%-10s%-10s%-10d%-15s%-15s\n", pCon->per[i].name, pCon->per[i].sex, pCon->per[i].age, pCon->per[i].tele, pCon->per[i].addr);
			return i;
		}
	}
	return -1;
}
void DelContact(Contact* pCon)
{
	int index = SearchContact(pCon);
	int i = 0;
	if (index == -1)
	{
		printf("没找到\n");
		return;
	}
	//删除
	for (i = index; i <pCon->usedSize-1; i++)
	{
		pCon->per[i] = pCon->per[i + 1];

	}
	pCon->usedSize--;
	printf("删除成功\n");
}
void ShowContact(Contact* pCon)
{
	int i = 0;
	printf("%-10s%-10s%-10s%-15s%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (i = 0; i < pCon->usedSize; i++)
	{
		printf("%-10s%-10s%-10d%-15s%-15s\n", pCon->per[i].name,
			pCon->per[i].sex, pCon->per[i].age, pCon->per[i].tele, pCon->per[i].addr);
	}

}
void ClearContact(Contact* pCon)
{
	pCon->usedSize = 0;
	printf("清除成功\n");
}
