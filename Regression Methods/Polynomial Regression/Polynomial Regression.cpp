#include <bits/stdc++.h>
using namespace std;

vector<double> gaussElimination(vector<vector<double>> A, vector<double> Y, int n) {
    for(int i=0; i<n; i++) {
        int maxRow = i;
        for(int k=i+1; k<n; k++)
            if(abs(A[k][i]) > abs(A[maxRow][i]))
                maxRow = k;
        swap(A[i], A[maxRow]);
        swap(Y[i], Y[maxRow]);

        for(int k=i+1; k<n; k++) {
            double factor = A[k][i]/A[i][i];
            for(int j=i; j<n; j++)
                A[k][j] -= factor*A[i][j];
            Y[k] -= factor*Y[i];
        }
    }

    vector<double> coeff(n);
    for(int i=n-1; i>=0; i--) {
        coeff[i] = Y[i];
        for(int j=i+1; j<n; j++)
            coeff[i] -= A[i][j]*coeff[j];
        coeff[i] /= A[i][i];
    }
    return coeff;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;
    vector<double> x(n), y(n);
    for(int i=0; i<n; i++)
        fin >> x[i] >> y[i];

    vector<vector<double>> A(m+1, vector<double>(m+1,0));
    vector<double> Y(m+1,0);
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=m; j++) {
            for(int k=0; k<n; k++)
                A[i][j] += pow(x[k], i+j);
        }
        for(int k=0; k<n; k++)
            Y[i] += pow(x[k], i) * y[k];
    }

    vector<double> coeff = gaussElimination(A, Y, m+1);

    fout << fixed << setprecision(6);
    fout << "Polynomial Regression Equation:\n";
    fout << "y = ";

    bool firstTerm = true;
    for(int i=0; i<=m; i++) {
        if(coeff[i] == 0) continue;

        if(firstTerm) {
            if(coeff[i] < 0) fout << "-";
        } else {
            if(coeff[i] < 0) fout << " - ";
            else fout << " + ";
        }
        fout << abs(coeff[i]);
        if(i > 0) fout << "*x";
        if(i > 1) fout << "^" << i;

        firstTerm = false;
    }
    fout << "\n";

    fin.close();
    fout.close();
    return 0;
}
