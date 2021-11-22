#include <stdio.h>

int ft_atoi(char *num)
{
	char *num2 = num;
	char n0 = num[0];
	int res = 0;
	int sign = 1;

	int len = 0;
	while ((*num >= '0' && *num <= '9') || (n0 == '-'))
	{
		if (n0 == '-')
		{
			sign = -1;
			n0 = 'x';
			len--;
		}
		len++;
		num++;
	}
	// printf(">> len: %d\n", len);

	int i = 0;
	int pow = 1;
	while (i < len - 1)
	{
		pow *= 10;
		i++;
	}

	i = 0;
	int j = 0;
	while (i < len + j)
	{
		if (sign < 0 && j == 0) 
		{
			i++;
			j++;
		}
		// printf("num2[%d] = %c\n", i, num2[i]);
		// printf("pow = %d\n", pow);

		res += pow * ((int) num2[i] - '0');
		// printf(">> res = %d\n", res);
		pow /= 10;
		
		i++;
	}

	return res * sign;
}

int main()
{
	char *num1 = "123-4";
	char *num2 = "-123";

	printf("num1: %s\n", num1);
	printf("num2: %s\n", num2);

	printf("\nft_atoi(num1): %d\n", ft_atoi(num1));
	printf("ft_atoi(num2): %d\n", ft_atoi(num2));

	return 0;
}
