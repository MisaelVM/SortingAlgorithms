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


/* -------------------------- QUICK SORT ---------------------------- */

// Esta funcion toma el ultimo elemento como pivote, coloca el elemento
// pivote en su posicion correcta en el arreglo ordenado, y coloca todos
// los menores (que el pivote) a la izquierda del pivote y todos los
// mayores a la derecha del pivote
int partition(int A[], int low, int high)
{
	int pivot = A[high]; // elemento pivote  
	int i = (low - 1); // Indice del elemento menor

	for (int j = low; j <= high - 1; j++) {  
		// Si el elemento actual es menor que el pivote
		if (A[j] < pivot) {
			i++; // Incrementa el indice del elemento menor
			intercambiar(A[i], A[j]);
		}
	}
	intercambiar(A[i + 1], A[high]);
	return (i + 1);
}

void quickSort(int A[], int low, int high) {
	if (low < high)	{
		// ip es el indice de particion, A[p] esta ahora
		// en el lugar correcto
		int ip = partition(A, low, high);

		// Ordena separadamente los elementos antes de
		// la particion y despues de la particion
		quickSort(A, low, ip - 1);
		quickSort(A, ip + 1, high);
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