#include "rush.h"

t_num	new_num(unsigned int nb)
{
	t_num	new;

	new.num = nb;
	new.next = NULL;
	new.prev = NULL;
	return (new);
}

t_num	*add_prev(t_num *lst, t_num new)
{
	t_num	*tmp;

	tmp = lst;
	new.next = tmp->prev;
	lst = new;
	return (lst);
}

t_num	*add_next(t_num *lst, t_num new)
{

}
