#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

int IndexOfFirstSpace(std::string &input){
    int index = -1;
    // find the first space character in the loop
    for(int i = 0; i < input.size(); i++){
        if(input.at(i) == ' '){
            index = i;
            break;
        }
    }
    return index;
}

void SeparateFirstAndLastNames(std::string &full_name, std::string &first_name,
                               std::string &last_name){
    //full_name is empty
    if(full_name.empty()){
        first_name = "";
        last_name = "";
    }
    int spa_index = IndexOfFirstSpace(full_name); 
    //no space or the first space is the last character of the full name
    if(spa_index == -1 || spa_index == full_name.size() - 1){
        last_name = "";
        first_name = full_name;
    }else{
        first_name = full_name.substr(0, spa_index);
        last_name = full_name.substr(spa_index + 1);
    }
}

std::vector<std::string> SplitString(const std::string &str){
    int start = 0, end = 0;
    std::vector<std::string> result;
    while(end < str.size()){
        //find a space
        if(str.at(end) == ' '){
            //Prevent consecutive Spaces and the first character is space
            if(start == end){
                start++;
            }else{
                //Intercepts the string between two Spaces
                result.push_back(str.substr(start, end - start));
                start = end + 1;
            }
        }
        end++;
    }
    //prevent the last character is space
    if(start != end){
        result.push_back(str.substr(start, end - start));
    }
    return result;
}

std::map<std::string, int> CalculateFrequency(const std::string &input){
    std::map<std::string, int> result;
    //get all the words
    std::vector<std::string> words = SplitString(input);
    // calculate each word's frequency
    for(std::string word : words){
        auto it = result.find(word);
        if(it != result.end()){
            result[word]++;
        }else{
            result.insert(std::pair(word,1));
        }
    }
    return result;
}