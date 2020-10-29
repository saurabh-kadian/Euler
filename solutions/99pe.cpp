#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    cout << "Answer : ";
    double maxi = 0;
    double n,m;
    for (double i=0;i<1000;++i){
        double base , exp;
        char ch;
        cin >> base >> ch >> exp;
        double value = (log10(base)*exp);
        if(value > maxi){
            maxi = value;
            n = base;
            m = exp;
        }
    }
    cout << n << "  " << m;
    return 0;
}
