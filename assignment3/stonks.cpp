// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include<map>
#include <algorithm>
using namespace std;
/*
tmp save the first trade
insum save the invest sum
outsum save the output sum
Sample Input 1 Sample Output 1
3
3 5
1 2
4 2
               2 3
Sample Input 2 Sample Output 2
3
2 1
5 5
12 2
               0 0
Sample Input 3 Sample Output 3
4
5 10
3 7
10 7
1 3
               1 11
*/

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)


int main(){
	ll length;
	cin>>length;
	ll len=0;
	ll a,b;
	vector<pair<ll,ll>> v;
	while(len!=length){
		cin>>a>>b;
		if(b>a){
			pair<ll,ll> p(a,b);
		    v.push_back(p);
		}
		
		len++;
	}
	sort(v.begin(),v.end());
	ll balance =0;
	//minimum is the max number of ll
	ll minimum=numeric_limits<ll>::max();
	for(auto t:v){
		balance-=t.first;
		minimum=min(minimum,balance);
		balance+=t.second;
	}
	if(v.size()==0){
		cout<<"0 0"<<endl;
	}
	else{
		cout<<-minimum<<" "<<balance<<endl;
	}
	return 0; 
}
/*
int main() {
  long length;
  char c; 
     while((c=cin.get())!='\n')
  {
      cin.unget();
      cin>>length;
  }
  vector<long long> a(length),b(length);
  string s;
  long len=0;

  while(len!=length){
    cin>>a[len]>>b[len];
    len++;
  }
  long long outsum=0;

  multimap <long long, long long> map;
  for(long i=0;i<length;++i){
  	pair<long long,long long> p(a[i],b[i]);
	map.insert(p); 
  }
  long long insum=0;
  multimap<long long,long long>::iterator iter;
//  cout<<insum<<endl;
  long long accum=0;
  long long tmp=-1;
  for(iter=map.begin();iter!=map.end();iter++){
 	if(iter->second-iter->first<=0){
 		continue;
	 }
	 outsum+=(iter->second-iter->first);
//	 cout<<outsum<<endl;
	 if(tmp==-1){
 		tmp=iter->second;
 		insum=iter->first;
	 }
	 else{
	 	if(accum+tmp-iter->first>=0){
	 		accum+=tmp-iter->first;
		 }
		 else{
		 	insum+=iter->first-tmp-accum;
		 }
		 tmp=iter->second;
	 }
	 
  }
  if(outsum!=0){
  	cout<<insum<<" "<<outsum;
  }
  else{
  	cout<<outsum<<" "<<outsum;
  }
   return 0;
  	} 
*/

