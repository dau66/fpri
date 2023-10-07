#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%s %p\n", NULL, NULL);
	ft_printf("%s %p\n", NULL,NULL);
}