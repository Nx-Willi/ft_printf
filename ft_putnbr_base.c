/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:22:49 by wdebotte          #+#    #+#             */
/*   Updated: 2021/12/04 19:02:11 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define HEXA "0123456789ABCDEF"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_hexa(int nb, int caps)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr <= 15)
	{
		if (caps == 0 && (nbr >= 10 && nbr <= 15))
			ft_putchar(HEXA[nbr] + 32);
		else
			ft_putchar(HEXA[nbr]);
	}
	else
	{
		ft_putnbr_hexa(nbr / 16, caps);
		ft_putnbr_hexa(nbr % 16, caps);
	}
}

int	main()
{
	for (int i = 0; i <= 100; i++)
	{
	    ft_putnbr_hexa(i, 0);
	    printf("\n");
	}
}
