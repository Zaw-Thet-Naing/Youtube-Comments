#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Video {
    string link;
    string title;                                       // struct to define video information
    string comments;
};

vector<Video> fetchVideos(const string& filename){
    ifstream inputFile(filename);                       // vector store videos acquired from input txt file
    vector<Video> videos;
}

if (!inputFile){
    throw runtime_error("Could not open file!");        // throws a runtime error if file is failed to open
}
