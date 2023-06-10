#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

class Reportes{

    public:
        void bkpMusicos();
        void bkpGeneros();
        void restaurarArchivo(const char* archivoDestino, const char* archivoRespaldo, const char* tipoArchivo);
        void restaurarMusicos();
        void restaurarGeneros();
        void establecerDatosInicio();
};

//////METODOS PARA EL MENU REPORTES//////



///METODOS PARA EL MENU CONFIGURACION///
void Reportes::bkpMusicos() {
    const char* archivoMusicos = "musicos.dat";
    const char* archivoRespaldo = "musicos.bkp";
    Musicos obj;
    FILE* pMusi = nullptr;
    FILE* pBkp = nullptr;

    pBkp = fopen(archivoRespaldo, "wb");
    if (pBkp == nullptr) {
        std::cout << "Error: No se pudo crear el archivo " << archivoRespaldo << std::endl;
        return;
    }

    pMusi = fopen(archivoMusicos, "rb");
    if (pMusi == nullptr) {
        std::cout << "Error: No se pudo abrir el archivo " << archivoMusicos << std::endl;
        fclose(pBkp);
        return;
    }

    while (fread(&obj, sizeof obj, 1, pMusi) == 1) {
        if (fwrite(&obj, sizeof obj, 1, pBkp) != 1) {
            std::cout << "Error: No se pudo escribir en el archivo de respaldo " << archivoRespaldo << std::endl;
            fclose(pBkp);
            fclose(pMusi);
            return;
        }
    }

    fclose(pBkp);
    fclose(pMusi);
}
void Reportes::bkpGeneros() {
    const char* archivoGeneros = "generos.dat";
    const char* archivoRespaldo = "generos.bkp";
    Generos obj;
    FILE *pGen;
    FILE *pBkp;

    pBkp = fopen(archivoRespaldo, "wb");
    if (pBkp == NULL) {
        cout << "Error: No se pudo crear el archivo " << archivoRespaldo <<endl;
        return;
    }

    pGen = fopen(archivoGeneros, "rb");
    if (pGen == NULL) {
        cout << "Error: No se pudo abrir el archivo " << archivoGeneros << endl;
        fclose(pBkp);
        return;
    }

    while (fread(&obj, sizeof obj, 1, pGen) == 1) {
        if (fwrite(&obj, sizeof obj, 1, pBkp) != 1) {
            cout << "Error: No se pudo escribir en el archivo de respaldo " << archivoRespaldo << endl;
            fclose(pBkp);
            fclose(pGen);
            return;
        }
    }

    fclose(pGen);
    fclose(pBkp);
}
void Reportes::restaurarArchivo(const char* archivoDestino, const char* archivoRespaldo, const char* tipoArchivo) {
    FILE* pDestino;
    FILE* pRespaldo;
    void* obj;
    size_t sizeObj;

    pDestino = fopen(archivoDestino, "wb");
    if (pDestino == NULL) {
        cout << "Error: No se pudo crear el archivo " << archivoDestino << endl;
        return;
    }

    pRespaldo = fopen(archivoRespaldo, "rb");
    if (pRespaldo == NULL) {
        cout << "Error: No se pudo abrir el archivo " << archivoRespaldo << endl;
        fclose(pDestino);
        return;
    }

    if (strcmp(tipoArchivo, "musicos") == 0) {
        obj = new Musicos;
        sizeObj = sizeof(Musicos);
    }
    else if (strcmp(tipoArchivo, "generos") == 0) {
        obj = new Generos;
        sizeObj = sizeof(Generos);
    }

    while (fread(obj, sizeObj, 1, pRespaldo) == 1) {
        if (fwrite(obj, sizeObj, 1, pDestino) != 1) {
            cout << "Error: No se pudo escribir en el archivo " << archivoDestino << endl;
            fclose(pRespaldo);
            fclose(pDestino);
            delete obj;
            return;
        }
    }

    fclose(pDestino);
    fclose(pRespaldo);
    delete obj;
    cout << "Archivo " << archivoDestino << " restaurado correctamente." << endl;
}
void Reportes::restaurarMusicos() {
    const char* archivoMusicos = "musicos.dat";
    const char* archivoRespaldo = "musicos.bkp";
    restaurarArchivo(archivoMusicos, archivoRespaldo, "musicos");
}
void Reportes::restaurarGeneros() {
    const char* archivoGeneros = "generos.dat";
    const char* archivoRespaldo = "generos.bkp";
    restaurarArchivo(archivoGeneros, archivoRespaldo, "generos");
}
void Reportes::establecerDatosInicio() {
    const char* archivoMusicos = "musicos.dat";
    const char* archivoRespaldoM = "datosInicioMusicos.dat";
    restaurarArchivo(archivoMusicos, archivoRespaldoM, "musicos");

    const char* archivoGeneros = "generos.dat";
    const char* archivoRespaldo = "datosInicioGeneros.dat";
    restaurarArchivo(archivoGeneros, archivoRespaldo, "generos");
}

#endif // REPORTES_H_INCLUDED
