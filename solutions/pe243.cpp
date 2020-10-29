#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(long long int k)
{
    if(k==2)
        return true;
    if(k%2==0)
        return false;
    long long int sq = sqrt(k);
    for(long long int i=3;i<=sq;++i)
        if(k%i==0)
            return false;
    return true;
}
long long int euclid(long long int m,long long int n)
{
    long long int r,count_euclid = 1;
        if(m>=n)
        {
            while(n%m)
            {
                count_euclid++;
                r=n%m;
                n=m;
                m=r;
            }
        }
        else
        {
            r=m;m=n;n=r;
            while(n%m)
            {
                count_euclid++;
                r=n%m;
                n=m;
                m=r;
            }
        }
        return r;
}
int main(){
    double minimum = 15499.0/94744.0;
    cout << "Start" << endl;
    double deno = (double)(2*3*5*7*11*13)*(double)(17*19*23);
    double num = (double)(1*2*4*6*10*12)*(double)(16*18*22);
            for(double j=2;j<10;++j){
                if((num*j)/((deno*j)-1) < minimum)
                    cout << (long long int)(deno*j) << " " << (num*j)/((deno*j)-1) << " " << minimum << endl;
            }
    cout << "End" << endl;
    return 0;
}
