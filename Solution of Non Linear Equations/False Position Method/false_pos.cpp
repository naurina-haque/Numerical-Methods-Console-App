#include <bits/stdc++.h>
using namespace std;

double func(int n, vector<double> coefficients, double x)
{
    double sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += pow(x, i) * coefficients[i];
    }
    return sum;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout << "=== False Position Method ===" << endl;

    int n;
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

    int interval_start, interval_end;
    fin >> interval_start >> interval_end;

    double step;
    fin >> step;

    double tolerance;
    fin >> tolerance;

    vector<pair<double, double>> intervals;
    for (double i = interval_start; i < interval_end; i += step)
    {
        if (func(n, coefficients, i) * func(n, coefficients, i + step) < 0)
        {
            intervals.push_back({i, i + step});
        }
    }

    fout << "\nIntervals containing roots: ";
    for (auto a : intervals)
        fout << "{" << a.first << "," << a.second << "} ";
    fout << endl;

    vector<double> roots;
    for (auto it = intervals.begin(); it != intervals.end(); it++)
    {
        double x1 = it->first;
        double x2 = it->second;
        double x0;

        while (fabs(x2 - x1) > tolerance)
        {
            double f1 = func(n, coefficients, x1);
            double f2 = func(n, coefficients, x2);

            if (fabs(f2 - f1) < 1e-14)
                break;

            x0 = (x1 * f2 - x2 * f1) / (f2 - f1);
            double f0 = func(n, coefficients, x0);

            if (fabs(f0) < tolerance)
                break;

            if (f0 * f1 < 0)
                x2 = x0;
            else
                x1 = x0;
        }
        roots.push_back(x0);
    }

    for (size_t r = 0; r < roots.size(); r++)
        fout << "Root " << (r + 1) << " = " << fixed << setprecision(6) << roots[r] << endl;

    fin.close();
    fout.close();
    return 0;
}
