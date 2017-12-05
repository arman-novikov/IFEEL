#include <iostream>


void factorize(int num)
{
    int factor(2); // this is the smallest possible multiple

    //this procedure is gonna try to divide by module of factor (num%factor==0)
    //every iteration it can reduce the num in factor times
    //if it can (else it gonna to increment the factor)
    while(factor<=num)
    {
        if(num%factor==0)
        {
            std::cout<<factor;
            num /= factor;
            if(num>1)
                std::cout<<"*";
        }
        else
            ++factor;
    }
    return;
}


//if I need to keep results in memory
//i'd probably use std::vector< std::list<int> >
// and push results into

int main()
{
    int N;
    std::cout<<"input size of your array: ";
    std::cin>>N;
    std::cout<<std::endl;

    int arr[N];
    for (int i = 0; i < N; ++i)
    {
        std::cout<<"Input the el #"<<i+1<<": ";
        std::cin>>arr[i];
    }

    std::cout<<std::endl;
    std::cout<<"results: "<<std::endl;

    for (int i = 0; i < N; ++i)
    {
        std::cout<<"for "<<arr[i]<<": ";
        factorize(arr[i]);
        std::cout<<std::endl;
    }

    std::cout<<std::endl<<"input any num to exit";
    std::cin>>N;
	return 0;
}
