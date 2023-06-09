#ifndef ARCHIVOGENEROS_H_INCLUDED
#define ARCHIVOGENEROS_H_INCLUDED

class ArchivoGeneros{
    private:
        char nombre[30];

    public:
        ArchivoGeneros(const char *n){
            strcpy(nombre, n);
        }

        ///ALTA
        void agregarRegistro();

        ///ID
        int ultimoID();
        Generos leerGeneros(int p);
        int buscarID(int id);
        void buscarPorID();

        //MOSTRAR
        void mostrarRegistros();

        //MODIFICAR
        bool modificarAnioOrigen();
        bool modificarRegistro(Generos obj, int p);
        //BAJA
        bool bajaLogica();


};

//////////////////////////////////////////////////////////
///////////////////CARGA EL ARCHIVO///////////////////////
//////////////////////////////////////////////////////////
void ArchivoGeneros::agregarRegistro(){
    Generos obj;
    FILE *pGen;
    pGen=fopen(nombre, "ab");
    if(pGen==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    cout<<"CARGA DE GENEROS"<<endl;
    cout<<"----------------"<<endl;
    int anioOrigen;
    cout<<"INGRESAR ANIO DE ORIGEN: ";
    cin>>anioOrigen;
    if(anioOrigen<1500){
        cout<<"EL ANIO DEBE SER MAYOR A 1500"<<endl;
        fclose(pGen);
        return;
    }
    int paisOrigen;
    cout<<"INGRESAR PAIS DE ORIGEN: ";
    cin>>paisOrigen;

    if(paisOrigen>0 && paisOrigen<=100){
        if(buscarPais(paisOrigen) == true){
            obj.Cargar(anioOrigen, ultimoID(), paisOrigen);
            fwrite(&obj, sizeof (Generos), 1, pGen);
            fclose(pGen);
            return;
        }else{
            cout<<"El PAIS NO CONICIDE CON NINGUN PAIS EXISTENTE"<<endl;
            fclose(pGen);
            return;
        }
    }else{
        cout<<"EL PAIS DE ORIGEN DEBE SER UN VALOR ENTRE 0 Y 100"<<endl;
        fclose(pGen);
        return;
    }
}
//////////////////////////////////////////////////////////
////////////////////////ULTIMO ID/////////////////////////
//////////////////////////////////////////////////////////
int ArchivoGeneros::ultimoID(){
    Generos obj;
    int ultimoID = 0; // VARIABLE PARA ALMACENAR EL �LTIMO ID
    FILE *pGen;
    pGen=fopen(nombre, "rb");
    if(pGen==NULL){
        return -2;
    }
    // POSICIONAR EL PUNTERO AL FINAL DEL ARCHIVO
    fseek(pGen, 0, SEEK_END);
    // OBTENIENE LA POSICI�N ACTUAL DEL PUNTERO
    long fileSize = ftell(pGen);
    // VERIFICAR SI EL TAMA�O DEL ARCHIVO ES MAYOR O IGUAL AL TAMA�O DE UN REGISTRO DE Generos
    if (fileSize >= sizeof(Generos)) {
        // RETROCEDER EL PUNTERO EN EL TAMA�O DE UN REGISTRO DE Generos DESDE EL FINAL DEL ARCHIVO
        fseek(pGen, -sizeof(Generos), SEEK_END);
        // LEE EL �LTIMO REGISTRO DE Generos DEL ARCHIVO
        fread(&obj, sizeof(Generos), 1, pGen);
        // OBTENIENE EL ID DEL �LTIMO REGISTRO
        ultimoID = obj.getId();
    }
    fclose(pGen);
    // RETORNAR EL �LTIMO ID INCREMENTADO EN 1 PARA EL NUEVO REGISTRO
    return ultimoID + 1;
}
/////////////////////////////////////////////////////////
//////////////FUNCIONES PARA BUSCAR POR ID////////////////
//////////////////////////////////////////////////////////
Generos ArchivoGeneros::leerGeneros(int p){
    Generos obj;

    FILE *pGen;
    pGen=fopen(nombre, "rb");
    if(pGen==NULL){
        obj.setId(-2);
        return obj;
    }
    fseek(pGen, sizeof obj * p, 0); ///0: desde el principio, 1: desde la posicion actual, 2: desde el eof
    int aux=fread(&obj, sizeof obj, 1, pGen);
    fclose(pGen);
    if(aux==0){
        obj.setId(-1);
    }
    return obj;
}
int ArchivoGeneros::buscarID(int id){
    Generos obj;
    int pos=0;
    FILE *pGen;
    pGen=fopen(nombre, "rb");
    if(pGen==NULL){// VERIFICA QUE LO PUEDA ABRIR SI NO ENVIA UN CODIGO DE ERROR
        return -2;
    }

    while(fread(&obj, sizeof obj, 1, pGen)==1){//MIENTRAS ALLA ARCHIVOS LO RECORRE
        if(obj.getId() == id){//SI COINCIDEN LOS DNI RETORNA LA POSICION
            fclose(pGen);
            return pos;
        }
        pos++;
	}
	fclose(pGen);
	return -1;
}
void ArchivoGeneros::buscarPorID(){
    Generos obj;
    int ID;
    cout<<"LISTAR GENERO POR ID"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"INGRESE EL ID A BUSCAR ";
    cin>>ID;
    int pos=buscarID(ID);
    obj=leerGeneros(pos);
    if(obj.getId()>0){
        obj.Mostrar();
    }else if(obj.getId()<=0){
        cout<<"EL ID NO EXISTE EN EL ARCHIVO"<<endl;
    }else{
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
}
//////////////////////////////////////////////////////////
///////////////////MOSTRAR ARCHIVO////////////////////////
//////////////////////////////////////////////////////////
void ArchivoGeneros::mostrarRegistros(){
    Generos obj;
    FILE *pGen;
    pGen=fopen(nombre, "rb");
    if(pGen==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    cout<<"GENEROS CARGADOS"<<endl;
    cout<<"----------------"<<endl;



    string separador = "---------------";

    cout<<"INSTRUMENTOS CARGADOS"<<endl;
    cout << left << setw(15) << separador;
    cout << left << setw(15) << separador;
    cout << left << setw(15) << separador;
    cout << left << setw(15) << separador;
    cout << endl;

    string txtId = "ID";
    string txtNombre = "NOMBRE";
    string txtPaisOrigen = "PAIS DE ORIGEN";
    string txtAnioOrigen = "ANIO DE ORIGEN ";
    cout << left << setw(15) << txtId ;
    cout << left << setw(15) << txtNombre;
    cout << left << setw(15) << txtPaisOrigen;
    cout << left << setw(15) << txtAnioOrigen;
    cout << endl;

    cout << left << setw(15) << separador;
    cout << left << setw(15) << separador;
    cout << left << setw(15) << separador;
    cout << left << setw(15) << separador;
    cout << endl;

	while(fread(&obj, sizeof obj, 1, pGen)==1){
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
	}
	fclose(pGen);
}
/////////////////////////////////////////////////////////
//////////////////MODIFICAR ARCHIVO///////////////////////
//////////////////////////////////////////////////////////
bool ArchivoGeneros::modificarRegistro(Generos obj, int pos){
    FILE *pGen;
    pGen = fopen(nombre, "rb+");
    fseek(pGen, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pGen);
    fclose(pGen);
    return aux;
}
bool ArchivoGeneros::modificarAnioOrigen(){
    ///SOLICITAR QUE REGISTRO SE QUIERE MODIFICAR EL MAIL
    Generos obj;
    int id;
    cout<<"INGRESE EL DNI DEL CLIENTE A MODIFICAR: ";
    cin>>id;
    ///BUSCAR EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarID(id);
    if(pos==-1){
        cout<<"NO EXISTE CLIENTE CON ESE DNI"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerGeneros(pos);
    if(obj.getEstado()==false){
        cout<<"EL CLIENTE INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    ///MODIFICAMOS EL CAMPO EMAIL
    int nuevoAnioOrigen;
    cout<<"INGRESE EL NUEVO ANIO DE ORIGEN"<<endl;
    cin>>nuevoAnioOrigen;
    obj.setAnioOrigen(nuevoAnioOrigen);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
    bool aux = modificarRegistro(obj, pos);
    return aux;
}
///////////////////////////////////////////////////////////
//////////////////////////BAJA/////////////////////////////
///////////////////////////////////////////////////////////
bool ArchivoGeneros::bajaLogica(){
    ///SOLICITAR QUE REGISTRO SE QUIERE DAR DE BAJA
    Generos obj;
    int id;
    cout<<"INGRESE EL DNI A DAR DE BAJA: ";
    cin>>id;
    ///BUSCAR EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarID(id);
    if(pos==-1){
        cout<<"NO EXISTEN MUSICOS CON ESE DNI"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerGeneros(pos);
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

#endif // ARCHIVOGENEROS_H_INCLUDED
