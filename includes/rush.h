/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:13:39 by hwong             #+#    #+#             */
/*   Updated: 2023/02/26 17:09:35 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RUSH_H
# define RUSH_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict
{
	unsigned int	nb;
	char			*val;
	struct s_dict	*next;
}					t_dict;

typedef struct s_num
{
	unsigned int	num;
	struct s_num	*next;
	struct s_num	*prev;
}					t_num;

/* UTILS */
int				ft_strlen(const char *s);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
char			*ft_join(char *buff, char *buffer);
unsigned int	ft_atoi(const char *str);
void			*ft_memmove(char *dst, const char *src, size_t n);
char			*get_next_line(int fd);
char			**ft_split(char const *s, char c);

void	*ft_free(char *ptr);
void	free_list(t_dict *lst);
void	free_tab(char **tab);

t_dict	*parse_dict(const char *path);

#endif