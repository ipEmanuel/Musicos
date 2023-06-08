#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED


class Instrumentos {
private:
    int _id;
    char _nombre[30];
    int _clasificacion;
    bool _estado;

public:
    int getId() const { return _id; }
    const char* getNombre() const { return _nombre; }
    int getClasificacion() const {return _clasificacion;}
    bool getEstado() const { return _estado; }

    void setId(int id) { _id = id; }
    void setNombre(const char *nombre){strcpy(_nombre,nombre);}
    void setClasificacion(int clasificacion) { _clasificacion = clasificacion; }
    void setEstado(bool estado) { _estado = estado; }

    void cargar(int id){
        _id=id;
        cout<<"CARGA DE INSTRUMENTOS"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"INGRESAR NOMBRE: ";
        cin>>_nombre;
         // Convertir _nombre a mayúsculas
        int length = std::strlen(_nombre);
        for (int i = 0; i < length; i++) {
            _nombre[i] = std::toupper(_nombre[i]);
        }
        cout<<"INGRESAR CLASIFICACION: ";
        cin>>_clasificacion;
        _estado=true;
    }

    void mostrar(){
        if(_estado){
            cout << "ID: " << _id<< endl;
            cout << "NOMBRE: " << _nombre<< endl;
            cout << "CLASIFICACION: " << _clasificacion<< endl;
            cout << "-----------------------" << endl;
        }
    }

};

#endif // INSTRUMENTOS_H_INCLUDED
