#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    vector<double> x(n), y(n);
    double sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;

    for(int i = 0; i < n; i++)
    {
        fin>>x[i]>>y[i];
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2 += x[i] * x[i];
    }
    double b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    double a = (sumy - b * sumx) / n;

    fout << fixed << setprecision(6);
    fout << "Linear Regression Equation:\n";
    fout << "y = " << a << " + " << b << "x\n";

    fin.close();
    fout.close();

    return 0;
}
