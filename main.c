#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FD_ERROR -1

#define ERROR 0

void	*load_file(char *path)
{
	int fd = open(path, O_RDONLY);

	if (fd == FD_ERROR)
		return (ERROR);

	struct stat file_stat;

	if (fstat(fd, &file_stat) < 0)
		return (ERROR);

	void *suffering = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

	close(fd);

	return (suffering);
}

int main(int argc, char **argv)
{
	char	*file_data;

	if (argc == 1)
		file_data = load_file("./a.out");
	else
		file_data = load_file(argv[1]);
	if (file_data == ERROR)
		return (write(1, "cant open or map the file\n", 27) ,1);
}
