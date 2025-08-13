#include "sqlite3.h"
#include <stdio.h>

// compilation: gcc shell.c sqlite3.c -lpthread -ldl -lm -o filename

int main(int argc, char **argv) {
    sqlite3 *db;
    int rc;

    rc = sqlite3_open(argv[1], &db);

    if (rc != SQLITE_OK) {
        printf("database could not be opened.\n");
        sqlite3_close(db);
        return 2;
    }

    printf("database opened.\n");
    sqlite3_close(db);
    return 0;
}