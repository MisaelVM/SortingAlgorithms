#include <iostream>

using namespace std;

/* ------------------------------------------------------------------*/

void imprimirArray(int A[], int a) {
	for (int i = 0; i < a; i++)
		cout << A[i] << "\t";
	cout << "\n";
}

void intercambiar(int &a, int &b) {
	int temp = a;
	b = a;
	a = temp;
}


/* ------------------------ COUNTING SORT --------------------------- */

void countingSort(int A[], int a) {
	// El tamano del conteo debe ser al menos (max + 1) pero VS2019
	// tiene soporte de asignacion dinamica de memoria
	// Por lo que lo haremos estaticamente
	int output[10];
	int count[10];
	int max = A[0];

	 // Encuentra el mayor elemento en el arreglo
	for (int i = 1; i < a; i++) {
		if (A[i] > max)
			max = A[i];
	}

	// Inicializamos el arreglo de cuentas con ceros
	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}

	// Almacenamos el conteo de cada elemento
	for (int i = 0; i < a; i++) {
		count[A[i]]++;
	}

	// Almacenamos el conteo acumulativo de cada arreglo
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	// Encuentra el indice de cada elemento del arreglo original en el arreglo
	// de cuentas y coloca los elementos en el arreglo de salida
	for (int i = a - 1; i >= 0; i--) {
		output[count[A[i]] - 1] = A[i];
		count[A[i]]--;
	}

	// Copia los elementos ordenados en el arreglo original
	for (int i = 0; i < a; i++) {
		A[i] = output[i];
	}
}


int main()
{
	int Array[] = { 4, 2, 2, 8, 3, 3, 1, 3, 6, 8 };
	int tam = sizeof(Array) / sizeof(Array[0]);

	cout << "Array desordenado:\n";
	imprimirArray(Array, tam);

	cout << "\n";

	countingSort(Array, tam);
	cout << "Array ordenado:\n";
	imprimirArray(Array, tam);

	return 0;
}