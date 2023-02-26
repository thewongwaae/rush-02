/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:12:09 by hwong             #+#    #+#             */
/*   Updated: 2023/02/26 17:14:35 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*out;

	out = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!out)
		return (0);
	i = -1;
	while (s[++i])
		out[i] = s[i];
	out[i] = '\0';
	return (out);
}

unsigned int	ft_atoi(const char *str)
{
	int	i;
	unsigned int	sign;
	unsigned int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (!dst || !src)
		return (0);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (n-- > 0)
		*(ptr_dst++) = *(ptr_src++);
	return (dst);
}

void	*ft_memmove(char *dst, const char *src, size_t n)
{
	unsigned char	*point_dst;
	unsigned char	*point_src;

	point_dst = (unsigned char *)dst;
	point_src = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		point_dst += n;
		point_src += n;
		while (n-- > 0)
			*(--point_dst) = *(--point_src);
	}
	return (dst);
}
