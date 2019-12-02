#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;

	for(int i=0;i<5;i++)
	{
	pid=fork();
	if(pid<0)
	{
		printf("Fork failed");
	}
	if(pid==0)
	{
		sleep(30);
		printf("\nIn Child Process\n");
		printf("\nChild Process ID: %d\n",getpid());
		printf("\nParent Process ID: %d\n",getppid());
		break;
	}
	else
	{
		printf("\nIn Parent Process\n");
		printf("\nChild Process ID: %d\n",pid);
		printf("\nParent Process ID: %d\n",getpid());
		int status=0;
		waitpid(pid,&status,0);
		if(WIFEXITED(status))
		{
			printf("\nExited Normally\n");
		}
	}
	}
}
