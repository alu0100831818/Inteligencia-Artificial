
#include <iostream>
#include "tablero.cpp"
#include "coche.cpp"
#include "obstaculos.hpp"
#include <list>
#include "Escalada_D_Manhattan.cpp"

using namespace std;

int main(void){
    cout<<endl;
    cout<<"///COCHE AUTONOMO//";
    cout<<endl<<endl<<endl;
    //coche pCoche;
    int n,m,pos1acceso,pos2acceso,pos1fin,pos2fin,pos1coche,pos2coche;
    cout<<"Introduzca numero de filas N:";
    cin>>n;
    cout<<"Introduzca numero de columnas M:";
    cin>>m;
    
    cout<<"Introduzca posicion de partida X:";
    cin>>pos1acceso;
    cout<<"Introduzca posicion de partida Y:";
    cin>>pos2acceso;
    cout<<"Introduzca posicion final X:";
    cin>>pos1fin;
    cout<<"Introduzca posicion final Y:";
    cin>>pos2fin;
    //
    
    //while(i==5){
        
        tablero t(n,m,pos1acceso,pos2acceso,pos1fin,pos2fin);
         coche pCoche(&t,pos1acceso,pos2acceso);
        obstaculo obstaculos_(t,80);
       
        t.pintar_tablero();
        list<elemento> lista;
        list<elemento> visitados;
        
        EC(&pCoche,&t,lista,visitados);
        pCoche.mostrar_ruta(visitados);
         t.pintar_tablero();
    };






