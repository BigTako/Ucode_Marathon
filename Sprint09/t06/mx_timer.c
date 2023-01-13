#include <time.h>
double mx_timer(void(*f)())
{
	if (!f) return -1;
	clock_t st, et;
	st = clock();    
	f();
	et = clock();
	return (double)(et - st) / CLOCKS_PER_SEC;
}



