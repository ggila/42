#include "test.h"
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int		test_isdigit(void)
{
	int		i;
	int		ret;
	char	str[] = "asd 123 ASD 546 asd";

	i = 0;
	ret = 0;
	while (str[i])
	{
		printf("%c %d %d\n", str[i], ft_isdigit(str[i]), isdigit(str[i]));
		if (ft_isdigit(str[i]) != isdigit(str[i]))
			ret = 1;
		i++;
	}
	return (ret);
}

int		test_isalpha(void)
{
	int		i;
	int		ret;
	char	str[] = "asd 123 ASD 546 asd";

	i = 0;
	ret = 0;
	while (str[i])
	{
		printf("%c %d %d\n", str[i], ft_isalpha(str[i]), isalpha(str[i]));
		if (ft_isalpha(str[i]) != isalpha(str[i]))
			ret = 1;
		i++;
	}
	return (ret);
}

int		test_isascii(void)
{
	int		i;
	int		ret;
	int		tab[] = {-10, -1, 0, 1, 2, 3, 4, 5, 125, 126, 127, 128, 129, 255};

	i = 0;
	ret = 0;
	while ((size_t)i < (sizeof(tab) / sizeof(int)))
	{
		printf("%d %d %d\n", tab[i], ft_isascii(tab[i]), isascii(tab[i]));
		if (ft_isascii(tab[i]) != isascii(tab[i]))
			ret = 1;
		i++;
	}
	return (ret);
}

int		test_isalnum(void)
{
	int		i;
	int		ret;
	char	str[] = "as!@4d 123 ASD $#!@42#{}| asd";

	i = 0;
	ret = 0;
	while (str[i])
	{
		printf("%c %d %d\n", str[i], ft_isalnum(str[i]), isalnum(str[i]));
		if (ft_isalnum(str[i]) != isalnum(str[i]))
			ret = 1;
		i++;
	}
	return (ret);
}

int		test_isprint(void)
{
	int		i;
	int		ret;
	int		tab[] = {-10, -1, 0, 1, 2, 40, 75, 125, 126, 127, 128, 129, 200};

	i = 0;
	ret = 0;
	while ((size_t)i < (sizeof(tab) / sizeof(int)))
	{
		printf("%c %d %d\n", tab[i], ft_isprint(tab[i]), isprint(tab[i]));
		if (ft_isprint(tab[i]) != isprint(tab[i]))
			ret = 1;
		i++;
	}
	return (ret);
}

int		test_tolower(void)
{
	int		i;
	int		ret;
	char	str[] = "as!@4d 123 ASD $#!@42#{}| asd";

	i = 0;
	ret = 0;
	while (str[i])
	{
		printf("%c %d %d\n", str[i], ft_tolower(str[i]), tolower(str[i]));
		if (ft_tolower(str[i]) != tolower(str[i]))
			ret = 1;
		i++;
	}
	return (ret);
}

int		test_toupper(void)
{
	int		i;
	int		ret;
	char	str[] = "as!@4d 123 ASD $#!@42#{}| asd";

	i = 0;
	ret = 0;
	while (str[i])
	{
		printf("%c %d %d\n", str[i], ft_toupper(str[i]), toupper(str[i]));
		if (ft_toupper(str[i]) != toupper(str[i]))
			ret = 1;
		i++;
	}
	return (ret);
}


int		test_puts(void)
{
	int		i;
	int		ret;
	int		tmp1;
	int		tmp2;
	char	str[][255] = {"Hello world", "123", ""};

	i = 0;
	ret = 0;
	while (i < 3)
	{
		tmp1 = ft_puts(str[i]);
		tmp2 =  puts(str[i]);
		printf("%s %d %d\n", str[i], tmp1, tmp2);
		fflush(stdout);
		if (tmp1 != tmp2)
			ret = 1;
		i++;
	}
	tmp1 =  ft_puts(NULL);
	printf("%s %d\n", "(null)", tmp1);
	fflush(stdout);
	return (ret);
}

int		test_bzero(void)
{
	size_t	len;
	char 	*str;

	len = 50;
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	bzero(str, (len + 1) * sizeof(char));
	memset(str, 'c', len);
	// Original 
	write(1, str, len);
	write(1, "\n", 1);
	// No size
	ft_bzero(str, 0);
	write(1, str, len);
	write(1, "\n", 1);
	// No str
	ft_bzero(NULL, 10);
	write(1, str, len);
	write(1, "\n", 1);
	// Normal use
	ft_bzero(str, 10);
	write(1, str, len);
	write(1, "\n", 1);
	return (0);
}


int		test_strcat(void)
{
	size_t	len;
	void	*ptr;
	char 	*str;

	len = 50;
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	memset(str, '.', len);
	write(1, str, len);
	write(1, "\n", 1);
	printf("INITIAL PTR : %p\n", str);
	fflush(stdout);
	str[0] = 0;
	// No src
	ptr = ft_strcat(NULL, "toto");
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// No dst
	ptr = ft_strcat(str, NULL);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// No arg
	ptr = ft_strcat(NULL, NULL);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// Normal Use 1
	ptr = ft_strcat(str, "Salut");
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// Normal Use 2
	ptr = ft_strcat(str, " ");
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// Normal Use 3
	ptr = ft_strcat(str, "toto");
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// Normal Use 4
	ptr = ft_strcat(str, "");
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// Normal Use 5
	ptr = ft_strcat(str, ".");
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	return (0);
}


int		test_strlen(void)
{
	int		i;
	int		ret;
	size_t	tmp1;
	size_t	tmp2;
	char	str[][255] = {"Hello world", "123", ""};

	i = 0;
	ret = 0;
	while (i < 3)
	{
		tmp1 = ft_strlen(str[i]);
		tmp2 =  strlen(str[i]);
		printf("%s: %zu %zu\n", str[i], tmp1, tmp2);
		fflush(stdout);
		if (tmp1 != tmp2)
			ret = 1;
		i++;
	}
	tmp1 = ft_strlen(NULL);
	printf("%s %zu\n", "(null)", tmp1);
	fflush(stdout);
	return (ret);
}


int		test_memset(void)
{
	size_t	len;
	void	*ptr;
	char 	*str;
	len = 50;
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	memset(str, '.', len);
	write(1, str, len);
	write(1, "\n", 1);
	printf("INITIAL PTR : %p\n", str);
	fflush(stdout);
	// No src
	ptr = ft_memset(NULL, 'c', 5);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// No size
	ptr = ft_memset(str, 'c', 0);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// Normal Use 1
	ptr = ft_memset(str, 'c', 5);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// Normal Use 2
	ptr = ft_memset(str + 10, 'a', 5);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// Normal Use 3
	ptr = ft_memset(str, 'a', 30);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	return (0);
}


int		test_memcpy(void)
{
	size_t	len;
	void	*ptr;
	char 	*str;
	len = 50;
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	memset(str, '.', len);
	write(1, str, len);
	write(1, "\n", 1);
	printf("INITIAL PTR : %p\n", str);
	fflush(stdout);
	// No s1
	ptr = ft_memcpy(NULL, "toto", 4);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// No s2
	ptr = ft_memcpy(str, NULL, 4);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// No ARG
	ptr = ft_memcpy(NULL, NULL, 4);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// No size
	ptr = ft_memcpy(str, "toto", 0);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// Normal Use 1
	ptr = ft_memcpy(str, "toto", 4);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// Normal Use 2
	ptr = ft_memcpy(str, "tutu", 5);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	// Normal Use 3
	ptr = ft_memcpy(str, "tatatatititi", 12);
	write(1, str, len);
	write(1, "\n", 1);
	printf("ptr : %p\n", ptr);
	fflush(stdout);
	return (0);
}

int		test_strdup(void)
{
	char 	*str;
	
	str = ft_strdup(NULL);
	printf("ptr : %d %p %s\n", ft_strlen(str), str, str);
	fflush(stdout);
	free(str);
	str = ft_strdup("toto");
	printf("ptr : %d %p %s\n", ft_strlen(str), str, str);
	fflush(stdout);
	free(str);
	str = ft_strdup("tatati");
	printf("ptr : %d %p %s\n", ft_strlen(str), str, str);
	fflush(stdout);
	free(str);
	str = ft_strdup("");
	printf("ptr : %d %p %s\n", ft_strlen(str), str, str);
	fflush(stdout);
	free(str);
	str = ft_strdup("123456789012345");
	printf("ptr : %d %p %s\n", ft_strlen(str), str, str);
	fflush(stdout);
	free(str);
	return (0);
}

int		test_cat(void)
{
	int		fd;

	puts("===================================================================");
	fd = open("fdgsdfgsfdg", O_RDONLY);
	printf("fd: %i\n", fd);
	fflush(stdout);
	ft_cat(fd);
	close(fd);
	puts("===================================================================");
	fd = open("Makefile", O_RDONLY);
	printf("fd: %i\n", fd);
	fflush(stdout);
	ft_cat(fd);
	close(fd);
	puts("===================================================================");
	ft_cat(-1);
	puts("===================================================================");
	ft_cat(0);
	puts("===================================================================");
	return (0);
}

typedef struct		s_test
{
	int		(*f)(void);
	char	*name;
}					t_test;

static const t_test	g_test[] = {
	{&test_isdigit, "IS DIGIT"},
	{&test_isalpha, "IS ALPHA"},
	{&test_isascii, "IS ASCII"},
	{&test_isalnum, "IS ALNUM"},
	{&test_isprint, "IS PRINT"},
	{&test_tolower, "TO LOWER"},
	{&test_toupper, "TO UPPER"},
	{&test_puts, "PUTS"},
	//
//	{&test_bzero, "BZERO"},
//	{&test_strcat, "STRCAT"},
//	{&test_strlen, "STRLEN"},
//	{&test_memset, "MEMSET"},
//	{&test_memcpy, "MEMCPY"},
//	{&test_strdup, "STRDUP"},
	//
	//
//	{&test_cat, "CAT"}
};

int		ft_test(t_test t)
{
	int 	ret;

	printf("=== ");
	printf("%s", t.name);
	printf(" ===\n");
	fflush(stdout);
	ret = t.f();
	if (!ret)
		printf("\033[32m=== OK ===\033[0m\n");
	else
		printf("\033[31m=== NO ===\033[0m\n");
	return (ret);
}

int		main(void)
{
	int		i;

	i = 0;
	while ((size_t)i < (sizeof(g_test) / sizeof(t_test)))
	{	
		ft_test(g_test[i++]);
	}
	return (0);
}
