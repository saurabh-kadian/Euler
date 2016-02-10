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
long long int finder (vector<long long int> test,long long int val){
    long long int last = val%100;
    for(long long int i=0;i<test.size();++i)
        if(test[i]/100 == last)
            return test[i];
    return 0;
}
int main(){
	//freopen("output.txt","w",stdout);
	vector<long long int> tri,trin;
	vector<long long int> sq,sqn;
	vector<long long int> pent,pentn;
	vector<long long int> hex,hexn;
	vector<long long int> hept,heptn;
	vector<long long int> oct,octn;
	vector<vector<long long int> >numbers;
	for(long long int i=0;i<500;++i){
        tri.push_back((i*(i+1))/2);
        sq.push_back(i*i);
        pent.push_back((i*(3*i-1))/2);
	}
	for(long long int i=0;i<500;++i){
        hex.push_back((i*(2*i-1)));
        hept.push_back((i*(5*i-3))/2);
        oct.push_back((i*(3*i-2)));
	}
	for(long long int i=0;i<500;++i){
        if(tri[i] >= 1000 && tri[i] <= 9999){
                trin.push_back(tri[i]);
        }
	}
	for(long long int i=0;i<500;++i){
        if(sq[i] >= 1000 && sq[i] <= 9999){
                sqn.push_back(sq[i]);
        }
	}
	for(long long int i=0;i<500;++i){
        if(pent[i] >= 1000 && pent[i] <= 9999){
                pentn.push_back(pent[i]);
        }
	}
	for(long long int i=0;i<500;++i){
        if(hex[i] >= 1000 && hex[i] <= 9999){
                hexn.push_back(hex[i]);
        }
	}
	for(long long int i=0;i<500;++i){
        if(hept[i] >= 1000 && hept[i] <= 9999){
                heptn.push_back(hept[i]);
        }
	}
	for(long long int i=0;i<500;++i){
        if(oct[i] >= 1000 && oct[i] <= 9999){
                octn.push_back(oct[i]);
        }
	}
	numbers.push_back(trin);
	numbers.push_back(sqn);
	numbers.push_back(pentn);
	numbers.push_back(hexn);
	numbers.push_back(heptn);
	numbers.push_back(octn);
    for(long long int i=0;i<octn.size();++i){
        int check[6] = {0};
        check[5] = 1;
        for(int h=0;h<5;++h){
            if(check[h] == 0){
                check[h] = 1;
                long long int next = finder(numbers[h],oct[i]);
                if(next){
                    for(int q=0;q<5;++q){
                        if(check[q] == 0){
                            check[q] = 1;
                            long long int next1 = finder(numbers[q],next);
                            if(next1){
                                for(int u=0;u<5;++u){
                                    if(check[u] == 0){
                                        check[u] = 1;
                                        long long int next2 = finder(numbers[u],next1);
                                        if(next2){
                                            for(int w=0;w<5;++w){
                                                if(check[w] == 0){
                                                    check[w] = 1;
                                                    long long int next3 = finder(numbers[w],next2);
                                                    if(next3){
                                                        for(int e=0;e<5;++e){
                                                            if(check[e] == 0){
                                                                check[e] = 1;
                                                                long long int nexter = finder(numbers[e],next3);
                                                                stringstream ss;
                                                                ss << oct[i];
                                                                string str = ss.str();
                                                                long long int f = nexter%100;
                                                                bool yes = false;
                                                                if(f == oct[i]/100)
                                                                    yes = true;
                                                                bool temper = true;
                                                                if(i == e || i == w || i == u || i == h || i == q || e == i || e == w || e == u || e == h || e == q || w == i || w == e || w == u || w == h || w == q || u == i || u == w || u == e || u ==h || u == q || h == i || h == w || h == e || u == h || h == q || q == i || q == w || q == e || q == h || u == q)
                                                                    temper = false;
                                                                if(nexter && str.length() == 4 && yes && temper){
                                                                    cout << nexter+next3+next2+next1+next+oct[i] << endl;
                                                                    cout << nexter << " " << next3<< " " << next2<< " " << next1<< " " << next<< " " << oct[i] << endl;
                                                                }
                                                            }
                                                            check[e] = 0;
                                                        }
                                                    }
                                                }
                                                check[w] = 0;
                                            }
                                        }
                                    }
                                    check[u] = 0;
                                }
                            }
                        }
                        check[q] = 0;
                    }
                }
            }
            check[h] = 0;
        }
    }
	/*for(long long int i=0;i<octn.size();++i){
        int s1 = octn[i]%100;
        for(int j=0;j<trin.size();++j){
            if(trin[j]/100 == s1){
                int s2 = trin[j]%100;
                for(int k=0;k<sqn.size();++k){
                    if(sqn[k]/100 == s2){
                        int s3 = sqn[k]%100;
                        for(int u=0;u<pentn.size();++u){
                            if(pentn[u]/100 == s3){
                                int s4 = pentn[u]%100;
                                for(int o=0;o<hexn.size();++o){
                                    if(hexn[o]/100 == s4){
                                        int s5 = hexn[o]%100;
                                        for(int q=0;q<heptn.size();++q){
                                            if(heptn[q]/100 == s5){
                                                if(heptn[q]%100 == octn[i]/100)
                                                    cout << heptn[q]+octn[i]+trin[j]+pentn[u]+sqn[k]+hexn[o] << endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
	}*/
	/*for(long long int i=1;i<500;++i){
        stringstream ss;
        ss << oct[i];
        numbers.clear();
        string num = ss.str();
        if(num.length()!=4)
            continue;
        numbers.push_back(oct[i]);
        vector<long long int>::iterator it;
        /*
        do{
            long long int finder;
            stringstream sat(num);
            sat >> finder;
            vector<long long int>::iterator it;
            it = find(tri.begin(),tri.end(),finder);
            if(it != tri.end()){
                    numbers.push_back(*it);
            }
            it = find(sq.begin(),sq.end(),finder);
            if(it != sq.end()){
                    numbers.push_back(*it);
            }
            it = find(pent.begin(),pent.end(),finder);
            if(it != pent.end()){
                    numbers.push_back(*it);
            }
            it = find(hex.begin(),hex.end(),finder);
            if(it != hex.end()){
                    numbers.push_back(*it);
            }
            it = find(hept.begin(),hept.end(),finder);
            if(it != hept.end()){
                    numbers.push_back(*it);
            }
        }while(next_permutation(num.begin(),num.begin()+4));
        */
        /*if(numbers.size()>=2){
            "Counter : " <<
            for(int i=0;i<numbers.size();++i)
                numbers[i] << " ";

        }
	}*/
	return 0;
}
