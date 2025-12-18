#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> buildForwardTable(const vector<double> &y)
{
    int n = y.size();
    vector<vector<double>> diff(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }
    return diff;
}

vector<vector<double>> buildBackwardTable(const vector<double> &y)
{
    int n = y.size();
    vector<vector<double>> diff(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++)
    {
        for (int i = n - 1; i >= j; i--)
        {
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }
    return diff;
}

void printTable(const vector<double> &x, const vector<vector<double>> &diff, string type, ostream &out)
{
    int n = x.size();
    out << endl;
    out << "\t\t" << type << " DIFFERENCE TABLE" << endl;
    out << endl;

    out << setw(8) << "x" << setw(8) << "y";
    for (int i = 1; i < n; i++)
    {
        out << setw(8) << "Δ^" << i << "y";
    }
    out << endl;

    if (type == "FORWARD")
    {
        for (int i = 0; i < n; i++)
        {
            out << setw(8) << fixed << setprecision(2) << x[i];
            out << setw(8) << fixed << setprecision(2) << diff[i][0];

            for (int j = 1; j < n - i; j++)
            {
                out << setw(8) << fixed << setprecision(2) << diff[i][j];
            }
            out << endl;
        }
    }
    else // BACKWARD
    {
        for (int i = 0; i < n; i++)
        {
            out << setw(8) << fixed << setprecision(2) << x[i];
            out << setw(8) << fixed << setprecision(2) << diff[i][0];

            for (int j = 1; j < n && i >= j; j++)
            {
                out << setw(8) << fixed << setprecision(2) << diff[i][j];
            }
            out << endl;
        }
    }
    out << endl;
}

double forwardFirstDerivative(const vector<double> &x, const vector<double> &y, double value)
{
    int n = x.size();
    double h = x[1] - x[0];

    vector<vector<double>> diff = buildForwardTable(y);

    double derivative = 0;
    derivative = diff[0][1];

    if (n > 2)
        derivative -= diff[0][2] / 2.0; 

    if (n > 3)
        derivative += diff[0][3] / 3.0; 

    if (n > 4)
        derivative -= diff[0][4] / 4.0; 

    return derivative / h;
}

double backwardFirstDerivative(const vector<double> &x, const vector<double> &y, double value)
{
    int n = x.size();
    double h = x[1] - x[0];

    vector<vector<double>> diff = buildBackwardTable(y);


    double derivative = 0;
    derivative = diff[n - 1][1]; 

    if (n > 2)
        derivative += diff[n - 1][2] / 2.0; 

    if (n > 3)
        derivative += diff[n - 1][3] / 3.0; 

    if (n > 4)
        derivative += diff[n - 1][4] / 4.0; 

    return derivative / h;
}

double forwardSecondDerivative(const vector<double> &x, const vector<double> &y)
{
    int n = x.size();
    double h = x[1] - x[0];

    vector<vector<double>> diff = buildForwardTable(y);


    double derivative = 0;
    derivative = diff[0][2]; 

    if (n > 3)
        derivative -= diff[0][3];

    if (n > 4)
        derivative += (11.0 / 12.0) * diff[0][4]; 

    return derivative / (h * h);
}

double backwardSecondDerivative(const vector<double> &x, const vector<double> &y)
{
    int n = x.size();
    double h = x[1] - x[0];

    vector<vector<double>> diff = buildBackwardTable(y);

    double derivative = 0;
    derivative = diff[n - 1][2]; 

    if (n > 3)
        derivative += diff[n - 1][3]; 

    if (n > 4)
        derivative += (11.0 / 12.0) * diff[n - 1][4]; 

    return derivative / (h * h);
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open())
    {
        cerr << "Error: Unable to open input.txt" << endl;
        return 1;
    }

    if (!fout.is_open())
    {
        cerr << "Error: Unable to open output.txt" << endl;
        return 1;
    }

    int n;
    fin >> n;

    vector<double> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        fin >> x[i];
    }

    for (int i = 0; i < n; i++)
    {
        fin >> y[i];
    }

    double value;
    fin >> value;

    fout << "=== NUMERICAL DIFFERENTIATION USING INTERPOLATION FORMULAS ===" << endl;
    fout << endl;
    fout << "Number of data points: " << n << endl;
    fout << "Point for differentiation: x = " << value << endl;

    bool isBeginning = (abs(value - x[0]) < 1e-10);
    bool isEnd = (abs(value - x[n - 1]) < 1e-10);

    if (isBeginning)
    {
        vector<vector<double>> forwardDiff = buildForwardTable(y);
        printTable(x, forwardDiff, "FORWARD", fout);

        double firstDeriv = forwardFirstDerivative(x, y, value);
        double secondDeriv = forwardSecondDerivative(x, y);

        fout << "\nUSING FORWARD DIFFERENCE FORMULA:" << endl;
        fout << endl;
        fout << "First Derivative f'(" << fixed << setprecision(4) << value << ") = "
             << setprecision(6) << firstDeriv << endl;
        fout << "Second Derivative f''(" << fixed << setprecision(4) << value << ") = "
             << setprecision(6) << secondDeriv << endl;
        fout << endl;
    }
    else if (isEnd)
    {
        vector<vector<double>> backwardDiff = buildBackwardTable(y);
        printTable(x, backwardDiff, "BACKWARD", fout);

        double firstDeriv = backwardFirstDerivative(x, y, value);
        double secondDeriv = backwardSecondDerivative(x, y);

        fout << "\nUSING BACKWARD DIFFERENCE FORMULA:" << endl;
        fout << string(50, '-') << endl;
        fout << "First Derivative f'(" << fixed << setprecision(4) << value << ") = "
             << setprecision(6) << firstDeriv << endl;
        fout << "Second Derivative f''(" << fixed << setprecision(4) << value << ") = "
             << setprecision(6) << secondDeriv << endl;
        fout << string(50, '=') << endl;
    }
    else
    {
        fout << "\nNote: For middle points, use central difference or divided difference." << endl;
        fout << "This implementation focuses on endpoints using forward/backward formulas." << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
