#include "header.h"

void	ft_lstinser(t_map *alst, t_map *new)
{
	if (!new)
		return ;
	new->next = alst->next;
	new->prev = alst;
	alst->next = new;
	if (new->next != NULL)
		new->next->prev = new;

}
