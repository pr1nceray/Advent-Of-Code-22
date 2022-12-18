

#include <fstream>
#include <string>
#include <iostream>
#include <set>

using namespace std;


int char_to_val(const char & char1){
    bool capital = (int(char1) <= 91);  
    int pos = (int(char1) - 64); //order here is flipped! upper case needs to be weighted higher, not lower
    int pos2 = (int(char1) - 96);
    return capital?(pos += 26):pos2;
}
int get_priority(const string & str1, const string & str2){
    set<char> cur_set;
    for(int i = 0; i < str1.size();i++){
        cur_set.insert(str1[i]);
    }
    
    for(int i = 0; i < str2.size();i++){
        if(cur_set.find(str2[i]) != cur_set.end()){
            return char_to_val(str2[i]);
        }
    }
    return 0;
}

int get_priority(const string & str1, const string & str2, const string & str3){
    set<char> cur_set;
    for(int i = 0; i < str1.size();i++){
        cur_set.insert(str1[i]);
    }

    set<char> cur_set_2;
    for(int i = 0; i < str2.size();i++){
        cur_set_2.insert(str2[i]);
    }

    for(int i = 0; i < str3.size();i++){
        if(cur_set.find(str3[i]) != cur_set.end() && cur_set_2.find(str3[i]) != cur_set_2.end()){
            return char_to_val(str3[i]);
        }
    }
    return 0;

}
int main(){

    fstream input_txt("day_three_input.txt");


    string sack;
    int total = 0;


    //part 1
    while(input_txt >> sack){
        
        int size = sack.size();
        total+= get_priority(sack.substr(0,size/2), sack.substr(size/2,size));
    }

    cout << total << "\n";


    //part 2
    input_txt = fstream("day_three_input.txt");

    string sack1;
    string sack2;
    string sack3;
    total = 0;
    while(input_txt >> sack1){
        input_txt >> sack2;
        input_txt >> sack3;
        total+= get_priority(sack1,sack2,sack3);
    }

    cout << total << "\n";
}