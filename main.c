#include <stdio.h>
#include "minunit.h"
#include "libft.h"
#include <ctype.h>
#include <string.h>

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
	mu_assert("error, expected a alphanum in isalnum", ft_isalnum('a') == (isalnum('a') != 0));
	mu_assert("error, expected a alphanum in isalnum", ft_isalnum('z') == (isalnum('z') != 0));
	mu_assert("error, expected a alphanum in isalnum", ft_isalnum('/') == (isalnum('/') != 0));
	mu_assert("error, expected a alphanum in isalnum", ft_isalnum('1') == (isalnum('1') != 0));
	mu_assert("error, expected a alphanum in isalnum", ft_isalnum('A') == (isalnum('A') != 0));
	mu_assert("error, expected a alphanum in isalnum", ft_isalnum('a' - 1) == (isalnum('a' - 1) != 0));
	return (0);
}

static char * test_isascii()
{
	mu_assert("error, expected a char ascii", ft_isascii('a') == (isascii('a') != 0));
	return (0);
}

static char * test_strlen()
{
	mu_assert("error, strlen", ft_strlen("a") == (strlen("a") != 0));
	return (0);
}

static char * test_toupper()
{
	mu_assert("error, toupper", ft_toupper('a') == toupper('a'));
	mu_assert("error, toupper", ft_toupper('A') == toupper('A'));
	return (0);
}

static char * test_tolower()
{
	mu_assert("error, tolower", ft_tolower('a') == tolower('a'));
	mu_assert("error, tolower", ft_tolower('A') == tolower('A'));
	return (0);
}

static char * test_bzero()
{
	char	str[] = "asdfz\f asd da";
	char	str2[] = "asdfz\f asd da";
	int		i;

	ft_bzero(str, 13);
	bzero(str2, 13);
	i = 0;
	while (i < 13)
	{
		mu_assert("error, bezero", str[i] == str2[i]);
		i++;
	}
	return (0);
}

static char * test_strncmp()
{
	mu_assert("error, strncmp (abc, ab, 3)", ft_strncmp("abc", "ab", 3) == strncmp("abc", "ab", 3));
	mu_assert("error, strncmp (abc, abc, 2)", ft_strncmp("abc", "abc", 2) == strncmp("abc", "abc", 2));
	mu_assert("error, strncmp (abcd, abc, 4)", ft_strncmp("abcd", "abc", 4) == strncmp("abcd", "abc", 4));
	mu_assert("error, strncmp (abcd, abc, 3)", ft_strncmp("abcd", "abc", 3) == strncmp("abcd", "abc", 3));
	mu_assert("error, strncmp (abcd, abc, 5)", ft_strncmp("abcd", "abc", 5) == strncmp("abcd", "abc", 5));
	mu_assert("error, strncmp ("", "", 1)", ft_strncmp("", "", 1) == strncmp("", "", 1));
	mu_assert("error, strncmp ("", asdfasfasdfas, 10)", ft_strncmp("", "asdfasfasdfas", 10) == strncmp("", "asdfasfasdfas", 10));
	mu_assert("error, strncmp (\201, A, 1)", ft_strncmp("\201", "A", 1) == strncmp("\201", "A", 1));
	return (0);
}

static char * test_strchr()
{
	mu_assert("error, strchr(abcdef, d)", ft_strchr("abcdef", 'd') == strchr("abcdef", 'd'));
	mu_assert("error, strchr(abcef, d)", ft_strchr("abcef", 'd') == strchr("abcef", 'd'));
	mu_assert("error, strchr(abcdfd, d)", ft_strchr("abcdfd", 'd') == strchr("abcdfd", 'd'));
	return (0);
}

static char * test_strrchr()
{
	mu_assert("error, strrchr(abcdfd, d)", ft_strrchr("abcdfd", 'd') == strrchr("abcdfd", 'd'));
	return (0);
}

static char * test_strnstr()
{
	// Substring encontrada dentro do limite
    mu_assert("Erro: deveria retornar \"world\"",
        strcmp(ft_strnstr("hello world", "world", 11), "world") == 0);
    mu_assert("Erro: deveria retornar \"cde\"",
        strcmp(ft_strnstr("abcde", "cd", 5), "cde") == 0);
    // Substring não encontrada por limite muito curto
    mu_assert("Erro: deveria retornar NULL (substring fora do limite)",
        ft_strnstr("hello world", "world", 5) == NULL);
    // Substring não encontrada
    mu_assert("Erro: deveria retornar NULL (substring não existe)",
        ft_strnstr("abcdef", "gh", 6) == NULL);
    // Needle vazia deve retornar haystack
    mu_assert("Erro: needle vazia deve retornar haystack",
        strcmp(ft_strnstr("abc", "", 3), "abc") == 0);
    // Needle maior que haystack
    mu_assert("Erro: needle maior que haystack deve retornar NULL",
        ft_strnstr("abc", "abcd", 4) == NULL);
    // Needle no final do haystack, limite exato
    mu_assert("Erro: deveria retornar \"e\"",
        strcmp(ft_strnstr("abcde", "e", 5), "e") == 0);
    // Teste com len 0
    mu_assert("Erro: com len 0 e needle não vazia, deve retornar NULL",
        ft_strnstr("abc", "a", 0) == NULL);
    // Teste com len 0 e needle vazia
    mu_assert("Erro: com len 0 e needle vazia, deve retornar haystack",
        strcmp(ft_strnstr("abc", "", 0), "abc") == 0);
	return (0);
}

static char	* test_strlcpy()
{
	char	dst[10];

	mu_assert("Erro: strlcpy", ft_strlcpy(dst, "asdfasdfafagag", 10) == 14);
	mu_assert("Erro: strlcpy", ft_strlcpy(dst, "afafagag", 12) == 8);
	mu_assert("Erro: strlcpy", ft_strlcpy(dst, "afasdfaa", 7) == 8);

	char buf[20];
    size_t ret;

    // Teste 1: copiar string normalmente (buffer grande)
    ret = ft_strlcpy(buf, "hello", 20);
    mu_assert("Erro: retorno incorreto (1)", ret == 5);
    mu_assert("Erro: conteúdo incorreto (1)", strcmp(buf, "hello") == 0);

    // Teste 2: copiar string com buffer pequeno (truncamento)
    ret = ft_strlcpy(buf, "hello world", 6);
    mu_assert("Erro: retorno incorreto (2)", ret == 11);
    mu_assert("Erro: conteúdo incorreto (2)", strcmp(buf, "hello") == 0);

    // Teste 3: copiar string com size == 0 (não copia nada)
    strcpy(buf, "unchanged");
    ret = ft_strlcpy(buf, "new", 0);
    mu_assert("Erro: retorno incorreto (3)", ret == 3);
    mu_assert("Erro: buffer deve permanecer igual (3)", strcmp(buf, "unchanged") == 0);

    // Teste 4: copiar string vazia
    ret = ft_strlcpy(buf, "", 10);
    mu_assert("Erro: retorno incorreto (4)", ret == 0);
    mu_assert("Erro: conteúdo incorreto (4)", strcmp(buf, "") == 0);
	return (0);
}

static char	* test_strlcat()
{
	char buf[20];

	// Teste 1: concatenação normal
	strcpy(buf, "abc");
	mu_assert("Erro: retorno incorreto (1)", ft_strlcat(buf, "def", 10) == 6);
	mu_assert("Erro: conteúdo incorreto (1)", strcmp(buf, "abcdef") == 0);

	// Teste 2: truncamento (size menor que resultado final)
	strcpy(buf, "abc");
	mu_assert("Erro: retorno incorreto (2)", ft_strlcat(buf, "defgh", 6) == 8);
	mu_assert("Erro: conteúdo incorreto (2)", strcmp(buf, "abcde") == 0);

	// Teste 3: size menor que strlen(dst), nada deve ser concatenado
	strcpy(buf, "hello");
	mu_assert("Erro: retorno incorreto (3)", ft_strlcat(buf, "world", 3) == 8);
	mu_assert("Erro: conteúdo incorreto (3)", strcmp(buf, "hello") == 0);
	return (0);
}

static char	* test_memset()
{
	char buffer[20];
    char expected[20];

    // Teste 1: Preencher com 'A'
    ft_memset(buffer, 'A', 5);
    memset(expected, 'A', 5);
    mu_assert("Erro: memset (1)", memcmp(buffer, expected, 5) == 0);

    // Teste 2: Preencher com 0 (zero)
    strcpy(buffer, "abcdef");
    strcpy(expected, "abcdef");
    ft_memset(buffer + 2, 0, 3);
    memset(expected + 2, 0, 3);
    mu_assert("Erro: memset (2)", memcmp(buffer, expected, 6) == 0);

    // Teste 3: Preencher buffer inteiro com '*'
    ft_memset(buffer, '*', sizeof(buffer));
    memset(expected, '*', sizeof(expected));
    mu_assert("Erro: memset (3)", memcmp(buffer, expected, sizeof(buffer)) == 0);
	return (0);
}

static char * test_memcpy()
{
	char src[20] = "Hello, World!";
    char dst[20];
    char expected[20];

    // Teste 1: Cópia simples de 5 bytes
    ft_memcpy(dst, src, 5);
    memcpy(expected, src, 5);
    mu_assert("Erro: memcpy (1)", memcmp(dst, expected, 5) == 0);

    // Teste 2: Cópia de string completa com \0 incluído
    ft_memcpy(dst, src, strlen(src) + 1);  // inclui o terminador nulo
    memcpy(expected, src, strlen(src) + 1);
    mu_assert("Erro: memcpy (2)", memcmp(dst, expected, strlen(src) + 1) == 0);

    // Teste 3: Cópia de 0 bytes (não deve alterar nada)
    strcpy(dst, "unchanged");
    strcpy(expected, "unchanged");
    ft_memcpy(dst, src, 0);
    memcpy(expected, src, 0);
    mu_assert("Erro: memcpy (3)", memcmp(dst, expected, strlen(expected) + 1) == 0);
	return (0);
}

static char	* test_atoi()
{
	printf("%i\n", ft_atoi("42"));
	printf("%i\n", ft_atoi("1"));
	printf("%i\n", ft_atoi("+1"));
	printf("%i\n", ft_atoi("-1"));
	
	mu_assert("Erro: ft_atoi test 1", ft_atoi(" 1") == 1);
	mu_assert("Erro: ft_atoi test 2", ft_atoi("a1") == 0);
	mu_assert("Erro: ft_atoi test 3", ft_atoi("--1") == 0);
    mu_assert("Erro: ft_atoi test 4", ft_atoi("++1") == 0);
    mu_assert("Erro: ft_atoi test 5", ft_atoi(" +1") == 1);
    mu_assert("Erro: ft_atoi test 6", ft_atoi(" -1") == -1);
    mu_assert("Erro: ft_atoi test 7", ft_atoi("0") == 0);
    mu_assert("Erro: ft_atoi test 8", ft_atoi("+42lyon") == 42);
    mu_assert("Erro: ft_atoi test 9", ft_atoi("+101") == 101);
    mu_assert("Erro: ft_atoi test 10", ft_atoi("2147483647") == 2147483647);
    mu_assert("Erro: ft_atoi test 11", ft_atoi("-2147483648") == -2147483648);
    mu_assert("Erro: ft_atoi test 12", ft_atoi("-+42") == 0);
    mu_assert("Erro: ft_atoi test 13", ft_atoi("+-42") == 0);
    mu_assert("Erro: ft_atoi test 14", ft_atoi("+42") == 42);
    mu_assert("Erro: ft_atoi test 15", ft_atoi("-42") == -42);
    mu_assert("Erro: ft_atoi test 16", ft_atoi("142") == 142);
    mu_assert("Erro: ft_atoi test 17", ft_atoi("-142") == -142);
	return (0);
}

static char * all_tests()
{
	mu_run(test_isalpha);
	mu_run(test_isdigit);
	mu_run(test_isprint);
	mu_run(test_isalnum);
	mu_run(test_isascii);
	mu_run(test_strlen);
	mu_run(test_toupper);
	mu_run(test_tolower);
	mu_run(test_bzero);
	mu_run(test_strncmp);
	mu_run(test_strchr);
	mu_run(test_strrchr);
	mu_run(test_strnstr);
	mu_run(test_strlcpy);
	mu_run(test_strlcat);
	mu_run(test_memset);
	mu_run(test_memcpy);

	mu_run(test_atoi);
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
