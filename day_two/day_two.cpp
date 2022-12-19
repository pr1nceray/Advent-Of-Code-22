
#include <vector>
#include "iostream"
#include "fstream"
#include <string>
#include <map>
using namespace std;

int main(){

    map<string, int> score_map;
    score_map["Y"] = 2;
    score_map["X"] = 1;
    score_map["Z"] = 3;
    
    score_map["A"] = 1;
    score_map["B"] = 2;
    score_map["C"] = 3;
    fstream input_txt("day_two_input.txt");

    string char_in;
    int total_sum = 0;
    //part one;
    while(input_txt >> char_in){
        string player_input;
        input_txt >> player_input;
        total_sum += score_map[player_input];
        
        if(score_map[player_input] == score_map[char_in]){
            total_sum += 3;
        }
        else if(score_map[player_input]%2 == score_map[char_in]%2){
            total_sum += (player_input == "X")?6:0; 
        }
        else{
            total_sum += (score_map[player_input] > score_map[char_in])?6:0;
        }

    }

    cout << total_sum << "\n";
    total_sum = 0;
    //part two; 
    fstream input_txt_2("day_two_input.txt");
    map<string, int> score_map_2;
    score_map_2["A"] = 3;
    score_map_2["B"] = 1;
    score_map_2["C"] = 2;

    score_map_2["AL"] = 2;
    score_map_2["BL"] = 3;
    score_map_2["CL"] = 1;

    //part one;
    while(input_txt_2 >> char_in){
        string player_input;
        input_txt_2 >> player_input;

        //switch statement better?
        if(player_input == "Y"){
            total_sum += (3 + score_map[char_in]); 
        } 
        else if(player_input == "X"){
            total_sum += (0 + score_map_2[char_in]); 
        } 
        else{
            total_sum += (6 + score_map_2[char_in.append("L")]); 
        }
    }
    cout << total_sum;

}