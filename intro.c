#include "sqlite3.h"
#include <stdio.h>

// compilation: gcc -o filename.exe filename.c libsqlite3.a

static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    for (i=0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : NULL);
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    if (argc != 3) {
        printf("usage: [DATABASE] [TABLE]\n");
        return 1;
    }

    rc = sqlite3_open(argv[1], &db);
    if (rc != SQLITE_OK) {
        printf("database could not be opened.\n");
        sqlite3_close(db);
        return 2;
    }
    printf("database opened.\n\n");

    char sql[100];
    sprintf(sql, "SELECT * FROM %s LIMIT 1;", argv[2]);
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return 3;
    }
    printf("data callbacked.\n");

    sqlite3_close(db);
    return 0;
}