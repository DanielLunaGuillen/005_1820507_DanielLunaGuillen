#include<iostream>
#include<conio.h>
#include<string.h>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>

using namespace std;

int* numart, * year, registros, n = 1;
string* nombre, * clasf, * caract, * descp, * gnr;
float* preu, * iva, * total;

void alta();
void modificar();
void eliminar();
void lista();
void archivo();

int main()
{
	setlocale(LC_ALL, "spanish");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	int op;

	printf("\t Black Clover GameStore \n");
	printf("1.-Agregar Articulo \n2.-Modificar Articulo \n3.-Eliminar Articulo \n4.-Lista de Articulos \n5.-Limpiar pantalla \n6.-Salir \n");
	scanf_s("%d", &op);

	switch (op)
	{
	case 1:
		alta();
		system("pause");
		return main();
		break;

	case 2:
		modificar();
		system("pause");
		return main();
		break;

	case 3:
		eliminar();
		system("pause");
		return main();
		break;

	case 4:
		lista();
		system("pause");
		return main();
		break;

	case 5:
		system("cls");
		system("pause");
		return main();
		break;

	case 6:
		archivo();
		exit(1);
		system("pause");
		break;

	default:
		printf("Opcion incorrecta \nIngrese una opcion valida");
		system("pause");
		return main();
		break;
	}
}

void alta()
{
	printf("Cuantos registros quiere dar de alta: \n");
	scanf_s("%d", &registros);
	if (registros > 0)
	{
		numart = new int[registros];
		year = new int[registros];
		nombre = new string[registros];
		clasf = new string[registros];
		caract = new string[registros];
		gnr = new string[registros];
		descp = new string[registros];
		preu = new float[registros];
		iva = new float[registros];
		total = new float[registros];

		for (int i = 0; i < registros; i++)
		{
			printf("Ingrese el numero articulo: \n");
			scanf_s("%d", &numart[i]);
			do
			{
				if (numart[i] != numart[i - n])
				{
					n = n + 1;
				}
				else
				{
					printf("Articulo ya existente \n");
					printf("Ingrese el numero articulo: \n");
					scanf_s("%d", numart[i]);
				}
			} while (n < registros);
			printf("Ingrese el año de lanzamiento: \n");
			scanf_s("%d", &year[i]);
			printf("Ingrese el nombre del videojuego: \n");
			cin.ignore();
			getline(cin, nombre[i]);
			printf("Ingrese la clasificacion: \n");
			getline(cin, clasf[i]);
			printf("Ingrese las caracteristicas: \n");
			getline(cin, caract[i]);
			printf("Ingrese el genero del videojuego: \n");
			getline(cin, gnr[i]);
			printf("Ingrese la descripcion: \n");
			getline(cin, descp[i]);
			printf("Ingrese el precio del videojuego: \n");
			scanf_s("%f", &preu[i]);
			iva[i] = preu[i] * .16;
			total[i] = preu[i] + iva[i];
			printf("**************************************************** \n\n");
			if (i == (registros - 1))
			{
				int desicion;
				printf("Desea agregar otro registro \n1.-Si    2.-No \n");
				scanf_s("%d", &desicion);
				if (desicion == 1)
				{
					registros = registros + 1;
				}
			}
		}
	}
	else
	{
		printf("El valor ingresado no es valido \nRegresando al menu principal.....\n");
	}
}

void modificar()
{
	int mod;
	
	printf("Ingrese el numero de articulo a modificar: \n");
	scanf_s("%d", &mod);
    if(mod > 0)
    {
        for (int i = 0; i < registros; i++)
		{
			if (mod == numart[i])
			{
				printf("Ingrese el año de lanzamiento: \n");
				scanf_s("%d", &year[i]);
				printf("Ingrese el nombre del videojuego: \n");
				cin.ignore();
				getline(cin, nombre[i]);
				printf("Ingrese la clasificacion: \n");
				getline(cin, clasf[i]);
				printf("Ingrese las caracteristicas: \n");
				getline(cin, caract[i]);
				printf("Ingrese el genero del videojuego: \n");
				getline(cin, gnr[i]);
				printf("Ingresde la descripcion: \n");
				getline(cin, descp[i]);
				printf("Ingrese el precio del videojuego: \n");
				scanf_s("%f", &preu[i]);
				iva[i] = preu[i] * .16;
				total[i] = preu[i] + iva[i];
			}
		}
    }
    else
    {
        printf("Opcion invalida \nRegresando al menu principal.... \n");
    }

}

void eliminar()
{
	int elm;
	printf("Ingrese el numero de articulo a eliminar: \n");
	scanf_s("%d", &elm);

	for (int i = 0; i < registros; i++)
	{
		if (elm == numart[i])
		{
			numart[i] = 0;
		}
	}

}

void lista()
{
	int op2=0;
	string busc;

	printf("Buscar por \n1.-Clasificacion \n2.-Genero \n3.-Ver todos \n4.-Salir \n");
	scanf_s("%d", &op2);
	
	switch (op2)
	{

		case 1:
			printf("Ingrese la clasificacion a buscar: \n");
			cin.ignore();
			getline(cin, busc);
			for (int i = 0; i < registros; i++)
			{
				if (clasf[i] == busc)
				{
					printf("Numero articulo: %d \n", numart[i]);
					printf("Año: %d \n", year[i]);
					printf("Nombre: %s \n", nombre[i].c_str());
					printf("Clasificacion: %s \n", clasf[i].c_str());
					printf("Genero: %s \n", gnr[i].c_str());
					printf("Caracteristicas: %s \n", caract[i].c_str());
					printf("Descripcion: %s \n", descp[i].c_str());
					printf("Precio: %f \n", preu[i]);
					printf("iva: %f \n", iva[i]);
					printf("Total: %f \n", total[i]);
				}
			}
			break;

		case 2:
			printf("Ingrese el genero a buscar: \n");
			cin.ignore();
			getline(cin, busc);
			for (int i = 0; i < registros; i++)
			{
				if (gnr[i] == busc)
				{
					printf("Numero articulo: %d \n", numart[i]);
					printf("Año: %d \n ", year[i]);
					printf("Nombre: %s \n", nombre[i].c_str());
					printf("Clasificacion: %s \n", clasf[i].c_str());
					printf("Genero: %s \n", gnr[i].c_str());
					printf("Caracteristicas: %s \n", caract[i].c_str());
					printf("Descripcion: %s \n", descp[i].c_str());
					printf("Precio: %f \n", preu[i]);
					printf("iva: %f \n", iva[i]);
					printf("Total: %f \n", total[i]);
				}
			}
			break;
			
		case 3:
		    for (int i = 0; i < registros; i++)
		    {
		        if (numart[i] != 0)
				{
					printf("Numero articulo: %d \n", numart[i]);
					printf("Año: %d \n ", year[i]);
					printf("Nombre: %s \n", nombre[i].c_str());
					printf("Clasificacion: %s \n", clasf[i].c_str());
					printf("Genero: %s \n", gnr[i].c_str());
					printf("Caracteristicas: %s \n", caract[i].c_str());
					printf("Descripcion: %s \n", descp[i].c_str());
					printf("Precio: %f \n", preu[i]);
					printf("iva: %f \n", iva[i]);
					printf("Total: %f \n", total[i]);
				}
		    }
			
		case 4:
		    printf("Regresando al menu principal.... \n");
		    system("pause");
		    break;

		default:
			printf("Opcion incorrecta \nIngrese una opcion valida \n");
			return lista();
			break;
	}
}

void archivo()
{
	ofstream archivo;
	string nomb;

	nomb = 'PIA';
		archivo.open(nomb.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("ERROR NO SE GENERO EL ARCHIVO \n");
		system("pause");
		exit(1);
	}

	archivo << "\t\t INFORMACION \n";
	for (int i = 0; i < registros; i++)
	{
		if (numart[i] != 0)
		{
			archivo << "REGISTO " << i + 1 << endl;
			archivo << "Numero articulo: " << numart[i] << endl;
			archivo << "Año: " << year[i] << endl;
			archivo << "Nombre: " << nombre[i].c_str() << endl;
			archivo << "Clasificacion: " << clasf[i].c_str() << endl;
			archivo << "Genero: " << gnr[i].c_str() << endl;
			archivo << "Caracteristicas: " << caract[i].c_str() << endl;
			archivo << "Descripcion: " << descp[i].c_str() << endl;
			archivo << "Precio: " << preu[i] << endl;
			archivo << "iva: " << iva[i] << endl;
			archivo << "Total: " << total[i] << endl;
		}
	}

	archivo.close();
}