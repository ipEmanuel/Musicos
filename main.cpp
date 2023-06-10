#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Fecha.h"
#include "Persona.h"
#include "Instrumentos.h"
#include "ArchivoInstrumentos.h"
#include "Paises.h"
#include "ArchivoPaises.h"
#include "FuncionesGlobales.h"
#include "Musicos.h"
#include "ArchivoMusicos.h"
#include "Generos.h"
#include "ArchivoGeneros.h"
#include "Reportes.h"
#include "SubMenus.h"

void cargarCadena(char *pal,int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

int main()
{
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1 - MENU MUSICOS"<<endl;
        cout<<"2 - MENU GENEROS"<<endl;
        cout<<"3 - MENU INSTRUMENTOS"<<endl;
        cout<<"4 - MENU PAISES"<<endl;
        cout<<"5 - REPORTES"<<endl;
        cout<<"6 - CONFIGURACION"<<endl;
        cout<<"0 - SALIR DEL PROGRAMA"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: menuMusicos();
            break;
            case 2: menuGeneros();
            break;
            case 3: menuInstrumentos();
            break;
            case 4: menuPaises();
            break;
            case 5: menuReportes();
            break;
            case 6: menuConfiguracion();
            break;
            case 0:
                return 0;
            break;
        }
        cout<<endl;
        system("pause");
    }
    return 0;
}
