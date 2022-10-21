/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:41:33 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/21 21:15:19 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h" 

int	ft_isdigit(int c);

int	ft_isalpha(int c);

int	is_sign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	is_space(int c)
{
	if (c < 33)
		return (1);
	return (0);
}

long	ft_atoi(char const *num)
{
	long	prefix;
	long	ans;

	prefix = 1;
	ans = 0;
	if (*num == '\0' || *num == '\e')
		return (0);
	while (is_space(*num))
		num++;
	while (is_sign(*num))
	{
		if (*num == '-')
			prefix *= -1;
		num++;
	}
	while (ft_isdigit(*num))
	{
		ans = (ans * 10) + *num - '0';
		num++;
	}
	return (prefix * ans);
}
/*

int	main(void)
{
	printf("atoi	: %d\n", atoi("  	123!"));
	printf("ft_atoi	: %d\n", ft_atoi("  	123!"));
	printf("atoi	: %d\n", atoi("  	-123!"));
	printf("ft_atoi	: %d\n", ft_atoi("  	-123!"));
	printf("atoi	: %d\n", atoi("   +-	123!"));
	printf("ft_atoi	: %d\n", ft_atoi("  +-	123!"));
	printf("atoi	: %d\n", atoi("		--123!"));
	printf("ft_atoi	: %d\n", ft_atoi("       --123!"));
	printf("atoi	: %d\n", atoi("123!"));
	printf("ft_atoi	: %d\n", ft_atoi("123!"));
	printf("atoi	: %d\n", atoi("-123!"));
	printf("ft_atoi	: %d\n", ft_atoi("\e456"));
	printf("ft_atoi	: %d\n", ft_atoi(""));
	printf("ft_atoi	: \es\n");
	return (0);
}*/
