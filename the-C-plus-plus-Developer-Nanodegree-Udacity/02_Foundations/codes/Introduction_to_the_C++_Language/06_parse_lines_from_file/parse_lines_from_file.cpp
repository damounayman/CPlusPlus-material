#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> readFile(string path){

    ifstream file(path);
    vector<vector<int>> container_vec {};

    if(file){
        string line;
        while (getline(file,line))
        {
            istringstream string_line(line);
            int n;
            char c;
            vector<int> temp_vec{};
            while(string_line>>n>>c){
                temp_vec.push_back(n);
            }
            container_vec.push_back(temp_vec);
        }
    }
    return container_vec;    


}


void printFile(const vector<vector<int>> dd_vector){
    // prints the 2D vector passed by iterating over each row
    // and then each column in the row
    for(vector<int> d_vector: dd_vector){
        for(int col: d_vector){
            cout << col << ",";
        }
        cout << "\n";
    }
}


int main(){

    printFile(readFile("../../board.csv"));

}