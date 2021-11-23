#include <stdio.h>

void set_pow(int n, int *pow)
{
	int i = 0;
	while (i++ < n)
		*pow *= 10;
}

int ft_atoi(char *num)
{
	char *num2 = num;
	char n0 = num[0];
	
	int res = 0;
	int sign = n0 == '-' ? -1 : 1;
	int len = n0 == '-' ? -1 : 0;

	while ((*num >= '0' && *num <= '9') || (n0 == '-'))
	{
		if (n0 == '-') n0 = 'x';

		len++;
		num++;
	}
	
	int pow = 1;
	set_pow(len - 1, &pow);

	int i = sign < 0 ? 1 : 0;
	int j = sign < 0 ? 1 : 0;

	for (; i < len + j; i++)
	{
		res += pow * ((int) num2[i] - '0');
		pow /= 10;
	}

	return res * sign;
}

int main()
{
	char *num1 = "234.1";
	char *num2 = "-420";

	printf("num1: %s\n", num1);
	printf("num2: %s\n", num2);

	printf("\nft_atoi(num1): %d\n", ft_atoi(num1));
	printf("ft_atoi(num2): %d\n", ft_atoi(num2));

	return 0;
}
