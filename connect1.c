#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//Подключение библиотеки для управления файлами
#include <fcntl.h>
int main() {
	int fd; //файловый дескриптор
	size_t size; //размер в байтах строки
	char string[]="Group 3.120.2.21\n";
//Открытие файла на запись, если файла не существует, то он будет создан с правами доступа 0666
	if((fd = open("file1.txt", O_WRONLY|O_CREAT, 0666))<0) {
		printf("ошибка при открытии файла на запись\n");
		exit(-1);
	}
//чтение из файла в строку string
	size = write(fd, string, 18);
	if (size != 18) {
		printf("не удалось записать всю строку в файл\n");
		exit(-1);
	}
//закрытие файла
	if(close(fd)<0) {
		printf("Не удалось закрыть файл\n");
		exit(-1);
	}
	return 0;
}
