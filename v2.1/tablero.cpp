#include "tablero.hpp"
#include <stdlib.h>

    tablero::tablero(int a,int b,int c_,int d_, int f_, int g_)
     {
         x=a; //FILAS!!
         y=b; //COLUMNAS!!
         c=c_;//punto partida
         d=d_;
         f=f_;//punto final
         g=g_;
         int d_p=x*y;
         T_= new char [d_p];
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                T_[(i-1)*y+j-1]=' ';
                if(i==c && j==d)
                    set_pos(i,j,'I');
                if(i==f && j==g)
                    set_pos(i,j,'F');
                if(i==1||j==1)
                    T_[(i-1)*y+j-1]='*';
                else{
                    if(i==x||j==y)
                        T_[(i-1)*y+j-1]='*';
                    else 
                        T_[(i-1)*y+j-1]=' ';
                }
                
            }
        }   
     }
  
    int tablero::datos_tabler(int a){
         if(a==1)
            return x;
         else{
                return y;
            }
        }
        
    void tablero::pintar_tablero(void){
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                cout << " ";
                if(i==f && j==g)
                    T_[(i-1)*y+j-1]='F';
                    
                if(T_[(i-1)*y+j-1]=='F'){
                    cout << "\033[1;33m"<< T_[(i-1)*y+j-1]<<"\33[m";
                }
                if(T_[(i-1)*y+j-1]=='&'){
                    //\033[0;31m
                    cout << "\033[1;31m"<< T_[(i-1)*y+j-1]<<"\033[0m";
                    
                }
                else{
                    if((T_[(i-1)*y+j-1]!='F')&&(T_[(i-1)*y+j-1]!='X'))
                        cout << T_[(i-1)*y+j-1];
                    
                    if(T_[(i-1)*y+j-1]=='X'){
                        //033[0;36m
                        cout << "\033[0;36m"<< T_[(i-1)*y+j-1]<<"\033[0m";
                    }
                }
                
           }
            cout << endl;
        }
     }
     
    void tablero::set_pos(int i,int j,char c){
        if(i>=x)
            i=x/5+ rand()%(x+1);
        if(j>=y)
            j=y/5 + rand()%(y+1);
            
        if((i>0)&&(i<x)&&(j>0)&&(j<y)){
            if(T_[(i-1)*y+j-1]==' ')
                T_[(i-1)*y+j-1]=c;
        }
     }
     void tablero::set_pos_i(int i,int j,char c){
        if(i>=x)
            i=x/5+ rand()%(x+1);
        if(j>=y)
            j=y/5 + rand()%(y+1);
            
        if((i>0)&&(i<x)&&(j>0)&&(j<y)){
            if((T_[(i-1)*y+j-1]==' ')||(T_[(i-1)*y+j-1]=='&'))
                T_[(i-1)*y+j-1]=c;
        }
        
     }
     
     
    char tablero::get_dato(int i,int  j){
        return T_[(i-1)*y+j-1];
    }
    
    int tablero:: get_y(){ //columnas
        return y;
    }
    
    int tablero:: get_x(){
        return x;
    }
    
    int tablero:: tam(){
        return x*y;
    }

    int tablero:: ocupado(int a,int b){
        if ((get_dato(a,b)!=' ')&&(get_dato(a,b)!='F')&&(get_dato(a,b)!='&'))
            return 1;
        else
            return 0;
    }
    
    int tablero:: get_posfin1(){
        return f;
    }
    
    int tablero:: get_posfin2(){
        return g;
    }
    
    
    
    
    
    