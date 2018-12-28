// erasing from vector
#include <iostream>
#include <vector>
#include <list>
#include "objetos_lista.cpp"
using namespace std;
int main ()
{
  list<elemento> lista;
  list<elemento> visitados;
  
  lista.push_front(elemento(8,2));
  lista.push_front(elemento(7,2));
  lista.push_front(elemento(6,2));
  lista.push_front(elemento(5,4));
  lista.push_front(elemento(8,6));
  
  podar(lista,7,3);
  
  for(elemento n : lista){
    
    cout << (n).get_1() << " "<< n.get_2() << endl;
  }
  
  
  
}