#ifndef MAP_AFTER_ANALISE_H
#define MAP_AFTER_ANALISE_H

#include "s_map_analize_by_wave_algorithm.h"
#include "s_path.h"

t_path find_shortest_path(t_analising_report wave_rep, t_point ext_point);
void add_points_to_path(t_path *path, t_analising_report wave_rep);
#endif  // !MAP_AFTER_ANALISE_H
