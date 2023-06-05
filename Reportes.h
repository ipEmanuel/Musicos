#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

class Reportes{

    public:
        void bkpMusicos();
        void bkpGeneros();
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
void Reportes::restaurarMusicos(){
    const char* archivoMusicos = "musicos.dat";
    const char* archivoRespaldo = "musicos.bkp";
    Musicos obj;
    FILE* pMusi;
    FILE* pBkp;

    pMusi = fopen(archivoMusicos, "wb");
    if (pMusi == NULL) {
        cout << "Error: No se pudo crear el archivo " << archivoMusicos <<endl;
        return;
    }

    pBkp = fopen(archivoRespaldo, "rb");
    if (pBkp == NULL) {
        cout << "Error: No se pudo abrir el archivo " << archivoRespaldo << endl;
        fclose(pMusi);
        return;
    }

    while (fread(&obj, sizeof obj, 1, pBkp) == 1) {
        if (fwrite(&obj, sizeof obj, 1, pMusi) != 1) {
            cout << "Error: No se pudo escribir en el archivo de musicos " << archivoMusicos << endl;
            fclose(pBkp);
            fclose(pMusi);
            return;
        }
    }

    fclose(pMusi);
    fclose(pBkp);
    cout << "Archivo " << archivoMusicos << " restaurado correctamente." << endl;
}
void Reportes::restaurarGeneros(){
    const char* archivoGeneros = "generos.dat";
    const char* archivoRespaldo = "generos.bkp";
    Generos obj;
    FILE* pGen;
    FILE* pBkp;

    pGen = fopen(archivoGeneros, "wb");
    if (pGen == NULL) {
        cout << "Error: No se pudo crear el archivo " << archivoGeneros<<endl;
        return;
    }

    pBkp = fopen(archivoRespaldo, "rb");
    if (pBkp == NULL) {
        cout << "Error: No se pudo abrir el archivo " << archivoRespaldo << endl;
        fclose(pGen);
        return;
    }

    while (fread(&obj, sizeof obj, 1, pBkp) == 1) {
        if (fwrite(&obj, sizeof obj, 1, pGen) != 1) {
            cout << "Error: No se pudo escribir en el archivo de musicos " << archivoGeneros<< endl;
            fclose(pBkp);
            fclose(pGen);
            return;
        }
    }

    fclose(pGen);
    fclose(pBkp);
    cout << "Archivo " << archivoGeneros << " restaurado correctamente." << endl;
}
void Reportes::establecerDatosInicio(){





}
#endif // REPORTES_H_INCLUDED
