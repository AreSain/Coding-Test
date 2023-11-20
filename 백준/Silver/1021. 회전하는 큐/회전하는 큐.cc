#include <iostream>
using namespace std;

typedef struct linkedlist {
    int num;
    struct linkedlist* next;
} lst;

typedef struct queue {
    lst* front;
    lst* back;
} queue;

void lst_push_front(queue** q, int i)
{
    lst* tonext;
    tonext = (lst*)malloc(sizeof(lst));
    if (!tonext)
        return;
    tonext->num = i;
    if (!*q)
    {
        *q = (queue*)malloc(sizeof(queue));
        (*q)->front = tonext;
        (*q)->back = tonext;
    }
    else
    {
        tonext->next = (*q)->front;
        (*q)->front = tonext;
    }
}

int lst_front(queue* q)
{
    return (q->front->num);
}

int lst_back(queue* q)
{
    return (q->back->num);
}

lst* lst_go_last(queue* q)
{
	if (q == NULL || q->front == NULL)
		return NULL;

	lst* temp = q->front;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	return temp;
}

void lst_push_back(queue** q, int i)
{
    lst* tonext;
    if (q == NULL)
        return;
    tonext = (lst*)malloc(sizeof(lst));
    tonext->num = i;
    tonext->next = NULL;
    if (!*q)
    {
        *q = (queue*)malloc(sizeof(queue));
        (*q)->front = tonext;
        (*q)->back = tonext;
    }
    else
    {
        (*q)->back->next = tonext;
        (*q)->back = tonext;
    }
}

void lst_pop(queue** q)
{
	if (*q == NULL)
		return;
	lst* second = (*q)->front->next;
	free((*q)->front);
	(*q)->front = second;
}

void lst_last_pop(queue** q)
{
	if ((*q)->front == (*q)->back)
	{
		free((*q)->back);
		(*q)->front = (*q)->back = NULL;
		return;
	}
	lst* temp;
	temp = (*q)->front;
	while (temp->next != (*q)->back)
		temp = temp->next;
	free((*q)->back);
	(*q)->back = temp;
	temp->next = NULL;
}

int lst_search(queue *q, int n)
{
	int i = 1;

	lst* temp = q->front;
	while (temp != NULL && temp->num != n)
	{
		temp = temp->next;
		i++;
	}
	return i;
}

int lst_size(queue* q)
{
	int i = 1;

	lst* temp = q->front;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return i;
}

int main()
{
    int n, i = 1, b = 0, c = 0, index, target;
    queue* q = NULL;

    cin >> n;
    while (i <= n)
    {
        lst_push_back(&q, i);
        i++;
    }
    cin >> i;
    while (i > 0)
    {

        cin >> target;
		index = lst_search(q, target);
		int move_front = index - 1;
		int move_back = lst_size(q) - index + 1;
		if (move_front <= move_back)
        {
			while (lst_front(q) != target)
			{
				lst_push_back(&q, lst_front(q));
				lst_pop(&q);
				b++;
			}
			lst_pop(&q);
        }
		else
		{
			while (lst_front(q) != target)
			{
				lst_push_front(&q, lst_back(q));
				lst_last_pop(&q);
				c++;
			}
			lst_pop(&q);
		}
        i--;
    }
    cout << b + c;
}