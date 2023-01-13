#include "s_map_analize_by_wave_algorithm.h"

static void malloc_report_parts(t_map map, t_analising_report *rep);
static int **malloc_arr(int n, int m);
static void fill_arr_by(int n, int m, int **arr, int filler);
static void fill_pathes_by_wave(t_analising_report *rep);
static void walk(t_point from, t_point this, t_analising_report *rep);
static int calculate_direction(t_point from, t_point this); 
static void find_max_value(t_analising_report *rep);

t_analising_report map_analise(t_map map, t_point entry_point) {
    t_analising_report rep;

    malloc_report_parts(map, &rep);

    rep.entry_point = entry_point;
    rep.max_shortest_path_value = -1;

    fill_pathes_by_wave(&rep);

    find_max_value(&rep);

    return rep;
}

void report_free(t_analising_report *report) {
    int n = report->map.n;

    while (n--) {
        free(report->shortest_pathes_directions[n]);
    }
    free(report->shortest_pathes_directions);

    n = report->map.n;

    while (n--) {
        free(report->shortest_pathes_values[n]);
    }
    free(report->shortest_pathes_values);

    report->shortest_pathes_directions = NULL;
    report->shortest_pathes_values = NULL;
}

// Static methods
static void malloc_report_parts(t_map map, t_analising_report *rep) {
    rep->map = map;
    rep->shortest_pathes_values = malloc_arr(map.n, map.m);
    rep->shortest_pathes_directions = malloc_arr(map.n, map.m);

    fill_arr_by(map.n, map.m, rep->shortest_pathes_values, -1);
    fill_arr_by(map.n, map.m, rep->shortest_pathes_directions, -1);
}

static int **malloc_arr(int n, int m) {
    int **new_arr = malloc(n * sizeof(int *));
    while (--n) {
        new_arr[n] = malloc(m * sizeof(int));
    }
    new_arr[0] = malloc(m * sizeof(int));
    return new_arr;
}

static void fill_arr_by(int n, int m, int **arr, int filler) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = filler;
        }
    }
}

static void fill_pathes_by_wave(t_analising_report *rep) {
    walk(rep->entry_point, rep->entry_point, rep);
}

static void find_max_value(t_analising_report *rep) {
    int max = -1;
    for (int i = 0; i < rep->map.n; i++) {
        for (int j = 0; j < rep->map.m; j++) {
            if (rep->shortest_pathes_values[i][j] > max)
                max = rep->shortest_pathes_values[i][j];
        }
    }
    rep->max_shortest_path_value = max;
}

static void walk(t_point from, t_point this, t_analising_report *rep) {
    if (this.x < 0 || this.x >= rep->map.n) return;
    if (this.y < 0 || this.y >= rep->map.m) return;

    char *this_element = &(rep->map.data[this.x][this.y]);
    int *this_direction =
        &(rep->shortest_pathes_directions[this.x][this.y]);
    int *this_value = &(rep->shortest_pathes_values[this.x][this.y]);

    if (*this_element == '#') {
        return;
    }

    int from_value = rep->shortest_pathes_values[from.x][from.y];

    if (*this_value == -1 || (from_value + 1) < *this_value) {
        *this_value = from_value + 1;
        *this_direction = calculate_direction(from, this);
    }
    else
        return;

    walk(this, point(this.x - 1, this.y), rep);
    walk(this, point(this.x, this.y + 1), rep);
    walk(this, point(this.x + 1, this.y), rep);
    walk(this, point(this.x, this.y - 1), rep);
}

static int calculate_direction(t_point from, t_point this) {
    if (this.x == from.x && this.y == from.y) {
        return IS_ENTRY;
    }
    else if (this.x < from.x && this.y == from.y) {
        return UP;
    }
    else if (this.x == from.x && this.y > from.y) {
        return RIGHT;
    }
    else if (this.x > from.x && this.y == from.y) {
        return BOTTOM;
    }
    else if (this.x == from.x && this.y < from.y) {
        return LEFT;
    }
    return IS_ENTRY;
}
