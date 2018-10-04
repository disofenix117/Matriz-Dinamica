/*
"Disofenix 117"
Diego Esteban Suarez C.
Universidad Militar Nueva Granada
2018
hola a todos

*/
//////////////////////////////////////////////////////////
//referencia: https://www.youtube.com/watch?v=i7cgXSfNhAQ
//////////////////////////////////////////////////////////
#include<iostream>
#include"clases.h"
using namespace std;
int main()
{
	Encadenamiento connect;
	int opcion, index = 1;

	do
	{
		cout << "----------------------------//----------------------------" << endl;
		cout << "\t\t. . : : M E N U : : . .\n" << endl;
		cout << " Eliga una opcion: " << endl;
		cout << " 1. crear matriz a mi gusto " << endl;
		cout << " 2. Dibujar rectangulo " << endl;
		cout << " 0. salir " << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			{
				connect.matriz();
				break;
			}
		case 2:
			system("cls");
			{
				connect.rectangulo();
				break;
			}
		case 3:
			system("cls");
			{
				connect.parabola();
				break;
			}
		case 4:
			system("cls");
			{
				connect.seno();
				break;
			}
		case 0:
		{
			index = 0;
			break;
		}
		}

	} while (index == 1);
	system(" ");
	return 0;

}