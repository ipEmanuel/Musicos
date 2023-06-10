#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

//////////////////////////////////////////////////////////
///////////FUNCION QUE BUSCA UN INSTRUMENTOS//////////////
//////////////////////////////////////////////////////////
bool buscarInstrumento(int instrumento){
    Instrumentos reg;
    ArchivoInstrumentos archivoInstrumentos("instrumentos.dat");
    int cantReg = archivoInstrumentos.contarRegistro();

    for (int i = 0; i < cantReg; i++) {
        reg = archivoInstrumentos.leerInstrumentos(i);
        if (reg.getId() == instrumento) {
            return true;
        }
    }
    return false;
}

//////////////////////////////////////////////////////////
///////////////FUNCION QUE BUSCA UN PAIS//////////////////
//////////////////////////////////////////////////////////
bool buscarPais(int paisOrigen){
    Paises reg;
    ArchivoPaises archivoPaises("paises.dat");
    int cantReg = archivoPaises.contarRegistro();

    for (int i = 0; i < cantReg; i++) {
        reg = archivoPaises.leerPaises(i);
        if (reg.getId() == paisOrigen) {
            return true;
        }
    }
    return false;
}

#endif // FUNCIONESGLOBALES_H_INCLUDED
