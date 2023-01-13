#include "map_analise_results_implementation.h"

static void fill_path_by_point(t_analising_report rep,
                               t_point ext_point,
                               t_path *path) {
    int **directions = rep.shortest_pathes_directions;
    int n = ext_point.x, m = ext_point.y;
    while (directions[n][m] != IS_ENTRY) {
        path->is_path[n][m] = IS_PATH;
        switch (directions[n][m]) {
            case UP:
                n++;
                break;
            case RIGHT:
                m--;
                break;
            case BOTTOM:
                n--;
                break;
            case LEFT:
                m++;
                break;
        }
    }
    path->is_path[n][m] = IS_PATH;
}

t_path find_shortest_path(t_analising_report rep, t_point ext_point) {
    t_path short_path = path_create(rep.map.n, rep.map.m);
    short_path.steps =
        rep.shortest_pathes_values[ext_point.x][ext_point.y];
    if (short_path.steps == -1) {
        return short_path;
    }
    fill_path_by_point(rep, ext_point, &short_path);

    return short_path;
}

void add_points_to_path(t_path *path, t_analising_report rep) {
    path->max_steps = rep.max_shortest_path_value;

    for (int i = 0; i < path->n; i++) {
        for (int j = 0; j < path->m; j++) {
            if (rep.shortest_pathes_values[i][j] == path->max_steps) {
                path->is_path[i][j] += IS_POINT;
            }
        }
    }
}
