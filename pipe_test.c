#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    pid_t pid = 0;
    int iRet = 0;
    int fd[2] = {0};
    char buf[20] = "hello";

    pipe(fd);

    iRet = fork();
    if (iRet < 0) /* fork failed */
    {
        printf("for failed!\n");
        return -1;
    }
    else if (iRet == 0) /* in child process */
    {
        close(fd[0]);
        write(fd[1], buf, sizeof(buf));
        exit(0);
    }
    else /* in parent process */
    {
        close(fd[1]);
        memset(buf, 0, sizeof(buf));
        read(fd[0], buf, sizeof(buf));
        printf("buf is %s.\n", buf);
        wait(NULL);
    }
    return 0;
}
