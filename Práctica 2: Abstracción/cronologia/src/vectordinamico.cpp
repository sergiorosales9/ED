#include <iostream>
#include <cassert>

using namespace std;

template <class T>
VectorDinamico<T>::VectorDinamico(){
  datos=0;
  reservados = utilizados = 0;
}

template <class T>
VectorDinamico<T>::VectorDinamico(int n) 
{
  assert(n>=0);
  if (n>0)
    datos=new T[n];
  reservados=n;
  utilizados=0;
}

template <class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico &original) 
{
  reservados= original.reservados;
  if (reservados>0){
    datos= new T[reservados];

  utilizados = original.utilizados;
  
  for (int i=0; i<utilizados; ++i)
    datos[i]= original.datos[i];
  
  }else {
    datos=0;
    utilizados = reservados = 0;
  }
}

template <class T>
VectorDinamico<T>::~VectorDinamico() 
{
  if (datos!=0) delete[] datos;
}

template <class T>
int VectorDinamico<T>::reservados() const 
{ 
  return reservados; 
}

template <class T>
int VectorDinamico<T>::utilizados() const 
{ 
  return utilizados; 
}

template <class T>
T& VectorDinamico<T>::operator[] (int i) {
  
  assert (0<=i && i<utilizados);
  return datos[i];
}

template <class T>
const T& VectorDinamico<T>::operator[] (int i) const {

  assert (0<=i && i<utilizados);
  return datos[i];
}

template <class T>
void VectoDinamico<T>::resize(int n){

  assert(n >= 0);
  
  if(n != reservados){
    if(n != 0) {

      T *aux = new T[n];

      int min = utilizados < n ? utilizados : n;  
	
      for(int i = 0; i < min; i++)
	aux[i] = datos[i];

      delete [] datos;
      datos = aux;
    }
    else{
      if(reservados > 0)
	delete [] datos;

      utilizados = reservados = 0;
      datos = 0;
    }
  }
}

template <class T>
VectorDinamico& VectorDinamico<T>::operator= (const VectorDinamico &original)
{
  if (this!= &original) {
    if (datos!=0) delete[] datos;
    
    reservados= original.reservados;
    utilizados= original.utilizados;
    
    if(reservados>0) datos= new T[reservados];
    
    for (int i=0; i<utilizados; ++i)
      datos[i]= original.datos[i];
  }
  return *this;
}

template <class T>
void VectorDinamico<T>::aniade(T dato) {
  if (datos == 0){
    reservados=1;
    datos= new T[reservados];
    datos[0]= dato;
    utilizados=1;
   
  } else {
    if(utilizados == reservados) resize(reservados*2);

    datos[utilizados]=dato;
    utilizados++;
  }
}

template <class T>
void VectorDinamico<T>::insertar(int i, T dato) {
  
  if(datos==0){
    aniade(dato);
  }else{
    assert(i>=0 && i <= reservados);
      if(i>=utilizados){
	aniade(dato);
      }else{
	if(utilizados == reservados)
	  resize(reservados*2);

	for(int j=utilizados; j>=i; j--){
	  datos[j] = datos[j-1];
	}
	datos[i]=dato;
	utilizados++;
    }
  }
}
	
template <class T>
void VectorDinamico<T>::elimina(int i){

  assert(i>=0 && i<utilizados);

  for(int j=i; j<utilizados-1; j++){
    datos[j]=datos[j+1];
  }

  utilizados--;
}
