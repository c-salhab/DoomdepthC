
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

    error = sqlite3_step(res);
    if (error != SQLITE_DONE) {
        fprintf(stderr, "Error in player table insertion: %s\n", sqlite3_errmsg(db));
        return 1;
    }




    sql_query = "SELECT * FROM player ORDER BY Id DESC LIMIT 1";



    rc = sqlite3_prepare_v2(db, sql_query, -1, &res, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return (1);
    }



    sqlite3_step(res);

    int idplayer = sqlite3_column_int(res, 0);




    sql_query = "INSERT INTO inv (name, descr, val, dura, type, Id_1) VALUES (?, ?, ?, ?, 2, ?)";

    error = sqlite3_prepare_v2(db, sql_query, -1, &res, 0);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return (1);
    }

    for (int i = 0; i < character->inventory->num_armors; i++) {
        if (character->inventory->armors[i] != NULL) {

            sqlite3_bind_text(res, 1, character->inventory->armors[i]->armor_name, -1, SQLITE_STATIC);
            sqlite3_bind_text(res, 2, character->inventory->armors[i]->description, -1, SQLITE_STATIC);
            sqlite3_bind_int(res, 3, character->inventory->armors[i]->physical_defense);
            sqlite3_bind_int(res, 4, character->inventory->armors[i]->durability);
            sqlite3_bind_int(res, 5, idplayer);


            error = sqlite3_step(res);
            sqlite3_reset(res);
            if (error != SQLITE_DONE) {
                fprintf(stderr, "Error in player table insertion: %s\n", sqlite3_errmsg(db));
                return 1;
            }

        }
    }

    sql_query = "INSERT INTO inv (name, descr, val, dura, type, Id_1) VALUES (?, ?, ?, ?, 1, ?)";

    error = sqlite3_prepare_v2(db, sql_query, -1, &res, 0);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return (1);
    }

    for (int i = 0; i < character->inventory->num_weapons; i++) {
        if (character->inventory->weapons[i] != NULL) {

            sqlite3_bind_text(res, 1, character->inventory->weapons[i]->weapon_name, -1, SQLITE_STATIC);
            sqlite3_bind_text(res, 2, character->inventory->weapons[i]->description, -1, SQLITE_STATIC);
            sqlite3_bind_int(res, 3, character->inventory->weapons[i]->physical_damage);
            sqlite3_bind_int(res, 4, character->inventory->weapons[i]->durability);
            sqlite3_bind_int(res, 5, idplayer);


            error = sqlite3_step(res);
            sqlite3_reset(res);
            if (error != SQLITE_DONE) {
                fprintf(stderr, "Error in player table insertion: %s\n", sqlite3_errmsg(db));
                return 1;
            }

        }
    }




    sqlite3_finalize(res);
    sqlite3_close(db);

    return 0;

}