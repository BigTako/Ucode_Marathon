#include "header.h"

static void change_color(WINDOW *win)
{
    start_color();
    init_color(COLOR_BLACK, COLOR_GREEN, COLOR_WHITE, 0);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    wbkgd(win, COLOR_PAIR(1));
}

int main(int argc, char *argv[])
{
    argv[0] = 0;
    mx_validate_argc(argc);
    initscr();
    noecho(); // do not print on screen any typed character
    int w_height = 0;
    int w_width = 0;
    WINDOW *win = newwin(w_height, w_width, 0, 0);
    getmaxyx(win, w_height, w_width);
    int arr_start[w_width];
    int line_length[w_width];
    int to_out[w_width];

    if (has_colors())
        change_color(win);
    srand(time(NULL));
    halfdelay(1);
    greeting(win, w_width, w_height);
    wclear(win);

    for (int i = 0; i < w_width; i++)
    {
        line_length[i] = rand() % w_height - 1;
        arr_start[i] = -1 * (rand() % (w_width / 2));
        to_out[i] = arr_start[i];
    }
    while (wgetch(win) != 'q')
    {
        for (int i = 0; i < w_width; i++)
        {
            wchar_t output_char = (rand() % 93 + 33);
            mvwaddch(win, to_out[i] + 1, i, output_char | COLOR_PAIR(2));
            mvwaddch(win, to_out[i], i, output_char | COLOR_PAIR(rand() % 6));
            mvwaddch(win, to_out[i] - line_length[i], i, ' ');
            if (to_out[i] - line_length[i] > w_height)
                to_out[i] = arr_start[i];
            to_out[i]++;
        }
        refresh();
    }
    endwin();
    return 0;
}
