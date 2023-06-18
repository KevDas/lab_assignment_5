#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count = 0;

	while (head->next != NULL){

		count++;
		head = head->next;	

	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int strLen = length(head);
	char* string = malloc(strLen + 1);
	for (int i = 0; i < strLen+1; i++){

		string[i] = head->letter;
		head = head->next;
	}
	return string; 
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *tempNode;
	node *nextNode;

	nextNode=(node *) malloc( sizeof(node));
	nextNode->letter= c;
	nextNode->next=NULL;

	if(*pHead == NULL)
		{
			*pHead = nextNode;
		}
	else 
		{
			tempNode= *pHead;
			while(tempNode->next!=NULL)
				{
					tempNode=tempNode->next;
				}
			tempNode->next=nextNode;

		}	
}

	

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	int strLength = length(*pHead);
	
	node* tmp = *pHead;
	while (tmp->next != NULL){
		*pHead = tmp->next;
		free(tmp);
		tmp = *pHead;
	}
	*pHead = NULL; 
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}