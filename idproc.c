/Подключение библиотек 
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//Главная функция программы
int main() {
//Обьявление переменных
        pid_t getpid;
        pid_t getppid;
//Системный вызов getpid()
        pid = getpid();
//Системный вызов getppid()
        ppid = getppid();
        printf("Ид. пользователя: %d\n", userid); //Вызов функции printf()
        printf("Ид. группы пользователя: %d\n ", groupid);
//Возврат значения ноль из главной функции
        return 0;
}
