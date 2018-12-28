
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
        p(j){ //porcentaje de onstaculos
                
           pintar(t_);
        
        }
        
        obstaculo()
        {}
        
        void obstaculo1(tablero* t_, int j){//porcentaje de onstaculos
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

        void pasajeros(tablero* t,std::vector<int>& pasajeros_){
            int z=pasajeros_.size();
            int pa1=2,pa2=3;
            for(int i=1;i<=2;i++){
                pa2=pasajeros_.back();
                pasajeros_.pop_back();
                pa1=pasajeros_.back();
                pasajeros_.pop_back();
                sleep(1);
                //cout <<pa1 << " pos pas " << pa2 << endl;
                t->set_pos_m(pa1,pa2,'&');
                //t->set_pos_m(6,6,'&');
            }
            
        }
        
        //pasajeros aleatorios
        void pasajeros(tablero* t){
           int i=10,j=4;
            
                for(int k=1;k<p;k++){
                    t->set_pos(i,j,'&');
                    i+=2; j+=rand()%25+3;
                }
            
                for(int k=1;k<p;k++){
                    t->set_pos(j*2,i-1,'&');
                    i+=2/rand()%22; j=rand()%30+3;
                }
                int k=t->get_x();
                int k_1=t->get_y();
                for(int i=2;i<k;i*=2){
                    for(int j=3;j<k_1;j*=2){
                        t->set_pos(i,j,'&');
                        t->set_pos(j,i,'&');
                        t->set_pos(j+j,i+j,'&');
                        t->set_pos(i+i,i+j,'&');
                    }
                }
        
        }
        
        
        
};

