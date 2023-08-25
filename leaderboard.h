#pragma once
#include <string>
using namespace std;

struct LeaderBoard{
    string User;
    string Time;
    LeaderBoard(){}
    LeaderBoard(string user_, string time_){
        User = user_;
        Time = time_;
    }
};
