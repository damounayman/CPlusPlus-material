#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    vector <int> myvect(N,0);
    for (size_t i = 0; i < N; i++)
    {
        cin >> myvect[i];
    }
    int q1;
    vector <int> q2(2,0);
    cin>>q1;
    cin>>q2[0]>>q2[1];
    
    myvect.erase(myvect.begin()+q1); 

    myvect.erase(myvect.begin()+q2[0]-1,myvect.begin()+q2[1]-1);

    cout<<myvect.size()<<endl;
    for (size_t i = 0; i < myvect.size(); i++)
    {
        cout << myvect[i]<<" ";
    }



    return 0;
}
