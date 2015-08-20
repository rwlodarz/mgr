#include "Neuron.hpp"
#include "Net.hpp"
#include "Logger.hpp"

#include <cmath>
#include <iomanip>

double Neuron::eta = 0.15;
double Neuron::alpha = 0.5;

static size_t weights_index = 0;

std::vector<double> weights
{
    0.3943829268190930381621228661970235407352447509765625,
    0.798440033476073285356733322259970009326934814453125,
    0.197551369293383960457077819228288717567920684814453125,
    0.768229594811904004103553234017454087734222412109375,
    0.5539699557954305131346472990117035806179046630859375,
    0.628870924761924410262281526229344308376312255859375,
    0.51340091019561551188843395721050910651683807373046875,
    0.91619506800370065224825566474464721977710723876953125,
    0.71729692943268308358284457426634617149829864501953125,
    0.606968876257058642664787839748896658420562744140625,
    0.24288677062973695885972347241477109491825103759765625,
    0.8041767542269904200935570770525373518466949462890625,
    0.400944394246183499763702684504096396267414093017578125,
    0.1088088020257692856151976457113050855696201324462890625,
    0.2182569053109068846207918568325112573802471160888671875,
    0.839112234692607206198999847401864826679229736328125,
    0.296031617697343041317736833661911077797412872314453125
};

Neuron::Neuron(size_t numOutputs, size_t index) : m_index(index)
{
    for(size_t i = 0; i < numOutputs; ++i)
    {
        m_outputWeights.push_back(Connection());
        m_outputWeights.back().weight = weights[weights_index++];//randomWeight();
        std::cout << std::setprecision(100) << m_outputWeights.back().weight << std::endl;
        LOG(DEBUG, std::string(__PRETTY_FUNCTION__) + " Weight for neuron: " + std::to_string(index) + " output: " + std::to_string(i) + " value: " + std::to_string(m_outputWeights.back().weight));
    }
}

void Neuron::feedForward(Layer& prevLayer)
{
    double sum = 0.0;
    for(size_t i = 0; i < prevLayer.size(); ++i)
    {
        sum += prevLayer[i].getOutput() * prevLayer[i].getOutputWeights()[m_index].weight;
    }

    m_output = Neuron::transferFunction(sum);

}

double Neuron::transferFunction(double x)
{
    return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
    return 1.0 - x * x;
}

void Neuron::calcOutputGradients(double targetValue)
{
    double delta = targetValue - m_output;
    m_gradient = delta * Neuron::transferFunctionDerivative(m_output);
}

void Neuron::calcHiddenGradients(const Layer& nextLayer)
{
    double dow = sumDOW(nextLayer);
    m_gradient = dow * Neuron::transferFunctionDerivative(m_output);
}

double Neuron::sumDOW(const Layer& nextLayer) const
{
    double sum = 0.0;

    for(size_t i = 0; i < nextLayer.size() - 1; ++i)
    {
            sum += m_outputWeights[i].weight * nextLayer[i].m_gradient;
    }

    return sum;
}

void Neuron::updateInputWeights(Layer& prevLayer)
{
    for(size_t i = 0; i < prevLayer.size(); ++i)
    {
        Neuron &neuron = prevLayer[i];
        double oldDeltaWeight = neuron.m_outputWeights[m_index].deltaWeight;

        double newDeltaWeight = eta * neuron.getOutput() * m_gradient + alpha * oldDeltaWeight;

        neuron.m_outputWeights[m_index].deltaWeight = newDeltaWeight;
        neuron.m_outputWeights[m_index].weight += newDeltaWeight;
    }
}
