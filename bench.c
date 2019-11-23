#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "rand.h"


#define ROUNDS 1000
#define LOOP 100000

//#define BUFFER 100


int main(void) {

  /*initiering av array av adresser till block av minne*/
  /*void *buffer[BUFFER];
  for (int i = 0; i < BUFFER; i++) {
  }*/

  void *init = sbrk(0);
  void *current;

  printf("The initial top of the heap is %p.\n", init);

  for (int j = 0; j < ROUNDS; j++) {
  	for (int i = 0; i < LOOP; i++) {
  	  //size_t size = (rand() % 4000) + sizeof(int);

      /*Buffer innehåller adress till olika block av minne*/
     /* int index = rand() % BUFFER; 
  	  if (buffer[index] != NULL) {
  	  	free(buffer[index]);
  	  } */
    
      size_t size = (size_t)request();
      //(rand() % 4000) + sizeof(int);
      int *memory;
      memory = malloc(size);
      
      
      if (memory == NULL) {
      	//fprintf(stderr, "memory allocation failed\n");
        perror("memory failed");
      	return 1;
      }
      /*buffer[index] = memory;*/

      *memory = 123;
      free(memory);
  	}
  	current = sbrk(0);
  	int allocated = (int)((current - init) / 1024);
  	printf("%d\n", j);
  	printf("The current top of the heap is %p.\n", current);
  	printf("    increased by %d Kbyte\n", allocated);
  }

	return 0;
}