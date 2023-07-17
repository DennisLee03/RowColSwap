#include <iostream>
using namespace std;
void FillIn(double ary[][5]);
void Display(double ary[][5]);
int FindMaxInRow(double ary[][5], int row);
void SwapRow(double ary[][5], int r1, int r2);
void SwapCol(double ary[][5], int c1, int c2);
int FindMaxInCol(double ary[][5], int col);
int main() {
	double ary[5][5];
	FillIn(ary);
	Display(ary);
	SwapCol(ary,0,FindMaxInRow(ary, 0));
	Display(ary);
	SwapRow(ary, 0, FindMaxInCol(ary, 0));
	Display(ary);

}
void FillIn(double ary[][5]) {
	srand(4321);
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			ary[i][j] = 10.0 * rand() / RAND_MAX;
		}
	}
}
void Display(double ary[][5]) {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			printf("%.2f   ", ary[i][j]);
		}
		cout << endl;
	}
	printf("==========\n");
}
int FindMaxInRow(double ary[][5], int row) {
	double max=0;
	for (int i = 0;i < 5;i++) {
		if (ary[row][i] < ary[row][i + 1]) {
			max = ary[row][i + 1];
		}
		else {
			max = ary[row][i];
		}
		return i + 1;
	}	
}
void SwapCol(double ary[][5], int c1, int c2) {
	double G[5][1];
	for (int i = 0;i < 5;i++) {
		G[i][0]= ary[i][c1] ;
		ary[i][c1] = ary[i][c2];
		ary[i][c2] = G[i][0];
	}
}
int FindMaxInCol(double ary[][5], int col) {
	double max = 0;
	for (int i = 0;i < 5;i++) {
		if (ary[i][col] < ary[i+1][col]) {
			max = ary[i+1][col];
		}
		else {
			max = ary[i][col];
		}
		return i + 1;
	}
}
void SwapRow(double ary[][5], int r1, int r2) {
	double G[1][5];
	for (int i = 0;i < 5;i++) {
		G[0][i] = ary[r1][i];
		ary[r1][i] = ary[r2][i];
		ary[r2][i] = G[0][i];
	}
}