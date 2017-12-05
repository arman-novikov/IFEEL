argc_max  = 8*2 + 1; #the max number of parameters
argc_min  = 4*2 + 1; #the min number of parameters
param_num = 8;       #number of structure 'parameters' attributes
nec_num   = 3;       #number of necessary parameters

possible_parameters = ["--double1", "--double2", "--int1", "--int2", "--string1", "--string2", "--flag1", "--flag2"];

class Parameters:
    double1 = 0.0   #necessary
    double2 = 0.0   #optional
    int1    = 0     #necessary
    int2    = 0     #optional
    string1 = ""    #necessary
    string2 = ""    #optional
    bool1   = False #optional
    bool2   = False #optional

# todo parameters types checks

def main(argc, *argv):
    if argc < argc_min or argc > argc_max: # to avoid getting too many or too few parameters
        print ("bad parameter's number")
        return -1

    MyParam = Parameters() # is used to keep recieved values
    necessary = [False, False, False,] # double1 , int1, string1

    for i in range(1, argc): #here cmd_params analyzing starts
        if argv[i] == possible_parameters[0]:
            MyParam.double1 = float(argv[i+1])
            necessary[0] = True
            continue    # not structural but still well readable
        elif argv[i] == possible_parameters[1]:
            MyParam.double2 = float(argv[i + 1])
            continue
        elif argv[i] == possible_parameters[2]:
            MyParam.int1 = int(argv[i + 1])
            necessary[1] = True
            continue
        elif argv[i] == possible_parameters[3]:
            MyParam.int2 = int(argv[i + 1])
            continue
        elif argv[i] == possible_parameters[4]:
            MyParam.string1 = argv[i + 1]
            necessary[2] = True
            continue
        elif argv[i] == possible_parameters[5]:
            MyParam.string2 = argv[i + 1]
            continue
        elif argv[i] == possible_parameters[6]:
            MyParam.bool1 = True
            continue
        elif argv[i] == possible_parameters[6]:
            MyParam.bool2 = True
            continue

        #check whether there all of the necessary parameters
        # todo: provide a user additional info about missing parameters
        for i in necessary:
            if i == False:
                print("no necessary parameter(s)\nrefer user's tutorial")
                return -2
        return 0