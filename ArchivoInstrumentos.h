#ifndef ARCHIVOINSTRUMENTOS_H_INCLUDED
#define ARCHIVOINSTRUMENTOS_H_INCLUDED

class ArchivoInstrumentos{
    private:
        char nombre[30];

    public:
        ArchivoInstrumentos(const char *n){
            strcpy(nombre, n);
        }

        ///ALTA
        void agregarRegistro();
        //RETORNA EL TOTAL DE LOS REGISTROS
        int contarRegistro();
        ///ID
        int ultimoID();
        Instrumentos leerInstrumentos(int p);
        int buscarID(int id);
        void buscarPorID();

        //MOSTRAR
        void mostrarRegistros();

        //MODIFICAR
        bool modificarNombre();
        bool modificarRegistro(Instrumentos obj, int p);
        //BAJA
        bool bajaLogica();
};
//////////////////////////////////////////////////////////
////////////RETORNA EL TOTAL DE LOS REGISTROS/////////////
//////////////////////////////////////////////////////////
int ArchivoInstrumentos::contarRegistro(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Instrumentos);
    }
//////////////////////////////////////////////////////////
///////////////////CARGA EL ARCHIVO///////////////////////
//////////////////////////////////////////////////////////
void ArchivoInstrumentos::agregarRegistro(){
    Instrumentos obj;
    FILE *pIns;
    pIns=fopen(nombre, "ab");
    if(pIns==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    obj.cargar(ultimoID());
	fwrite(&obj, sizeof (Instrumentos), 1, pIns);
	fclose(pIns);
}
//////////////////////////////////////////////////////////
////////////////////////ULTIMO ID/////////////////////////
//////////////////////////////////////////////////////////
int ArchivoInstrumentos::ultimoID(){
    Instrumentos obj;
    int ultimoID = 0; // VARIABLE PARA ALMACENAR EL ÚLTIMO ID
    FILE *pIns;
    pIns=fopen(nombre, "rb");
    if(pIns==NULL){
        return -2;
    }
    // POSICIONAR EL PUNTERO AL FINAL DEL ARCHIVO
    fseek(pIns, 0, SEEK_END);
    // OBTENIENE LA POSICIÓN ACTUAL DEL PUNTERO
    long fileSize = ftell(pIns);
    // VERIFICAR SI EL TAMAÑO DEL ARCHIVO ES MAYOR O IGUAL AL TAMAÑO DE UN REGISTRO DE Instrumentos
    if (fileSize >= sizeof(Instrumentos)) {
        // RETROCEDER EL PUNTERO EN EL TAMAÑO DE UN REGISTRO DE Instrumentos DESDE EL FINAL DEL ARCHIVO
        fseek(pIns, -sizeof(Instrumentos), SEEK_END);
        // LEE EL ÚLTIMO REGISTRO DE Instrumentos DEL ARCHIVO
        fread(&obj, sizeof(Instrumentos), 1, pIns);
        // OBTENIENE EL ID DEL ÚLTIMO REGISTRO
        ultimoID = obj.getId();
    }
    fclose(pIns);
    // RETORNAR EL ÚLTIMO ID INCREMENTADO EN 1 PARA EL NUEVO REGISTRO
    return ultimoID + 1;
}
//////////////////////////////////////////////////////////
//////////////FUNCIONES PARA BUSCAR POR ID////////////////
//////////////////////////////////////////////////////////
Instrumentos ArchivoInstrumentos::leerInstrumentos(int p){
    Instrumentos obj;
    FILE *pIns;
    pIns=fopen(nombre, "rb");
    if(pIns==NULL){
        obj.setId(-2);
        return obj;
    }
    fseek(pIns, sizeof obj * p, 0); ///0: desde el principio, 1: desde la posicion actual, 2: desde el eof
    int aux=fread(&obj, sizeof obj, 1, pIns);
    fclose(pIns);
    //SI LA AUX ES IGUAL A CERO NO PUDO LEER ELEMENTOS DEL ARCHIVO
    // Y SETEA -1 AL ID
    if(aux==0){
        obj.setId(-1);
    }
    return obj;
}
int ArchivoInstrumentos::buscarID(int id){
    Instrumentos obj;
    int pos=0;
    FILE *pIns;
    pIns=fopen(nombre, "rb");
    if(pIns==NULL){// VERIFICA QUE LO PUEDA ABRIR SI NO ENVIA UN CODIGO DE ERROR
        return -2;
    }

    while(fread(&obj, sizeof obj, 1, pIns)==1){//MIENTRAS ALLA ARCHIVOS LO RECORRE
        if(obj.getId() == id){//SI COINCIDEN LOS DNI RETORNA LA POSICION
            fclose(pIns);
            return pos;
        }
        pos++;
	}
	fclose(pIns);
	return -1;
}
void ArchivoInstrumentos::buscarPorID(){
    Instrumentos obj;
    int ID;
    cout<<"LISTAR INSTRUMENTO POR ID"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"INGRESE EL ID A BUSCAR ";
    cin>>ID;
    int pos=buscarID(ID);
    obj=leerInstrumentos(pos);
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
void ArchivoInstrumentos::mostrarRegistros(){
    Instrumentos obj;
    FILE *pIns;
    pIns=fopen(nombre, "rb");
    if(pIns==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    string separador = "---------------";

    cout<<"INSTRUMENTOS CARGADOS"<<endl;
    cout << left << setw(15) << separador;
    cout << left << setw(15) << separador;
    cout << left << setw(15) << separador;
    cout << endl;

    string txtId = "ID";
    string txtNombre = "NOMBRE";
    string txtClasificacion = "CLASIFICACION";

    cout << left << setw(15) << txtId ;
    cout << left << setw(15) << txtNombre;
    cout << left << setw(15) << txtClasificacion;
    cout << endl;

    cout << left << setw(15) << separador;
    cout << left << setw(15) << separador;
    cout << left << setw(15) << separador;
    cout << endl;

	while(fread(&obj, sizeof obj, 1, pIns)==1){
        if(obj.getEstado()){
            obj.mostrar();
             cout<<endl;
        }
	}
	fclose(pIns);
}
//////////////////////////////////////////////////////////
//////////////////MODIFICAR ARCHIVO///////////////////////
//////////////////////////////////////////////////////////
bool ArchivoInstrumentos::modificarRegistro(Instrumentos obj, int pos){
    FILE *pIns;
    pIns = fopen(nombre, "rb+");
    fseek(pIns, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pIns);
    fclose(pIns);
    return aux;
}
bool ArchivoInstrumentos::modificarNombre(){
    ///SOLICITAR QUE REGISTRO SE QUIERE MODIFICAR
    Instrumentos obj;
    int id;
    cout<<"INGRESE EL ID DEL INSTRUMENTO A MODIFICAR: ";
    cin>>id;
    ///BUSCAR EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarID(id);
    if(pos==-1){
        cout<<"NO EXISTE INSTRUMENTO CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerInstrumentos(pos);
    if(obj.getEstado()==false){
        cout<<"EL INSTRUMENTO INGRESADO ESTA DADO DE BAJA"<<endl;
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
bool ArchivoInstrumentos::bajaLogica(){
    ///SOLICITAR QUE REGISTRO SE QUIERE DAR DE BAJA
    Instrumentos obj;
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
    obj = leerInstrumentos(pos);
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

#endif // ARCHIVOINSTRUMENTOS_H_INCLUDED
