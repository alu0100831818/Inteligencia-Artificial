#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <fstream>
#include "objetos_lista.cpp"

class coche{
    private:
        int pos1;
        int pos2;
        tablero* t;
    public:
        

  
  
coche(tablero* t_){
  t=t_;
  pos1=2;
  pos2=2;
  pintar();
}

coche(tablero* t_,int k, int p):
pos1(k),
pos2(p),
t(t_){
  pintar();
}

int get_pos1_coche()
{
  return(pos1);
}

int get_pos2_coche()
{
  return(pos2);
}

void set_pos1_coche(int x)
{
  pos1 = x;
}

void set_pos2_coche(int y)
{
  pos2 = y;
}

void pintar(){
  t->set_pos(pos1,pos2,'@');
}

void mostrar_ruta(std::list<elemento> visitados){
  int m=visitados.size();
    for(int j=0;j<m; j++){
      // cout << "\033[2J\033[1;1H";
      elemento p=visitados.back();
      sleep(1);
      t->set_pos_i(p.get_1(),p.get_2(),'X');
      visitados.pop_back();
      t->pintar_tablero();
    }
  
}

};