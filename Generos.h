#ifndef GENEROS_H_INCLUDED
#define GENEROS_H_INCLUDED

class Generos{
    private:
        int _id;
        char _nombre[30];
        int _paisOrigen;
        int _anioOrigen;
        bool _estado;

    public:
        //GETTERS

        int getId(){return _id;}
        const char* getNombre(){return _nombre;}
        int getPaisOrigen(){return _paisOrigen;}
        int getAnioOrigen(){return _anioOrigen;}
        bool getEstado(){return _estado;}

        //SETTERS
        void setId(const int id){_id=id;}
        void setNombre(const char *n){strcpy(_nombre,n);}
        void setPaisOrigen(int paisOrigen);
        void setAnioOrigen(int anioOrigen);
        void setEstado(bool e){_estado=e;}

        void Cargar(int anioOrigen, int id, int paisOrigen);
        void Mostrar();
        bool anioValido(int anio);

};


bool Generos::anioValido(int anio){

    Fecha anioActual;
    if(anio>1500 && anio <= anioActual.getAnio()){
        return true;
    }
}

void Generos::setPaisOrigen(int paisOrigen){
    if(paisOrigen>0 && paisOrigen<=100){
         _paisOrigen=paisOrigen;}

}
void Generos::setAnioOrigen(int anioOrigen){

    if(anioValido(anioOrigen)){
        _anioOrigen=anioOrigen;
    }else{
        cout<<"ANIO NO VALIDO";
    }
}

void Generos:: Cargar(int anioOrigen, int id, int paisOrigen){

    _id=id;
    _anioOrigen=anioOrigen;

    cout<<"INGRESAR NOMBRE: ";
    cin>>_nombre;

    // Convertir _nombre a mayúsculas
    int length = std::strlen(_nombre);
    for (int i = 0; i < length; i++) {
        _nombre[i] = std::toupper(_nombre[i]);
    }

    _paisOrigen=paisOrigen;
    _estado=true;
}

void Generos::Mostrar(){
    if(_estado){
        cout<<"ID "<<_id<<endl;
        cout<<"NOMBRE "<<_nombre<<endl;
        cout<<"PAIS DE ORIGEN "<<_paisOrigen<<endl;
        cout<<"ANIO DE ORIGEN "<<_anioOrigen<<endl;
    }
}

#endif // GENEROS_H_INCLUDED
