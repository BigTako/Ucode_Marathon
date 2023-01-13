#include "playlist.h"


void print_songs(t_list * songs){
	t_list * temp = songs;
	t_song * tsong;
	int i = 0;
	while(temp){
		tsong = temp->data;
		mx_printint(i++);
		write(1, ". ", 2);
		write(1, tsong->artist, mx_strlen(tsong->artist)); 
		write(1, " - ", 3);
		write(1, tsong->name, mx_strlen(tsong->name)); 
		write(1, "\n", 1);
		temp = temp->next;
	}	
}

void write_to_file(t_list * songs, char * filename){
	int file = open(filename, O_WRONLY | O_TRUNC);
	if (file == -1){
		mx_printerr("error\n");
		return;
	}
	t_list * temp = songs;
	t_song * tsong;
	while(temp){
		tsong = temp->data;
		write(file, tsong->artist, mx_strlen(tsong->artist)); 
		write(file, ",", 1);
		write(file, tsong->name, mx_strlen(tsong->name)); 
		write(file, "\n", 1);
		temp = temp->next;
	}
	close(file);
}

void clear_file(char * filename){
	int file = open(filename, O_WRONLY | O_TRUNC);
	if (file == -1){
		mx_printerr("error\n");
		return;
	}
	int len = mx_filelen(file);
	for (int i = 0; i < len; i++) write(file, " ", 1);
}


