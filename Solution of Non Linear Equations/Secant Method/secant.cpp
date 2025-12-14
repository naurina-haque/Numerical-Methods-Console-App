#include <bits/stdc++.h>
using namespace std;
double f(double p, vector<double> coeffs, double x)
{
    double s = 0.0;
    for (int i = 0; i <= p; i++)
    {
        s += coeffs[i] * pow(x, i);
    }
    return s;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout << "=== Secant Method ===" << endl;

    double n = 0;
    fin >> n;
    vector<double> coefficients(n + 1);
    for (int i = 0; i <= n; i++)
    {
        fin >> coefficients[i];
    }

    fout << "Equation is: ";
    bool firstTerm = true;
    for (int i = n; i >= 0; i--)
    {
        if (coefficients[i] == 0)
            continue;
        if (!firstTerm)
        {
            if (coefficients[i] > 0)
                fout << " + ";
            else
                fout << " - ";
        }
        else
        {
            if (coefficients[i] < 0)
                fout << "-";
            firstTerm = false;
        }
        if (fabs(coefficients[i]) != 1.0 || i == 0)
            fout << fabs(coefficients[i]);
        if (i > 0)
            fout << "x";
        if (i > 1)
            fout << "^" << i;
    }
    fout << " = 0" << endl;

    double xmax;
    fin >> xmax;
    double j;
    fin >> j;
    double tolance;
    fin >> tolance;

    vector<pair<double, double>> v;
    for (double i = -fabs(xmax); i < fabs(xmax); i += j)
    {
        if (f(n, coefficients, i) * f(n, coefficients, i + j) < 1e-8)
            v.push_back({i, i + j});
    }
    fout << "\nIntervals containing roots: ";
    for (auto i : v)
    {
        fout << "[" << i.first << "," << i.second << "]" << " ";
    }
    fout << endl;

    vector<double> roots;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        double x1 = it->first;
        double x2 = it->second;

        int iterations = 0;
        double x0 = x2;
        while (iterations < 1000)
        {
            double fx1 = f(n, coefficients, x1);
            double fx2 = f(n, coefficients, x2);

            if (fabs(fx2 - fx1) < 1e-14)
                break;

            x0 = x2 - fx2 * (x2 - x1) / (fx2 - fx1);
            iterations++;

            if (fabs(x0 - x2) < tolance)
                break;

            x1 = x2;
            x2 = x0;
        }
        roots.push_back(x0);
    }

    fout << "\nRoots:" << endl;
    for (size_t i = 0; i < roots.size(); i++)
    {
        fout << "Root " << (i + 1) << " = " << fixed << setprecision(4) << roots[i] << endl;
    }

    fin.close();
    fout.close();
    return 0;
}