#include <stdlib.h>
#include <unistd.h>

/*en chunk(nod)*/
struct chunk {
  int size;
  struct chunk *next;
};

/*en chunk-pekare*/
struct chunk* flist = NULL;

void *malloc(size_t size) {
  if (size == 0) {
  	return NULL;
  }

  struct chunk *next = flist;
  struct chunk *prev = NULL;
  /*så länge vi inte är i slutet av listan*/
  while (next != NULL) {
    if (next->size >= size) {
      if (prev != NULL) {
        prev->next = next->next;
      } else {
        flist = next->next;
      }
    return (void*)(next + 1);
    } else {
        prev = next;
        next = next->next;
      }
  }
  /*vi har inte hittat rätt storlek i listan och använder sbrk för att hämta mer minne*/
  void *memory = sbrk(size + sizeof(struct chunk));
  if (memory == (void *)-1) {
  	return NULL;
  } else {
  	struct chunk *cnk = (struct chunk*)memory;
    cnk->size = size;
    return (void*)(cnk + 1);
  }
}


/*frigör minne genom att länka in blocket av minne i fria listan.*/
void free(void *memory) {
  if (memory != NULL) {
    struct chunk *cnk = (struct chunk*)((struct chunk*)memory - 1);
    cnk->next = flist;
    flist = cnk;
  }
	return;
}