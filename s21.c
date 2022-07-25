#include <stdio.h>

void read_file(char *filename, int *flag);
void write_file(char *filename);

int main(void) {
    int choice = 0;
    char filename[260];
    int flag = 0;
    int empty = 0;
    do {
        if (scanf("%d", &choice) == 1) {
            if (choice == 1) {
                read_file(filename, &flag);
            } else if (choice == -1) {
                break;
            } else if (choice == 2 && flag == 1) {
                // write_file(filename);
                read_file(filename, &empty);
            } else {
                printf("n/a--\n");
            }
        } else {
            printf("n/a..\n");
            break;
        }
    } while (choice != -1);
}

void read_file(char *filename, int *flag) {
    char ch;
    FILE *file;
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file) {
        if ((ch = getc(file)) == EOF) {
            printf("n/a !!");
        } else {
            do {
                printf("%c", ch);
            } while ((ch = getc(file)) != EOF);
            *flag = 1;
        }
        fclose(file);
    } else {
        printf("n/a ??");
    }
    printf("\n");
}

void write_file(char *filename) {
    char ch;
    FILE *filew;
    int end = 0;
    filew = fopen(filename, "a+");
    printf("writting...\n");
    if (filew) {
        printf("file was opened'\n");
        while(!end) {
            scanf("%c", &ch);
            printf("symbol is: %c\n", ch);
            if (ch == '\n') {
                end = 1;
                break;
            }
            fputc(ch, filew);
        }
        fclose(filew);
    } else {
        printf("n/a-wf\n");
    }
}