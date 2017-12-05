#include <iostream>

int del(int v_size)
{
    if (v_size <= 2) return 1; // check correctness of the size
    if (v_size == 3) return 2;

    int denumerator(v_size / 2); // denumerator can't be more than half to divide with zero remainder
    int remainder(0); // current remainder

    while (denumerator>1)
    {
        remainder = v_size % denumerator;
        if(remainder == 0)
        {
            return denumerator;
        }
        else
        {
            --denumerator;
        }
    }
    return 2;
}

void testing()
{
    int testing_vectors_size[] = {29, 25, 2, 1, 180, 5, 0,3,2 };
    int the_size = sizeof(testing_vectors_size)/sizeof(int);


    for (int i = 0; i < the_size; i++)
    {
        if (testing_vectors_size[i] <= 1 ) { std::cout<<"(0)\n"; continue; }

        int delim = del(testing_vectors_size[i]);
        std::cout<<delim<<": ";

        for(int n = 0; n < testing_vectors_size[i]/delim - 1; n++)
        {
            std::cout<<'('<<n*delim<<','<<(n+1)*delim-1<<"), ";

        }

        int rem = testing_vectors_size[i]%delim;
        int tail = testing_vectors_size[i]-delim;

        if (rem == 0)
        {
            std::cout<<'('<<tail<<','<<testing_vectors_size[i]-1<<')';
        }
        else
        {
            std::cout<<'('<<tail-1<<','<<testing_vectors_size[i]-2<<"), ";
            std::cout<<'('<<testing_vectors_size[i]-1<<')';
        }
        std::cout<<'\n';

    }
    return;
}

int main()
{
    int N;
    std::cout<<"input vector's size: ";
    std::cin>>N;

    if (N<=2)
    {
        std::cout<<"incorrect values\n";
        return -1;
    }

    int delim = del(N); // the max denumerator
    std::cout<<delim<<": ";
    for(int n = 0; n < N/delim - 1; n++) // how many whole parts
    {
        std::cout<<'('<<n*delim<<','<<(n+1)*delim-1<<"), ";
    }

    int rem = N%delim; // computing the remaining
    int tail = N-delim;

    if (rem == 0) // if no remaining just print the tail
    {
        std::cout<<'('<<tail<<','<<N-1<<')';
    }
    else // the tail is to be N-2 : N-1
    {
        std::cout<<'('<<tail-1<<','<<N-2<<"), ";
        std::cout<<'('<<N-1<<')';
    }
    std::cout<<'\n';
    std::cin>>N;
    return 0;
}
