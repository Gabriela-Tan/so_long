/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:31:29 by gabtan            #+#    #+#             */
/*   Updated: 2023/07/14 08:22:13 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	void			*temp;
	size_t			test;
	int				c;

	c = 0;
	if (count == 0 || size == 0)
	{
		temp = malloc(0);
		return (temp);
	}
	test = count * size;
	if (test / count != size)
		return (NULL);
	temp = malloc(size * count);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		((unsigned char *)temp)[i] = (unsigned char)c;
		i++;
	}
	return (temp);
}
