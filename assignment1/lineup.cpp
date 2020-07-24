#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
/*
Print x, the maximum of the sum of player strengths over all possible lineups.
Sample Input 1                      Sample Output 1
100 0 0 0 0 0 0 0 0 0 0
0 80 70 70 60 0 0 0 0 0 0
0 40 90 90 40 0 0 0 0 0 0
0 40 85 85 33 0 0 0 0 0 0
0 70 60 60 85 0 0 0 0 0 0
0 0 0 0 0 95 70 60 60 0 0
0 45 0 0 0 80 90 50 70 0 0
0 0 0 0 0 40 90 90 40 70 0
0 0 0 0 0 0 50 70 85 50 0
0 0 0 0 0 0 66 60 0 80 80
0 0 0 0 0 0 50 50 0 90 88
                                       970
*/


int main()
{
 int n=11;
 vector<vector<ll>> scores(n,vector<ll>(n));
 for(auto& v:scores){
 	for(ll& l:v)
 	  cin>>l;
 } 
 vector<int> permutation(n);
 //fill permutation vector with 0 1 2..10
 iota(permutation.begin(),permutation.end(),0);

 ll maxm=0;
 do{
 
   ll sum=0;
   for(int i=0;i<n;i++){
   	sum+=scores[i][permutation[i]];
   }
   maxm=max(maxm,sum);
 }while(next_permutation(permutation.begin(),permutation.end()));
 
 cout<<maxm<<endl;
    return 0;
     }


