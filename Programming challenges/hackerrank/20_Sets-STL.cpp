#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int Q; 
    cin >> Q;
    vector <int> types(Q,0);
    vector <int> elements(Q,0);
    set<int>s;
    for (size_t i = 0; i < Q; i++)
    {
        /* code */
        cin >> types[i];
        cin >> elements[i];
    }

    for (size_t i = 0; i < Q; i++)
    {
        /* code */
        switch (types[i])
        {
        case 1:
            s.insert(elements[i]);
            break;
        
        case 2:
            s.erase(elements[i]);
            break;
        case 3:
            set<int>::iterator itr=s.find(elements[i]);
            if(itr==s.end()){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
            break;
        }
    }
    


    
    return 0;
}



