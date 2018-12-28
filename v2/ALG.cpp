#include "objetos_lista.cpp"
#include <stdlib.h>
#include <vector>
 void insertar_descen(int k_1,int k_2, tablero* tablero_, int& i, list<elemento>& lista){
      vector<elemento> descendientes; //push_back añade elementos al final
      //pop_back elimina el ultimo elemnto
      //back accede al ultimo elemento
     
     
     int p=0;
       //comprobaremos una a una las 4 posiciones o posibles
      //direcciones a las que dirigirse.
      //k_1 y k_2 es donde esta el coche en ese momento
      //IZQUIERDA
      if(tablero_->ocupado(k_1,k_2-1)==0){
          p=abs(k_1 - tablero_->get_posfin1()) + abs(k_2 - 1 - tablero_->get_posfin2());
          descendientes.push_back(elemento(k_1,k_2-1,p ) );
      }
      //DERECHA
      if(tablero_->ocupado(k_1,k_2+1)==0){
          descendientes.push_back(elemento (k_1,k_2+1,abs(k_1 - tablero_->get_posfin1()) + abs(k_2 + 1 - tablero_->get_posfin2()) ) );
        }
      //NORTE
      if(tablero_->ocupado(k_1-1,k_2)==0){
          descendientes.push_back(elemento (k_1-1,k_2,abs(k_1 - 1 - tablero_->get_posfin1()) + abs(k_2 - tablero_->get_posfin2()) ) );
      }
      //SUR
      if(tablero_->ocupado(k_1+1,k_2)==0){
          descendientes.push_back(elemento (k_1+1,k_2,abs(k_1 + 1- tablero_->get_posfin1()) + abs(k_2 - tablero_->get_posfin2()) ) );
      }
      
      
      i=descendientes.size();
      if(i!=0){
          //metodo de ordenacion
        burbuja(descendientes,i);
        
        for(int l=0;l<i;l++){ 
              //insertamos los elementos ordenados en la lista 
              cout <<descendientes[l].get_1() << " "<< descendientes[l].get_2() << " " << descendientes[l].peso<< endl;
              if(no_existe(lista,descendientes[l].get_1(),descendientes[l].get_2())==false)
                lista.push_front(elemento(descendientes[l].get_1(),descendientes[l].get_2()));
          }
      }
      
  }

void EC(coche* coche_e,tablero* tablero_e ,list<elemento>& lista,list<elemento>& visitados ){

    int i=0,j=0;
    int f_1=tablero_e->get_posfin1();
    int f_2=tablero_e->get_posfin2();
    
    //posicion actual del coche
    int p_1=coche_e->get_pos1_coche();
    int p_2=coche_e->get_pos2_coche();
    
    lista.push_front(elemento(p_1,p_2));
    
    while(lista.empty()==false){
        
        p_2=lista.front().get_1();
        p_1=lista.front().get_2();
        lista.pop_front();
        
         if((p_1==f_1)&&(p_2==f_2)){
             lista.clear();
         }
         else {
            i=0;
            visitados.push_front(elemento(p_1,p_2)); 
            int k_1=visitados.front().get_1();
            int k_2=visitados.front().get_2();
            
            insertar_descen(k_1,k_2, tablero_e, i, lista);
            if(i==0)
                podar(k_1,k_2,lista);
                //podamos
            for(elemento n: lista){
                cout << n.get_1() << " " << n.get_2()<< endl;
            }
            cout << "_____________________" << endl;
            if(j==15)
                lista.clear();
                j++;
         }
        
        
    }
    
}