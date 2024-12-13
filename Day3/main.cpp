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

int first_problem(vector<string> input)
{
    regex pattern("mul\\(\\d+,\\d+\\)");
    int result = 0;

    for (auto &line : input)
    {
        smatch match;

        while (regex_search(line, match, pattern))
        {
            string numbers_str = match[0].str();

            regex number_pattern("\\d+");
            smatch number_match;

            vector<int> numbers;

            while (regex_search(numbers_str, number_match, number_pattern))
            {
                numbers.push_back(stoi(number_match[0].str()));
                numbers_str = number_match.suffix().str();
            }

            result += numbers[0] * numbers[1];

            line = match.suffix().str();
        }
    }

    return result;
}

int main()
{
    string file_name = "input_1.txt";

    vector<string> input = parse_input(file_name);
    cout << first_problem(input) << endl;

    return 0;
}