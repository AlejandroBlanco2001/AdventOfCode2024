#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <typeinfo>
#include <bits/stdc++.h>

using namespace std;

vector<string> parse_input(string file_name)
{
    ifstream input_stream(file_name);

    if (!input_stream)
    {
        cerr << "Error opening file" << endl;
        return {};
    }

    vector<string> text;

    string line;

    while (getline(input_stream, line))
    {
        text.push_back(line);
    }

    input_stream.close();

    return text;
}

bool check_report_safe(vector<string> report){
    if(report.size() == 2){
        int first = stoi(report[0]);
        int second = stoi(report[1]);

        bool is_between_one_and_three = abs(first - second) <= 3;
        
        return first != second && is_between_one_and_three;
    }

    int first = stoi(report[0]);
    int second = stoi(report[1]);

    bool is_asceding = first < second;

    for(int i = 0; i < report.size() - 1; i++){
        int current = stoi(report[i]);
        int next = stoi(report[i + 1]);

        if(abs(current - next) > 3){
            return false;
        }

        if(!(is_asceding && current < next || !is_asceding && current > next)){
            return false;
        }
    }

    return true;
}

int first_problem(vector<string> input){
    int valid_reports = 0;

    for (auto &line : input)
    {
        string report_line = line;
        stringstream ss(report_line);

        vector<string> report;

        while(getline(ss, report_line, ' ')) {
            report.push_back(report_line);
        }

        if(check_report_safe(report)){
            valid_reports += 1;
        }

    }

    return valid_reports;
}

int main(){
    vector<string> input = parse_input("input_1.txt");
    cout << first_problem(input) << endl;
    return 0;
}