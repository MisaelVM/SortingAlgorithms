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


/* -------------------------- RADIX SORT ---------------------------- */

// Funcion que obtiene el mayor elemento del arreglo
int getMax(int A[], int a) {
	int mx = A[0];
	for (int i = 1; i < a; i++)
		if (A[i] > mx)
			mx = A[i];
	return mx;
}

// Usando el counting sort para ordenar los elementos en las bases
// de los lugares significativos
void countSort(int A[], int a, int exp) {
	const int max = 10;
	int output[a]; // Arreglo de salida
	int count[max] = { 0 };

	// Almacena el conteo de ocurrencias en count[]
	for (int i = 0; i < a; i++)
		count[(A[i] / exp) % 10]++;
	
	// Calcula el conteo acumulativo
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Construye el arreglo de salida
	for (int i = a - 1; i >= 0; i--) {
		output[count[(A[i] / exp) % 10] - 1] = A[i];
		count[(A[i] / exp) % 10]--;
	}

	// Copia el arreglo de salida a A[], para que A[] contenga
	// los numeros ordenados segun su digito actual
	for (int i = 0; i < a; i++)
		A[i] = output[i];
}

void radixSort(int A[], int a) {
	// Encuentra el numero maximo para saber el numero de digitos
	int m = getMax(A, a);

	// Realiza el counting sort para cada digito.
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(A, a, exp);
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