#include <unistd.h>

void ft_ft(int *nbr);

int main(void)
{
	int *a;
	int b; 
	b='0';
	a=&b;
	ft_ft(a);
	return(0);
}
