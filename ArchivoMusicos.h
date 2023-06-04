#ifndef ARCHIVOMUSICOS_H_INCLUDED
#define ARCHIVOMUSICOS_H_INCLUDED

class ArchivoMusicos{
    private:
        char nombre[30];

    public:
        ArchivoMusicos(const char *n){
            strcpy(nombre, n);
        }

        ///ALTA
        void agregarRegistro();

        ///DNI
        int buscarMusico(int d);
        Musicos leerMusico(int p);
        void buscarPorDNI();

        //MOSTRAR
        void mostrarRegistros();

        //MODIFICAR
        bool modificarInscripcion();
        bool modificarRegistro(Musicos obj, int p);
        //BAJA
        bool bajaLogica();


};
//////////////////////////////////////////////////////////
///////////////////CARGA EL ARCHIVO///////////////////////
//////////////////////////////////////////////////////////
void ArchivoMusicos::agregarRegistro(){
    Musicos obj;
    FILE *pMusi;
    pMusi=fopen(nombre, "ab");
    if(pMusi==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    int dni;
    cout<<"DNI: ";
    cin>>dni;
    if(buscarMusico(dni)>0){
        cout<<"ESE DNI YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    obj.Cargar(dni);
	fwrite(&obj, sizeof (Musicos), 1, pMusi);
	fclose(pMusi);
}

//////////////////////////////////////////////////////////
//////////////FUNCIONES PARA BUSCAR POR DNI///////////////
//////////////////////////////////////////////////////////
int ArchivoMusicos::buscarMusico(int d){
    Musicos obj;
    int pos=0;
    FILE *pMusi;
    pMusi=fopen(nombre, "rb");
    if(pMusi==NULL){// VERIFICA QUE LO PUEDA ABRIR SI NO ENVIA UN CODIGO DE ERROR
        return -2;
    }

    while(fread(&obj, sizeof obj, 1, pMusi)==1){//MIENTRAS ALLA ARCHIVOS LO RECORRE
        if(obj.getDNI() == d){//SI COINCIDEN LOS DNI RETORNA LA POSICION
            fclose(pMusi);
            return pos;
        }
        pos++;
	}
	fclose(pMusi);
	return -1;
}

Musicos ArchivoMusicos::leerMusico(int p){
    Musicos obj;
    if(p<0){
        obj.setDNI(-3);
        return obj;
    }
    FILE *pMusi;
    pMusi=fopen(nombre, "rb");
    if(pMusi==NULL){
        obj.setDNI(-2);
        return obj;
    }
    fseek(pMusi, sizeof obj * p, 0); ///0: desde el principio, 1: desde la posicion actual, 2: desde el eof
    int aux=fread(&obj, sizeof obj, 1, pMusi);
    fclose(pMusi);
    if(aux==0){
        obj.setDNI(-1);
    }
    return obj;
}

void ArchivoMusicos::buscarPorDNI(){
    Musicos obj;
    int DNI;
    cout<<"INGRESE EL DNI A BUSCAR ";
    cin>>DNI;
    int pos=buscarMusico(DNI);
    obj=leerMusico(pos);
    if(obj.getDNI()>0){
        obj.Mostrar();
    }else if(obj.getDNI()==-3 || obj.getDNI()==-1){
        cout<<"EL DNI NO EXISTE EN EL ARCHIVO"<<endl;
    }else{
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
}

//////////////////////////////////////////////////////////
///////////////////MOSTRAR ARCHIVO////////////////////////
//////////////////////////////////////////////////////////

void ArchivoMusicos::mostrarRegistros(){
    Musicos obj;
    FILE *pMusi;
    pMusi=fopen(nombre, "rb");
    if(pMusi==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof obj, 1, pMusi)==1){
        obj.Mostrar();
        if(obj.getEstado()) cout<<endl;
	}
	fclose(pMusi);
}

//////////////////////////////////////////////////////////
//////////////////MODIFICAR ARCHIVO///////////////////////
//////////////////////////////////////////////////////////

bool ArchivoMusicos::modificarRegistro(Musicos obj, int pos){
    FILE *pMusi;
    pMusi = fopen(nombre, "rb+");
    fseek(pMusi, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pMusi);
    fclose(pMusi);
    return aux;
}

bool ArchivoMusicos::modificarInscripcion(){
    ///SOLICITAR QUE REGISTRO SE QUIERE MODIFICAR EL MAIL
    Musicos obj;
    int DNI;
    cout<<"INGRESE EL DNI DEL CLIENTE A MODIFICAR: ";
    cin>>DNI;
    ///BUSCAR EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarMusico(DNI);
    if(pos==-1){
        cout<<"NO EXISTE CLIENTE CON ESE DNI"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerMusico(pos);
    if(obj.getEstado()==false){
        cout<<"EL CLIENTE INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    ///MODIFICAMOS EL CAMPO EMAIL
    Fecha nuevafechaInscripcion;
    cout<<"INGRESE EL NUEVA FECHA DE INSCRIPCION"<<endl;
    nuevafechaInscripcion.Cargar();
    obj.setFechaIngreso(nuevafechaInscripcion);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
    bool aux = modificarRegistro(obj, pos);
    return aux;
}

//////////////////////////////////////////////////////////
//////////////////MODIFICAR ARCHIVO///////////////////////
//////////////////////////////////////////////////////////

bool ArchivoMusicos::bajaLogica(){
    ///SOLICITAR QUE REGISTRO SE QUIERE DAR DE BAJA
    Musicos obj;
    int DNI;
    cout<<"INGRESE EL DNI A DAR DE BAJA: ";
    cin>>DNI;
    ///BUSCAR EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarMusico(DNI);
    if(pos==-1){
        cout<<"NO EXISTEN MUSICOS CON ESE DNI"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerMusico(pos);
    if(obj.getEstado()==false){
        cout<<"EL MUSICO INGRESADO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }
    ///MODIFICAMOS EL CAMPO ESTADO (LO PONEMOS EN FALSE)
    obj.setEstado(false);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
    bool aux = modificarRegistro(obj, pos);
    return aux;
}

#endif // ARCHIVOMUSICOS_H_INCLUDED
