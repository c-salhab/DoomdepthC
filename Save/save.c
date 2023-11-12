
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sqlite3.h>






#define FILENAME_PREFIX "csv_files/maps/save_"
#define FILENAME_SUFFIX ".csv"

void saveMapToCSV(const char *filename, int **matrix, int rows, int cols) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d", matrix[i][j]);

            // Add a comma if it's not the last column
            if (j < cols - 1) {
                fprintf(file, ",");
            }
        }

        // Add a newline if it's not the last row
        if (i < rows - 1) {
            fprintf(file, "\n");
        }
    }

    fclose(file);
}



int save_file(Character *character, int ** matrix, int posX, int posY) {

    sqlite3 *db;
    sqlite3_stmt *res;
    int error = 0;
    int rc;

    error = sqlite3_open("final.db", &db);
    if (error) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (1);
    }

    const char *sql_query = "INSERT INTO player (name, posX, posY, level, xp, pv, mana, gold) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";

    error = sqlite3_prepare_v2(db, sql_query, -1, &res, 0);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return (1);
    }



    sqlite3_bind_text(res, 1, character->username, -1, SQLITE_STATIC);
    sqlite3_bind_int(res, 2, posX);
    sqlite3_bind_int(res, 3, posY);
    sqlite3_bind_int(res, 4, character->level);
    sqlite3_bind_int(res, 5, character->exp);
    sqlite3_bind_int(res, 6, character->current_health);
    sqlite3_bind_int(res, 7, character->current_mana);
    sqlite3_bind_int(res, 8, character->gold);

    error = sqlite3_step(res);
    if (error != SQLITE_DONE) {
        fprintf(stderr, "Error in player table insertion: %s\n", sqlite3_errmsg(db));
        return 1;
    }



    //get save ID
    sql_query = "SELECT * FROM player ORDER BY Id DESC LIMIT 1";



    rc = sqlite3_prepare_v2(db, sql_query, -1, &res, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return (1);
    }



    sqlite3_step(res);

    int idplayer = sqlite3_column_int(res, 0);




    sql_query = "INSERT INTO inv (name, descr, val, dura, type, Id_1, lvl) VALUES (?, ?, ?, ?, 2, ?, ?)";

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
            sqlite3_bind_int(res, 6, character->inventory->armors[i]->level);


            error = sqlite3_step(res);
            sqlite3_reset(res);
            if (error != SQLITE_DONE) {
                fprintf(stderr, "Error in player table insertion: %s\n", sqlite3_errmsg(db));
                return 1;
            }

        }
    }

    sql_query = "INSERT INTO inv (name, descr, val, dura, type, Id_1, lvl) VALUES (?, ?, ?, ?, 1, ?, ?)";

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
            sqlite3_bind_int(res, 6, character->inventory->weapons[i]->level);


            error = sqlite3_step(res);
            sqlite3_reset(res);
            if (error != SQLITE_DONE) {
                fprintf(stderr, "Error in player table insertion: %s\n", sqlite3_errmsg(db));
                return 1;
            }

        }
    }

    //save map
    char fileName[40];
    sprintf(fileName, "%s%02d%s", FILENAME_PREFIX, idplayer, FILENAME_SUFFIX);


    saveMapToCSV(fileName, matrix, 20 ,20);

    sqlite3_finalize(res);
    sqlite3_close(db);

    return 0;

}

