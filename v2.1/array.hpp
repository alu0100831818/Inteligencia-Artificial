
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#pragma once

using namespace std;

class array{
    private:
        tablero* t;
        int size;
        int p;
    public:
        array(tablero* t_, int obj[][2], int size_):
            t(t_),
            size(size_),
            p(){
                 pintar(obj);
            }
            void pintar(int obj[][2]){
                int j=0,x,y;
                for (int i=0;i<size;i++){
                    x=obj[i][j];
                    y=obj[i][j+1];
                    t->set_pos(x,y,'#');
                    j=0;
                }
            }
};
