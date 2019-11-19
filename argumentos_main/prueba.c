#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc  == 1)
	{
		printf("Ha olvidado su nombre y sus apellidos");
		exit (1);
	}

	if (argc  == 2)
	{
		printf("Ha olvidado  sus apellidos");
		exit (1);
	}
	if (argc  == 3)
	{
		printf("Ha olvidado  su segundo apellido");
		exit (1);
	}
	if (argc  == 4)
	{
		printf("Hola %s %s %s", argv[1], argv[2], argv[3]);
		exit (1);
	}


		
}
