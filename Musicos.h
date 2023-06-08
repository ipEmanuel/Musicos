#ifndef MUSICOS_H_INCLUDED
#define MUSICOS_H_INCLUDED


class Musicos: public Persona{
    private:
        int _claustro;
        int _instrumento;
        int _tipoDeMusica;
        Fecha _fechaInscripcion;
        float _matricula;

    public:

        //GETTERS//
        int getClasutro(){return _claustro;}
        int getInstrumento(){return _instrumento;}
        int getTipoDeMusica(){return _tipoDeMusica;}
        Fecha getFechaIngreso(){return _fechaInscripcion;}
        float getMatricula(){return _matricula;}

        //SETTERS//
        void setClasutro(int claustro){_claustro = claustro;}
        void setInstrumento(int instrumento){_instrumento = instrumento;}
        void setTipoDeMusica(int tipoDeMusica){_tipoDeMusica = tipoDeMusica;}
        void setFechaIngreso(Fecha fechaInscripcion){_fechaInscripcion = fechaInscripcion;}
        void setMatricula(float matricula){_matricula = matricula;}

        void Cargar(int dni=-1, int Instrumentos=-1){
                cout<<"INGRESAR CLAUSTRO (1-Docente; 2-Alumno; 3-No Docente; 4-Graduado): ";
                cin>>_claustro;
                cout<<"INGRESAR TIPO DE MUSICA (ENTRE 1 y 10): ";
                cin>>_tipoDeMusica;
                cout<<"INGRESAR FECHA DE INSCRIPCION: "<<endl;
                cout<<"------------------------------"<<endl;
                _fechaInscripcion.Cargar();
                cout<<"------------------------------"<<endl;
                cout<<"INGRESAR MATRICULA: ";
                cin>>_matricula;
                cout<<"------------------------------"<<endl;
                Persona::Cargar(dni);
        }

        void Mostrar(){
            if(estado){
                //cout<<"------------------------------"<<endl;
                cout<<"CLAUSTRO: "<<_claustro<<endl;
                cout<<"INSTRUMENTO: "<<_instrumento<<endl;
                cout<<"TIPO DE MUSICA: "<<_tipoDeMusica<<endl;
                cout<<"MATRICULA: "<<_matricula<<endl;
                cout<<"FECHA DE INSCRIPCION: ";
                _fechaInscripcion.Mostrar();
                Persona::Mostrar();
                cout<<"------------------------------";
            }
        }
};

#endif // MUSICOS_H_INCLUDED
