/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:33:20 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/25 18:33:20 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(const char *str)
{
	int				res;
	int				sign;
	int				i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = sign * (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*rtn;

	i = 0;
	rtn = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rtn)
		return (NULL);
	while (s[i] && i < (size_t)ft_strlen(s))
	{
		rtn[i] = s[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	ft_digit_len(int n)
{
	int		sign;
	int		i;

	i = 0;
	sign = 0;
	if (!n)
		return (0);
	if (n < 0)
	{
		sign = 1;
		n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + sign);
}

char	*ft_positiv_letters(int n, int count)
{
	char	*letters;
	int		i;

	i = 0;
	letters = (char *)malloc(sizeof(char) * (count + 1));
	if (!letters)
		return (0);
	letters[count] = '\0';
	i = count;
	while (i >= 1)
	{
		i--;
		letters[i] = n % 10 + '0';
		n = n / 10;
	}
	return (letters);
}

char	*ft_negativ_letters(int n, int count)
{
	char	*letters;
	int		i;

	letters = NULL;
	i = 0;
	letters = (char *)malloc(sizeof(char) * (count + 1));
	if (!letters)
		return (0);
	letters[count] = '\0';
	i = count - 1;
	letters[0] = '-';
	while (i > 0)
	{
		letters[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (letters);
}

char	*ft_check_int(int n)
{
	char	*letters;

	letters = NULL;
	if (n == 0)
	{
		letters = (char *)malloc(sizeof(char) * (2));
		letters[0] = '0';
		letters[1] = '\0';
		return (letters);
	}
	if (n >= 2147483647 || n <= -2147483648)
	{
		if (n == -2147483648)
			letters = ft_strdup("-2147483648");
		else
			letters = ft_strdup("2147483647");
		return (letters);
	}
	return ("x");
}

char	*ft_itoa(int n)
{
	int		count;
	int		sign;
	char	*letters;

	letters = NULL;
	if (n == 0 || n >= 2147483647 || n <= -2147483648)
	{
		letters = ft_check_int(n);
		return (letters);
	}
	sign = 0;
	count = ft_digit_len(n);
	if (n < 0)
	{
		sign = -1;
		n = n * -1;
	}
	if (sign == -1)
		letters = ft_negativ_letters(n, count);
	else if (sign == 0)
		letters = ft_positiv_letters(n, count);
	if (!letters)
		return (0);
	return (letters);
}