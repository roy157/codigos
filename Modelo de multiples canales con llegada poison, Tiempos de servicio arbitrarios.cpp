/*
M/G/K
Modelo de multiples canales con llegada poison, Tiempos de servicio arbitrarios
y sin linea de espera
*/

#define canaless 100 
// PARA CALCULAR EL FACTORIAL DE FORMA RECURSIVA
int factorial(int i){
if (i == 0){
    return 1;
}
else{
    return i*factorial(i-1);
}
}

void ocupados(float tasa_llegada, float tasa_servicio, int numk, float canales_ocupados[])
{
    float sum=0;
    for (int i=0; i<=numk; i++){
        sum=sum+(pow(tasa_llegada/tasa_servicio,i)/factorial(i));
    } 
    for(int j=0; j<= numk; j++){
        canales_ocupados[j]=(pow(tasa_llegada/tasa_servicio,j)/factorial(j))/sum;
    }

    cout<< "\n------------------------- ------------------\n";
    cout<< "Numero de lineas Ocupadas| Probabilidad  ";
    for (int i = 0; i <= numk; i++)
    {
        cout<<endl;
        cout<<"\t   "<<i;
        cout<<"\t\t    "<<canales_ocupados[i]<<endl;
    }
    cout << "------------------------- ------------------\n";
}

/*
int main(){
    system("cls");
    float tasa_llegadas = 0, tasa_servicios = 0, canales_ocupados[canaless],promedio_sistema, sumatoria, factorial;
    int cantidad_canales = 0;
    cout<<"\nIngrese tasa de llegadas (lambda): ";
    cin>>tasa_llegadas;
    cout<<"\nIngrese tasa de de servicios (u): ";
    cin>>tasa_servicios;
    cout<<"\nIngrese numero de canales: ";
    cin>>cantidad_canales;
    ocupados(tasa_llegadas, tasa_servicios, cantidad_canales, canales_ocupados);
    cout<< endl;
    promedio_sistema=(tasa_llegadas/tasa_servicios)*(1-canales_ocupados[cantidad_canales]);
    cout<<"\n---------------------------------------------\n";
    cout<<"Numero promedio de unidades en el sistema";
    cout<<"\n---------------------------------------------\n";
    cout<<"\t\t"<<promedio_sistema;
    cout<<endl;
    cout <<endl<< endl;
    system("pause");
}
*/
