#include "playlist.h"

t_song * create_song(char * name, char * artist){
	t_song * song = malloc(sizeof(t_song*));
	song->name = name;
	song->artist = artist;
	return song;
}


