#include "pch.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
using namespace std;

double sum(double* A, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += A[i];
	}
	return sum / size;
}


int main()
{

	ifstream f("D:\\51.txt");


	for (int m = 1; m <= 3; m++) {

		double N, del1 = 0, del2 = 0;
		f >> N >> del1 >> del2;
		double ** B;
		B = new double *[N];
		for (int i = 0; i < N; i++) {
			B[i] = new double[46];
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 46; j++) {
				f >> B[i][j];
			}
		}


		int key[24];
		double Temp[50];
		double TEMPERATURE[24][39];

		int time = 0, size = 0, t = 0, v = 0;
		for (int time = 0; time < 24; time++) {
			key[time] = B[t][6];
			for (int i = 7; i < 46; i++) {
				for (int p = t; p < N && time == B[p][3]; p++) {
					Temp[p - t] = B[p][i];
					size++;
				}
				if (size > v)
					v = size;
				TEMPERATURE[time][i - 7] = sum(Temp, size);
				size = 0;
			}
			t += v;
			v = 0;
		}

		ofstream out("D:\\TEMPERATURE.txt", ios::app);
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 44; j++) {
				if (j == 0)
					out << "19 ";
				else if (j == 1)
					out << "05 ";
				else if (j == 2)
					out << setfill('0') << setw(2) << m << " ";
				else if (j == 3)
					out << setfill('0') << setw(2) << i << " ";
				else if (j == 4)
					out << key[i] << " ";
				else if (j == 43)
					out << fixed << setprecision(1) << TEMPERATURE[i][j - 5];
				else
					out << fixed << setprecision(1) << TEMPERATURE[i][j - 5] << " ";
			}
			out << endl;
		}
		out.close();

		for (int i = 0; i < N; i++) {
			delete[] B[i];
		}
		delete[] B;
	}

	return 0;
}
