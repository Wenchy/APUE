/*
 * a simple signal handler that catches either of the two user-defined
 * signals and prints the signal number.
 *
 * Test case:
 * $ ./a.out & #start process in background
 * [1] 7216 job-control shell prints job number and process ID
 * $ kill -USR1 7216 #send it SIGUSR1
 * received SIGUSR1
 * $ kill -USR2 7216 #send it SIGUSR2
 * received SIGUSR2
 * $ kill 7216 #now send it SIGTERM
 * [1]+ Terminated ./a.out
 * /

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sig_usr(int); /* one handler for both signals */

int main(void)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		fprintf(stderr, "can't catch SIGUSR1");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		fprintf(stderr, "can't catch SIGUSR2");
	for ( ; ; )
		pause();
}
static void sig_usr(int signo) /* argument is signal number */
{
	if (signo == SIGUSR1)
		fprintf(stdout, "received SIGUSR1\n");
	else if (signo == SIGUSR2) 
		fprintf(stdout, "received SIGUSR2\n");
	else
		fprintf(stdout, "received signal %d\n", signo);	
}
