#include <stdio.h>
#include <stdlib.h>
# define V 5

int queue[V];
int front =-1;
int rear = -1;

void enqueue(int x)
{
	if(rear == V-1)
	{
        printf("full\n");
        return ;
	}
	queue[++rear]=x;
	if(front == -1)
		front++;
}

int dequeue()
{
	if(front ==-1)
	{
		printf("Empty\n");
		return -1;
	}
	int x = queue[front];
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
		front++;

	return x;
}
