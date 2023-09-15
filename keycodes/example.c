#include <stdio.h>

int main() {
    int key;

    printf("Press any key...\n");
    key = getchar();

    printf("You pressed the key with ASCII value: %d\n", key);

    return 0;
}
