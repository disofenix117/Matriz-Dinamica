/*
"Disofenix 117"
Diego Esteban Suarez C.
Universidad Militar Nueva Granada
2018
*/
#include<iostream>
#include <fstream> //para genrerar archivos
#include"clases.h"

using namespace std;

void Encadenamiento::matriz()
{
	//definiendo valores
	
	int **matriz;
	int f, c;
	cout << "ingrese cantidad de filas" << endl;
	cin >> f;
	cout << " ingrese cantidad de columnas" << endl;
	cin >> c;

	//reservando memoria para matriz
	matriz = new int*[f];//para filas
	for (int i = 0; i < f; i++)
	{
		matriz[i] = new int[c];//para columnas
	}

	//rellenando matriz de 0 y 1
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < c; j++)
		{
			*(*(matriz + i) + j) = rand() % 2; //rellenando [i][j]
		}
	}

	//mostrar matriz
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << *(*(matriz + i) + j);
			cout << " ";
		}
		cout << "\n";
	}

	//liberar memoria 
	for (int i = 0; i < f; i++) //columnas
	{
		delete[] matriz[i];
	}
	delete matriz;//filas

	//version noob
	/*
	// creacion de la matriz
	int arr[500][500];
	// creacion de variables del tamaño de la matriz
	int fila, columna;
	cout << "ingrese cantidad de filas" << endl;
	cin >> fila;
	cout << " ingrese cantidad de columnas" << endl;
	cin >> columna;
	// llenar matriz
	for (int i = 0; i < fila; i++) {
	for (int j = 0; j < columna; j++) {
	arr[i][j] = rand() % 2;
	}
	}

	// mostrar matriz

	for (int i = 0; i < fila; i++) {
	for (int j = 0; j < columna; j++) {
	cout << arr[i][j];
	}
	cout << endl;
	}*/
}

void Encadenamiento::rectangulo()
{
	//definiendo valores

	int **matriz;
	int f, c, opc1, opc2;
	cout << "ingrese cantidad de filas" << endl;
	cin >> f;
	cout << " ingrese cantidad de columnas" << endl;
	cin >> c;
	//crear(f, c);

	//reservando memoria para matriz
	matriz = new int*[f];//para filas
	for (int i = 0; i < f; i++)
	{
		matriz[i] = new int[c];//para columnas
	}

	// pidiendo punto inicial y final
		int coordX1, coordX2, coordY1, coordY2;
		cout << "ingrese La coordenada X inicial" << endl;
		cin >> coordX1;
		cout << " ingrese la coordenada Y inicial" << endl;
		cin >> coordY1;
		cout << " ingrese la coordenada X final" << endl;
		cin >> coordX2;
		cout << " ingrese la coordenada Y final" << endl;
		cin >> coordY2;
		//confirmacion 1
		if (coordX1 > f || coordY1 > c || coordX2 > f || coordY2 > c)
		{
			do
			{
				cout << "E R R O R P3ND3J0 :Las coordenadas estan por fuera de la matriz dada.\n";
				cout << "ingrese La coordenada X inicial" << endl;
				cin >> coordX1;
				cout << " ingrese la coordenada Y inicial" << endl;
				cin >> coordY1;
				cout << " ingrese la coordenada X final" << endl;
				cin >> coordX2;
				cout << " ingrese la coordenada Y final" << endl;
				cin >> coordY2;
			} while (coordX1 > f || coordY1 > c || coordX2 > f || coordY2 > c);
		}
		//confirmacion 2
		if (coordX1 > coordX2 || coordY1 > coordY2)
		{
			do
			{
				cout << "E R R O R P3ND3J0 :Las coordenadas estan mal ubicadas.\n";
				cout << "ingrese La coordenada X inicial" << endl;
				cin >> coordX1;
				cout << " ingrese la coordenada Y inicial" << endl;
				cin >> coordY1;
				cout << " ingrese la coordenada X final" << endl;
				cin >> coordX2;
				cout << " ingrese la coordenada Y final" << endl;
				cin >> coordY2;
			} while (coordX1 > coordX2 || coordY1 > coordY2);
		}
		//arreglando los valores :V
		coordX1 = coordX1 - 1; coordX2 = coordX2 - 1; coordY1 = coordY1 - 1; coordY2 = coordY2 - 1;

		//relleno con 1
		while (coordX1 < coordX2 && coordY1 < coordY2)
		{
			for (int i = coordX1; i < coordX2; i++)
			{
				for (int j = coordY1; j < coordY2; j++)
				{
					*(*(matriz + i) + j) = 1;
				}
			}
			break;
		}
		cout << "Desea ver la matriz? \n1)Si. \n2)No. \n";
		cin >> opc1;
		//confirmacion
		if (opc1 != 1 && opc1 != 2)
		{
			do
			{
				cout << "E R R O R P3ND3J0: Esa opcion no existe!.  \n";
				cout << "Desea ver la matriz? \n1)Si. \n2)No. \n";
				cin >> opc1;

			} while (opc1 != 1 && opc1 != 2);
		}
		if (opc1 == 1)
		{
			//mostrar matriz
			for (int i = 0; i < f; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (*(*(matriz + i) + j) == 1)
					{

						cout << *(*(matriz + i) + j);
						cout << " ";
					}
					else
					{
						cout << 0;
						cout << " ";
					}
				}
				cout << endl;
			}

		}
		cout << "Quiere generar un archivo de imagen? \n1)Si. \n2)No. \n";
		cin >> opc2;
		//confirmacion
		if (opc2 != 1 && opc2 != 2)
		{
			do
			{
				cout << "E R R O R P3ND3J0: Esa opcion no existe!.  \n";
				cout << "Desea generar un archivo de imagen? \n1)Si. \n2)No. \n";
				cin >> opc2;

			} while (opc2 != 1 && opc2 != 2);
		}
		//crear archivo .pbm
		if (opc2 == 1)
		{
			ofstream notepad;//ofstream es la clase que genera archivos de texto 
			notepad.open("imagen.pbm");
			notepad << "P1" << endl;//tipo de formato
			notepad << "# Disofenix117" << endl;//comentario
			notepad << f << " " << c << endl;
			for (int i = 0; i < f; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (matriz[i][j] == 1)
					{

						notepad << matriz[i][j] << " ";
					}
					else
					{
						notepad << 0 << " ";
					}
				}
			}
			cout << "Imagen generada con el nombre de : imagen.pbm \n";
		}


		//solo bordes con 1
		/*while (coordX1 < coordX2)
		{
			for (int i = coordX1; i < coordX2; i++)
			{
				matriz[i][coordY1] = 1;
				matriz[i][coordY2] = 1;
			}
			while (coordY1 < coordY2)
			{
				for (int j = coordY1; j <= coordY2; j++)
				{
					matriz[coordX1][j] = 1;
					matriz[coordX2][j] = 1;
				}
				break;
			}
			break;
		}*/


		//liberar memoria 
		for (int i = 0; i < f; i++)//columnas
		{
			delete[] matriz[i];
		}
		delete matriz;//filas
	}

void Encadenamiento::parabola()
{
	int **matriz;
	int f, c, limite, centroX, centroY,lim1,lim2,Ddif=1;
	cout << "ingrese cantidad de filas" << endl;
	cin >> f;
	cout << " ingrese cantidad de columnas" << endl;
	cin >> c;
	//reservando memoria para matriz
	matriz = new int*[f];//para filas
	for (int i = 0; i < f; i++)
	{
		matriz[i] = new int[c];//para columnas
	}

	centroX = (f / 2)-1; centroY = (c / 2)-1; //ubicando centro 
	*(*(matriz + centroX) + centroY) = 1;//en la matriz


	//colocando los ejes
	for (int i = centroX; i < f; i++)
	{
		matriz[centroX][i] = 1;
		matriz[i][centroX] = 1;
	}
	for (int i = centroY; i < c; i--)
	{
			matriz[centroY][i] = 1;
			matriz[i][centroY] = 1;
			if (i == 0)
			{
				break;;
			}
	}

	cout << "ingrese el tamaño de la parabola" << endl;
	cin >> limite;
	cout << endl;
	for (int i =centroX -limite; i <=centroX+ limite; i++)
	{
		for (int j =centroY -limite; j <=centroY+ limite; j++)
		{
			lim1 = i;
			lim2 = j * j;
			if (lim1 - lim2 >0)
			{
				
				*(*(matriz + lim1) + lim2) = 1;

			}
		}
	}
	
	//mostrar matriz
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (matriz[i][j] == 1)
			{

				cout << *(*(matriz + i) + j);
				cout << " ";
			}
			else
			{
				cout << 0;
				cout << " ";
			}
		}
		cout << endl;
	}
	//liberar memoria 
	for (int i = 0; i < f; i++)//columnas
	{
		delete[] matriz[i];
	}
	delete matriz;//filas
}



void Encadenamiento::seno()
{
	int **matriz;
	//ventanas
	int XVmax = 50, XVmin = 10, YVmax = 50, YVmin = 10, XWmax = 300, XWmin = 100, YWmax = 300, YWmin = 100, f;
	int Sx = ((XVmax - XVmin) / (XWmax - XWmin)), Sy = ((YVmax - YVmin) / (YWmax - YWmin));
	double  c, o, y, a = 1, w = 2, phi = 0, d, x, dx = 0.05;
	double xw, yw, xv, yv;
	cout << "ingrese cantidad de filas" << endl;
	cin >> f;
	cout << " ingrese cantidad de columnas" << endl;
	cin >> c;

	//reservando memoria para matriz
	matriz = new int*[f];//para filas
	for (int i = 0; i < f; i++)
	{
		matriz[i] = new int[c];//para columnas
	}

	int centroX = (f / 2) - 1, centroY = (c / 2) - 1; //ubicando centro 
	*(*(matriz + centroX) + centroY) = 1;//en la matrizx	


										 //colocando los ejes
	for (int i = centroX; i < f; i++)
	{
		matriz[centroX][i] = 1;
		matriz[i][centroX] = 1;
	}
	for (int i = centroY; i < c; i--)
	{
		matriz[centroY][i] = 1;
		matriz[i][centroY] = 1;
		if (i == 0)
		{
			break;;
		}
	}
	/*
	cout << " ingrese la amplitud de la funcion" << endl;
	cin >> a;
	cout << " ingrese la frecuencia de la funcion" << endl;
	cin >> w;
	cout << " ingrese la constante de fase" << endl;
	cin >> phi;
	cout << " ingrese el corrimiento vertical" << endl;
	cin >> d;
	*/
	for (x = XWmin; x <= XWmax; x += dx)
	{
		//parametrizar	
		y = (a*sin(w*x + phi) + dx);
		xw = x;
		yw = y;
		int xi = (int)xw;
		int yi = (int)(c - yw);
		*(*(matriz + xi) + yi) = 1;


	}


	//mostrar matriz
	{for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (*(*(matriz + i) + j) == 1)
			{

				cout << *(*(matriz + i) + j);
				cout << " ";
			}
			else
			{
				cout << 0;
				cout << " ";
			}
		}
		cout << endl;
	}


	//liberar memoria 
	for (int i = 0; i < f; i++)
	{
		delete[] matriz[i];
	}
	delete matriz;

	}
}