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

    for(size_t i = 0; i < 20000; ++i)
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

    std::vector<double> input = { 0, 0 };
    myNet.feedForward(input);

    std::cout << "For input1 =" << input[0] << ", input2 =" << input[1] << " result is = " << myNet.getResults()[0] << '.' << std::endl;

    input = { 0, 1 };
    myNet.feedForward(input);

    std::cout << "For input1 =" << input[0] << ", input2 =" << input[1] << " result is = " << myNet.getResults()[0] << '.' << std::endl;

    input = { 1, 0 };
    myNet.feedForward(input);

    std::cout << "For input1 =" << input[0] << ", input2 =" << input[1] << " result is = " << myNet.getResults()[0] << '.' << std::endl;

    input = { 1, 1 };
    myNet.feedForward(input);

    std::cout << "For input1 =" << input[0] << ", input2 =" << input[1] << " result is = " << myNet.getResults()[0] << '.' << std::endl;


    return 0;
}
