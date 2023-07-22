#include "main.h"
/**
* execute_external_command - executes an external command
*@line: pointer to char from input
* @array: array of arguments
*@argv: pointer to main second argument
*@cmdnum: count of command
* Return: 0 on success, 1 on failure
*/
int execute_external_command(char *line, char **array,
char **argv, int cmdnum)
{
	struct stat *st;
	int isOnPath = -1;
    
	
	st = malloc(sizeof(struct stat));
	if (stat(array[0], st) == -1)
	{
		
		isOnPath = _chck_if_path(array, cmdnum);
		if (isOnPath == 0)
		{
			free(st);
			return (0);
		}
	}
		_executor(line, array, argv, cmdnum, st);
		free(st);
		return (0);
}
