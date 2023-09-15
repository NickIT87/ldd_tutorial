#include <stdio.h>

int main() {
    FILE *logFile;

    // Open the file in "a" (append) mode, so new messages are added to the end
    logFile = fopen("logfile.txt", "a");

    if (logFile == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    fprintf(logFile, "This is a log message.\n");

    // Always remember to close the file after you're done
    fclose(logFile);

    return 0;
}
