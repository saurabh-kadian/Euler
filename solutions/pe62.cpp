#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iterator>
using namespace std;
int main(){
    vector<long long int> all,indexs;
    for(long long int i=3500;i<10000;++i)
        all.push_back(i*i*i);
    while(all.size()){
        vector<long long int> matching;
        matching.push_back(0);
        int c1[10] = {0};
        stringstream ss;
        ss << all[0];
        string str = ss.str();
        for(long long int j=0;j<str.length();++j)
            c1[str[j]-48]++;
        for(long long int i=1;i<all.size();++i){
            int c2[10] = {0};
            stringstream sa;
            sa << all[i];
            string strC = sa.str();
            for(long long int j=0;j<strC.length();++j)
                c2[strC[j]-48]++;
            bool found = true;
            for(int q=0;q<10;++q)
                if(c1[q] != c2[q])
                    found = false;
            if(found && all[i] != all[0])
                matching.push_back(i);
            if(matching.size() == 5)
                break;
        }
        if(matching.size() == 5){
            indexs = matching;
            break;
        }
        for(int i=0;i<matching.size();++i)
            all.erase(all.begin()+matching[i]);
    }
    if(all.size() == 0){
        cout << "Not Found." << endl;
        return 0;
    }
    sort(indexs.begin(),indexs.end());
    cout << "ProjectEuler Problem 62 : " << all[indexs[0]] << endl;
	return 0;
}
