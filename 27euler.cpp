#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> primes;
    for(int i=-999;i<1000;i+=2)
    {
        bool isPrime = false;
        int root = sqrt(i);
        for(int j=3;j<=root;j+=2)
        {
            if(i%j==0)
            {
                isPrime=true;
                break;
            }
        }
        if(isPrime==false){
            primes.push_back(i);
        }
    }
    int globali,globalj,globalx=0;
    int c=0 ;
    for(int i=0;i<primes.size();++i)
    {
        for(int j=0;j<primes.size();++j)
        {
            int x;
            c++;
            for(x=0;;++x)
            {
                long long int exp = ((x*x)+(primes[i]*x)+(primes[j]));
                long long int root = sqrt(exp);
                if(exp==2)
                    continue;
                if(exp%2==0)
                    break;
                bool isPrime = false;
                for(long int t=3;t<=root;t+=2)
                {
                    if(i%j==0)
                    {
                    isPrime=true;
                    break;
                    }
                }
                if(isPrime==true)
                    break;
            }
            cout << c << " " << x << endl;
            if(x>globalx)
            {globalx=x;globali=i;globalj=j;}
        }
    }
    cout << globalx << " " << globali << " " << globalj << endl;
    return 0;
}
