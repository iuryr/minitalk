#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	pid_t	current_pid;
	pid_t	parent_pid;

	current_pid = getpid();
	parent_pid = getppid();

	printf("Current process PID: %i\n", current_pid);
	printf("Parent process PID: %i\n", parent_pid);


}
