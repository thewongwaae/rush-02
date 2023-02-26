/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:13:19 by hwong             #+#    #+#             */
/*   Updated: 2023/02/26 17:11:17 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	parse_words(t_dict **dict, char **darray)
{
	int		i;
	int		j;
	int		len;
	t_dict	*ptr;

	ptr = *dict;
	i = 0;
	while (darray[i])
	{
		j = 0;
		ptr->nb = ft_atoi(darray[i]);
		while (is_space(darray[i][j]) || darray[i][j] == ':')
			j++;
		len = 0;
		while (darray[i][j + len] >= 'a' && darray[i][j + len] <= 'z')
			len++;
		ptr->val = malloc(sizeof(char) * len + 1);
		ft_memmove(ptr->val, &darray[i][j], len);
		ptr->val[len + 1] = '\0';
		ptr->next = malloc(sizeof(t_dict));
		ptr = ptr->next;
		i++;
	}
}

t_dict	*parse_dict(const char *path)
{
	int		fd;
	char	*file;
	char	*line;
	char	**darray;
	t_dict	*dict;
	
	fd = open(path, O_RDONLY);
	file = NULL;
	line = get_next_line(fd);
	while (line)
	{
		file = ft_join(file, line);
		ft_free(line);
		line = get_next_line(fd);
	}
	ft_free(line);
	darray = ft_split(file, '\n');
	parse_words(&dict, darray);
	free_tab(darray);
	return (dict);
}
