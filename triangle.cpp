#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int getPathValue(vector<int> path){
    int result = 0;
    for(int i: path){
        result += i;
    }    
    return result;
}

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
    ifstream in ("small.txt");
    
    while(getline(in,line)){
        result.push_back(convert(line));
    }
    return result;
}

int main(){
    vector<vector<int> > triangle;
    triangle = loading();
    
    for(int i=0;i<triangle.size();i++){
        for(int j=0;j<triangle.at(i).size();j++){
            cout << triangle.at(i).at(j) << endl;
        }
    }
    return 0;
}




