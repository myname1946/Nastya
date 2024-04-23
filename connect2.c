#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//библиотека управления файлами
#include <fcntl.h>
int main() {
	int fd;
	size_t size;
//инициализируем массив символов, чтобы записать туда информацию
	char string[18];
//открытие файла на чтение
	if((fd = open("file1.txt", O_RDONLY))<0) {
		printf("ошибка при открытии файла на чтение\n");
		exit(-1);
	}
//чтение информации из файла
	size = read(fd, string, 18);
//проверка колличества прочитанных байт
	if (size != 18 ) {
		printf("не удалось прочитать всю строку в файл\n");
		exit(-1);
	}
//печать строки
	printf("%s\n", string);
//закрытие файла
	if(close(fd)<0) {
		printf("Не удалось закрыть файл\n");
		exit(-1);
	}
	return 0;
}
