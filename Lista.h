template <class T>
class Lista
{
    private: 
        int size; 
        int len = 20; 
        T arrElem[20];

    public: 
        Lista();
        bool agrega(T);
        int getSize() const { return size; }
        T getElement(int);
        int posicion(T); 

};

template <class T>
Lista<T>::Lista()
{
    size = 0; 
}

template <class T>
int Lista<T>::posicion(T dato)
{
    int pos = -1; 
    for(int i = 0; i < len; i++)
        if(arrElem[i] == dato)
            pos = i; 
    return pos; 
}

template <class T>
bool Lista<T>::agrega(T dato)
{
    if(size < len && posicion(dato) == -1)
    {
        arrElem[size] = dato; 
        size++; 
        return true; 
    }
    return false; 
}

template <class T>
T Lista<T>::getElement(int pos)
{
    T dato; 
    if(pos >= 0 && pos < size)
        return dato = arrElem[pos];
    return dato; 
}