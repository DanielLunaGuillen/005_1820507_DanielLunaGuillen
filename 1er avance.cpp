#include<iostream>
#include<string.h>
#include<string>

using namespace std;
int main()
{
    int numart, adlanz, op;
    string nomvid, clasf, carct, descp, gnr;
    float preu, total;
    
    cout<<"\t *** MENU *** \n 1.-Agregar Articulo\n 2.-Modificar Articulo\n 3.-Eliminar Articulo\n 4.-Lista de Articulos Vigentes\n 5.-Limpiar pantalla\n 6.-Salir\n";
    cin>>op;
    switch(op)
    {
        case 1: //Agregar Articulo
        cout<<"Ingrese el numero de articulo: \n";
        cin>>numart;
        cout<<"Ingrese el nombre del videojuego: \n";
        cin.ignore();
        getline(cin,nomvid);
        cout<<"Ingrese el ano de lazamiento: \n";
        cin>>adlanz;
        cout<<"Ingrese la clasificacion: \n";
        cin.ignore();
        getline(cin,clasf);
        cout<<"Ingrese las caracteristicas: \n";
        cin.ignore();
        getline(cin,carct);
        cout<<"Ingrese una descripcion: \n";
        cin.ignore();
        getline(cin,descp);
        cout<<"Ingrese el genero: \n";
        cin.ignore();
        getline(cin,gnr);
        cout<<"Ingrese el precio unitario: \n";
        cin>>preu;
        total=preu+(preu*0.16);
        return main();
        break;
        
        case 2: //Modificar articulo
        break;
        
        case 3: //Eliminar articulo
        break;
        
        case 4: //Lista de Articulos
        break;
        
        case 5: //Limpiar pantalla
        system("cls");
        return main();
        break;
        
        case 6: //Salir 
        cout<<"Gracias por utilizar el programa \n";
        break;
        
        default:
        cout<<"Ingrese una opcion correcta \n";
        return main();
        
    }
}