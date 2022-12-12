/*
 ============================================================================
 Name        : RecuExamen.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

	int id;
	char Marca[20];
	char tipo[20];
	float Precio;

}eBicicleta;

#define IIBB 3.5


int calcularIIBB(float Totalfactura,float* Impuesto);
int quitarVocales(char cadena[]);
int Ordenar(eBicicleta lista[],int longitud);

int main(void) {

	setbuf(stdout,NULL);

	eBicicleta Array[5] = {{1, "asdf", "bmx", 10000},{2, "qwda", "bmx", 100},{3, "gsrf", "sd", 1000},{4, "wet", "rt", 2000},{5, "fga", "b", 24567}};

	float Factura=500;
	char cadena[20]="Cadena";

	float Impuesto;

	calcularIIBB(Factura, &Impuesto);

	printf("%.2f\n",Impuesto);

	quitarVocales(cadena);

	printf("%s\n",cadena);

	Ordenar(Array, 5);


	return EXIT_SUCCESS;
}


int calcularIIBB(float Totalfactura,float* Impuesto)
{
	int rtn=0;

	if(Impuesto!=NULL && Totalfactura>0)
	{
		*Impuesto=Totalfactura*IIBB/100;
		rtn=1;
	}

	return rtn;
}

int quitarVocales(char cadena[])
{
	int rtn=0;

	if(cadena!=NULL)
	{
		for(int i=0;cadena!='\0';i++)
		{
			if((cadena[i]=='a' || cadena[i]=='e' || cadena[i]=='i' || cadena[i]=='o' || cadena[i]=='u') ||
					(cadena[i]=='A' || cadena[i]=='E' || cadena[i]=='I' || cadena[i]=='O' || cadena[i]=='U'))
			{
				cadena[i]=' ';
				rtn=1;
			}
		}
	}

	return rtn;
}


int Ordenar(eBicicleta lista[],int longitud)
{
	int rtn=0;
	eBicicleta Aux;

		if(lista!=NULL && longitud>0)
		{
			for(int i=0;i<longitud-1;i++)
			{
				for(int j=i+1;j<longitud;j++)
				{
					if(strcmp(lista[i].Marca,lista[j].Marca)<0 || (strcmp(lista[i].Marca,lista[j].Marca)==0 && lista[i].Precio > lista[j].Precio))
					{
						Aux=lista[i];
						lista[i]=lista[j];
						lista[j]=Aux;
					}
				}
			}

			rtn=1;
			printf("Ordenamiento Exitoso\n");
		}

	return rtn;
}
