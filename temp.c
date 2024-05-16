#include <stdio.h>
#include <string.h>
static	int	is_ber_file(const char *argv);

int main(int argc, char **argv)
{

	if (argc == 2 && !(is_ber_file(argv[1])))
		printf("Can't open file. The format is not supported!\n");
	else if (argc != 2)
		printf("input format must be \".so_long [~.ber]\"\n");
	else if (argc == 2 && (is_ber_file(argv[1]))) 
		printf("file format is \".ber\"\n");
}



static	int	is_ber_file(const char *argv)
{
	char	*string;

	string = strrchr(argv, '.');
	if (string)
		return (strcmp(string, ".ber") == 0);
	return (0);
}