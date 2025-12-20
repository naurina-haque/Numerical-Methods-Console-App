#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;
    vector<double> x(n), y(n), X(n), Y(n);

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for(int i = 0; i < n; i++) {
        fin >> x[i] >> y[i];
        if(x[i] <= 0 || y[i] <= 0) {
            fout << "Error: x and y values must be > 0 for power regression.\n";
            return 1;
        }
        X[i] = log(x[i]);
        Y[i] = log(y[i]);
        sumX += X[i];
        sumY += Y[i];
        sumXY += X[i] * Y[i];
        sumX2 += X[i] * X[i];
    }
    double B = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double lnA = (sumY - B*sumX)/n;
    double A = exp(lnA);

    fout << fixed << setprecision(6);
    fout << "Exponential Regression Equation:\n";
    fout << "y = " << A << " * x^" << B << "\n";

    fin.close();
    fout.close();

    return 0;
}
