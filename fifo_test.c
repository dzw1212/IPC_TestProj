/* fifo_read_test.c */

#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{
	int fifo_fd = 0;
	int iRet = 0;
	char buf[20] = {0};

	iRet = mkfifo("./FIFOTEXT", 0777);
	if (iRet == -1) /* fifo aleady exist */
	{
		printf("fifo aleady exist.\n");
	}
	else
	{
		printf("create new fifo.\n");
	}
	fifo_fd = open("./FIFOTEXT", O_RDONLY);
	read(fifo_fd, buf, sizeof(buf));
	printf("buf is %s.\n", buf);
	close(fifo_fd);
}

/* fifo_write_test.c */

#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{
	int fifo_fd = 0;
	int iRet = 0;
	char buf[20] = "hello fifo";

	iRet = mkfifo("./FIFOTEXT", 0777);
	if (iRet == -1) /* fifo aleady exist */
	{
		printf("fifo aleady exist.\n");
	}
	else
	{
		printf("create new fifo.\n");
	}
	fifo_fd = open("./FIFOTEXT", O_WRONLY);
	write(fifo_fd, buf, sizeof(buf));
	printf("buf is %s.\n", buf);
	close(fifo_fd);
}
