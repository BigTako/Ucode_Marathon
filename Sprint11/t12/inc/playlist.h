#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "header.h"
#include "list.h"

typedef struct s_song
{
  	char * name;
  	char * artist;
} t_song;

enum e_usage{
	USAGE_ARGC,
	USAGE_ADD,
	USAGE_REMOVE,
	USAGE_SORT,
	USAGE_PRINT
};

t_song * create_song(char * name, char * artist);
void print_songs(t_list * songs);
void write_to_file(t_list * songs, char * filename);
void clear_file(char * filename);
#endif

