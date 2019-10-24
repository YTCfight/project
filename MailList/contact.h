#ifndef _CONTACT_H_
#define _CONTACT_H_
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<Windows.h>
#include<assert.h>
enum Option
{
	EXIT,
	ADD,
	SEARCH,
	DEL,
	SHOW,
	CLEAR,
	SORT
};

#define MAX_NAME 20
#define MAX_TEL 11
#define MAX_ADDR 15
#define MAX_SEX 3
#define MAX_person 1000
//void InitContact(Contact* pCon);

typedef struct PersonInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	short age;
	char tele[MAX_TEL];
	char addr[MAX_ADDR];
	
}PersonInfo;

typedef struct Contact
{
	PersonInfo per[MAX_person];
	int usedSize;
}Contact;

void InitContact(Contact *pCon);
void AddContact(Contact *pCon);
int SearchContact(Contact *pCon);
void DelContact(Contact *pCon);
void ShowContact(Contact* pCon);
void ClearContact(Contact* pCon);
void SortContact(Contact* pCon);

#endif
