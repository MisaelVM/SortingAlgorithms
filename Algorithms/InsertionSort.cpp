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



/* ------------------------ INSERTION SORT -------------------------- */

void insertionSort(int A[], int a) {
	for (int i = 1; i < a; i++) {
		int key = A[i];
		int j = i - 1;

		// Compara key con cada elemento en la izquierda de el
		// hasta que se encuentre un elemento menor que el
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}


int main()
{
	int Array[] = { 45, 32, 13, 80, 63, 37, 15, 23, 56, 48 };
	int tam = sizeof(Array) / sizeof(Array[0]);

	cout << "Array desordenado:\n";
	imprimirArray(Array, tam);

	cout << "\n";

	insertionSort(Array, tam);
	cout << "Array ordenado:\n";
	imprimirArray(Array, tam);

	return 0;
}