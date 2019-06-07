/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:53:37 by fgaribot          #+#    #+#             */
/*   Updated: 2019/06/04 12:07:19 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The differents swaps.
*/

void	sa(int *a)
{
	int		swap;

	swap = a[0];
	a[0] = a[1];
	a[1] = swap;
}

void	sb(int *b)
{
	int		swap;

	swap = b[0];
	b[0] = b[1];
	b[1] = swap;
}

void	ss(int *a, int *b)
{
	sa(a);
	sb(b);
}

/*
** The differents push.
*/

void	pa(int *a, int *b)
{
	int		i;
	int		swap;
	int		swap2;

	i = 0;
	if (b[0])
	{
		swap = a[0];
		a[0] = b[0]
		while (*a)
		{
			i++;
			swap2 = a[i];
			a[i] = swap;
			swap = swap2;
		}
		correctb(int *b);
	}
}

void	correct(int *b)
{
	int		i;

	i = 0;
	while (*b)
	{
		b[i] = b[i + 1];
		i++;
	}
}
