/*

MENU PRINCIPAL, EN EL SE DESARROLLAN LAS LLAMADAS PRINCIPALES
SE CREA EL TABLERO, EL COCHE Y LOS DISTINTOS OBSTACULOS Y PASAJEROS.


*/
#include <unistd.h>
#include <iostream>
#include "tablero.cpp"
#include "coche.cpp"
#include "obstaculos.hpp"
#include <list>
#include "Escalada_D_Manhattan.cpp"
#include "array.hpp"


using namespace std;

int main(void){
    //-----------------------------------------------
    int n,m,pos1acceso,pos2acceso,pos1fin,pos2fin,pos1coche,pos2coche;
    int selec, porciento,num_obstaculos=0, k=0;
    //limpiar pantalla
    cout << "\033[2J\033[1;1H";
    cout<<endl;
    cout<<"///COCHE AUTONOMO//";
    cout<<endl<<endl<<endl;
    
    
   //-----------------------------------------------
    cout<<"Introduzca numero de filas N:";
    cin>>n;
    cout<<"Introduzca numero de columnas M:";
    cin>>m;
    bool opcion=true;
    while(opcion==true){
        cout<<"Introduzca posicion de partida X:";
        cin>>pos1acceso;
        cout<<"Introduzca posicion de partida Y:";
        cin>>pos2acceso;
        cout<<"Introduzca posicion final X:";
        cin>>pos1fin;
        cout<<"Introduzca posicion final Y:";
        cin>>pos2fin;
        
        if((pos1acceso<=1)||(pos2acceso<=1))
            cout << "posicion de partida x,y incorrecta, deben ser mayores que 1"<< endl;
        else
            opcion=false;
        if((pos1acceso>=n)||(pos2acceso>=m))
             cout << "posicion de partida x,y incorrecta, no deben coincidir con los limites de la tabla o superarlos"<< endl;
        else
            opcion=false;
        
    }
    //-----------------------------------------------
    vector<int> paseng;
    int select2;
    cout << endl;
    cout <<"Elegir pasajeros: " << endl;
    cout << "[1.]Pasajeros aleatorios?\n"
         << "[2.]Elegir posiciones de los pasajeros en la tabla?\n"
         << endl;
    cin>>select2;
    if(select2==2){
        cout << "Numero de posibles pasajeros?: ";
        int pas=0,p_s=0;
        cin >> pas;
        for(int i =0;i<pas;i++){
            cout << "Coordenada  " << i+1 << ": " << endl;
            cin >> p_s;
            paseng.push_back(p_s);
            cin >> p_s;
            paseng.push_back(p_s);
        }
    }
    //-----------------------------------------------
    vector<int> objetos;
    cout<<"Como quiere ejecutar el programa?"<<endl;
    cout<<"*Sin obstaculos(0)"<<endl;
    cout<<"*Con obstaculos:"<<endl;
    cout<<"      -Aleatorios (1) "<<endl;cout<<"      -Manual (2)"<<endl;cout<<"      -Porcentaje (3)"<<endl;
    cin>>selec;
    
    srand (time(NULL));
    //sin obstaculos
    if(selec==0){
        porciento = 0;
    }
    //aleatorios
    else if(selec==1){
        //solo hasta el 80%
        porciento = rand() %80 + 1;
    }
    //manual 1 a 1
    else if(selec==2){
        cout<<"Cuantos obstaculos quiere poner?";
        int pas=0,p_s1=0;
        cin >> pas;
        for(int i =0;i<pas;i++){
            cout << "coordenada  " << i+1 << ": " << endl;
            cin >> p_s1;
            objetos.push_back(p_s1);
            cin >> p_s1;
            objetos.push_back(p_s1);
        }
    }
    
    //introduciendo el porcentaje
    else if(selec==3){
        cout<<"Introduzca porcentaje % : ";
        cin>>porciento;
    }else{
        cout<<"Opcion incorrecta!"<<endl;
        return 1;
    }
    //-----------------------------------------------
    
        obstaculo obstaculos_;
        tablero t(n,m,pos1acceso,pos2acceso,pos1fin,pos2fin);
        coche pCoche(&t,pos1acceso,pos2acceso);
        //pasajeros
        
        if(selec!=2){
            obstaculos_.obstaculo1(&t,porciento);
        }
        //si se ponen los obstaculos manualmente 1 a 1
        else{
            obstaculos_.array_(&t,objetos);
        }
        
        if(select2==2){
            obstaculos_.pasajeros(paseng);
        }
        else{
            obstaculos_.pasajeros();
        }
        
        
        t.pintar_tablero();
        list<elemento> lista;
        list<elemento> visitados;
        
        EC(&pCoche,&t,lista,visitados);
        
         elemento v=visitados.front();
            int a=v.get_1();
            int b=v.get_2();
            visitados.pop_front();
        if(v.vecino(pos1fin,pos2fin)==false)
         cout << "No existe un camino minimo hasta el lugar" << endl;
         else{
            visitados.push_front(v);
            pCoche.mostrar_ruta(visitados);
         }
    }






