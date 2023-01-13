#ifndef PATH_H
#define PATH_H

#include <stdlib.h>

enum is_path_values { IS_DEF, IS_PATH, IS_POINT };

typedef struct s_path {
    int steps;
    int max_steps;
    int n, m;
    int **is_path;
} t_path;

t_path path_create(int n, int m);
void path_free(t_path *path);

#endif  // !PATH
