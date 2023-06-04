#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        ///constructor
        Fecha(){
        time_t t = time(nullptr);
        tm* fS = localtime(&t);
        dia = fS->tm_mday;
        mes = fS->tm_mon + 1;
        anio = fS->tm_year + 1900;

        }
        ///metodos
        bool FechaValida(int d, int m, int a);
        bool AnioBisiesto(int a);
        void Cargar();
        void Mostrar();

        ///sets
        void setDia(int x){dia=x;}
        void setMes(int x){mes=x;}
        void setAnio(int x){anio=x;}
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

};

bool Fecha::AnioBisiesto(int a){

if((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) return true;
else return false;

}

bool Fecha::FechaValida(int d, int m, int a){

    if (a < 0 || m < 1 || m > 12 || d < 1 || d > 31) {
            cout << "ERROR: FECHA INVALIDA" << endl;
            return false;
            system("pause");

        }
        else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
            cout << "ERROR: FECHA INVALIDA" << endl;
            return false;
            system("pause");

        }
        else if (m == 2 && AnioBisiesto(a) && d > 29) {
            cout << "ERROR: FECHA INVALIDA" << endl;
            return false;
            system("pause");

        }
        else if (m == 2 && !AnioBisiesto(a) && d > 28) {
            cout << "ERROR: FECHA INVALIDA" << endl;
            return false;
            system("pause");

        }
        else if (a > getAnio() ||  (a == getAnio() && m == getMes() && d > getDia() )) {//(a == getAnio() && m > getMes()) ||QUITE ESTAS CONDICION PARA PODER CARGAR LA FECHA DE LOS DATOS INICIALES DADOS POR LOS PROFESORES
            cout << "ERROR: FECHA INVALIDA" << endl;
            return false;
            system("pause");
        }
        else if(a < 1500){
            cout << "ERROR: FECHA INVALIDA - ANIO DEBE SER MAYOR O IGUAL QUE 1500" << endl;
            return false;
            system("pause");
        }else return true;
}

 void Fecha::Cargar(){

int d,m,a;
bool check=false;

   while(check==false){

    cout<<"DIA: ";
    cin>>d;
    cout<<"MES: ";
    cin>>m;
    cout<<"ANIO: ";
    cin>>a;
    check=FechaValida(d,m,a);
   }
    dia=d;
    mes=m;
    anio=a;
}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

#endif // FECHA_H_INCLUDED
