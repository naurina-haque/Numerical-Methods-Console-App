#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t=1;
    while(t)
    {

        int n;
        cout<<"Enter number of eqn: ";
        cin>>n;
        vector<vector<double>>a(n,vector<double>(n+1));
        vector<vector<double>>l(n,vector<double>(n,0));
        cout<<"Enter augmented Matrix:"<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n+1; j++)
                cin>>a[i][j];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                l[i][i]=1;
        }
        vector<double>b(n);
        for(int j=0; j<n; j++)
            b[j]=a[j][n];

        for(int i=0; i<n-1; i++)
        {
            if(fabs(a[i][i])<1e-6)
            {
                bool swapp=false;
                for(int j=i+1; j<n; j++)
                {
                    if(fabs(a[j][i])>1e-6)
                    {
                        swap(a[i],a[j]);
                        swapp=true;
                        break;

                    }
                }
                if(!swapp)
                {
                    cout<<"Singular Matrix"<<endl;
                }
            }
            else
            {
                for(int j=i+1; j<n; j++)
                {
                    double f=a[j][i]/a[i][i];
                    l[j][i]=f;
                    cout<<"Lower triangular Matrix"<<endl;
                    for(int i=0; i<n; i++)
                    {
                        for(int j=0; j<n; j++)
                            cout<<setprecision(3)<<l[i][j]<< " ";
                        cout<<endl;
                    }
                    for(int k=i; k<n+1; k++)
                    {
                        a[j][k]-=f*a[i][k];
                        cout<<"Upper triangular Matrix"<<endl;
                        for(int i=0; i<n; i++)
                        {
                            for(int j=0; j<n; j++)
                                cout<<setprecision(3)<<a[i][j]<< " ";
                            cout<<endl;
                        }
                    }
                }
            }


        }




        bool trap=false;
        for(int i=0; i<n; i++)
        {
            bool all=true;
            for(int j=0; j<n; j++)
            {
                if(fabs(a[i][j])>1e-6)
                {
                    all=false;
                    break;
                }

            }
            if(all && fabs(a[i][n])>1e-6)
            {
                cout<<"No Solution"<<endl;
                trap=true;
                break;
            }
            if(all && fabs(a[i][n])<1e-6)
            {
                cout<<"Infinite Solution"<<endl;
                trap=true;
                break;
            }

        }
        if(trap)
        {
            char ab;
            cout<<"Solve another system?(y/n)"<<endl;
            cin>>ab;
            if(ab=='y')
                t=1;
            else
                t=0;
        }
        else
        {
            vector<double>y(n);
            for(int i=0; i<n; i++)
            {
                double sum=0;
                for(int j=0; j<i; j++)
                {
                    sum+=l[i][j]*y[j];
                }
                y[i]=b[i]-sum;
            }
            vector<double>x(n);
            for(int i=n-1; i>=0; i--)
            {
                double sum=0;
                for(int j=i+1; j<n; j++)
                {
                    sum+=a[i][j]*x[j];
                }
                x[i]=(y[i]-sum)/a[i][i];
            }
            cout<<"System has Unique Solution"<<endl;
            cout<<"Value of y"<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<setprecision(3)<<y[i]<< " ";
            }
            cout<<endl;
            cout<<"Value of x"<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<setprecision(3)<<x[i]<< " ";
            }
            cout<<endl;

            char ab;
            cout<<"Solve another system?(y/n)"<<endl;
            cin>>ab;
            if(ab=='y')
                t=1;
            else
                t=0;
        }


    }

    return 0;
}

