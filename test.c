#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "rand.h"

/*struct chunk {
	int size;
	struct chunk *next;
};*/ 

int main(int argc, char *argv[]) {
  if (argc < 2) {
  	printf("usage: rand <loop>\n");
  	exit(1);
  }
  int loop = atoi(argv[1]);
  for (int i = 0; i < loop; i++) {
  	int size = request();
  	printf("%d\n", size);
  }
/*struct chunk *next;
printf("storlek på chunk: %ld\n", sizeof(next));*/
  return 0;
}