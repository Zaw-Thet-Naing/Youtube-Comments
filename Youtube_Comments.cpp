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


if (!inputFile){
    throw runtime_error("Could not open file!");        // throws a runtime error if file is failed to open
}

string line;
while (getline(inputFile, line)){
    if (line.empty())                                   // reads very line, skips if line is empty
    continue;

    size_t firstQuotation = line.find('"');
    size_t secondQuotation = line.find('"', firstQuotation + 1);
    size_t thirdQuotation = line.find('"', secondQuotation + 1);            // finds the four quotation marks in each line
    size_t fourthQuotation = line.find('"', thirdQuotation + 1);
    size_t find_Comments = line.find("Comments:");

    if (firstQuotation == string::npos || secondQuotation == string::npos || thirdQuotation == string::npos || fourthQuotation == string::npos){
        continue;           //skips if one quotation mark is not found
    }

    Video video;
    video.link = line.substr(firstQuotation, secondQuotation - firstQuotation + 1);
    video.title = line.substr(thirdQuotation, fourthQuotation - thirdQuotation + 1);    // extracts video link and video title 

    string findComment;
    if(getline(inputFile,findComment)){
        string c = "Comments: ";                    // find comments line, extracts it and stores into the vector
        if(findComment.rfind(c,0) == 0){                
            video.comments = findComment.substr(c.size());
        }
    }

    videos.push_back(video);    //stores the extracted information into the vector
}

return videos;

}
