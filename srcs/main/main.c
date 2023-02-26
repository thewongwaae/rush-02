/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:13:16 by hwong             #+#    #+#             */
/*   Updated: 2023/02/26 17:12:38 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	get_digits(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

// unsigned int	*split_nb(unsigned int nb)
// {
// 	int				digits;
// 	int				i;
// 	unsigned int	*arr;

// 	digits = get_digits(nb);
// 	if (nb < 21)
// 		arr[i] = nb;
// 	else if (nb > 20 && nb < 100)
// 		twenty(&arr, &i);
// 	else if (nb > 100 && nb < 1000)
// 		hundred(&arr, &i);
// 	else if (nb > 1000 && nb < 1000000)
// 		thousand(&arr, &i);
// 	else if (nb > 1000000 && nb < 1000000000)
// 		million(&arr, &i);
// 	return (arr);
// }

unsigned int*	split_nb(unsigned int nb)
{
	unsigned int*	arr;
	int				digits;
	int				i;
	int				divisor;

    if (nb == 0)
	{
        arr = (unsigned int*) malloc(sizeof(unsigned int));
        arr[0] = 0;
        return arr;
    }

    digits = get_digits(nb);
	i = digits - 1;
    arr = (unsigned int*) malloc(sizeof(unsigned int) * digits);
    divisor = 1;
    while (i >= 0)
	{
		arr[i] = (nb / divisor) * divisor;
		nb -= arr[i];
		divisor *= 10;
		i--;
	}
    return (arr);
}

int	print_word(t_dict *dict, unsigned int nb)
{
	int				i;
	int				len;
	t_dict			*ptr;
	unsigned int	*nbarr;

	i = -1;
	ptr = dict;
	len = get_digits(nb);
	nbarr = split_nb(nb);
	while (++i < len)
	{
		while (ptr->nb != nbarr[i])
			ptr = ptr->next;
		write(1, ptr->val, ft_strlen(ptr->val));
		write(1, " ", 1);
		ptr = dict;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_dict			*dict;
	unsigned int	nb;

	dict = malloc(sizeof(t_dict));
	if (ac == 2)
	{
		dict = parse_dict("../../dict/numbers.dict");
		nb = ft_atoi(av[1]);
	}
	else if (ac == 3)
	{
		dict = parse_dict(av[1]);
		nb = ft_atoi(av[2]);
	}
	else
		return (write(2, "Too many arguments\n", 20));
	if (!dict)
		return (write(2, "Dict Error\n", 11));
	if (!print_word(dict, nb))
		write(2, "Dict Error\n", 11);
	free_list(dict);
	return (0);
}
