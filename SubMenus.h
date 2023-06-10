#ifndef SUBMENUS_H_INCLUDED
#define SUBMENUS_H_INCLUDED

////////////////////////////////////
/////////SUBMENU MUSICOS////////////
////////////////////////////////////
const char *ARCHIVO_MUSICOS="musicos.dat";
const char *ARCHIVO_GENEROS="generos.dat";
const char *ARCHIVO_INSTRUMENTOS="instrumentos.dat";
const char *ARCHIVO_PAISES="paises.dat";
void menuMusicos(){

ArchivoMusicos objMusicos(ARCHIVO_MUSICOS);

int opc;
    while(true){
        system("cls");
        cout<<"MENU MUSICOS"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1 - AGREGAR MUSICOS"<<endl;
        cout<<"2 - LISTAR MUSICOS POR DNI"<<endl;
        cout<<"3 - MOSTRAR TODOS LOS MUSICOS"<<endl;
        cout<<"4 - MODIFICAR FECHA DE INSCRIPCION"<<endl;
        cout<<"5 - ELIMINAR REGISTRO DE INSCRIPCION"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: objMusicos.agregarRegistro();
            break;
            case 2: objMusicos.buscarPorDNI();
            break;
            case 3: objMusicos.mostrarRegistros();
            break;
            case 4: if(objMusicos.modificarInscripcion()){
                        cout<<"MUSICO MODIFICADO CORRECTAMENTE"<<endl;
                    }else{
                        cout<<"NO SE PUDO REALIZAR LA MODIFICACION"<<endl;
                    }
            break;
            case 5:if(objMusicos.bajaLogica()){
                      cout<<"MUSICO DADO DE BAJA CORRECTAMENTE"<<endl;
                    }else{
                      cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
                    }
            break;
            case 0:
                return;
            break;
        }
        cout<<endl;
        system("pause");
    }
}
void menuGeneros(){

    ArchivoGeneros objGeneros(ARCHIVO_GENEROS);
    int opc;
    while(true){
        system("cls");
        cout<<"MENU GENEROS"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1 - AGREGAR GENERO"<<endl;
        cout<<"2 - LISTAR GENERO POR ID"<<endl;
        cout<<"3 - LISTAR TODO"<<endl;
        cout<<"4 - MODIFICAR ANIO DE ORIGEN"<<endl;
        cout<<"5 - ELIMINAR REGISTRO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: objGeneros.agregarRegistro();
            break;
            case 2:objGeneros.buscarPorID();
            break;
            case 3:objGeneros.mostrarRegistros();
            break;
            case 4:if(objGeneros.modificarAnioOrigen()){
                       cout<<"ANIO MODIFICADO CORRECTAMENTE"<<endl;
                   }else{
                       cout<<"NO SE PUDO REALIZAR LA MODIFICACION"<<endl;
                   }
            break;
            case 5:if(objGeneros.bajaLogica()){
                      cout<<"GENERO DADO DE BAJA CORRECTAMENTE"<<endl;
                    }else{
                      cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
                    }
            break;
            case 0:
                return;
            break;
        }
        cout<<endl;
        system("pause");
    }
}
void menuInstrumentos(){

    ArchivoInstrumentos objInstrumentos(ARCHIVO_INSTRUMENTOS);
    int opc;
    while(true){
        system("cls");
        cout<<"MENU INSTRUMENTOS"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1 - AGREGAR INSTRUMENTO"<<endl;
        cout<<"2 - LISTAR INSTRUMENTO POR ID"<<endl;
        cout<<"3 - LISTAR TODO"<<endl;
        cout<<"4 - MODIFICAR NOMBRE"<<endl;
        cout<<"5 - ELIMINAR REGISTRO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: objInstrumentos.agregarRegistro();
            break;
            case 2:objInstrumentos.buscarPorID();
            break;
            case 3:objInstrumentos.mostrarRegistros();
            break;
            case 4:if(objInstrumentos.modificarNombre()){
                        cout<<"NOMBRE MODIFICADO CORRECTAMENTE"<<endl;
                    }else{
                        cout<<"NO SE PUDO REALIZAR LA MODIFICACION"<<endl;
                    }
            break;
            case 5:if(objInstrumentos.bajaLogica()){
                        cout<<"INSTRUMENTO DADO DE BAJA CORRECTAMENTE"<<endl;
                    }else{
                        cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
                    }
            break;
            case 0:
                return;
            break;
        }
        cout<<endl;
        system("pause");
    }
}
void menuPaises(){

    ArchivoPaises objPaises(ARCHIVO_PAISES);
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PAISES"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1 - AGREGAR PAIS"<<endl;
        cout<<"2 - LISTAR PAIS POR ID"<<endl;
        cout<<"3 - LISTAR TODO"<<endl;
        cout<<"4 - MODIFICAR NOMBRE"<<endl;
        cout<<"5 - ELIMINAR REGISTRO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: objPaises.agregarRegistro();
            break;
            case 2:objPaises.buscarPorID();
            break;
            case 3:objPaises.mostrarRegistros();
            break;
            case 4:if(objPaises.modificarNombre()){
                        cout<<"NOMBRE MODIFICADO CORRECTAMENTE"<<endl;
                    }else{
                        cout<<"NO SE PUDO REALIZAR LA MODIFICACION"<<endl;
                    }
            break;
            case 5:if(objPaises.bajaLogica()){
                        cout<<"PAIS DADO DE BAJA CORRECTAMENTE"<<endl;
                    }else{
                        cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
                    }
            break;
            case 0:
                return;
            break;
        }
        cout<<endl;
        system("pause");
    }
}
void menuReportes(){

    Reportes objReportes;
    int opc;
        while(true){
            system("cls");
            cout<<"MENU REPORTES"<<endl;
            cout<<"------------------------"<<endl;
            cout<<"1 - "<<endl;
            cout<<"2 - "<<endl;
            cout<<"3 - "<<endl;
            cout<<"4 - "<<endl;
            cout<<"5 - "<<endl;
            cout<<"6 - "<<endl;
            cout<<"7 - "<<endl;
            cout<<"8 - "<<endl;
            cout<<"0 - "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"INGRESE UNA OPCION: ";
            cin>>opc;
            system("cls");
            switch(opc){
                case 1: cout<<"1 - "<<endl;
                break;
                case 2: cout<<"1 - "<<endl;
                break;
                case 3: cout<<"1 - "<<endl;
                break;
                case 4: cout<<"1 - "<<endl;
                break;
                case 5: cout<<"1 - "<<endl;
                break;
                case 6: cout<<"1 - "<<endl;
                break;
                case 7: cout<<"1 - "<<endl;
                break;
                case 8: cout<<"1 - "<<endl;
                break;
                case 0:
                    return;
                break;
            }

            cout<<endl;
            system("pause");
        }
}
void menuConfiguracion(){
    Reportes objReportes;
    int opc;
    while(true){
        system("cls");
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1 - COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS"<<endl;
        cout<<"2 - COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS"<<endl;
        cout<<"3 - RESTAURAR EL ARCHIVO DE MUSICOS"<<endl;
        cout<<"4 - RESTAURAR EL ARCHIVO DE GENEROS"<<endl;
        cout<<"5 - ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:objReportes.bkpMusicos();
            break;
            case 2:objReportes.bkpGeneros();
            break;
            case 3:objReportes.restaurarMusicos();
            break;
            case 4:objReportes.restaurarGeneros();
            break;
            case 5:objReportes.establecerDatosInicio();
            break;
            case 0:
                return;
            break;
        }
        cout<<endl;
        system("pause");
    }
}

#endif // SUBMENUS_H_INCLUDED
