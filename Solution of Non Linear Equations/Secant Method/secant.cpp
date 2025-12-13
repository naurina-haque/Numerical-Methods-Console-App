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
    double n = 0;
    cout << "Enter degree of polynomial:";
    cin >> n;
    vector<double> coefficients(n + 1);
    cout << "Enter coefficients (from constant to highest degree):";
    for (int i = 0; i <= n; i++)
    {
        cin >> coefficients[i];
    }
    cout << endl;

    cout << "Equation is: ";
    bool firstTerm = true;
    for (int i = n; i >= 0; i--)
    {
        if (coefficients[i] == 0)
            continue;
        if (!firstTerm)
        {
            if (coefficients[i] > 0)
                cout << " + ";
            else
                cout << " - ";
        }
        else
        {
            if (coefficients[i] < 0)
                cout << "-";
            firstTerm = false;
        }
        if (fabs(coefficients[i]) != 1.0 || i == 0)
            cout << fabs(coefficients[i]);
        if (i > 0)
            cout << "x";
        if (i > 1)
            cout << "^" << i;
    }
    cout << " = 0" << endl;

    double xmax;
    cout << "Enter max absolute value of x to search for roots: ";
    cin >> xmax;
    double j;
    cout << endl
         << "Enter step size for interval search: ";
    cin >> j;
    double tolance;
    cout << "Enter tolerance: ";
    cin >> tolance;

    vector<pair<double, double>> v;
    for (double i = -fabs(xmax); i < fabs(xmax); i += j)
    {
        if (f(n, coefficients, i) * f(n, coefficients, i + j) < 1e-8)
            v.push_back({i, i + j});
    }
    cout << "\nIntervals containing roots: ";
    for (auto i : v)
    {
        cout << "[" << i.first << "," << i.second << "]" << " ";
    }
    cout << endl;

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

    cout << "\nRoots:" << endl;
    for (size_t i = 0; i < roots.size(); i++)
    {
        cout << "Root " << (i + 1) << " = " << fixed << setprecision(4) << roots[i] << endl;
    }
    return 0;
}