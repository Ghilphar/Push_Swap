/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:20:56 by fgaribot          #+#    #+#             */
/*   Updated: 2019/06/07 11:17:30 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		data_analysis(char *data)
{

}

int		ft_isdigit(char c)
{
	return (47 < c && c < 58) ? 1 : 0;
}

int		ft_isanint(char *str)
{
	int	i;

	i = 0;

	if (!str)
	return (0);
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != 45)
			return(0);
		i++;
		if (i > 11)
			return(0); 
	}
	if (i == 11 && (str[0] != '-' || str[1] > 2 || str[10] > '8'))
		return (0);
	if (i == 10 && (str[0] > '2' || str[9] > '7'))
		return (0);
	return (1);
}

void	ft_splitdata(char **av)
{
	int	i;

	i = 0;
	while (ft_isdigit(av[1][i]) || (i == 0 && av[1][i] == 45))
	{
		i++;
		if (i > 11)
			printf("%s\n", "ERROR");
	}
	if (av[1][i] != ' ' || av[1][i] != '\0')
		printf("%s\n", "ERROR");
	if (i == 11 && (av[1][0] != '-' || av[1][1] > 2 || av[1][10] > '8'))
		printf("%s\n", "ERROR");
	if (i == 10 && (av[1][0] > '2' || av[1][9] > '7'))
		printf("%s\n", "ERROR");
	//Cree le mayon et l'insere a la fin;
//	ft_splitdata(*av[1][i + 1]); //relance la fonction avec la suite.
}

void	parser(int ac, char ***av)
{
	if (!ft_isanint(*av[1]) && ac == 2)
		ft_splitdata(av);
}

int		main(int ac, char **av)
{
	parser(ac, *ac);
	if (ac <= 1)
		return (0);
	if (ac == 2)
	{
		cor_av(av[1]);
	}
	if (ac > 2)
	{
		return (0);
		//cor_av_2(*av);
	}
	return (0);
}
