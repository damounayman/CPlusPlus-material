#include <iostream>
#include <vector>
#include <sstream>
#include <string>


using namespace std;


int main(){
    string str("1,2,3,");
    vector<int> vec{-1,0};
    istringstream my_stream(str);
    char c;
    int n;

    while (my_stream>>n>>c)
    {
        vec.push_back(n);
    }
    cout << "stream has stopped"<< endl;

    for(int i:vec){
        cout<<i<<"\n";
    }

}