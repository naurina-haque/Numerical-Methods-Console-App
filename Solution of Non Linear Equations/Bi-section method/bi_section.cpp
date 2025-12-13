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

int main()
{
    cout << "Enter the degree of polynomial: ";
    cin >> n;
    coefficients.resize(n + 1);
    cout << "Enter the coefficients (from constant to highest degree): ";
    for (int i = 0; i <= n; i++)
    {
        cin >> coefficients[i];
    }

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

    vector<pair<double, double>> v;
    cout << "Enter the interval to find roots:";
    int interval_start, interval_end;
    cin >> interval_start >> interval_end;
    cout << endl;
    cout << "Enter interval step:";
    double step;
    cin >> step;
    cout<<"Enter tolerance:";
    double tolerance;
    cin>>tolerance;

    for (double i = interval_start; i < interval_end; i += step)
    {
        if (func(i) * func(i + step) < 0)
        {
            v.push_back({i, i + step});
        }
    }
    cout << "Intervals containing roots: ";
    for (auto a : v)
        cout << "{" << a.first << "," << a.second << "}" << "  ";
    cout << endl;
    double x1, x2;
    vector<double> roots;
    cout << "Roots are: " << endl;
    for (auto i = v.begin(); i != v.end(); i++)
    {
        x1 = i->first;
        x2 = i->second;
        double x0;
        while (fabs(x2 - x1) > tolerance)
        {
            x0 = (x1 + x2) / 2.0;
            if (fabs(func(x0)) < 1e-6)
                break;
            else if (func(x0) * func(x1) < 0)
                x2 = x0;
            else if (func(x0) * func(x2) < 0)
                x1 = x0;
        }
        roots.push_back(x0);
    }
    for (int r = 0; r < roots.size(); r++)
        cout << "Root" << r + 1 << " = " << fixed << setprecision(2) << roots[r] << endl;
    return 0;
}