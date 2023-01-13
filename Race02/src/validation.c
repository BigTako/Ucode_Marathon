#include "path_finder.h"

int validate_point(int * points, char ** map, int rows, int p_e) {
	int cols = mx_strlen(map[0]);
	int x = points[0];
	int y = points[1];
	if (x < 0 || x >= cols) return throw_error(POINT_OUT_OF_RANGE_ERR, 0);
	else if (y < 0 || y >= rows) return throw_error(POINT_OUT_OF_RANGE_ERR, 0);
	else if (map[y][x] == '#') {
		if (p_e == ENT_POINT_IS_OBS_ERR) 
			return throw_error(ENT_POINT_IS_OBS_ERR, 0);
		else if (p_e == EXIT_POINT_IS_OBS_ERR) 
			return throw_error(EXIT_POINT_IS_OBS_ERR, 0);
	}
	return 1;
}

int throw_error(int code, int ex){
	if (code == MAP_NOT_EXISTS_ERR)
		mx_printerr("map does not exist\n");
	else if (code == MAP_ERR)
		mx_printerr("map error\n");
	else if (code == POINT_OUT_OF_RANGE_ERR)
		mx_printerr("points are out of map range\n");
	else if (code == ENT_POINT_IS_OBS_ERR)
		mx_printerr("entry point cannot be an obstacle\n");
	else if (code == EXIT_POINT_IS_OBS_ERR)
		mx_printerr("exit point cannot be an obstacle\n");
	else if (code == ROUTE_NOT_FOUND_ERR)
		mx_printerr("route not found\n");
	else mx_printerr("error\n");
	if (ex){
		exit(0);
	}
	return -1;
}

void mx_validate_argc(int argc, char * argv[]){
	if (argc != 6){
		mx_printerr("usage: ");
		mx_printerr(argv[0]);
		mx_printerr(" [file_name] [x1] [y1] [x2] [y2]\n");
		exit(0);
	}
}

int mx_get_nlc(char * text){
	int c = 0;
	for (int i = 0; text[i] != '\0'; i++)
		if (text[i] == '\n') c++;
	return c;
}


