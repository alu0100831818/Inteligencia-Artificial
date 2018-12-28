
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
    public:
        obstaculo(tablero& t_, int j):
        p(j){ //porcentaje de onstaculos
                
           pintar(t_);
        
        }
        void pintar(tablero& t){
            int i=3,j=2;
            
                for(int k=1;k<p;k++){
                    t.set_pos(i,j,'#');
                    i+=2; j+=rand()%21+3;
                }
            
                for(int k=1;k<p;k++){
                    t.set_pos(j*2,i-1,'#');
                    i+=2/rand()%21; j=rand()%51+3;
                }
        }
        
};