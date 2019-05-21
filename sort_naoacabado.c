
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define Max 64

struct Node
{
	char *data;
	struct Node *next;
};

void bubbleSort(struct Node *start);
int verifica(char palavra[], char palavra2[], int i);


int verifica(char palavra[], char palavra2[], int i) {
		if (palavra[i]=='\0') return -1;
		if (palavra2[i]=='\0') return 1;
		if (palavra[i] > palavra2[i]) return 1;
		if (palavra[i] == palavra2[i]) {
			
			i++;
			verifica(palavra, palavra2, i);
		}
		
		return -1;
	}
	
void bubbleSort(struct Node *start)
{
	int swapped, i=0;
	struct Node *ptr1;
	struct Node *lptr = NULL;
	
	struct Node *temp;
	
	
	do
	{
		swapped = 0;
		
		ptr1 = start;
		
		
		while (ptr1->next != lptr)
		{
			if (verifica(ptr1->data, ptr1->data, 0)==1)
			{
				//troca
				if (ptr1==start)
					temp= ptr1;
					ptr1 = ptr1->next;
					ptr1->next= temp;
					
					swapped = 1;
			}
			
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	while (swapped);
	// so é swapped quando existe alguma troca na lista
}


