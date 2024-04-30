#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	// Создаем массив из двух элементов для хранения файловых дескрипторов  для чтения и записи
        int fd1[2], fd2[2];
	pid_t result;
        size_t size;
        char string1[] = "Hello, child!", string2[] = "Hello, parent!";
        char resstring1[13], resstring2[14];
        if (pipe(fd1)<0){
		printf("Can\'t create pipe\n");
	// Возврат признака аврийного завершения программы (-1)
		exit(-1);
	}
	if (pipe(fd2)<0){
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
		if (close(fd1[0])<0) {
			printf("ошибка при закрытии pipe на чтение\n");
			exit(-1);
		}
		if (close(fd2[1])<0) {
                        printf("ошибка при закрытии pipe на чтение\n");
                        exit(-1);
                }

		size = write(fd1[1], string1, 13);
		// Проверка колличества байт, записанных в строку 
		if (size != 13) {
			printf("Can\'t write all string\n");
			exit(-1);
		}
		printf("процесс родитель записал информацию в pipe и заканчивает работу \n");
		size = read(fd2[0], resstring2, 14);
                //Проверка колличества байт, записанных в строку  
                if(size !=14){
                        printf("Can\'t read string\n");         
                         exit(-1);      
                }
                printf("Информация от дочернего процесса: %s\n",resstring2);
		if (close(fd1[1])<0) {
                        printf("Can\'t close output stream\n");
                        exit(-1);
		}
		if (close(fd2[0])<0) {
                        printf("Can\'t close input stream\n");
                        exit(-1);
                }


	}
	else {
		if(close(fd1[1])<0){
        	        printf("Can\'t close output stream\n");
			exit(-1);
	        }
		if(close(fd2[0])<0){
                        printf("Can\'t close input stream\n");
                        exit(-1);
                }
		size = read(fd1[0], resstring1, 13);
		//Закрытие pipe для записи 
        	if(size !=13){
                	printf("Can\'t read string\n");		
      		       	 exit(-1);	
		}
		printf("%s\n",resstring1);
		size = write(fd2[1], string2, 14);
                // Проверка колличества байт, записанных в строку 
                if (size != 14) {
                        printf("Can\'t write all string\n");
                        exit(-1);
                }
                printf("процесс ребенок  записал информацию в pipe \n");
		//Проверка колличества байт, прочитанных из pipe 
		if(close(fd1[0])<0){
			printf("Can\'t close input stream\n");
			exit(-1);
		}
		if(close(fd2[1])<0){
                        printf("Can\'t close  output stream\n");
	                exit(-1);
                }

	}
        return 0;
}


