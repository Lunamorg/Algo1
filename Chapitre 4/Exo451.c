// Exercice 4.5.1

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ELEMENT_MAX 50
typedef unsigned int element;
typedef bool ensemble[ELEMENT_MAX + 1];

// initialisation au vide
void vide(ensemble e);
// ajout d'un élément dans l'ensemble
int ajout(ensemble e,element x);
// retrait d'un élément dans l'ensemble
void retrait(ensemble e, element x);
// cardinal de l'ensemble
size_t card(const ensemble e);
// test de vacuité
bool est_vide(const ensemble e);
// test de présence
bool est_dans(const ensemble e, element x);

int main(int argc, char *argv[])
{
  ensemble e;
  if(ajout(e, 1) == 0) printf("Element ajoute  \n");
  else printf("L'element n'a pas pu être ajoute \n");
  
	if(est_vide(e)) printf("L'ensemble est vide ! \n");  
  else printf("L'ensemble n'est pas vide \n");
  
	return 0;
}

bool est_dans(const ensemble e, element x) {
  return x <= ELEMENT_MAX && e[x];  
}

bool est_vide(const ensemble e) {
  element x = 0;
  // IB : 0 <= x && x <= ELEMENT_MAX+1 && e[0...x-1] == false
  // QC : x
  while(x <= ELEMENT_MAX && !e[x]) {
    ++x;
  }
  return x > ELEMENT_MAX;
}

size_t card(const ensemble e) {
  size_t n = 0;
  element x = 0;
  // IB : 0 <= x && x <= ELEMENT_MAX + 1 
  //  && n == #(e inter [0....x-1]
  // QC : x
  while(x <= ELEMENT_MAX) {
    n+=e[x];
    ++x;
  }
  return n;
}

int ajout(ensemble e, element x) {
  if(!(x <= ELEMENT_MAX)) {
    return -1;
  }
  e[x] = true;
  return 0;
}

void retrait(ensemble e, element x) {
  if(!(x <= ELEMENT_MAX)) {
    return;
  }
  e[x] = false;
}

void vide(ensemble e) {
  element x = 0;
  // IB : 0 <= x && x <= ELEMENT_MAX + 1 && e[0....x-1] == false
  // QC : x
  while(x <= ELEMENT_MAX) {
    e[x] = false;
    ++x;
  }
}
