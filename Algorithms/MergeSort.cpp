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



/* -------------------------- MERGE SORT ---------------------------- */

void merge(int A[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Arreglos temporales auxiliares
	int L[n1], R[n2];

	// Copia los elementos a los arreglos temporales L[] y R[]
	for (i = 0; i < n1; i++)
		L[i] = A[l + i];
	for (j = 0; j < n2; j++)
		R[j] = A[m + 1 + j];

	// Mezcla los arreglos temporales en A[1..r]
	i = 0; // Indice inicial del primer sub-arreglo
	j = 0; // Indice inicial del segundo sub-arreglo
	k = l; // Indice inicial del sub-arreglo mezclado

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}

	// Copia los elementos restantes de L[], si es que hay alguno
	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}

	// Copia los elementos restantes de R[], si es que hay alguno
	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int A[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2; 
		
		// Ordena la primer y segunda mitad
		mergeSort(A, l, m);
		mergeSort(A, m + 1, r);

		merge(A, l, m, r);
	}
}


int main()
{
	int Array[] = { 170, 28, 325, 12, 60, 91, 537, 5, 61, 8 };
	int tam = sizeof(Array) / sizeof(Array[0]);

	cout << "Array desordenado:\n";
	imprimirArray(Array, tam);

	cout << "\n";

	countingSort(Array, tam);
	cout << "Array ordenado:\n";
	imprimirArray(Array, tam);

	return 0;
}