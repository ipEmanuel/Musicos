#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED
class Paises {
private:
    int _id;
    char _nombre[30];
    char _continente[30];
    bool _estado;

public:
    int getId() const { return _id; }
    const char* getNombre() const { return _nombre; }
    const char* getContinente() const { return _continente; }
    bool getEstado() const { return _estado; }

    void setId(int id) { _id = id; }
    void setNombre(const char *nombre){strcpy(_nombre,nombre);}
    void setContinente(const char *continente){strcpy(_continente,continente);}
    void setEstado(bool estado) { _estado = estado; }

    void cargar(int id){
        _id=id;
        cout<<"CARGA DE PAISES"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"INGRESAR NOMBRE: ";
        cin>>_nombre;
         // Convertir _nombre a mayúsculas
        int length = std::strlen(_nombre);
        for (int i = 0; i < length; i++) {
            _nombre[i] = std::toupper(_nombre[i]);
        }
        cout<<"INGRESAR CONTINENTE: ";
        cin>>_continente;
        length = std::strlen(_continente);
        for (int i = 0; i < length; i++) {
            _continente[i] = std::toupper(_continente[i]);
        }
        _estado=true;
    }

    void mostrar(){
        if(_estado){
            cout << left << setw(15) <<  _id;
            cout << left << setw(15) <<  _nombre;
            cout << left << setw(15) <<  _continente;
        }
    }

};
#endif // PAISES_H_INCLUDED
