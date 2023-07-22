#include "main.h"

void _run_path_command(char *s, char **tokens, int cmdnum)
{
    int status = 0, x, y;
	pid_t child_pid;
	char *pthstr = NULL;

    x = _strlen(s);
    y = _strlen(tokens[0]);
    pthstr = malloc(sizeof(char) * (x + y + 2));
    if (pthstr == NULL)
    {
        perror("Error: ");
        exit(1);
    }
    _str_cpy(pthstr, s);
    _str_cat(pthstr, "/");
    _str_cat(pthstr, tokens[0]);
    pthstr[x + y + 1] = '\0';
    if(access(pthstr, X_OK) == 0)
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error: ");
            free(pthstr);
            free_array(tokens);
            exit(1);
        }
        if (child_pid == 0)
        {
                if(execve(pthstr, tokens, environ) == -1)
                {
                    _print_f("%s: %d: %s: not found\n", tokens[0], cmdnum, tokens[0]);
                    free(pthstr);
                    free_array(tokens);
                    _exit(-1);
                }
            } else
        {
        while (waitpid(-1, &status, 0) !=  child_pid)
                ;
        }
    }
    else
    {
        _print_f("%s: %d: %s: not found\n", tokens[0], cmdnum, tokens[0]);
        free(pthstr);
        return;
    }
    if (status == 0)
        errno = 0;
    free(pthstr);
}