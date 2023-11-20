#include <iostream>
using namespace std;

typedef struct linkedlist {
    int num;
    struct linkedlist *next;
} lst;

void lst_push_front(lst **que, int i)
{
    lst *tonext;
    tonext = (lst *)malloc(sizeof(lst));
    if (!tonext)
        return;
    tonext->num = i;
    tonext->next = *que;
    *que = tonext;
}

int lst_front(lst *que)
{
    return (que->num);
}

lst *lst_go_last(lst *que)
{
	while (que->next != NULL)
		que = que->next;
	return (que);
}

void lst_push_back(lst **que, int i)
{
    lst *tonext;
    if (que == NULL)
        return;
    tonext = (lst *)malloc(sizeof(lst));
    tonext->num = i;
    tonext->next = NULL;
    if (!*que)
		*que = tonext;
	else
		lst_go_last(*que)->next = tonext;
}

void lst_pop(lst **que)
{ 
    if (*que == NULL)
        return;
    lst *second;
    second = (*que)->next;
    free (*que);
    *que = second;
}

int main()
{
    int n, i = 1;
    lst *que = NULL;

    cin >> n;
    while (i <= n)
    {
        lst_push_back(&que ,i);
        i++;
    }
    while (n > 1)
    {
        cout << lst_front(que) << ' ';

        lst_pop(&que);
        lst_push_back(&que, lst_front(que));
        lst_pop(&que);
        n--;
    }
    cout << lst_front(que);
}