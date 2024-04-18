#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main(int ac,char **av){
	if (ac<2){
		printf("unsufficient argc\n");
		printf("input testcase num\n");
		return 0;
	}
	int m = atoi(av[1]);
	printf("%d\n",m);
	srand(time(NULL));
	for(int i=0;i<m;i++){
		printf("%d\n",rand()%100);
	}
	return (0);
}