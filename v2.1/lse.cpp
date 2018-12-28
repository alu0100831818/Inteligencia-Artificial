#include <cstring>
#include <iomanip>
#define LIMITE 1000
#include "nodo_t.hpp"
using namespace std;

template <class T>

class les{
    public:
    nodo_t<T>* inicio;
    nodo_t<T>* final;
    int tami;
    
    les(void):
    inicio(NULL),
    final(NULL),
    tami(0)
    {}
    
    ~les(void){
        
        while(inicio!=NULL){
            nodo_t<T>* aux=inicio;
            inicio=inicio->get_next();
            delete aux;
        }
        
    }
    //insertar por delante
    void insert_lse(nodo_t<T>* a){
        if(inicio==NULL){
            a->set_next(inicio);
            a->set_prev(inicio);
            inicio=a;
            final=a;
        }
        else{
            a->set_prev(inicio);
            inicio->set_next(a);
            inicio=a;
        }
    }
    
    void imprimir_ll(void){
        nodo_t<T>* auxe=inicio;
        while(auxe!=NULL){
            std::cout << auxe->get_dato()<<" ";
            auxe=auxe->get_prev();
        }
        std::cout<<" "<<std::endl;
    }
    //lista vacia
    bool p_empty(void){
        if(tami<=0)
            return true;
        else
            return false;
    
    }
    //insercion por delante sensilla
    void insert(T a){
        if(tami<=LIMITE){
            tami++;
            insert_lse(new nodo_t<T>(a));
        }
        
    }
    //extraer a quien aunta inicio
    T extrac_lse(void){
        nodo_t<T>* auxe=inicio;
        if(!p_empty()){
            tami--;
            inicio=inicio->get_prev();
            return auxe->get_dato();
        }
        return (-1);
        
    }
    //extrae una copia de quien apunta final
    T extrac_copia(void){
        return (final->get_dato());
    }
    //elimina los elementos empezando por el final
    void eliminar(void){
        while(final!=NULL){
            tami--;
            final->set_prev(NULL);
            final=final->get_next();
        }
        inicio=NULL;
        
    }
    //elimina el ultimo elemento apuntado por final
    void eliminar_final(void){
        if(final!=NULL){
            tami--;
            std::cout << final->get_dato()<<" " << endl;
            final=final->get_next();
            final->set_prev(NULL);
            
        }
    }
    
    //METODO PODAR
    void podar(int x, int y){
        int k=0;
        while(k==0){
            k=0;
            //vecino a comprobar
            int b=extrac_lse();
            int a=extrac_lse();
            if((x==a)&&(y==(b-1))){ //vecino occidente
                insert(a); //se me quedaria | b,a
                insert(b);
                k=1;
            }
            
            
            if((x==a)&&(y==(b+1))){ //vecino de oriente
                insert(a); //se me quedaria | b,a
                insert(b);
                k=1;
            }
            
            
            if((x==(a-1))&&(y==b)){ //vecino del norte
                insert(a); //se me quedaria | b,a
                insert(b);
                k=1;
            }
            
            
            if((x==(a+1))&&(y==b)){ //vecino del sur
                insert(a); //se me quedaria | b,a
                insert(b);
                k=1;
            }
            
        }
    }
    
};




