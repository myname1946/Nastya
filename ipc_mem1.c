#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main () {
	int *array; //указатель на массив, расположенный в разделенной памяти
	int shmid; //идентификатор области разделяемрй памяти
	int new = 1; //признак необходимости создания нового массива
	char pathname[] = "forftok.ipc"; //файл небходимый для генерации ключа
	key_t key; //переменная для хранения ключа
        //попытка генерации ключа
	if ((key = ftok(pathname,0))<0) {
		printf("Не удалось сгенирировать ipc-ключ\n");
		exit(-1);
	}
	//попытка создания области разделенной памяти
	if((shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0) {
		//проверяем что ошибки при создании области разделяемой памяти не связаны  с тем 
		if(errno != EEXIST) {
			printf("Не удается создать область разделяемой памяти\n");
			exit(-1);
		}
		//получение индификатора области разделяемой памяти если область уже существует
		else {
			if((shmid = shmget(key, 3*sizeof(int), 0))<0) {
				printf("Не удается найти область разделяемой памяти\n");
                        	exit(-1);
			}
			new = 0; //установка признака уже существующей области разделяемой памяти
		}
	}
	//включение разделяемой памяти в адресное пространство текущего процесса
	if((array =(int*)shmat(shmid, NULL, 0)) == (int *)(-1)) {
		printf("Не удалось добавить разделяемую память в адресное пространство процесса\n");
		exit(-1);
	}
	//операции над вновь созданным массивом
	if(new) {
		array[0] = 0;
		array[1] = 1;
		array[2] = 1;
	}
	//операции над уже сущетсвующем массивом
	else {
		array[1] += 1;
		array[2] += 1;
	}
	printf("Программа 1 была запущена %d раз(а), программа 2 - %d раз(а), всего - %d\n", array[0], array[1],array[2]);
	//исключение области разделяемой памяти из адресного пространства текущего процесса
	if(shmdt(array)<0) {
		printf("Не удается исключить разделяемую память из адресованного пространства процесса\n");
		exit(-1);
	}
	return 0;
}