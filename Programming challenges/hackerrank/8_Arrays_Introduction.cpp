#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    int arr[N];

    for (size_t i = 0; i < N; i++)
    {
        cin>>arr[i];
    }
    for (size_t i = 0; i < N; i++)
    {
        cout<<arr[N-1-i]<<" ";
    }
    
    
    return 0;
}

