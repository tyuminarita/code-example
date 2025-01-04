#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>



int main(){

    char *line1;
    char *line2;
    void function1(char *line1);
    void function2(char *line1);
    int function3(char *line1, char *line2);
    void function4(char *line1);

    printf("\t\t\tВыберите один из следующих вариантов:\n\n");
    printf("1. Функция считывания произведения всех кодов символов.\n");
    printf("2. Функция перевода двоичного числа в десятичную систему счисления.\n");
    printf("3. Функция проверяющая вхождение одной строки во вторую.\n");
    printf("4. Функция считающая количество гласных букв в строке.\n");
    printf("5. Завершить программу.\n\n");

    printf("Введите номер выбранной функции: ");

    char c;
    int b = 0;
    char n = getchar();
    while ((c = getchar() != '\n')){
        b = 1;
    }
    if (b != 0){
        n = 'n';
    }

    switch (n) {
        case '1':
            printf("Введите строку: ");
            function1(line1);
            break;
        case '2':
            printf("Введите строку: ");
            function2(line1);
            break;
        case '3':
            printf("Введите строку: ");
            int res = function3(line1, line2);
            if (res == 1){
                printf("Данная подстрока входит в данную строку.\n");
            }
            else{
                printf("Данная подстрока НЕ входит в данную строку.\n");
            }
            break;
        case '4':
            printf("Введите строку: ");
            function4(line1);
            break;
        case '5':
            break;
        default:
            printf("Данные некорректны, такого варианта не существует.");
            break;
    }
    return 0;
}


void function1(char *line1)
{
    char c;
    int index=0;
    int memory1=0;

    line1=(char*)malloc(8);
    while ((c = getchar()) != '\n') {

        line1[index] = c;

        if (index == 8 + memory1) {
            memory1 += 15;
            line1 = realloc(line1, 8 + memory1);
        }
        index += 1;

        if (line1 == NULL) {
            printf("Ситуация некорректна.\n");
            break;
        }
        line1[index+1]='\0';
    }

    int i, n;
    unsigned long long summary;
    summary = 1;
    int error = 0;
    n = strlen(line1);

    printf("Произведение кодов символов равно: ");
    for (i = 0; i < n; i++){
        if (summary > 0) {
            if ((int)(line1[i]) > 0){
                if (summary > (INT_MAX / (int)(line1[i]))){
                    printf("Ошибка переполнения.\n");
                    error = 1;
                    break;
                }
                else{
                    summary = summary * (int)(line1[i]);
                }
            }
        }
    }
    if (error != 1){
        printf("%lld", summary);
        printf("\n");
        free(line1);
    }
}



void function2(char *line1)
{
    char c;
    int index=0;
    int memory1=0;

    line1=(char*)malloc(8);
    while ((c = getchar()) != '\n') {

        line1[index] = c;

        if (index == 8 + memory1) {
            memory1 += 15;
            line1 = realloc(line1, 8 + memory1);
        }
        index += 1;

        if (line1 == NULL) {
            printf("Ситуация некорректна.\n");
            break;
        }
        line1[index+1]='\0';
    }

    int i, error, num10;
    int n = strlen(line1);
    int position;
    for (i = 0; i < strlen(line1); i++){
        if ((line1[i]) != '0' && (line1[i]) != '1'){
            printf("Данная строка не является двоичным числом.\n");
            error = 1;
            break;
        }
    }
    if (error != 1){
        for (i = 0; i < strlen(line1); i++){
            if ((line1[i]) == '1'){
                position = (i+1- n) * (-1) ;
                num10 += pow(2, position);
            }
        }
        printf("Десятичная запись числа: %d", num10);
        printf("\n");
        free(line1);
    }
}

int str(char str1[], char str2[], int i) {
    for (i; i < strlen(str1); i++) {
        if (i > strlen(str2)) {
            break;
        }
        for (int j = 0; j < strlen(str2); j++) {
            if (str1[i++] != str2[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int function3(char *line1, char *line2) {

    char c;
    int index = 0;
    int memory1 = 0, memory2 = 0;

    line1 = (char *) malloc(8);
    while ((c = getchar()) != '\n') {
        line1[index] = c;

        if (index == 8 + memory1) {
            memory1 += 10;
            line1 = realloc(line1, 8 + memory1);

        }
        index += 1;

        if (line1 == NULL) {
            printf("Ситуация некорректна.\n");
            break;

        }
        line1[index + 1] = '\0';
    }

    index = 0;

    printf("Введите подстроку: ");

    line2 = (char *) malloc(8);
    while ((c = getchar()) != '\n') {

        line2[index] = c;

        if (index == 8 + memory2) {
            memory2 += 10;
            line2 = realloc(line2, 8 + memory2);
        }
        index += 1;

        if (line2 == NULL) {
            printf("Ситуация некорректна.\n");
            break;
        }
        line2[index + 1] = '\0';
    }
    int j = 0;
    int check = 0;

    for (int i = 0; i < strlen(line1); i++) {
        if ((line1[i] == line2[j]) && (check != 1)) {
            check = 1;
        }
        if (check == 1) {
            if (str(line1, line2, i) == 1) {
                return 1;
            }
            else {
                check = 0;
            }
        }
    }
    return -1;
}





void function4(char *line1){

    char c;
    int index=0;
    int memory1=0;

    line1=(char*)malloc(8);
    while ((c = getchar()) != '\n') {

        line1[index] = c;

        if (index == 8 + memory1) {
            memory1 += 15;
            line1 = realloc(line1, 8 + memory1);
        }
        index += 1;

        if (line1 == NULL) {
            printf("Ситуация некорректна.\n");
            break;
        }
        line1[index+1]='\0';
    }

    int count = 0, len, i, j;
    char glas[12] = {'e', 'y', 'u', 'i', 'o', 'a', 'E', 'Y', 'U', 'I', 'O', 'A'};
    len = strlen(line1);

    for (i = 0; i < len; i++){
        for (j = 0; j < 12; j++){
            if ((int)(line1[i]) == (int)(glas[j])){
                count ++;
            }
        }
    }
    printf("Количество гласных в данной строке: %d", count);
    printf("\n");
    free(line1);
}
