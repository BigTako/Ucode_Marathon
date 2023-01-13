#include "playlist.h"


int main(int argc, char * argv[]){
	mx_validate_argc(argc, argv);
	char * file_str = mx_file_to_str(argv[1]);
	char ** songs_str = mx_strsplit(file_str, '\n');
	t_list * songs;
	t_song * song;
	int len = 0;
	for (; songs_str[len]; len++);
	for (int i = 0; i < len; i++){
		char ** pair = mx_strsplit(songs_str[i], ',');
		song = create_song(pair[1], pair[0]);
		if (i == 0) songs = mx_create_node(song);
		else mx_push_back(&songs, song);
		free(songs_str[i]);
	}
	if (mx_strcmp(argv[2], "print") == 0) print_songs(songs);
	else if(mx_strcmp(argv[2], "add") == 0){
		mx_push_back(&songs, create_song(argv[4], argv[3]));
		write_to_file(songs, argv[1]);
	}else if(mx_strcmp(argv[2], "remove") == 0){	
		mx_pop_index(&songs, mx_atoi(argv[3]));
		clear_file(argv[1]);
		write_to_file(songs, argv[1]);
	}else if(mx_strcmp(argv[2], "sort") == 0){
		if (mx_strcmp(argv[3], "name") == 0) 
			mx_sort_list(songs, mx_by_name);
		else mx_sort_list(songs, mx_by_artist);
		clear_file(argv[1]);
		write_to_file(songs, argv[1]);
	}
	mx_clear_list(&songs);
	free(file_str);
	free(songs_str);
	return 0;
}


