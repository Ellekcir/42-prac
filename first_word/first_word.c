/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:56:58 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/29 15:26:03 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char s)
{
	return (s == ' ' || s == '\t');
}

void	ft_printfirstword(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	while (s[i] != '\0' && !ft_isspace(s[i]))
	{
		write(1, &s[i], 1);
		i++;
	}

}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
		ft_printfirstword(argv[1]);
	write(1, "\n", 1);
	return (0);
}
