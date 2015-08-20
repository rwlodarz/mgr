//============================================================================
// Name        : neural_network.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Net.hpp"
#include "Logger.hpp"

#include <iomanip>

int main()
{
    std::vector<size_t> topology;
    topology.push_back(1);
    topology.push_back(4);
    topology.push_back(1);

    Net myNet(topology);

//    for(size_t i = 0; i < 20000; ++i)
//    {
//        int n1 = (int)(2.0 * rand() / double(RAND_MAX));
//        int n2 = (int)(2.0 * rand() / double(RAND_MAX));
//        int t = n1 ^ n2;
//
//
//        std::vector<double> input;
//        input.push_back(n1);
//        input.push_back(n2);
//
//        myNet.feedForward(input); // training
//
//        std::vector<double> target;
//        target.push_back(t);
//        myNet.backProp(target); // set prop
//
//    }

    LOG(INFO,"Testing:");

    std::vector<double> input = { 0.84018771715470952354820610707974992692470550537109375 };
    myNet.feedForward(input);

    LOG(INFO,"For input1 =" + std::to_string(input[0]) + /*", input2 =" + std::to_string(input[1]) +*/ " result is = " + std::to_string(myNet.getResults()[0]) + '.');
    std::cout << std::setprecision(100) << "OUTPUT: " << myNet.getResults()[0] << std::endl;

//    input = { 0, 1 };
//    myNet.feedForward(input);
//
//    LOG(INFO,"For input1 =" + std::to_string(input[0]) + ", input2 =" + std::to_string(input[1]) + " result is = " + std::to_string(myNet.getResults()[0]) + '.');
//
//    input = { 1, 0 };
//    myNet.feedForward(input);
//
//    LOG(INFO,"For input1 =" + std::to_string(input[0]) + ", input2 =" + std::to_string(input[1]) + " result is = " + std::to_string(myNet.getResults()[0]) + '.');
//
//    input = { 1, 1 };
//    myNet.feedForward(input);

//    LOG(INFO,"For input1 =" + std::to_string(input[0]) + ", input2 =" + std::to_string(input[1]) + " result is = " + std::to_string(myNet.getResults()[0]) + '.');

    return 0;
}
