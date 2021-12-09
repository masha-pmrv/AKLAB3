#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int START_INDEX = 1;

bool is_single_arg(string arg)
{
    if (arg.size() == 2 && arg[0] == '-' && arg[1] != '-')
    {
        return true;
    }

    return false;
}

bool is_double_arg(string arg)
{
    if (arg.size() > 2 && arg[0] == '-' && arg[1] == '-' && arg[2] != '-')
    {
        return true;
    }
    return false;
}

bool in(string arg, vector<string> vc, int start_index) {
    for (int i = start_index; i < vc.size(); i++)
    {
        if (vc[i] == arg)
        {
            return true;
        }
        if (is_single_arg(arg) && vc[i][1] == arg[0] && vc[i][2] == arg[1])
        {
            return true;
        }
        if (is_double_arg(arg) && vc[i][0] == arg[1] && vc[i][1] == arg[2])
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
 {
    vector<string> vc;
    for (int i = 0; i < argc; i++)
    {   
        string arg(argv[i]);
        vc.push_back(arg);
    }

    vector<string> newVector;
    for (int i = START_INDEX; i < vc.size(); i++)
    {
        string arg(vc[i]);

        if (is_single_arg(arg))
        {   
            if (!in(arg, vc, i + 1))
            {
                cout << arg << endl;
            }            
        } else if (is_double_arg(arg)) {
            if (!in(arg, vc, i + 1))
            {
                cout << arg << endl;; 
            }      
        } else {
            cout << "invalid argument: " << arg << endl;
        }
    }
    
    return 0;
}