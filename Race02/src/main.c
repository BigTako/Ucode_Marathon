#include "path_finder.h"

void print_lenth(t_path path) {
    write(1, "dist=", 5);
    mx_printint(path.max_steps);
    write(1, "\nexit=", 6);
    mx_printint(path.steps);
    write(1, "\n", 1);
}

int main(int argc, char *argv[]) {
    mx_validate_argc(argc, argv);  // if agrument count is invalid;
    int ERR = 0;
    char *file_str = mx_file_to_str(argv[1]);
    char **lines = mx_strsplit(file_str, '\n');
    int rows = mx_get_nlc(file_str);
    char **map_chr = malloc(rows * sizeof(char *));  // map where to search path
    int ent_points[2] = {mx_atoi(argv[2]), mx_atoi(argv[3])};
    int ext_points[2] = {mx_atoi(argv[4]), mx_atoi(argv[5])};
    // cycle to make valid (no coma) map
    for (int i = 0; i < rows; i++) {
        if (i != rows - 1)
            if (mx_strlen(lines[i]) != mx_strlen(lines[i + 1]))
                ERR = throw_error(MAP_ERR, 0);  // not rectangle map
        if (ERR) break;
        map_chr[i] = delete_comas(lines[i], ',', mx_strlen(lines[i]), &ERR);
    }
    if (!ERR){
	    ERR = validate_point(ent_points, map_chr, rows, ENT_POINT_IS_OBS_ERR);
	    ERR += validate_point(ext_points, map_chr, rows, EXIT_POINT_IS_OBS_ERR);
	    if (ERR > 0){
	    	    t_map map = map_create_from_arr(rows,
		                            mx_strlen(map_chr[0]),
		                            (const char **)map_chr);
		    t_analising_report report = map_analise(map, point(ent_points[1], ent_points[0]));
		    t_path path = find_shortest_path(report, point(ext_points[1], ext_points[0]));
		    if (path.steps < 0) {
			throw_error(ROUTE_NOT_FOUND_ERR, 0);
		    }
		    else {
			add_points_to_path(&path, report);
			print_lenth(path);
			write_path_to_file(map, path, "path.txt");  // write to path.txt
		    }
		    map_free(&map);
    	    	    path_free(&path);
            	    report_free(&report);
	    }
    }
    for (int j = 0; j < rows + 1; j++) mx_strdel(&lines[j]); 
    for (int i = 0; i < rows; i++) mx_strdel(&map_chr[i]);
    free(map_chr);
    free(lines);
    mx_strdel(&file_str);
    return 0;
}
