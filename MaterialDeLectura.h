#ifndef MaterialDeLectura_h
#define MaterialDeLectura_h

class MaterialDeLectura
{

    protected: 
        string titulo; 
        string autor; 
    public: 
        MaterialDeLectura(string t, string a){ titulo = t; autor = a; }
        MaterialDeLectura(){ titulo = ""; autor = ""; }

        void setTitulo(string t){ titulo = t; }
        void setAutor(string a){ autor = a; }
        
        string getTitulo(){ return titulo; }
        string getAutor(){ return autor; }

        virtual void muestra() = 0; 

};

#endif 