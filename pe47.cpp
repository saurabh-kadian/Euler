/*********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
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
int main(){
    for(long long int i=12;i<100000;++i){
        vector<long int> dt1;
        vector<long int> dt2;
        vector<long int> dt3;
        vector<long int> dt4;
        long long int n1=i,n2=i+1,n3=i+2,n4=i+3;
        for(long long int factor = 2;factor < i+3;++factor){
            if(is_prime(factor) == false)
                    continue;
            if(n1%factor == 0){
                bool found = false;
                for(long int q=0;q<dt1.size();++q){
                    if(dt1[q] == factor){
                        found = true;
                        break;
                    }
                }
                if(found == false)
                    dt1.push_back(factor);
                n1 /= factor;
            }
            if(n2%factor == 0){
                bool found = false;
                for(long int q=0;q<dt2.size();++q){
                    if(dt2[q] == factor){
                        found = true;
                        break;
                    }
                }
                if(found == false)
                    dt2.push_back(factor);
                n2 /= factor;
            }
            if(n3%factor == 0){
                bool found = false;
                for(long int q=0;q<dt3.size();++q){
                    if(dt3[q] == factor){
                        found = true;
                        break;
                    }
                }
                if(found == false)
                    dt3.push_back(factor);
                n3 /= factor;
            }
            if(n4%factor == 0){
                bool found = false;
                for(long int q=0;q<dt4.size();++q){
                    if(dt4[q] == factor){
                        found = true;
                        break;
                    }
                }
                if(found == false)
                    dt4.push_back(factor);
                n4 /= factor;
            }
            if(dt4.size() == 4 && dt1.size() == 4 && dt2.size() == 4 && dt3.size() == 4)
                break;
        }
        if(dt1.size() == 4 && dt2.size()==4 && dt3.size()==4)
            cout << i <<  " " << i+1 << " " << i+2 << endl;
        if(dt4.size() == 4 && dt1.size() == 4 && dt2.size() == 4 && dt3.size() == 4){
                for(int i=0;i<4;++i){
                    cout << dt4[i] << " " << dt1[i] << " " << dt2[i] << " " << dt3[i] << endl;
                }
                cout << i << " " << i+1 << " " << i+2 << " " <<  i+3 << endl;
                goto x;
            }
    }
    x:
return 0;}
