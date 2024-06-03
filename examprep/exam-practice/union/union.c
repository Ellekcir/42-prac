#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        write(1, "\n", 1);
        return 0;
    }

    char *str1 = argv[1];
    char *str2 = argv[2];
    int i = 0;

    while (str1[i]) {
        int j = 0;
        int found = 0;
        while (str2[j]) {
            if (str1[i] == str2[j]) {
                found = 1;
                break;
            }
            j++;
        }
        if (!found) {
            write(1, &str1[i], 1);
        }
        i++;
    }

    i = 0;
    while (str2[i]) {
        write(1, &str2[i], 1);
        i++;
    }

    write(1, "\n", 1);

    return 0;
}
