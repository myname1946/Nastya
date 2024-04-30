#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
// Создаем массив из двух элементов для хранения файловых дескрипторов  для чтения и записи
        int fd[2];
	pid_t result;
        size_t size;
        char string[] = "Hello, world!";
        char resstring[14];
        if(pipe(fd)<0){
		printf("Can\'t create pipe\n");
// Возврат признака аврийного завершения программы (-1)
		exit(-1);
	}
	result = fork();
	if (result<0) {
		printf("ошибка выполнения fork()\n");
		exit(-1);
	}
	else if (result>0) {
		if (close(fd[0])<0) {
			printf("ошибка при закрытии pipe на чтение\n");
			exit(-1);
		}
		size = write(fd[1], string, 14);
		// Проверка колличества байт, записанных в строку 
		if (size != 14) {
			printf("Can\'t write all string\n");
			exit(-1);
		}
		printf("процесс родитель записал информацию в pipe и заканчивает работу \n");
		if (close(fd[1])<0) {
                        printf("Can\'t close input stream\n");
                        exit(-1);
		}

	}
	else {
		if(close(fd[1])<0){
        	        printf("Can\'t close input stream\n");
			exit(-1);
	        }
	
		size = read(fd[0], resstring, 14);
		//Закрытие pipe для записи 
        	if(size !=14){
                	printf("Can\'t read string\n");		
      		       	 exit(-1);	
		}
		printf("%s\n",resstring);
		//Проверка колличества байт, прочитанных из pipe 
		if(close(fd[0])<0){
			printf("Can\'t close input stream\n");
		exit(-1);
		}
	}
        return 0;
}


