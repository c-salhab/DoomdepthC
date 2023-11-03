
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sqlite3.h>



int save_file(Character *character) {
    sqlite3 *db;
    sqlite3_stmt *res;
    int error = 0;

    error = sqlite3_open("testt.db", &db);
    if (error) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (1);
    }

    const char *sql_query = "INSERT INTO player (name, posX, posY, level, xp, pv, mana, gold) VALUES (?, 0, 0, ?, ?, ?, ?, ?)";

    error = sqlite3_prepare_v2(db, sql_query, -1, &res, 0);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return (1);
    }



    sqlite3_bind_text(res, 1, character->username, -1, SQLITE_STATIC);
    sqlite3_bind_int(res, 2, character->level);
    sqlite3_bind_int(res, 3, character->exp);
    sqlite3_bind_int(res, 4, character->current_health);
    sqlite3_bind_int(res, 5, character->current_mana);
    sqlite3_bind_int(res, 6, character->gold);

    sqlite3_step(res);


    sqlite3_finalize(res);
    sqlite3_close(db);

    return 0;

}