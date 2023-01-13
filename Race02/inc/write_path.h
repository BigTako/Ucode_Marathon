#ifndef WP_H
#define WP_H

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include "s_map.h"
#include "s_path.h"

void write_path_to_file(t_map map, t_path path, char *filename);

#endif
