#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
        pid_t pid,cid;

        for(int i=0;i<5;i++)
        {
        pid=fork();
	
        if(pid<0)
        {
                printf("Fork failed");
        }
        if(pid==0)
        {
                printf("\nIn Child Process\n");
                printf("\nChild Process ID: %d\n",getpid());
                printf("\nParent Process ID: %d\n",getppid());
		cid=fork();
		if(cid<0)
		{
			printf("\nFork is failed");
		}
		if(cid==0)
		{
			printf("\nChild of Child \n");
			printf("\nChild of child process ID:%d\n",getpid());
			printf("\nParent of Child process ID:%d\n",getppid());
		}
		else
		{
			printf("\nParent of Child\n");
			printf("\nParent of Child process:%d",getpid());
			printf("\nChild of Child process:%d",cid);
			int stat=0;
			waitpid(cid,&stat,0);
		}
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

