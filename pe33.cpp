#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
using namespace std;
long long int gcd(long long int a,long long int b){
    while(b)
        a=b,b=fmod(a,b);
    return a;
}
int main(){
    long long int upper=1,lower=1;
    for(double i=10;i<100;++i){
        for(double j=i+1;j<100;++j){
            double final = i/j;
            if(final == (double)(1))
                continue;
            if(fmod(i,11) == 0 || fmod(j,11) == 0)
                continue;
            if(fmod(i,10) == 0 || fmod(j,10) == 0)
                continue;
            string num,deno;
            ostringstream convert,convert1;
            convert << i;
            num = convert.str();
            convert1 << j;
            deno = convert1.str();
            if(num[0] == deno[0]){
                num.erase(num.begin()+0);
                deno.erase(deno.begin()+0);
            }
            else if(num[1] == deno[0]){
                num.erase(num.begin()+1);
                deno.erase(deno.begin()+0);
            }
            else if(num[0] == deno[1]){
                num.erase(num.begin()+0);
                deno.erase(deno.begin()+1);
            }
            else if(num[1] == deno[1]){
                num.erase(num.begin()+1);
                deno.erase(deno.begin()+1);
            }
            istringstream con(num);
            istringstream cod(deno);
            double a,b;
            con >> a;
            cod >> b;
            double final1 = a/b;
            if(final == final1 && num.length() == 1 && deno.length() ==1 )
                upper*=i,lower*=j;
        }
    }
    long long int number = gcd(max(lower,upper),min(lower,upper));
    cout << "Project Euler 32 : " << lower/number << endl;
    return 0;
}
