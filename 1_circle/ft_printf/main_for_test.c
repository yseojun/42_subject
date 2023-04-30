#include "ft_printf.h"
#include <stdio.h>

int main()
{
	ft_printf("%05.2s\n", "123");
	printf("%05.2s\n", "123");
}