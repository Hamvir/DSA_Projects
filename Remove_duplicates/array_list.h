#pragma once
int max_size = 100;
struct list {
	int arr[100];
	int size;//=0;
};

typedef int point;

void initialise_list(struct list* l)
{
	l->size = 0;
}

int initialise_pos(struct list* l)
{
	return(0);
}

int next_pos(int x)
{
	return(x + 1);
}

int change_pos(struct list* l, int x)
{
	return(x-1);
}

int empty(struct list* l)
{
	if (l->size == 0)
		return(1);
	else
		return(0);
}

void insert(struct list* l,int x,int p)
{
	if (l->size == max_size)
	{
		printf("ERROR : The array size is full\n");
		return;
	}
	if (p > l->size)
	{
		printf("ERROR: Invalid position\n");
		return;
	}


	for (int i = l->size;i>p;i--)
	{
		l->arr[i] = l->arr[i - 1];
	}
	l->arr[p] = x;
	l->size = l->size + 1;

}

void delet(struct list* l, int p)
{
	if (l->size == 0)
	{
		printf("ERROR: The list is empty\n");
		return;
	}
	if (p >= l->size)
	{
		printf("ERROR: Wrong position\n");
		return;
	}
	for (int i = p; i < l->size-1; i++)
	{
		l->arr[i] = l->arr[i + 1];
	}
	l->size = l->size - 1;
}

int retrieve(struct list* l, int p)
{
	if (p >= l->size)
	{
		printf("ERROR: Wrong position\n");
		return(-1);
	}
	else
		return(l->arr[p]);
}