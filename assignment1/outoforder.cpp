#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>  
#include <vector>
using namespace std;
/*
If there are two stamps such that swapping them yields a sorted collection, print their two positions in any order.
Otherwise, print impossible.
Sample Input 1 Sample Output 1
5          
1 2 5 3 3
                      3 5
Sample Input 2 Sample Output 2
5
5 4 3 2 1
                 impossible


*/
int main()
{
  long long length;
  long long i=0;
  char c;
  //get length
   while((c=cin.get())!='\n')
  {
      cin.unget();
      cin>>length;
  }
  //input vector

   vector<int> vec(length);

   vector<int> vec1(length);

  while(i<length)
  {
      cin>>vec[i];
      vec1[i]=vec[i];
      i++;
  }
  //sort and input to a new vector
  sort (vec1.begin(), vec1.end());

      //verify
      long long k=0,a=0,b=0;
      for(long long i=0;i<length;i++)
      {

          if(vec1[i]!=vec[i])
          {
            k++;
            if(k==1){
              a=i+1;
            }
            else{
              b=i+1;
            }
            }
      }
      if(k<2||k>=3){
        cout<<"impossible"<<"\n";
      }
      if(k==2){
       cout<<a<<" "<<b;
      }
}









