#include "header.h"

void mx_print_agent_info(char * name, int s, int p){
	write(1, "agent: ", 7);
	write(1, name, mx_strlen(name));
	write(1, ", strength: ", 12);
	mx_printint(s);
	write(1, ", power: ", 9);
	mx_printint(p);
	write(1, "\n", 1);
}
int mx_validate_argc(int argc, char * argv[]){
	if (argc != 3 
		|| (mx_strcmp(argv[1], "-p") != 0 
			&& mx_strcmp(argv[1], "-s") != 0
				&& mx_strcmp(argv[1], "-n") != 0)){
		mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
		return 0;
	}
	return 1;
}

int main(int argc, char * argv[]){
	if (mx_validate_argc(argc, argv)){
		char * agents_str = mx_file_to_str(argv[2]);
		int a_c = mx_count_substr(agents_str, "agent");
		int n_c = mx_count_substr(agents_str, "name");  
		int p_c = mx_count_substr(agents_str, "power");
		int s_c = mx_count_substr(agents_str, "strength");
		int rb_c = mx_count_substr(agents_str, "{");
		int lb_c = mx_count_substr(agents_str, "}");
		t_agent ** as = NULL;
		if ((a_c == n_c) && (p_c == s_c) && (rb_c == lb_c) && (rb_c + lb_c == 2 * a_c)){
			as = mx_take_data(agents_str, n_c, p_c, s_c);
			if (mx_strcmp(argv[1], "-p") == 0) 
				mx_sort(as, p_c, ascending_p);
			else if (mx_strcmp(argv[1], "-s") == 0) 
				mx_sort(as, s_c, ascending_s);
			else 
				mx_sort(as, n_c, ascending_n);
			for (int i = 0; i < n_c; i++){
				mx_print_agent_info(as[i]->name, as[i]->strength, as[i]->power);
			}
		}else mx_printerr("error\n");		
		free(agents_str);
		if (as) mx_exterminate_agents(&as);
		as = NULL;
	}
	return 0;
}


