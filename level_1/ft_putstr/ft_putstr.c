/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:33:10 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/29 15:46:29 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i],1);
		i++;
	}
}
/*
int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		ft_putstr(argv[1]);
	}
	else
		write(1, "Usage: ./program_name <enter_your_string>\n", 42);
	return (0);
}
*/
