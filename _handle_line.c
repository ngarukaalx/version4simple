#include "main.h"
/**
* handle_line - the function name
* @line: parameter of type char *.
* @num_tokens: parameter of type int .
* @argv: parameter of type char **.
* @cmdnum: parameter of type int .
* Return: int .
*/
int handle_line(char *line, int num_tokens, char **argv, int cmdnum)
{
	char **array2 = NULL;
	int status = 0;

	array2 = create_array_from_line(line, num_tokens);
	if (array2 == NULL)
	{
		return (1);
	}
	status = execute_external_command(line, array2, argv, cmdnum);
	free(line);
	free_array(array2);
	return (status);
}
