#include "sqlite3.h"
#include <stdio.h>

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
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return 3;
    }
    printf("database cached.\n");

    char syscall[100];
    sprintf(syscall, 'sqlite3 test.db ".schema" | grep -owi "CREATE TABLE" | wc -l');
    int tables = system(syscall);
    printf("amount of tables: %i\n", tables);

    sqlite3_close(db);
    return 0;
}