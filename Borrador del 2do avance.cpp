#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>

using namespace std;

struct empresa
{
    int numart, adlanz;
    string nomvid, clasf, carct, descp, gnr;
    float preu, iva, total;

};

int main()
{
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int i, opcion, busqueda, op2;
    empresa compras[3];
    do
    {
        printf("\t ***MENU DE OPCIONES*** \n");
        printf(" 1.-Agregar Articulo \n 2.-Modificar Articulo \n 3.-Eliminar Articulo \n 4.-Lista de Articulos Vigentes \n 5.-Limpiar Pantalla \n 6.-Salir \n");
        scanf_s("%d", &opcion);

        switch (opcion)
        {
        case 1: //AGREGAR ARTICULO
            for (i = 0; i < 3; i++)
            {
                int op3 = 1;
                do
                {
                    printf("Ingrese el numero del articulo: \n");
                    scanf_s("%d", &compras[i].numart);
                    if (compras[i].numart == compras[i - 1].numart || compras[i].numart == compras[i - 2].numart)
                    {
                        printf("El numero de articulo se encuentra vigente en otro recibo \nIngrese nuevo un numero de articulo \n");
                    }
                    else
                    {
                        op3 = 2;
                    }
                } while (op3 == 1);
                printf("Ingrese el nombre del videojuego: \n");
                cin.ignore();
                getline(cin, compras[i].nomvid);
                printf("Ingrese el año de lanzamiento: \n");
                scanf_s("%d", &compras[i].adlanz);
                printf("Ingrese la clasificacion del videojuego: \n");
                cin.ignore();
                getline(cin, compras[i].clasf);
                printf("Ingrese las caracteristicas del videojuego: \n");
                cin.ignore();
                getline(cin, compras[i].carct);
                printf("Ingrese una descripcion del videojuego: \n");
                cin.ignore();
                getline(cin, compras[i].descp);
                printf("Ingrese el genero del videojuego: \n");
                cin.ignore();
                getline(cin, compras[i].gnr);
                printf("Ingrese el precio unitario del videojuego: \n");
                scanf_s("%f", &compras[i].preu);
                compras[i].iva = compras[i].preu * .16;
                compras[i].total = compras[i].preu * 1.16;
            }
            break;

        case 2: //MODIFICAR ARTICULO
            printf("Modificar articulo XD \n");
            break;

        case 3: //ELIMINAR ARTICULO
            printf("ingrese su numero de articulo \n");
            scanf_s("%d", &busqueda);
            for (int i = 0; i < 3; i++)
            {
                if (busqueda == compras[i].numart)
                {
                    compras[i].numart = 0;
                    printf("su regitro ah sido eliminado \n");
                    system("pause");
                }
            }
            break;

        case 4: //LISTA DE ARTICULOS
            printf("1.- Buscar articulo \n2.-Ver todos los articulos \n3.-Salir al menu principal \n");
            scanf_s("%d", &op2);
            switch (op2)
            {
                do
                {
            case 1:
                printf("ingrese el numero del articulo: \n");
                scanf_s("%d", &busqueda);
                for (i = 0; i < 3; i++)
                {
                    if (compras[i].numart != 0)
                    {
                        if (busqueda == compras[i].numart)
                        {
                            printf("El numero de articulo es: %d \n", compras[i].numart);
                            printf("El nombre del videojuego es: %s \n", compras[i].nomvid.c_str());
                            printf("El año de lanzamiento es: %d \n", compras[i].adlanz);
                            printf("La clasificaion del videojuego es: %s \n", compras[i].clasf.c_str());
                            printf("Las caracteristicas del videojuego son: %s \n", compras[i].carct.c_str());
                            printf("La descipcion del videojuego es: %s \n", compras[i].descp.c_str());
                            printf("La genero del videojuego es: %s \n", compras[i].gnr.c_str());
                            printf("El precio unitario es: %.2f \n", compras[i].preu);
                            printf("el iva es %.2f \n", compras[i].iva);
                            printf("el total es %.2f \n", compras[i].total);
                        }
                    }
                }
                break;

            case 2:
                for (i = 0; i < 3; i++)
                {
                    printf("El numero de articulo es: %d \n", compras[i].numart);
                    printf("El nombre del videojuego es: %s \n", compras[i].nomvid.c_str());
                    printf("El año de lanzamiento es: %d \n", compras[i].adlanz);
                    printf("La clasificaion del videojuego es: %s \n", compras[i].clasf.c_str());
                    printf("Las caracteristicas del videojuego son: %s \n", compras[i].carct.c_str());
                    printf("La descipcion del videojuego es: %s \n", compras[i].descp.c_str());
                    printf("La genero del videojuego es: %s \n", compras[i].gnr.c_str());
                    printf("El precio unitario es: %.2f \n", compras[i].preu);
                    printf("el iva es %.2f \n", compras[i].iva);
                    printf("el total es %.2f \n", compras[i].total);
                }
                break;

            case 3:
                printf("Regresara al menu principal \n");
                system("pause");
                break;

            default:
                printf("Opcion invalida \nIngrese una opcion correcta \n");
                break;
                } while (op2 != 3);
            }
            break;

        case 5: //LIMPIAR PANTALLA
            system("cls");
            break;

        case 6: //SALIR
            printf("Gracias utilizar el programa \n");
            break;

        default:
            printf("Opcion invalida \nIngrese una opcion correcta \n");
            break;
        }
    } while (opcion != 6);
    system("pause");
}