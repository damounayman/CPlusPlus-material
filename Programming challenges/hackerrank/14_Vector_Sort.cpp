#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    vector<int> V(N, 0);
    int x;

    for (size_t i = 0; i < N; i++)
    {
       cin >> V[i];
    }
    sort(V.begin(), V.end());
    for(int i = 0; i < N; i++) 
    {
        cout << V[i] << " ";
    }
    /* Vector-Sort in C++ - Hacker Rank Solution End */
    


    return 0;
}
