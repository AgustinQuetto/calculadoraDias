#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

int esBisiesto(int anio);

int main(void)
{
    int diasAnioTotales[]={00,31,59,90,120,151,181,212,243,273,304,334,365}; //suma meses completos
    int diasTotales=0, difAnio=0, i;
    Fecha fechaOrigen={25,7,1995}, fechaFin={12,6,2017};

/*
    printf("Ingrese su anio de nacimiento: ");
    fflush(stdin);
    scanf(&fechaOrigen.anio);

    printf("Ingrese su mes de nacimiento: ");
    fflush(stdin);
    scanf(&fechaOrigen.mes);

    printf("Ingrese su dia de nacimiento: ");
    fflush(stdin);
    scanf(&fechaOrigen.dia);
*/

    int origAnioTot = fechaOrigen.dia + diasAnioTotales[fechaOrigen.mes-1]; //Dia de origen + la suma de los meses anteriores al mes correspondientes.
    int finAnioTot = fechaFin.dia + diasAnioTotales[fechaFin.mes-1];//Dia de fin + la suma de los meses anteriores al mes correspondientes.

    difAnio = fechaFin.anio - fechaOrigen.anio;

    if(difAnio != 0)
    {
        diasTotales += 365 - origAnioTot;
        if( fechaOrigen.mes < 3) //comprueba si debe sumar 1 por ser bisiesto y pasar por febrero
        {
            diasTotales += esBisiesto(fechaOrigen.anio);
        }

        for(i= fechaOrigen.anio +1; i< fechaFin.anio; i++)
        {
            diasTotales += 365 + esBisiesto(i);
        }

        diasTotales += finAnioTot;
        if( fechaFin.mes > 2)
        {
            diasTotales += esBisiesto(fechaFin.anio);
        }
    }
    else
    {
        diasTotales += finAnioTot - origAnioTot;
        if( fechaOrigen.mes <= 2 && fechaFin.mes > 2)//comprueba si debe sumar 1 por ser bisiesto y pasar por febrero
        {
            diasTotales += esBisiesto(fechaOrigen.anio);
        }
    }
    printf("\nFecha origen: %d/%d/%d\nFecha final: %d/%d/%d\nDias: %d\n", fechaOrigen.dia, fechaOrigen.mes, fechaOrigen.anio,
           fechaFin.dia, fechaFin.mes, fechaFin.anio, diasTotales);
    return 0;
}

//comprueba si el anio es bisiesto
int esBisiesto(int anio)
{
    if((anio%400) == 0 || (anio %4 == 0 && anio%100 != 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
