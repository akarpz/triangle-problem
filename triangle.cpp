#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

vector<int> convert(string line){
    string buf;
    stringstream ss(line);

    vector<int> result;

    while (ss >> buf)
        result.push_back(stoi(buf));
    return result;
}

vector<vector<int> > loading(){
    vector<vector<int> > result;
    string line;
    ifstream in ("triangle.txt");
    
    while(getline(in,line)){
        result.push_back(convert(line));
    }
    return result;
}

void generateMaxPath(vector<vector<int> > triangle){
    for(int i = triangle.size()-1; i > 0; i--){
        for(int j=0; j < triangle.at(i).size()-1; j++){
            triangle.at(i-1).at(j) += max(triangle.at(i).at(j),triangle.at(i).at(j+1));
        }
    }
    cout << triangle[0][0] << endl;
}

int main(){
    vector<vector<int> > triangle;
    triangle = loading();
    generateMaxPath(triangle);
    
    return 0;
}






/*for(int i=0;i<triangle.size();i++){
        for(int j=0;j<triangle.at(i).size();j++){
            cout << triangle.at(i).at(j) << endl;
        }
    }*/




