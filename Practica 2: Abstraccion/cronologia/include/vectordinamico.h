#ifndef _VECTORDINAMICO_
#define _VECTORDINAMICO_

template <class T>
class VectorDinamico{

 private:
  
  int utilizados;
  int reservados;
  T *datos;

 public:

  VectorDinamico();
  
  VectorDinamico(int n);

  VectorDinamico& operator=(const VectorDinamico &original);
  
  VectorDinamico(const VectorDinamico &original);
    
  ~VectorDinamico();

  void destruir();
  
  int reserved() const;

  int used() const;

  T& operator[](int i);

  const T& operator[](int i) const;
    
  void insertar(int i, T elemento);

  void aniade(T elemento);

  void elimina(int i);

  void resize(int n);

  bool empty();
  
};

#include "../src/vectordinamico.cpp"

#endif
  
  
