#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
	int fd;
	size_t size;
	char string[17];
	if((fd = open("file1.txt", O_RDONLY))<0) {
		printf("ошибка при открытии файла на чтение\n");
		exit(-1);
	}
	size = read(fd, string, 17);
	if (size != 17 ) {
		printf("не удалось прочитать всю строку в файл\n");
		exit(-1);
	}
	printf("%s\n", string);
	if(close(fd)<0) {
		printf("Не удалось закрыть файл\n");
		exit(-1);
	}
	return 0;
}
