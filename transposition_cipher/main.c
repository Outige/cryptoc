#include <stdlib.h>
#include <stdio.h>

int file_length(char *fname) {
    FILE *fp = fopen(fname, "r");
    int len = 0;
    char ch;

    /* file doesn't exist */
    if (!fp) return 0;

    while ((ch = fgetc(fp)) != EOF) {
        len++;
    }
    fclose(fp);
    return len;
}

void file_to_str(char *fname, char *data, int len) {
    FILE *fp = fopen(fname, "r");
    for (int i = 0; i < len; i++) {
        data[i] = fgetc(fp);
    }
    fclose(fp);
}

int calc_matrix_size(int len) {
    for (int i = 1; i < len; i++) {
        if (i*i >= len) {
            return i;
        }
    }
}

// void str_to_matrix(char *data, int len) {

// }

void transpose_data(char *data, int len) {
    char *newdata = malloc(sizeof(len));
    int n = calc_matrix_size(len);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newdata[i+j*n] = data[i*n+j];
        }
    }
    printf("%s", newdata);
}

int main(int argc, char const *argv[]) {
    char *fname = "in.txt";
    char *data;
    int len = file_length("in.txt");
    file_to_str(fname, data=malloc(sizeof(len)), len);
    transpose_data(data, len);

    return 0;
}
