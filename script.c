#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct database {
    int table_count;
    char** table_names;

    int* column_count;
    char*** column_names;
};

int main(int argc, char **argv) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    if (argc != 3) {
        printf("usage: [DATABASE] TABLE\n");
        return 1;
    }

    rc = sqlite3_open(argv[1], &db);
    if (rc != SQLITE_OK) {
        printf("database could not be opened.\n");
        sqlite3_close(db);
        return 2;
    }
    printf("database opened.\n\n");

    // if !database.JSON, create JSON file

    sqlite3_close(db);
    return 0;
}