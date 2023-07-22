#include "main.h"

int _chck_if_path(char **tokens, int cmdnum)
{
    int i = 0, isOnPath = -1;
    char *str = NULL, *path = NULL;

    while (environ[i] != NULL && isOnPath != 0)
    {
        if(_str_n_cmp("PATH=", environ[i], 5) == 0)
        {
            path = _strdup(environ[i]);
            strtok(path, "=");
            str = strtok(NULL, "=");
            isOnPath = _look_in_path(str, tokens, cmdnum);
            break;
        }
        i++;
    }
    free(path);
    return (isOnPath);

}