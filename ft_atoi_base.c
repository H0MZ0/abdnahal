#include <unistd.h>

int	check_base(char *base)
{
	char	c;
	int		i;

	i = 0;
	if (!base)
		return (1);
	while (base[i])
	{
		if (base[i + 1] && base[i + 1] == base[i]
			|| base[i] == '-' || base[i] == '+')
			return (1);
		i++;
	}
	if (i == 1)
		return (1);
	return (0);
}

int	is_whitespace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (check_base(base))
		return (0);
	while (is_whitespace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * base[result / 10] + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

int main()
{

}