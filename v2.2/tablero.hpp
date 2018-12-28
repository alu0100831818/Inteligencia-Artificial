#pragma once

using namespace std;
class tablero{
    int x; //tamaño tablero
    int y;
    
    int c; //punto de partida
    int d;
    
    int f; //punto final
    int g;
    char* T_;
    public:
     
    tablero(int a,int b,int,int,int,int);
  
    int datos_tabler(int a);
        
    void pintar_tablero(void);
     
    void set_pos(int i,int j,char c);
     
    void set_pos_i(int i,int j,char c);
    
    char get_dato(int i,int  j);
    
    int get_y();
    int get_x();
    
    int get_posfin1();
    
    int get_posfin2();
    
    int ocupado(int,int);
    
    int tam();
};