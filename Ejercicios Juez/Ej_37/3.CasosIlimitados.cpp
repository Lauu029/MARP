
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "EnterosInf.h"
#include "Matriz.h"// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct infoCordel {
	long long int longitud;
	long long int precio;
};

//Numero de cordeles con matriz
EntInf numCordelesM(vector<infoCordel>const& cordeles, long long int L) {
	Matriz<EntInf> mat(cordeles.size() + 1, L + 1, Infinito);
	for (long long int i = 0; i < cordeles.size()+1; i++)
	{
		mat[i][0] = 0;
	}
	for (long long int i = 1; i <= cordeles.size(); i++)
	{
		for (long long int j = 1; j <= L; j++)
		{
			if (cordeles[i - 1].longitud > j)
				mat[i][j] = mat[i - 1][j];
			else
				mat[i][j] = min(mat[i - 1][j], mat[i - 1][j - cordeles[i - 1].longitud] + 1);
		}
	}
	return mat[cordeles.size()][L];
}
//Precio con matriz
EntInf precioM(vector<infoCordel>const& cordeles, int L) {
	Matriz<EntInf> mat(cordeles.size() + 1, L + 1, Infinito);
	for (long long int i = 0; i < cordeles.size() + 1; i++)
	{
		mat[i][0] = 0;
	}
	for (long long int i = 1; i <= cordeles.size(); i++)
	{
		for (long long int j = 1; j <= L; j++)
		{
			if (cordeles[i - 1].longitud > j)
				mat[i][j] = mat[i - 1][j];
			else
				mat[i][j] = min(mat[i - 1][j], mat[i - 1][j - cordeles[i - 1].longitud] + cordeles[i-1].precio);
		}
	}
	return mat[cordeles.size()][L];
}
//formas de hacerlo con matriz
long long int FormasM(vector<infoCordel>const& cordeles, long long int L) {
	Matriz<long long int> mat(cordeles.size() + 1, L+1, 0);
	for (long long int i = 0; i < cordeles.size(); i++)
	{
		mat[i][0] = 1;
	}
	for (long long int i = 1; i <= cordeles.size(); i++)
	{
		for (long long int j = 1; j <= L; j++)
		{
			if (cordeles[i - 1].longitud >j)
				mat[i][j] = mat[i - 1][j];
			else {
				mat[i][j] = mat[i - 1][j] + mat[i - 1][j - cordeles[i - 1].longitud];
			}
		}
	}
	return mat[cordeles.size() ][L];
}
////Numero de cordeles con vector
EntInf numCordelesV(vector<infoCordel>const& cordeles, int L) {
	vector<EntInf> mat(L + 1, Infinito);
	mat[0] = 0;
	for (long long int i = 1; i <= cordeles.size(); i++)
	{
		for (long long int j = L; j >= cordeles[i - 1].longitud; --j)
		{
			mat[j] = min(mat[j] , mat[j - cordeles[i - 1].longitud]+1);
		}
	}
	return mat[L];
}

//Precio con vector
EntInf precioV(vector<infoCordel>const& cordeles, int L) {
	vector<EntInf> mat(L + 1, Infinito);
	mat[0] = 0;
	for (long long int i = 1; i <= cordeles.size(); i++)
	{
		for (long long int j = L; j >= cordeles[i - 1].longitud; --j)
		{
			mat[j] = min(mat[j], mat[j - cordeles[i - 1].longitud] + cordeles[i-1].precio);
		}
	}
	return mat[L];
}
//formas con vector
long long int FormasV(vector<infoCordel>const& cordeles, int L) {
	vector<long long int> mat(L + 1, 0);
	mat[0] = 1;
	for (long long int i = 1; i <= cordeles.size(); i++)
	{
		for (long long int j = L; j >= cordeles[i-1].longitud; --j)
		{
				mat[j] = mat[j] + mat[j - cordeles[i-1].longitud];
		}
	}
	return mat[L];
}
bool resuelveCaso() {
	//leer los datos de la entrada
	long long int N, L;
	cin >> N >> L;
	if (!std::cin)  // fin de la entrada
		return false;
	vector<infoCordel>cordeles(N);
	// resolver el caso posiblemente llamando a otras funciones
	for (long long int i = 0; i < N; i++)
		cin >> cordeles[i].longitud >> cordeles[i].precio;

	Matriz<EntInf> minimoPrecio(N + 1, L + 1, Infinito);
	Matriz<EntInf> minimasCuerdas(N + 1, L + 1, Infinito);

	// escribir la solución
	long long int solucionMatematico = FormasV(cordeles, L);
	EntInf costeMinimo = numCordelesV(cordeles, L);
	EntInf solucionEconomista = precioV(cordeles, L);
	if (costeMinimo != Infinito)
		cout << "SI " << solucionMatematico << " " << costeMinimo << " " << solucionEconomista <<"\n";
	else cout << "NO\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
