#ifndef WAVE_ALGORITHM_H
#define WAVE_ALGORITHM_H


#include <stdio.h>
#include "s_map.h"
#include "s_point.h"

enum directions { UP, RIGHT, BOTTOM, LEFT, IS_ENTRY };

typedef struct s_analising_report {
    t_map map;
    t_point entry_point;
    int max_shortest_path_value;
    int **shortest_pathes_values;
    int **shortest_pathes_directions;
} t_analising_report;

t_analising_report map_analise(t_map map, t_point entry_point);
void report_free(t_analising_report *report);

#endif  // !SHORTEST_PATH_H
