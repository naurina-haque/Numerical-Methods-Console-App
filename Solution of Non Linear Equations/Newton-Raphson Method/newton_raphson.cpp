#include <bits/stdc++.h>
using namespace std;

vector<double> coefficients;
int n;

double func(double x)
{
    double sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += pow(x, i) * coefficients[i];
    }
    return sum;
}

double derivative(double x)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i * coefficients[i] * pow(x, i - 1);
    }
    return sum;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fout << "=== Newton-Raphson Method ===" << endl;
    fin >> n;
    coefficients.resize(n + 1);

    for (int i = 0; i <= n; i++)
    {
     fin >> coefficients[i];
    }

    fout << "\nEquation is: ";
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

    vector<double> intervals;
    for (double i = interval_start; i < interval_end; i += step)
    {
        if (func(i) * func(i + step) < 0)
        {
            intervals.push_back(i);
        }
    }

    fout << "\nIntervals containing roots: ";
    for (auto a : intervals)
        fout << "{" << a << "} ";
    fout << endl;
    double xn, xn_1;
    int n;
    vector<double> roots;
    for (auto it : intervals)
    {
        xn = it;
        do
        {
            xn_1 = xn - (func(xn) / derivative(xn));
            n++;
            if (fabs(xn_1 - xn) < tolerance)
                break;
            xn = xn_1;
        } while (n < 100);
        roots.push_back(xn_1);
    }

    fout << "\nRoots:" << endl;
    for (size_t r = 0; r < roots.size(); r++)
    {
        fout << "Root " << (r + 1) << " = " << fixed << setprecision(6) << roots[r] << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
