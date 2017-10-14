#ifndef _CRONOLOGIA_
#define _CRONOLOGIA_

#include "vectordinamico.h"
#include "fechahistorica.h"

class Cronologia{

 private:

  VectorDinamico<FechaHistorica> fechas;

  void ordenar();
  
 public:

  Cronologia();

  Cronologia(const Cronologia &original);

  Cronologia& operator=(const Cronologia &original);

  void aniade(const FechaHistorica &fecha);
  
  Cronología& operator+=(const Cronologia &crono);

  friend ostream& operator<<(ostream &flujo, const Cronologia &crono);

  friend istream& operator>>(istream &flujo, Cronologia &crono);
};

#endif
