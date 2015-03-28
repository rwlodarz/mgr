//============================================================================
// Name        : neural_network.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

//#include <Neuron.hpp>
#include "Net.hpp"


int main()
{
    std::vector<size_t> topology;
    topology.push_back(2);
    topology.push_back(4);
    topology.push_back(1);

    Net myNet(topology);

    for(size_t i = 0; i < 2000; ++i)
    {
        int n1 = (int)(2.0 * rand() / double(RAND_MAX));
        int n2 = (int)(2.0 * rand() / double(RAND_MAX));
        int t = n1 ^ n2;


        std::vector<double> input;
        input.push_back(n1);
        input.push_back(n2);

        myNet.feedForward(input); // training

        std::vector<double> target;
        target.push_back(t);
        myNet.backProp(target); // set prop

    }

    std::cout << "Test:" << std::endl;

    for(size_t i = 0; i < 10; ++i)
    {
        int n1 = (int)(2.0 * rand() / double(RAND_MAX));
        int n2 = (int)(2.0 * rand() / double(RAND_MAX));

        std::vector<double> input;
        input.push_back(n1);
        input.push_back(n2);

        myNet.feedForward(input);

        std::cout << "For input1 =" << n1 << ", input2 =" << n2 << " result is = " << myNet.getResults()[0] << << std::endl;
    }

    return 0;
}
