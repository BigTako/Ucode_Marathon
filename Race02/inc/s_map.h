#ifndef MAP_H
#define MAP_H

#include <stdlib.h>

typedef struct s_map {
    int n, m;
    char **data;
} t_map;

t_map map_create_from_str(int n, int m, const char *data);
t_map map_create_from_arr(int n, int m, const char **data);
void map_free(t_map *path);

#endif  // !MAP
