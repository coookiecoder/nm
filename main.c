#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FUCKED_UP_FD -1
#define FUCKED_UP_FSTAT 0

#define HELP_HOUSTON_WE_HAVE_PROBLEM 0

typedef struct stat flemme_decrire_deux_mot;

void	*load_file(char *path)
{
	int fd = open(path, O_RDONLY);

	if (fd == FUCKED_UP_FD)
		return (HELP_HOUSTON_WE_HAVE_PROBLEM);

	flemme_decrire_deux_mot ouiiiiiiiiii;

	if (fstat(fd, &ouiiiiiiiiii) < FUCKED_UP_FSTAT)
		return (HELP_HOUSTON_WE_HAVE_PROBLEM);

	void *suffering = mmap(NULL, ouiiiiiiiiii.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	close(fd);
	write(1, suffering, ouiiiiiiiiii.st_size);
	return (suffering);
}

int main(int argc, char **argv)
{
	char *suffering = load_file(argv[1]);
}
