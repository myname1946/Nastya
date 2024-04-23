#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
// Создаем массив из двух элементов для хранения файловых дескрипторов  для чтения и записи
        int fd[2];
        size_t size;
        char string[] = "Hello, world!";
        char resstring[14];
        if(pipe(fd)<0){
		printf("Can\'t create pipe\n");
// Возврат признака аврийного завершения программы (-1)
		exit(-1);
	}
	size = write(fd[1], string, 14);
// Проверка колличества байт, записанных в строку 
	if(size != 14){
		printf("Can\'t write all string\n");
		exit(-1);
	}
	size = read(fd[0], resstring, 14);
// Проверка колличества байт, прочитанных  из pipe 
        if(size < 0){
                printf("Can\'t read string\n");
                exit(-1);
	}
	printf("%s\n",resstring);
//Закрытие pipe для чтения 
	if(close(fd[0])<0){
		printf("Can\'t close input stream\n");
	}
//Закрытие pipe для записи
	if(close(fd[1])<0){
		printf("Can\'t close output stream\n");
	}
        return 0;
}


