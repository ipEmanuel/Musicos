#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED


class Instrumentos {
private:
    int _dni;
    int _tipoMusica;
    char _nombre[30];
    char _apellido[30];

public:
    int getDNI() const { return _dni; }
    const char* getNombre() const { return _nombre; }
    const char* getApellido() const { return _apellido; }
    int getTipoDeMusica() const { return _tipoMusica; }

    void setDNI(int d) { _dni = d; }
    void setNombre(const char* n) { strncpy(_nombre, n, sizeof(_nombre)); _nombre[sizeof(_nombre) - 1] = '\0'; }
    void setApellido(const char* a) { strncpy(_apellido, a, sizeof(_apellido)); _apellido[sizeof(_apellido) - 1] = '\0'; }
    void setTipoDeMusica(int tipoDeMusica) { _tipoMusica = tipoDeMusica; }

    void mostrar(){
        cout << "DNI: " << _dni<< endl;
        cout << "NOMBRE: " << _nombre<< endl;
        cout << "APELLIDO: " << _apellido<< endl;
        cout << "TIPO DE MUSICA: " << _tipoMusica<< endl;
        cout << "-----------------------" << endl;
    }

};

#endif // INSTRUMENTOS_H_INCLUDED
