#include <iostream>
using namespace std;
int call(int );
int main()
{
    unsigned long long int n,temp;
    cin >> n;
    for(int i=1;i<=n;++i)
        temp+=call(i);
    cout << temp << endl;
    return 0;
}
int call(int i)
{
    unsigned long long int value[4] = {0,1,1,3},sum=0;
    int t = i-1;
    int t1 = i-3;
    if(i==1)
        sum+=1;
    else if(i==3)
        sum+=3;
    if(t%4==0)
    {
            t/=4;
            sum += 2*call(2*t+1)-call(t);
    }
    else if(t1%4==0)
    {
            t1/=4;
            sum += 2*call(2*t1+1)-call(t1);
    }
    else
        sum+=call(i/2);
    return sum;
}
