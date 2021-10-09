#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n , q;
    cin >> n >> q;
    cin.ignore();
    vector<vector<int>> a(n);

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin,line);
        istringstream line_input(line);
        int array_size;
        line_input >> array_size;
        vector <int> array(array_size,0);
        for (int j = 0; j < array_size; j++)
        {
           line_input>>array[j];
        }
        a[i]=array;
    }

    for (int i = 0; i < q; i++)
    {
        string query;
        getline(cin,query);
        istringstream thequery(query);
        int x , y;
        thequery>>x>>y;
        cout<<a.at(x).at(y)<<endl;
    }
    
    return 0;
}