int mx_atoi(const char* str);
void mx_printchar(char c);
void mx_printint(int n);

int main(int argc , char  * argv[])
{	
	int fro_inx = mx_atoi(argv[1]);
	int to_inx = mx_atoi(argv[2]);
	if (argc != 3) return 0;
	if ( fro_inx >  to_inx){
		fro_inx = mx_atoi(argv[2]);
		to_inx = mx_atoi(argv[1]);
	}
	if ( fro_inx < 0 
			|| fro_inx > 9 ) return 0;
	if ( to_inx < 0 
			|| to_inx > 9 ) return 0;
	for ( int i = fro_inx; i <= to_inx; i++){
		for ( int j = fro_inx; j <= to_inx; j++){
			mx_printint(i * j);
			if (j != to_inx) mx_printchar('\t');
		}
		mx_printchar('\n');
	}
	return 0;
}


