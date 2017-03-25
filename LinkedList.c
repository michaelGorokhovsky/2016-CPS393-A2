
#include <stdio.h>
#include <stdlib.h>
/*
Gorokhovsky, Michael
CPS393-3
*/
typedef struct NODE{
        int count;
        int fibbNum;
        struct NODE *next;
}NODE;

int main(){

        NODE *curr, *prev;
        curr = (NODE*)calloc(sizeof(NODE), 1);
        prev = (NODE*)calloc(sizeof(NODE), 1);
        curr->count = 2;
        prev->count = 1;
        curr->fibbNum = 1;
        prev->fibbNum = 1;
        prev->next = curr;
		
		NODE *head = prev;
		NODE *otherHead = prev;
		
		int newLineCounter = 1;

        while(curr->fibbNum < curr->count * 1000)
		{
			NODE *newNode;
			newNode = (NODE*)calloc(sizeof(NODE), 1);
			newNode->fibbNum = prev->fibbNum + curr->fibbNum;
			newNode->count = curr->count + 1;
			
			prev->next = curr;
			curr->next = newNode;
			
			prev = curr;
			curr = newNode;
		}
		
		while (head->fibbNum < head->count * 1000)
		{
      		printf("%d ", head->count);        
      		head = head->next;
		}
		printf("\n");
		while (otherHead->fibbNum < otherHead->count * 1000)
		{
			printf("%5d ", otherHead->fibbNum);
			if(newLineCounter==5)
			{
			    printf("\n");
			    newLineCounter = 0;
			}
			newLineCounter = newLineCounter + 1;
			otherHead = otherHead->next;
		
		}
        return 0;
}
