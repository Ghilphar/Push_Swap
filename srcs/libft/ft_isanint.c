/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isanint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:08:26 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/23 18:52:42 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isanint(char *str)
{
	int			i;
	int			x;
	int			neg;

	i = 0;
	neg = 1;
	if (!str)
		return (0);
	if (str[0] == 43 || str[0] == 45)
		i++;
	if (str[0] == 45)
		neg = -1;
	while (str[i] == 48)
		i++;
	x = i - 1;
	while (str[++x])
	{
		if ((str[x] < 48 || str[x] > 57) || (x - i > 10))
			return (0);
	}
	if ((x - i == 10 && neg == 1 && (str[i] > '2' || str[x - 1] > '7')) ||
	(x - i == 10 && neg == -1 && (str[i] > '2' || str[x - 1] > '8')) ||
	(neg == -1 && x == i))
		return (0);
	return (1);
}
