#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    unsigned long long int sum = 0;
    int prime[] = {2,3,5,7,11,13,17};
    string test = "0123456789";
   do {
        bool flag = true;
        for(int i=0;i<7;++i){
            string all;
            all = test.substr(i+1,3);
            istringstream con(all);
            long long int k;
            con >> k;
            if(k%prime[i] != 0){
                flag = false;
                break;
            }
        }
        if(flag == true){
            istringstream con1(test);
            long long int k1;
            con1 >> k1;
            sum += k1;
        }
  } while (next_permutation(test.begin(),test.end()));
    cout << sum << endl;
    return 0;
}
