int mx_atoi(const char* str);
void mx_printint(int n);
void mx_printchar(char c);

int main(int argc , char * argv[])
{
	int num[32];
	int i;
	int q = 0;
	if (argc < 1) return 0;
	for (int j = 1; j < argc; j++){
		i = 0;
		for (int c = 0 ; c < 32; c++) num[c] = 0;
		for (int n = mx_atoi(argv[j]); n != 0; n /= 2)
			if (n % 2 < 0)  num[i++] = -(n % 2);
			else num[i++] = n % 2;
		if ( mx_atoi(argv[j]) < 0 ) {
			q = 0;
			for (int c = 31; c >= 0; c--) num[c] = !(num[c]);
			for (; num[q] + 1 != 1; q++) if (num[q] + 1 == 2) num[q]--;
			num[q]++;
		}
		for (int k = 31; k >= 0; k--) mx_printint(num[k]);
		mx_printchar('\n');
	}
	return 0;
}


