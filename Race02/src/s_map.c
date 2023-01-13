#include "s_map.h"

static void malloc_map(int n, int m, t_map *map);
// static void create_borders(t_map map);
// static void return_normal_indexation(t_map *map);

static void copy_data_from_str(t_map map, const char *data);

t_map map_create_from_str(int n, int m, const char *data) {
    t_map new_map;

    malloc_map(n, m, &new_map);

    copy_data_from_str(new_map, data);

    return new_map;
}

static void copy_data_from_arr(t_map map, const char **data);

t_map map_create_from_arr(int n, int m, const char **data) {
    t_map new_map;

    malloc_map(n, m, &new_map);

    copy_data_from_arr(new_map, data);

    return new_map;
}

void map_free(t_map *map) {
    int n = map->n;
    char **data = map->data;

    while (n--) {
        free(*(data));
        data++;
    }
    free(map->data);
    map->data = NULL;
}

// Static functions realisation
static void malloc_map(int n, int m, t_map *map) {
    map->n = n;
    map->m = m;
    map->data = malloc(n * sizeof(char *));
    while (--n) {
        map->data[n] = malloc(m * sizeof(char));
    }
    map->data[0] = malloc(m * sizeof(char));
}

static void copy_data_from_str(t_map new_map, const char *data) {
    char **str_link = new_map.data;
    char *str_element;
    int n = new_map.n;
    int m;

    while (n--) {
        str_element = *str_link;
        m = new_map.m;
        while (m--) {
            *str_element = *data;
            str_element++;
            data++;
        }
        str_link++;
    }
}

static void copy_data_from_arr(t_map map, const char **data) {
    for (int i = 0; i < map.n; i++) {
        for (int j = 0; j < map.m; j++) {
            map.data[i][j] = data[i][j];
        }
    }
}
