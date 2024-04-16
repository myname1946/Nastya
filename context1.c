// подключение библиотек 
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// главня фкнкция программы
int main(int argc, char *argv[], char *envp[]) {
	int result;
	//Запуск программы cat с аргументом otch1.txt
	result = execle("/bin/cat", "/bin/cat", "otchet_16.04.2024.txt", 0, envp);
	//printf() выполняется тольлко в случае ошибки вызова  execle()
	printf("ошибка при выполнении системного вызова execle()\n");
	exit(-1);
	return 0;//Никогда не выполняется
}
