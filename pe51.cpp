/** only adjacent digits */
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;
bool is_prime(long long int k){
    long long int sq = sqrt(k);
    if(k==2)
        return true;
    else if(k%2==0)
        return false;
    for(long long int i=3;i<=sq;++i)
        if(k%i == 0)
            return false;
    return true;
}
int main()
{
    long long int i = 3;
    while(i<1000000){
        if(!is_prime(i)){
            i+=2;continue;
        }
        string number;
        ostringstream con;
        con << i;
        number = con.str();
        for(long long int l=1;l<=number.length()-1;++l){
            for(long long int p=0;p<number.length()-l;++p){
                int counter = 0;
                vector<long long int> lol;
                for(long long int t=0;t<10;++t){
                    string temp = number;
                    for(long long int o=p,y=0;y<l;++o,++y){
                        temp[o] = t+48;
                    }
                    long long int rofl;
                    istringstream lel(temp);
                    lel >> rofl;
                    if(is_prime(rofl)){
                        string c;
                        ostringstream con1;
                        con1 << rofl;
                        c = con1.str();
                        if(c.length() != number.length())
                            continue;
                        counter++;
                        lol.push_back(rofl);
                    }
                }
                if(counter == 8){
                    for(int a=0;a<2;++a)
                        cout << lol[a] << endl;
                    goto x;
                }
            }
        }
        i+=2;
    }
    x:
    return 0;
}
