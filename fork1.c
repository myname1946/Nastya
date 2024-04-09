// программа для иллюстрации одинаковой работы процесса-родителя и процесса-ребенка
// подключение библиотек 
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// главня фкнкция программы
int main() {
	// обьявление переменных
	pid_t procid, parentid; // ид.процессов
	pid_t result; // рез. системного вызова fork()
	int a = 0; // переменная для проверки работы процесса-родителя и процесса-ребенка
	result = fork(); 
	if (result < 0) {
		printf("ошибка при выполнении fork()\n");
		exit(-1);
	}
	else if (result == 0) {
		a = a+1;
		procid = getpid(); // получение ид. текущего процесса
		parentid = getppid(); // получение ид. род-го процесса
		printf("Ид.процесса: %d, ид.родителя: %d, значение переменной a: %d\n ", procid, parentid, a);
	}
	else {
		a = a + 555;
		procid = getpid(); // получение ид. текущего процесса
                parentid = getppid(); // получение ид. род-го процесса
                printf("Ид.процесса: %d, ид.родителя: %d, значение переменной a: %d\n ", procid, parentid, a);
	}
	return 0;
}
