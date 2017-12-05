#include <iostream>
#include <string>

const int argc_max  = 8*2 + 1; // the max number of parameters
const int argc_min  = 4*2 + 1; // the min number of parameters
const int param_num = 8;       // number of structure 'parameters' attributes
const int nec_num   = 3;       // number of necessary parameters

std::string possible_parameters[] = {"--double1", "--double2", "--int1", "--int2", "--string1", "--string2", "--flag1", "--flag2"};

struct parameters
{
    double      double1; //necessary
    double      double2; //optional
    int         int1; //necessary
    int         int2; //optional
    std::string string1; //necessary
    std::string string2; //optional
    bool        bool1; //optional
    bool        bool2; //optional
    parameters(): double1(0), double2(0), int1(0), int2(0), string1(""), string2(""), bool1(false), bool2(false){};
};

//todo parameters types checks

int main(int argc, char *argv[])
{
    if (argc < argc_min || argc > argc_max) // to avoid getting too many or too few parameters
    {
        std::cout<<"bad parameter's number\n";
        return -1;
    }

    struct parameters my_param; // is used to keep recieved values
    bool necessary[nec_num] = {false}; // double1 , int1, string1

    for (int i = 1; i < argc; i++) // here cmd_params analyzing starts
    {
        if (argv[i] == possible_parameters[0])
            {
                my_param.double1 = atof(argv[i+1]);
                necessary[0] = true;
                continue; // not structural but still well readable
            }
        else if (argv[i] == possible_parameters[1])
            {
                my_param.double2 = atof(argv[i+1]);
                continue;
            }
        else if (argv[i] == possible_parameters[2])
            {
                my_param.int1 = atoi(argv[i+1]);
                necessary[1]  = true;
                continue;
            }
        else if (argv[i] == possible_parameters[3])
            {
                my_param.int2    = atoi(argv[i+1]);
                continue;
            }
        else if (argv[i] == possible_parameters[4])
        {
                my_param.string1 = std::string(argv[i+1]);
                necessary[2] = true;
                continue;
        }
        else if (argv[i] == possible_parameters[5])
            {
                my_param.string1 = std::string(argv[i+1]);
                continue;
            }
        else if (argv[i] == possible_parameters[6])
            {
                my_param.bool1 = true;
                continue;
            }
        else if (argv[i] == possible_parameters[7])
            {
                my_param.bool2 = true;
                continue;
            }
        else // we got unknown parameter's name
        {
            std::cout<<"bad parameter \'"<<argv[i]<<'\''<<std::endl;
            return -1;
        }
    }

    // check whether there all of the necessary parameters
    // todo: provide a user additional info about missing parameters
    for (int i = 0; i < nec_num; i++)
    {
        if (!necessary[i])
        {
            std::cout<<"no necessary parameter(s)\nrefer user's tutorial";
            return -2;
        }
    }

    std::cin>>argc;
    return 0;
}
