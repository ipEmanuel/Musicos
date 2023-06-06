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
        cout<<"CARGA DE INSTRUMENTOS"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"INGRESAR NOMBRE: ";
        cin>>_nombre;
        cout<<"INGRESAR CONTINENTE: ";
        cin>>_continente;
        _estado=true;
    }

    void mostrar(){
        if(_estado){
            cout << "ID: " << _id<< endl;
            cout << "NOMBRE: " << _nombre<< endl;
            cout << "CONTINENTE: " << _continente<< endl;
            cout << "-----------------------" << endl;
        }
    }

};
#endif // PAISES_H_INCLUDED
