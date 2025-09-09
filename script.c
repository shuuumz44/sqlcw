#include <stdio.h>
#include <stdlib.h>

#include "sqlite3.h"
#include "json.h"

struct database {
    int table_count;
    char** table_names;

    int* column_count;
    char*** column_names;
};

int main(int argc, char **argv) {
    sqlite3 *db;
    struct database *table;
    char *zErrMsg = 0;
    int rc;

    if (argc != 2 && argc != 3) {
        printf("usage: [DATABASE] TABLE\n");
        return 1;
    }

    rc = sqlite3_open_v2(argv[1], &db, SQLITE_OPEN_READWRITE, NULL);
    if (rc != SQLITE_OK) {
        printf("database could not be opened.\n");
        sqlite3_close(db);
        return 2;
    }
    printf("database opened.\n\n");

    // initialize database to "database.json" file if it exists, otherwise NULL
    json_object *database = NULL;
    char json_str[1000];
    FILE *json_file = fopen("database.JSON", "r");
    
    if (!json_file)
    {
        database = json_object_new_object();

        // output sqlite commands to output to JSON
    }
    fread(json_str, sizeof(json_file)/4, 1, json_file);
    database = json_tokener_parse(json_str);

    fclose(json_file);
    sqlite3_close(db);
    return 0;
}