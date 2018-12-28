
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#pragma once

using namespace std;

class obstaculo{
    private:
        int p;
        tablero* t;
        
    public:
    
        obstaculo(tablero& t_, int j):
        p(j){ //porcentaje de obstaculos
                
           pintar(t_);
        
        }
        
        obstaculo()
        {}
        
        void obstaculo1(tablero* t_, int j){//porcentaje de obstaculos
             t=t_;
             p=j;
           pintar();
        
        }
        
        void array_(tablero* t,std::vector<int>& objetos){
            int z=objetos.size();
            int pa1,pa2;
            for(int i=0;i<z;i++){
                pa2=objetos.back();
                objetos.pop_back();
                pa1=objetos.back();
                objetos.pop_back();
                
                t->set_pos(pa1,pa2,'#');
            }
        }
        
        void pintar(tablero& t){
            int i=3,j=2;
             
                for(int k=1;k<p;k++){
                    t.set_pos(i,j,'#');
                    i+=2; j+=rand()%11+3;
                }
                for(int k=1;k<p;k++){
                    t.set_pos(j*2,i-1,'#');
                    i+=2/(rand()%20 +1); j=rand()%51+3;
                }
        }
        
        void pintar(){
            int i=3,j=2;
            
                for(int k=1;k<p;k++){
                    t->set_pos(i,j,'#');
                    i+=2; j+=rand()%21+3;
                }
            
                for(int k=1;k<p;k++){
                    t->set_pos(j*2,i-1,'#');
                    i+=2/rand()%21; j=rand()%51+3;
                }
        }

        void pasajeros(int passobj[][2], int size){
            
            // int z=pasajeros_.size();
            cout<<"Dentro pasajeros, cantidad: "<<size<<endl;
            // int pa1=2,pa2=3;
            int j=0,x,y;
            for (int i=0;i<size;i++){
                    x=passobj[i][j];
                    y=passobj[i][j+1];
                    t->set_pos(x,y,'&');
                    j=0;
                }
            // for(int i=0;i<z;i++){
            //     pa2=pasajeros_.back();
            //     pasajeros_.pop_back();
            //     pa1=pasajeros_.back();
            //     pasajeros_.pop_back();
            //     cout<<"pos1: "<<pa1<<" pos2: "<<pa2<<endl;
            //     t->set_pos(pa1,pa2,'&');
            // }
            
        }
        
        //pasajeros aleatorios
        void pasajeros(){
           int i=10,j=4;
            
                for(int k=1;k<p;k++){
                    t->set_pos(i,j,'&');
                    i+=2; j+=rand()%25+3;
                }
            
                for(int k=1;k<p;k++){
                    t->set_pos(j*2,i-1,'&');
                    i+=2/rand()%22; j=rand()%30+3;
                }
        
        }
        
        
        
};

