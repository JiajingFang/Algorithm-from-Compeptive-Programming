#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
/*
If, among the n given numbers, there are three that sum to 42, print them in any order. The three numbers must be
distinct. If there are multiple solutions, print any of them. If there are no such three integers, print impossible.

Sample Input 1 Sample Output 1
4
21 15 10 11
                21 10 11
Sample Input 2 Sample Output 2
5
1 2 3 4 5
                impossible
Sample Input 3 Sample Output 3
5
47 -1 -2 -3 -4
                 47 -1 -4
*/


int main()
{
  long long length;
  long long i=0;
  char c;
  //get array
   while((c=cin.get())!='\n')
  {
      cin.unget();
      cin>>length;
  }
  if(length<3){
    cout<<"impossible"<<"\n";
    return 0;
  }
  long long array[length];
  while(i<length)
  {
      cin>>array[i];
      i++;
  }

    for(long long i=0;i<length;i++){
    for(long long j=0;j<length-i-1;j++){
       if(array[j+1]<array[j]){
        long long t=array[j];
        array[j]=array[j+1];
        array[j+1]=t;
       }
    }
  }
  
 //find 3 numbers 
for(long long i=0;i<length-2;i++){
     long long a=i+1;
     long long b=length-1;
     while(a<b){
      if(array[i]+array[a]+array[b]==42){
        cout<<array[i]<<" "<<array[a]<<" "<<array[b]<<"\n";
        return 0;
      }
      else if(array[i]+array[a]+array[b]<42){
        a++;
      }
      else{
        b--;
      }
     }
      }
    cout<<"impossible"<<"\n";
    return 0;
     }
