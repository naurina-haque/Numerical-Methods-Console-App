#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return 2*x + y;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    if(!fin || !fout)
    {
        cout << "File error\n";
        return 1;
    }
    fout<<"---Runge-Kutta Method---"<<endl;

    double x0, y0, h, xn;
    fin >> x0 >> y0 >> h >> xn;

    double x = x0;
    double y = y0;
    fout << fixed << setprecision(6);

    int i = 1;
    while (x <= xn + 1e-9)
    {
        fout << "x" << i << " = " << x
             << "   y" << i << " = " << y << endl;

        double k1 = h * f(x, y);
        double k2 = h * f(x + h/2, y + k1/2);
        double k3 = h * f(x + h/2, y + k2/2);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x = x + h;
        i++;
    }

    fin.close();
    fout.close();

    return 0;
}
