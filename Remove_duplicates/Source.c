// Hamvir Dev 

#include<stdio.h>
#include<stdlib.h>

// Include any of the below file by removing comment and commenting other file to include the header

#include"array_list.h" //The maximum size of array is 100 so give less than 100 values
//#include"curr_pointer_list.h"
//#include"prev_pointer_list.h"

int main()
{
	int flag = 1;
	int temp;
	point pos;
	struct list* l;
	l = (struct list*)malloc(sizeof(struct list));
	initialise_list(l);
	pos = initialise_pos(l);

	while (flag == 1)
	{
		printf("To enter number press 1 , to stop entering value press 0\n");
		scanf_s("%d", &flag);
		if (flag == 0)
			break;
		else
		{
			printf("Enter the number\n");
			scanf_s("%d", &temp);
			insert(l,temp,pos); // consider position starts from 0
			pos = next_pos(pos);
		}
	}

	point pos_1;
	pos_1 = initialise_pos(l);
	int temp_1;
	while (pos_1!=pos)
	{
		temp = retrieve(l, pos_1);
		point pos_2;
		pos_2 = next_pos(pos_1);
		while (pos_2 != pos)
		{
			temp_1 = retrieve(l, pos_2);
			if (temp_1 == temp)
			{
				delet(l, pos_2);
				pos = change_pos(l,pos);
			}
			else
				pos_2=next_pos(pos_2);
		}
		pos_1=next_pos(pos_1);
	}

	pos_1 = initialise_pos(l);
	printf("After removing the duplicates the list is:");
	while (pos_1 != pos)
	{
		temp = retrieve(l, pos_1);
		printf(" %d ", temp);
		pos_1 = next_pos(pos_1);
	}
	free(l);
	return(0);

}