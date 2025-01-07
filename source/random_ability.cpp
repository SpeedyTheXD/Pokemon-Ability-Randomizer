#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 500;

void update_ability_file()
{
    // string exe_path = filesystem::current_path().string();
    // string python_path = exe_path + "/source/ability_updater.py";
    // string command = "python \"" + python_path + "\"";
    // system(command.c_str());     *This method is for trying to change exe file location*

    system("python ability_updater.py");
}

void save_ability(string file_name, vector<string> &list)
{
    ifstream in_file(file_name);
    string line;
    int line_pos = 0;

    while (getline(in_file, line))
    {
        string word;

        word = line.substr(0, line.find(':'));
        list.push_back(word);

        word.clear();
        line_pos++;
    }

    in_file.close();
}

void print_string_list(const vector<string> &list, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << list[i] << endl;
    }
}

void print_random_ability(const vector<string> &list, int length)
{
    int random_index = rand() % length;
    cout << "Your pokemon's random ability is: " << list[random_index] << endl;
}

int main()
{
    update_ability_file();
    string file = "../data/ability.txt";

    srand(time(0));
    vector<string> ability_list;
    save_ability(file, ability_list);
    int length = ability_list.size();

    char enter_key;
    do
    {
        string enter;
        cout << "\nPress enter to generate random ability: ";
        enter_key = cin.get();

        if (enter_key == '\n')
        {
            print_random_ability(ability_list, length);
        }

    } while (true);

    return 0;
}