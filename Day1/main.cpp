#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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

int main()
{
    string file_name = "input_1.txt";

    vector<string> text = parse_input(file_name);

    if (text.empty())
    {
        return 1;
    }

    vector<string> first_column;
    vector<string> second_column;

    for (auto &line : text)
    {
        int pos = line.find(" ");

        first_column.push_back(line.substr(0, pos));
        second_column.push_back(line.substr(pos + 1));
    }

    sort(first_column.begin(), first_column.end());
    sort(second_column.begin(), second_column.end());

    // I will assume that every line has the same length,
    // so I can traverse the first column to get the result
    int result = 0;

    for (int i = 0; i < first_column.size(); i++)
    {
        int first = stoi(first_column[i]);
        int second = stoi(second_column[i]);

        result += abs(first - second);
    }

    cout << "Result: " << result << endl;

    return 0;
}
