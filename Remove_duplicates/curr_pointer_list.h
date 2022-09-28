#pragma once
struct list
{
	struct list* next;
	int size;
	int data;
};

typedef struct list* point;

void initialise_list(struct list* l)
{
	l->next = NULL;
	l->size = 0;
	l->data = -1;
}

struct list* initialise_pos(struct list* l)
{
	return(l);
}

struct list* next_pos(struct list* l)
{
	if (l->next == NULL)
		printf("ERROR: Invalid position\n");
	else
		return(l->next);
}

struct list* change_pos(struct list* l, struct list* p)
{
	p = l;
	for (int i = 0; i < l->size; i++)
		p = p->next;
	return(p);
}

int empty(struct list* l)
{
	if (l->size == 0)
		return(1);
	else
		return(0);
}

void insert(struct list* l, int x, struct list* p)
{
	if (p == NULL)
	{
		printf("ERROR: Invalid position\n");
		return;
	}
	
	struct list* newnode = (struct list*)malloc(sizeof(struct list));
	newnode->data = p->data;
	newnode->next = p->next;
	p->data = x;
	p->next = newnode;
	l->size = l->size + 1;

}

void delet(struct list* l, struct list* p)
{
	if (l->size == 0)
	{
		printf("ERROR: The list is empty\n");
		return;
	}
	if (p->next == NULL)
	{
		printf("ERROR: Wrong position\n");
		return;
	}
	struct list* temp = p->next;
	p->data = temp->data;
	p->next = temp->next;
	temp->next = NULL;
	//free(temp);
	l->size = l->size - 1;
}

int retrieve(struct list* l,struct list* p)
{
	if (p == NULL)
	{
		printf("ERROR: Wrong position\n");
		return(-1);
	}
	else
	{
		return(p->data);
	}

}