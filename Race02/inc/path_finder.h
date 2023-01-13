#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include "header.h"
#include "s_path.h"
#include "map_analise_results_implementation.h"
#include "s_map_analize_by_wave_algorithm.h"
#include "write_path.h"

enum e_error{
	MAP_NOT_EXISTS_ERR,
	MAP_ERR,
	POINT_OUT_OF_RANGE_ERR,
	ENT_POINT_IS_OBS_ERR,
	EXIT_POINT_IS_OBS_ERR,
	ROUTE_NOT_FOUND_ERR,
	ERROR,
};

#endif
