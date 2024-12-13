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

bool check_report_safe(vector<int> report)
{
    if (report.size() == 2)
    {
        int first = report[0];
        int second = report[1];

        bool is_between_one_and_three = abs(first - second) <= 3;

        return first != second && is_between_one_and_three;
    }

    int first = report[0];
    int second = report[1];

    bool is_asceding = first < second;

    for (int i = 0; i < report.size() - 1; i++)
    {
        int current = report[i];
        int next = report[i + 1];

        if (abs(current - next) > 3)
        {
            return false;
        }

        if (!(is_asceding && current < next || !is_asceding && current > next))
        {
            return false;
        }
    }

    return true;
}

int second_problem(vector<string> input)
{
    int valid_reports = 0;

    for (auto &line : input)
    {
        string report_line = line;
        stringstream ss(report_line);

        vector<int> report;

        while (getline(ss, report_line, ' '))
        {
            report.push_back(stoi(report_line));
        }

        // First try, if the report is already safe
        if (check_report_safe(report))
        {
            valid_reports += 1;
            continue;
        }

        // Second try, if the report is safe after removing one element
        int size_minus_one_level = report.size();
        int i = 0;
        while (i < size_minus_one_level)
        {
            vector<int> report_minus_one = report;
            report_minus_one.erase(report_minus_one.begin() + i);

            if (check_report_safe(report_minus_one))
            {
                valid_reports += 1;
                break;
            }
            i++;
        }
    }

    return valid_reports;
}

int first_problem(vector<string> input)
{
    int valid_reports = 0;

    for (auto &line : input)
    {
        string report_line = line;
        stringstream ss(report_line);

        vector<int> report;

        while (getline(ss, report_line, ' '))
        {
            report.push_back(stoi(report_line));
        }

        if (check_report_safe(report))
        {
            valid_reports += 1;
        }
    }

    return valid_reports;
}

int main()
{
    string file_name = "input_1.txt";

    vector<string> input = parse_input(file_name);
    cout << first_problem(input) << endl;
    cout << second_problem(input) << endl;

    return 0;
}