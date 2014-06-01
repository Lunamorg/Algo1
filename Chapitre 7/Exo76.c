#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void mem_swap(void *s1, void *s2, size_t size);

int main(int argc, char *argv[]) {
  char *chaine1 = "Lunamo";
  char *chaine2 = "Freder";
  
  printf("%s \n", chaine1);
  printf("%s \n", chaine2);
  
  mem_swap(&chaine1, &chaine2, 6);
  
  printf("%s \n", chaine1);
  printf("%s \n", chaine2);    
  
  return EXIT_SUCCESS;
}

void mem_swap(void *s1, void *s2, size_t size) {
  size_t k = 0;  
  while(k < size) {
    char c = ((char*)s1)[k];
    ((char*)s1)[k] = ((char*)s2)[k];
    ((char*)s2)[k] = c;   
    ++k; 
  }
}
