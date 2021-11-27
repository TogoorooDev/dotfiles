#include <stdio.h>
#include <time.h>

int main(){
	while (1){
		time_t ttme;
		time(&ttme);
		printf(".");
	}
	return 0;
}
