#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_memory(FILE *file, char *data) {
    fclose(file);
    free(data);
    file = NULL;
    data = NULL;
}
int menu() {
    int command;
    printf("\n< 1 > - открыть файл и вывести текст в консоль\n");
    printf("< 2 > - дописать текст из консоли\n");
    printf("< 3 > - шифрация кодом Цезаря всех .c и .h файлов\n");
    printf("< -1 > - завершить работу\n");
    printf("Введите номер исполняемой операции: ");
    scanf("%d", &command);
    return command;
}

void read(char *path) {
    char *data = (char *)malloc(sizeof(char *));
    printf("Введите название файла: ");
    scanf("%s", path);
    FILE *ptr_file;
    ptr_file = fopen(path, "r");
    if (ptr_file == NULL) {
        printf("n/a");
        return;
    }
    fscanf(ptr_file, "%s", data);
    printf("%s", data);

    clear_memory(ptr_file, data);
}

void write(char *path) {
    char *data = (char *)malloc(sizeof(char *));
    FILE *ptr_file;
    ptr_file = fopen(path, "r+");
    if (ptr_file == NULL) {
        printf("n/a");
        return;
    }
    printf("Введите строку для записи в файл: ");
    scanf("%s", data);
    fprintf(ptr_file, "\n%s", data);

    clear_memory(ptr_file, data);
}

void caesar() {
    FILE *ptr_input, *ptr_output;
    int caesar_shift;
    char ch;
    scanf("%d", &caesar_shift);
    ptr_input = fopen("./ai_modules/m1.h", "w");
    fclose(ptr_input);
    ptr_input = fopen("./ai_modules/m2.h", "w");
    fclose(ptr_input);
    ptr_input = fopen("./ai_modules/m1.c", "r");
    ptr_output = fopen("./ai_modules/m1.encrypted", "w");
    do {
        ch = fgetc(ptr_input);
        fputc(ch + caesar_shift, ptr_output);
    } while (!feof(ptr_input));
    fclose(ptr_input);
    fclose(ptr_output);
    ptr_input = fopen("./ai_modules/m2.c", "r");
    ptr_output = fopen("./ai_modules/m2.encrypted", "w");
    do {
        ch = fgetc(ptr_input);
        fputc(ch + caesar_shift, ptr_output);
    } while (!feof(ptr_input));
    fclose(ptr_input);
    fclose(ptr_output);
}

int main() {
    int command;
    char *path = (char *)malloc(sizeof(char *));
    while (1) {
        int toggle_cycle_off = 0;
        command = menu();
        switch (command) {
            case 1: {
                read(path );
                break;
            }
            case 2: {
                write(path);
                break;
            }
            case 3: {
                caesar();
                break;
            }
            case -1: {
                toggle_cycle_off = 1;
                break;
            }
            default: {
                printf("n/a");
                toggle_cycle_off = 1;
                break;
            }
        }
        if (toggle_cycle_off == 1) {
            break;
        }
    }
    free(path);
    path = NULL;
    return 0;
}