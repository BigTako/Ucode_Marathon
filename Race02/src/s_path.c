#include "s_path.h"

void path_free(t_path *path) {
    int **data = path->is_path;
    int n = path->n;
    while (n--) {
        free(*(data));
        data++;
    }
    free(path->is_path);
    path->is_path = NULL;
}

static void fill_arr_by(int n, int m, int **arr, int filler);

t_path path_create(int n, int m) {
    t_path new_path;

    new_path.n = n;
    new_path.m = m;
    new_path.steps = -1;
    new_path.is_path = malloc(n * sizeof(int *));
    while (--n) {
        new_path.is_path[n] = malloc(m * sizeof(int));
    }
    new_path.is_path[0] = malloc(m * sizeof(int));

    fill_arr_by(new_path.n, new_path.m, new_path.is_path, IS_DEF);
    return new_path;
}

// Static functions

static void fill_arr_by(int n, int m, int **arr, int filler) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = filler;
        }
    }
}
