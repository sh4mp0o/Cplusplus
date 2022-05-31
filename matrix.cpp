//двумерный массив на C++

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int** createMatrix(istream& in, int& n, int& m);
void printMatrix(ostream& out, int** matrix, int n, int m);
void removeMatrix(int**& matrix, int& n, int& m);

int main() {
	int n, m;
	int** A = createMatrix(cin, n, m);
	printMatrix(cout, A, n, m);
	removeMatrix(A, n, m);

	return 0;
}

int** createMatrix(istream& in, int& n, int& m) {
	in >> n >> m;
	int** matrix = new int* [n + 1];
	matrix[n] = new int[n * m];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = &matrix[n][i * m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			in >> matrix[i][j];
		}
	}
	return matrix;
}
void printMatrix(ostream& out, int** matrix, int n, int m) {
	out << n << " " << m << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			out << setw(7) << matrix[i][j];
		}
		out << endl;
	}
}
void removeMatrix(int**& matrix, int& n, int& m) {
	delete[]matrix[n];
	delete[]matrix;
	matrix = nullptr;
	n = m = 0;
}
