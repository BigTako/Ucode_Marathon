#include "header.h"

static int hello_neo(WINDOW *win, int w_height, int w_width, char *word) { 
    int height = w_height / 16; 
    int width = w_width / 64; 
    int i = 0; 
    usleep(13000); 
 	wclear(win); 
    while (i < mx_strlen(word)) { 
        if (wgetch(win) == 'q') return 0;
        mvwaddch(win, height, width + i, word[i]); 
        wrefresh(win); 
        usleep(180000); 
        i++; 
    }
    return 1; 
}

void greeting(WINDOW * win, int w, int h){
    char words[][256] = {"Wake up , Neo..\0", "The Matrix has you..\0", "Follow the white rabbit\0", "Knock, knock, Neo\0"};
    for (int i = 0; i < 4; i++)
    	if (!hello_neo(win, h, w, words[i])){
    		endwin();
	 	exit(0);
    	}	
}

