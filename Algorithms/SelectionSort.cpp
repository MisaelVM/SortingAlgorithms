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


/* ------------------------ SELECTION SORT -------------------------- */

void selectionSort(int A[], int a) {
	// Uno a uno se va moviendo el limite del sub-arreglo no ordenado
	for (int i = 0; i < a - 1; i++) {

		// Encuentra el menor elemento en el arreglo no ordenado
		int min_index = i;
		for (int j = i + 1; j < a; j++)
			if (A[j] < A[min_index])
				min_index = j;

		// Intercambia el menor elemento encontrado con el primer
		// elemento del arreglo no ordenado
		intercambiar(A[min_index], A[i]);
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