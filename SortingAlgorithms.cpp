#include <iostream>
#include <cstdlib>
#include <ctime>

#include <string>

using namespace std;

/* ------------------------------------------------------------------*/

void llenarArray(int A[], int a) {
	srand(time(0));
	for (int i = 0; i < a; i++)
		A[i] = rand() % 1000 + 1;
}

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