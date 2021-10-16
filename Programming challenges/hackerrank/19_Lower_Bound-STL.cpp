#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
   int N;
   int Q;
   cin >>N;
   vector <int> Vect(N);
   for (size_t i = 0; i < N; i++)
   {
       cin>> Vect[i];
   }

   cin >>Q;
   vector <int> query(Q);
   for (size_t i = 0; i < Q; i++)
   {
       cin >> query[i];
   }

   vector<int>::iterator low;
   for (size_t i = 0; i < Q; i++)
   {
        low=lower_bound (Vect.begin(), Vect.end(), query[i]);
        if (Vect[low - Vect.begin()] == query[i])
       {
           cout << "Yes " << (low - Vect.begin() + 1) << endl;
       }
       else
       {
           cout << "No " << (low - Vect.begin() + 1) << endl;
       }
   }

 return 0;
}