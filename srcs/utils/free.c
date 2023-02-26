/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:13:26 by hwong             #+#    #+#             */
/*   Updated: 2023/02/26 17:13:58 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	*ft_free(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void	free_list(t_dict *lst)
{
	t_dict	*tmp;

	while (lst && lst->next)
	{
		tmp = lst;
		lst = lst->next;
		ft_free(tmp->val);
		free(tmp);
	}
	ft_free(lst->val);
	free(lst);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			ft_free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}
