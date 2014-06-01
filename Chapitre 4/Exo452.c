// Exercice 4.5.2

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ELEMENT_MAX 50
typedef unsigned int element;

typedef struct {
  size_t card;
  bool pres[ELEMENT_MAX+1];

} ensemble;

// Test de vacuité
bool est_vide(const ensemble *e);
// Test de présence
bool est_dans(const ensemble *e, element x);
// Cardinal de l'ensemble
size_t card(const ensemble *e);
// Ajouter un element à l'ensemble 
int ajout(ensemble *e, element x);
// Retirer un element à l'ensemble
void retrait(ensemble *e, element x);
// Initialisation de l'ensemble à vide
void vide(ensemble *e);

int main(int argc, char *argv[]) {

  return EXIT_SUCCESS;
}

bool est_vide(const ensemble *e) {
  return e->card == 0;
}

size_t card(const ensemble *e) {
  return e->card;
}

int ajout(ensemble *e, element x) {
  if(!(x <= ELEMENT_MAX)) {
    return 67;
  }
  if(e->pres[x] == false) {
    e->pres[x] = true;
    ++e->card;
  }
  return 0;
}

void retrait(ensemble *e, element x) {
  if(!(x <= ELEMENT_MAX)) {
    return;    
  }
  if(e->pres[x] == true) {
    e->pres[x] = false;
    ++e->card;
  }
  return;
}

bool est_dans(const ensemble *e, element x) {
  return x <= ELEMENT_MAX && e[x];
}
