#ifndef ARCHIVOPAISES_H_INCLUDED
#define ARCHIVOPAISES_H_INCLUDED

class ArchivoPaises{
    private:
        char nombre[30];

    public:
        ArchivoPaises(const char *n){
            strcpy(nombre, n);
        }

        ///ALTA
        void agregarRegistro();

        ///ID
        int ultimoID();
        Paises leerPaises(int p);
        int buscarID(int id);
        void buscarPorID();

        //MOSTRAR
        void mostrarRegistros();

        //MODIFICAR
        bool modificarNombre();
        bool modificarRegistro(Paises obj, int p);
        //BAJA
        bool bajaLogica();
};
//////////////////////////////////////////////////////////
///////////////////CARGA EL ARCHIVO///////////////////////
//////////////////////////////////////////////////////////
void ArchivoPaises::agregarRegistro(){
    Paises obj;
    FILE *pPais;
    pPais=fopen(nombre, "ab");
    if(pPais==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    obj.cargar(ultimoID());
	fwrite(&obj, sizeof (Paises), 1, pPais);
	fclose(pPais);
}
//////////////////////////////////////////////////////////
////////////////////////ULTIMO ID/////////////////////////
//////////////////////////////////////////////////////////
int ArchivoPaises::ultimoID(){
    Paises obj;
    int ultimoID = 0; // VARIABLE PARA ALMACENAR EL ÚLTIMO ID
    FILE *pPais;
    pPais=fopen(nombre, "rb");
    if(pPais==NULL){
        return -2;
    }
    // POSICIONAR EL PUNTERO AL FINAL DEL ARCHIVO
    fseek(pPais, 0, SEEK_END);
    // OBTENIENE LA POSICIÓN ACTUAL DEL PUNTERO
    long fileSize = ftell(pPais);
    // VERIFICAR SI EL TAMAÑO DEL ARCHIVO ES MAYOR O IGUAL AL TAMAÑO DE UN REGISTRO DE Paises
    if (fileSize >= sizeof(Paises)) {
        // RETROCEDER EL PUNTERO EN EL TAMAÑO DE UN REGISTRO DE Paises DESDE EL FINAL DEL ARCHIVO
        fseek(pPais, -sizeof(Paises), SEEK_END);
        // LEE EL ÚLTIMO REGISTRO DE Pises DEL ARCHIVO
        fread(&obj, sizeof(Paises), 1, pPais);
        // OBTENIENE EL ID DEL ÚLTIMO REGISTRO
        ultimoID = obj.getId();
    }
    fclose(pPais);
    // RETORNAR EL ÚLTIMO ID INCREMENTADO EN 1 PARA EL NUEVO REGISTRO
    return ultimoID + 1;
}
//////////////////////////////////////////////////////////
//////////////FUNCIONES PARA BUSCAR POR ID////////////////
//////////////////////////////////////////////////////////
Paises ArchivoPaises::leerPaises(int p){
    Paises obj;
    FILE *pPais;
    pPais = fopen(nombre, "rb");
    if(pPais == NULL){
        obj.setId(-2);
        return obj;
    }
    fseek(pPais, sizeof obj * p, 0); ///0: desde el principio, 1: desde la posicion actual, 2: desde el eof
    int aux = fread(&obj, sizeof obj, 1, pPais);
    fclose(pPais);
    if(aux==0){
        obj.setId(-1);
    }
    return obj;
}
int ArchivoPaises::buscarID(int id){
    Paises obj;
    int pos=0;
    FILE *pPais;
    pPais=fopen(nombre, "rb");
    if(pPais==NULL){// VERIFICA QUE LO PUEDA ABRIR SI NO ENVIA UN CODIGO DE ERROR
        return -2;
    }

    while(fread(&obj, sizeof obj, 1, pPais)==1){//MIENTRAS ALLA ARCHIVOS LO RECORRE
        if(obj.getId() == id){//SI COINCIDEN LOS DNI RETORNA LA POSICION
            fclose(pPais);
            return pos;
        }
        pos++;
	}
	fclose(pPais);
	return -1;
}
void ArchivoPaises::buscarPorID(){
    Paises obj;
    int ID;
    cout<<"INGRESE EL ID A BUSCAR ";
    cin>>ID;
    int pos=buscarID(ID);
    obj=leerPaises(pos);
    if(obj.getId() > 0 && obj.getEstado() == true){
        obj.mostrar();
    }else if(obj.getId()<=0){
        cout<<"EL ID NO EXISTE EN EL ARCHIVO"<<endl;
    }else{
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
}
//////////////////////////////////////////////////////////
///////////////////MOSTRAR ARCHIVO////////////////////////
//////////////////////////////////////////////////////////
void ArchivoPaises::mostrarRegistros(){
    Paises obj;
    FILE *pPais;
    pPais=fopen(nombre, "rb");
    if(pPais==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof obj, 1, pPais)==1){
        if(obj.getEstado()){
            obj.mostrar();
             cout<<endl;
        }
	}
	fclose(pPais);
}

//////////////////////////////////////////////////////////
//////////////////MODIFICAR ARCHIVO///////////////////////
//////////////////////////////////////////////////////////

bool ArchivoPaises::modificarRegistro(Paises obj, int pos){
    FILE *pPais;
    pPais = fopen(nombre, "rb+");
    fseek(pPais, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pPais);
    fclose(pPais);
    return aux;
}

bool ArchivoPaises::modificarNombre(){
    ///SOLICITAR QUE REGISTRO SE QUIERE MODIFICAR
    Paises obj;
    int id;
    cout<<"INGRESE EL ID DEL PAIS A MODIFICAR: ";
    cin>>id;
    ///BUSCAR EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarID(id);
    if(pos==-1){
        cout<<"NO EXISTE PAIS CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerPaises(pos);
    if(obj.getEstado()==false){
        cout<<"EL PAIS INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    ///MODIFICAMOS EL CAMPO NOMBRE
    char nuevoNombre[30];
    cout<<"INGRESE EL NUEVO NOMBRE"<<endl;
    cin>>nuevoNombre;
    obj.setNombre(nuevoNombre);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO
    //(EN LA MISMA POSICION QUE OCUPABA)
    bool aux = modificarRegistro(obj, pos);
    return aux;
}
///////////////////////////////////////////////////////////
//////////////////////////BAJA/////////////////////////////
///////////////////////////////////////////////////////////
bool ArchivoPaises::bajaLogica(){
    ///SOLICITAR QUE REGISTRO SE QUIERE DAR DE BAJA
    Paises obj;
    int id;
    cout<<"INGRESE EL ID A DAR DE BAJA: ";
    cin>>id;
    ///BUSCAR EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarID(id);
    if(pos==-1){
        cout<<"NO EXISTEN INSTRUMENTOS CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerPaises(pos);
    if(obj.getEstado()==false){
        cout<<"EL INSTRUMENTO INGRESADO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }
    ///MODIFICAMOS EL CAMPO ESTADO (LO PONEMOS EN FALSE)
    obj.setEstado(false);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
    bool aux = modificarRegistro(obj, pos);
    return aux;
}
#endif // ARCHIVOPAISES_H_INCLUDED
