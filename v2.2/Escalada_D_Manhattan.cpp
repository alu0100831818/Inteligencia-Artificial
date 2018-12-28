


void descendientes_(tablero* tablero_,  vector<elemento>& descendientes,int k_1,int k_2, int& i){
    
    int p_f1=tablero_->get_posfin1();
    int p_f2=tablero_->get_posfin2();
    //cout << "desendientes de: " << k_1 << " " << k_2 <<"_____________"<< endl;
     if(tablero_->ocupado(k_1,k_2-1)==0){
         descendientes.push_back(elemento(k_1,k_2-1, abs(k_1 -p_f1 ) + abs(k_2 - 1 - p_f2)) );
          //cout << "valor: " << (abs(k_1 -p_f1 ) + abs(k_2 - 1 - p_f2)) <<" del punto: " << k_1<< " "<<k_2-1 << endl;
      }
      //DERECHA
      if(tablero_->ocupado(k_1,k_2+1)==0){
          
          descendientes.push_back(elemento (k_1,k_2+1,abs(k_1 - p_f1) + abs(k_2 + 1 - p_f2) ) );
         // cout << "valor: " << (abs(k_1 -p_f1 ) + abs(k_2 + 1 - p_f2)) <<" del punto: " << k_1<< " "<<k_2+1 << endl;
        }
      //NORTE
      if(tablero_->ocupado(k_1-1,k_2)==0){
         
          descendientes.push_back(elemento (k_1-1,k_2,abs(k_1 - 1 - p_f1) + abs(k_2 - p_f2) ) );
          //cout << "valor: " << (abs(k_1 - 1 -p_f1 ) + abs(k_2  - p_f2)) <<" del punto: " << k_1-1<< " "<<k_2 << endl;
      }
      //SUR
      if(tablero_->ocupado(k_1+1,k_2)==0){
          
          descendientes.push_back(elemento (k_1+1,k_2,abs(k_1 + 1- p_f1) + abs(k_2 - p_f2) ) );
          //cout << "valor: " << (abs(k_1 + 1 -p_f1 ) + abs(k_2 - p_f2)) <<" del punto: " << k_1+1<< " "<<k_2 << endl;
      }
      
      
      i=descendientes.size();
}
 void insertar_descen(int k_1,int k_2, tablero* tablero_, int& i, list<elemento>& lista, list<elemento>& visitados){
      vector<elemento> descendientes; //push_back añade elementos al final
      //pop_back elimina el ultimo elemnto
       //comprobaremos una a una las 4 posiciones o posibles
      //direcciones a las que dirigirse.
      //k_1 y k_2 es donde esta el coche en ese momento
      //IZQUIERDA
      descendientes_(tablero_,descendientes,k_1,k_2,i);
     int c_i=i;
     
    if(i!=0){
          //metodo de ordenacion
        burbuja(descendientes,i);
        //cout << "{" << k_1 << " " << k_2 << "}" << endl;
        for(int l=i-1;l>=0;l--){ 
              //insertamos los elementos ordenados en la lista 
              //cout <<descendientes[l].get_1() << " "<< descendientes[l].get_2() << " " << descendientes[l].peso<< endl;
              int p=no_existe(lista,descendientes[l].get_1(),descendientes[l].get_2(),visitados);
              if(p==0){
                lista.push_front(elemento(descendientes[l].get_1(),descendientes[l].get_2()));
              }
              else{
                  c_i--;
              }
        }
        if(c_i==0){
            int a_= lista.front().get_1();
            int b_= lista.front().get_2();
            podar(visitados,a_,b_ );
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
    int final_sincamino=0;
    while((lista.empty()==false)&&(final_sincamino<5000)){
        final_sincamino++;
        elemento pi=lista.front();
        p_1=pi.get_1();
        p_2=pi.get_2();
        lista.pop_front();
         //cout <<"["<<p_1 << " "<< p_2 <<"]"<< endl;
         if((p_1==f_1)&&(p_2==f_2)){
             lista.clear();
         }
         else {
            i=0;
            visitados.push_front(elemento(p_1,p_2)); 
            //cout << "elemento: " << p_1 << " " << p_2 << endl;
            insertar_descen(p_1,p_2, tablero_e, i, lista,visitados);
            //nodo actual en el que estoy7
             
             
         }
         
    }
    
    
}


