// подключение библиотек 
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// главня фкнкция программы
int main(int argc, char *argv[], char *envp[])  {
	// обьявление переменных
	int result1;
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
		result1 = execle("/bin/cat", "/bin/cat", "otchet_16.04.2024.txt", 0, envp);
		printf("ошибка при выполнении системного вызова execle()\n");
	        exit(-1);

	}
	else {
		a = a + 555;
		procid = getpid(); // получение ид. текущего процесса
                parentid = getppid(); // получение ид. род-го процесса
                printf("Ид.процесса: %d, ид.родителя: %d, значение переменной a: %d\n ", procid, parentid, a);
	}
	return 0;//Никогда не выполняется
}
