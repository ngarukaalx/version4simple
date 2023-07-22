#include "main.h"
/**
* create_array_from_line - the function name
* @line: parameter of type char *.
* @num_tokens: parameter of type int .
* @array: parameter of type char **.
* Return: char **.
*/
char **create_array_from_line(char *line, int num_tokens)
{
	char *otherstr = NULL, *thirdstr = NULL, **array2 = NULL , **array = NULL;
	int x = 0;

	array = malloc(sizeof(char *) * (num_tokens));
	if (array == NULL)
	{
		free(line);
		return (NULL);
	}
	otherstr = _strdup(line);
	thirdstr = strtok(otherstr, " \t\r\n\f\v");
	if (thirdstr == NULL)
	{
		free(array);
		free(line);
		free(otherstr);
		return (NULL);
	}
	for (; thirdstr != NULL; thirdstr = strtok(NULL, " \t\r\n\f\v"))
		array[x++] = thirdstr;
	array2 = malloc(sizeof(char *) * (num_tokens + 1));
	if (array2 == NULL)
	{
		perror("Error: ");
		free(line);
		free(array);
		free(otherstr);
		return (NULL);
	}
	for (x = 0; x < num_tokens; x++)
		array2[x] = _strdup(array[x]);
	array2[x] = NULL;
	free(otherstr);
	free(array);
	return (array2);
}
