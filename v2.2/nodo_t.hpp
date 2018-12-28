
template <class DATO>
    class nodo_t{
      public:
        DATO dato_;
        nodo_t<DATO>* next;
        nodo_t<DATO>* prev_;
        
        nodo_t(DATO a): 
        dato_(a),
        next(NULL),
        prev_(NULL){}
        
        ~nodo_t(void){}
        
        DATO get_dato(void){
            return dato_;}
            
        nodo_t<DATO>* get_next(void){
            return next;}
            
        void set_next(nodo_t<DATO>* a){
            next=a;}
            
        void set_prev(nodo_t<DATO>* a){
            prev_=a;}
        
        nodo_t<DATO>* get_prev(void){
            return prev_;}
    };