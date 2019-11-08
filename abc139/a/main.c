#include <stdio.h>

int main(void) {
    char s[5];
    char t[5];
    int count = 0;

    fgets(s, 5, stdin);
    fgets(t, 5, stdin);

    for (int i = 0; i < 3; i++) {
        if (s[i] == t[i]) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
