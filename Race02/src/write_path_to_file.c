#include "write_path.h"

void write_path_to_file(t_map map, t_path path, char *filename) {
    int dst = open(filename, O_WRONLY | O_CREAT);
    for (int n = 0; n < map.n; n++) {
        for (int m = 0; m < map.m; m++) {
            if (path.is_path[n][m] == IS_DEF) {
                write(dst, &(map.data[n][m]), 1);
            }
            else {
                if (path.is_path[n][m] == IS_PATH) {
                    write(dst, "*", 1);
                }
                else if (path.is_path[n][m] == IS_POINT) {
                    write(dst, "D", 1);
                }
                else {
                    write(dst, "X", 1);
                }
            }
        }
        write(dst, "\n", 1);
    }
    close(dst);
}

