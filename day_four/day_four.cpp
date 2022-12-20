

#include <fstream>
#include <string>
#include <iostream>
#include <set>

using namespace std;


pair<string,string> split_string (const string & line, const char & char_split){

    int pos = line.find(char_split);
    return {line.substr(0,pos),line.substr(pos+1)};
}

bool count_copy(const string & line){
    pair<string, string> split = split_string(line, ',');
    pair<string,string> left_nums = split_string(split.first, '-');
    pair<string,string> right_nums = split_string(split.second, '-');
    
    bool first_less = (stoi(left_nums.first) <= stoi(right_nums.first));
    bool first_greater = (stoi(left_nums.second) >= stoi(right_nums.second));

    bool second_less = ( stoi(right_nums.first) <= stoi(left_nums.first));
    bool second_greater = (stoi(right_nums.second)  >= stoi(left_nums.second));

    return (first_less && first_greater) || (second_less && second_greater);


}

bool overlap_count(const string & line){
    pair<string, string> split = split_string(line, ',');
    pair<string,string> left_nums = split_string(split.first, '-');
    pair<string,string> right_nums = split_string(split.second, '-');
    
     bool first_in = ((stoi(left_nums.first) >= stoi(right_nums.first)) && 
       (stoi(left_nums.first) <= stoi(right_nums.second)) );

    bool second_in = ((stoi(right_nums.first) >= stoi(left_nums.first)) && 
       (stoi(right_nums.first) <= stoi(left_nums.second)) );
    return (first_in || second_in);

}

int main(){
    fstream input_txt("day_four_input.txt");
    string line;
    int sum = 0;
    //part 1;
    while(input_txt >> line){
        sum += count_copy(line);
    }

    cout << sum << "\n";
    sum = 0;
    //part 2
    input_txt = fstream("day_four_input.txt");
     while(input_txt >> line){
        sum += overlap_count(line);
    }
    cout << sum << "\n";

}