#include <iostream>
#include <forward_list>


std::forward_list<int> myList;

int main()
{
    for (int i = 11; i > 0; --i) myList.push_front(i);
    for (auto i = myList.begin(); i != myList.end(); ++i) std::cout<<*i<<" ";
    std::cout<<std::endl;
    //here we have forward_list containing [1,2,3,4,5,6,7,8,9,10...]

    int length = 0;
    for (auto i = myList.begin(); i != myList.end(); ++i) length++;
    //std::cout<<"list's length "<<length<<" "; // now we know the list's length

    auto b_iter  = myList.begin();
    auto e_iter  = myList.begin();
    auto pe_iter = myList.begin();

    // e_iter is the last, and pe_iter is the last--
    for (int i = 0; i<length-1; i++) pe_iter = e_iter++;

    //according to the algorithm
    // we have to process n/2 steps
    for (int i = 0; i < length/2; i++)
    {
        b_iter = myList.insert_after(b_iter,*(e_iter)); // push the last into front
        b_iter++; // take next element pointer
        myList.erase_after(pe_iter); // delete last from the end

        e_iter = pe_iter = b_iter; // because it's a forward list we have to begin again

        // e_iter is the last, and pe_iter is the last--
        for (int j = 0; j < length-(i*2)-3; j++) pe_iter = e_iter++; // -3 because -1 (before end() is the last) +
                                                                     //(-2) (because of doubled reducing
    }

    //cout the result
    std::cout<<"\n\n";
    for (auto i = myList.begin(); i != myList.end(); ++i) std::cout<<*i<<" ";
    std::cout<<std::endl;
    std::cin>>length;
    return 0;
}
