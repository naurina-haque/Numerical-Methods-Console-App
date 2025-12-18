#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    if(!fin)
    {
        cout<<"Input file not found"<<endl;
        return 0;
    }

    ofstream fout("output.txt",ios::app);
    if(!fout)
    {
        cout<<"Output file not found"<<endl;
        return 0;
    }

    int n;
    if(!(fin>>n))
    {
        cout<<"End of file"<<endl;
        return 0;
    }

    vector<vector<double>>a(n,vector<double>(n+1));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
            fin>>a[i][j];
    }

    for(int i=0; i<n; i++)
    {
        if(fabs(a[i][i])<1e-6)
        {
            bool swapped=false;
            for(int j=i+1; j<n; j++)
            {
                if(fabs(a[j][i])>1e-6)
                {
                    swap(a[i],a[j]);
                    swapped=true;
                    break;
                }
            }
            if(!swapped)
            {
                fout<<"Matrix is singular"<<endl;
                return 0;
            }
        }

        for(int j=i+1; j<n; j++)
        {
            double f=a[j][i]/a[i][i];
            for(int k=i; k<n+1; k++)
            {
                a[j][k]=a[j][k]-a[i][k]*f;
            }
        }

    }

    fout<<"Upper Triangular Matrix:"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
            if(fabs(a[i][j])<1e-6)
                fout<<"0"<<" ";
            else
                fout<<setprecision(3)<<a[i][j]<<" ";
        fout<<endl;
    }

    bool allzero;
    int x=1;
    for(int i=0; i<n; i++)
    {
        allzero=true;
        for(int j=0; j<n; j++)
        {
            if(fabs(a[i][j])>1e-6)
            {
                allzero=false;
                break;
            }
        }
        if(allzero && fabs(a[i][n])>1e-6)
        {
            fout<<"No solution"<<endl;
            x=0;
            break;
        }
        else if(allzero && fabs(a[i][n])<1e-6)
        {
            fout<<"Infinite solution"<<endl;
            x=0;
            break;
        }
    }

    if(x==0)
    {
        return 0;
    }

    for(int i=0; i<n; i++)
    {
        double f=a[i][i];
        for(int j=i; j<n+1; j++)
        {
            a[i][j]=a[i][j]/f;
        }
    }
    fout<<endl;

    for(int i=n-1; i>=0; i--)
    {
        if(fabs(a[i][i])>1e-6)
        {
            for(int j=i-1; j>=0; j--)
            {
                double f=a[j][i];
                for(int k=i; k<n+1; k++)
                {
                    a[j][k]-=f*a[i][k];
                }
            }
        }
    }

    fout<<"Row Reduced Echelon form:"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
            if(fabs(a[i][j])<1e-6)
                fout<<"0"<<" ";
            else
                fout<<setprecision(3)<<a[i][j]<<" ";
        fout<<endl;
    }
    fout<<endl;

    for(int i=0;i<n;i++)
    {
        fout<<"x"<<i+1<<"= "<<a[i][n]<<endl;
    }
    fout<<endl;

    return 0;
}
