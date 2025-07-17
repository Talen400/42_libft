#include <stdio.h>
#include "minunit.h"
#include "libft.h"
#include <ctype.h>

int tests_run = 0;

static char * test_isalpha()
{
	mu_assert("error, alpha 'a' == 'a'", ft_isalpha('a') == (isalpha('a') != 0));
	mu_assert("error, alpha 'z' == 'z'", ft_isalpha('z') == (isalpha('z') != 0));
	mu_assert("error, alpha 'a' - 1", ft_isalpha('a' - 1) == (isalpha('a' - 1) != 0));
	mu_assert("error, alpha 'z' + 1", ft_isalpha('z' + 1) == (isalpha('z' + 1) != 0));
	return (0);
}

static char * test_isdigit()
{
	char	num;

	num = '0';
	while (num <= '9')
	{
		mu_assert("error, expected digit", ft_isdigit(num) == (isdigit(num) != 0));
		num++;
	}
	return (0);
}

static char * test_isprint()
{
	char	num;

	num = 32;
	while (num < 127)
	{
		mu_assert("error, expected a printable char", ft_isprint(num) == (isprint(num) != 0));
		num++;
	}
	return (0);
}

static char * test_isalnum()
{
	mu_assert("error, expected a asii char", ft_isalnum('a') == (isalnum('a') != 0));
	mu_assert("error, expected a ascii char", ft_isalnum('z') == (isalnum('z') != 0));
	mu_assert("error, expected a ascii char", ft_isalnum('/') == (isalnum('/') != 0));
	mu_assert("error, expected a ascii", ft_isalnum('1') == (isalnum('1') != 0));
	mu_assert("error, expected a ascii", ft_isalnum('A') == (isalnum('A') != 0));
	mu_assert("error, expected a ascii", ft_isalnum('a' - 1) == (isalnum('a' - 1) != 0));
	return (0);
}

static char * test_isacii()
{
	mu_assert("error, expected a printable char", ft_isalnum('a') == (isalnum('a') != 0));
}

static char * all_tests()
{
	mu_run(test_isalpha);
	mu_run(test_isdigit);
	mu_run(test_isprint);
	mu_run(test_isalnum);

	return (0);
}

int main(void)
{
	char	*result = all_tests();
	
	if (result != 0)
	{
		printf("%s\n", result);
	}
	else
	{
		printf("All tests aproved\n");
	}
	printf("Tests run: %d\n", tests_run);
	return (result != 0);
}
