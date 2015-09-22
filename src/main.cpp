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
    topology.push_back(2);
    topology.push_back(4);
    topology.push_back(1);

    Net myNet(topology);

    std::cout << "BEFORE TRAINING" << std::endl;

    std::vector<double> input = { 1, 1 };
    myNet.feedForward(input);
    std::cout <<"INPUT: " << input[0] << " " << input[1] << " OUTPUT: " << myNet.getResults()[0] << std::endl;

    input = { 0, 1 };
    myNet.feedForward(input);
    std::cout <<"INPUT: " << input[0] << " " << input[1] << " OUTPUT: " << myNet.getResults()[0] << std::endl;

    input = { 1, 0 };
    myNet.feedForward(input);
    std::cout <<"INPUT: " << input[0] << " " << input[1] << " OUTPUT: " << myNet.getResults()[0] << std::endl;

    input = { 0, 0 };
    myNet.feedForward(input);
    std::cout <<"INPUT: " << input[0] << " " << input[1] << " OUTPUT: " << myNet.getResults()[0] << std::endl;

    for(size_t i = 0; i < 10000; ++i)
    {
        int n1 = (int)(2.0 * rand() / double(RAND_MAX));
        int n2 = (int)(2.0 * rand() / double(RAND_MAX));
        double t = n1 ^ n2;


        std::vector<double> input = {n1, n2};

        myNet.feedForward(input); // training

        if(t <= myNet.getResults()[0])
        	std::cout << myNet.getResults()[0] - t << std::endl;
        else
        	std::cout << t - myNet.getResults()[0] << std::endl;
        std::vector<double> target;
        target.push_back(t);
        myNet.backProp(target); // set prop

    }

    std::cout << "AFTER TRAINING" << std::endl;


    input = { 1, 1 };
    myNet.feedForward(input);
    std::cout <<"INPUT: " << input[0] << " " << input[1] << " OUTPUT: " << myNet.getResults()[0] << std::endl;

    input = { 0, 1 };
    myNet.feedForward(input);
    std::cout <<"INPUT: " << input[0] << " " << input[1] << " OUTPUT: " << myNet.getResults()[0] << std::endl;

    input = { 1, 0 };
    myNet.feedForward(input);
    std::cout <<"INPUT: " << input[0] << " " << input[1] << " OUTPUT: " << myNet.getResults()[0] << std::endl;

    input = { 0, 0 };
    myNet.feedForward(input);
    std::cout <<"INPUT: " << input[0] << " " << input[1] << " OUTPUT: " << myNet.getResults()[0] << std::endl;

//    std::vector<double> input2 = { 1, 1 };
//    std::cout << std::setprecision(100) << "INPUT: " << input2[0] << std::endl;
//    myNet.feedForward(input2);

//    LOG(INFO,"For input1 =" + std::to_string(input[0]) + /*", input2 =" + std::to_string(input[1]) +*/ " result is = " + std::to_string(myNet.getResults()[0]) + '.');
//    std::cout << std::setprecision(100) << "OUTPUT: " << myNet.getResults()[0] << std::endl;

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
