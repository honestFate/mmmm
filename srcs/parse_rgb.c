/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:36:18 by fate              #+#    #+#             */
/*   Updated: 2022/11/13 18:38:17 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_next_number(char *str, int *nmb, char del, int i)
{
	while (is_space(str[i]))
		++i;
	if (!ft_isdigit(str[i]))
	{
		return (-1);
	}
	*nmb = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		++i;
	while (is_space(str[i]))
		++i;
	if (str[i] != del)
		return (-1);
	++i;
	return (i);
}

int	parse_rgb(char *str, int *color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	i = get_next_number(str, &r, ',', i);
	if (i < 0)
		return (CUB_ERR);
	i = get_next_number(str, &g, ',', i);
	if (i < 0)
		return (CUB_ERR);
	i = get_next_number(str, &b, '\0', i);
	if (i < 0)
		return (CUB_ERR);
	*color = create_trgb(0, r, g, b);
	return (CUB_OK);
}
