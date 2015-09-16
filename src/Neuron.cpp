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
    0.39438292681909303816212286619702354073524475097656432,
    0.798440033476073285356733322259970009326934814453175654,
    0.1975513692933839604570778192282887175679206848144531654654,
    0.76822959481190400410355323401745408773422241210937999,
    0.5539699557954305131346472990117035806179046630859371325,
    0.628870924761924410262281526229344308376312255859374132,
    0.513400910195615511888433957210509106516838073730468878238,
    0.9161950680037006522482556647446472197771072387695312111,
    0.71729692943268308358284457426634617149829864501953142135,
    0.606968876257058642664787839748896658420562744140628786,
    0.24288677062973695885972347241477109491825103759765698768,
    0.80417675422699042009355707705253735184669494628906243432,
    0.40094439424618349976370268450409639626741409301757815541,
    0.108808802025769285615197645711305085569620132446289064311,
    0.218256905310906884620791856832511257380247116088867184324,
    0.8391122346926072061989998474018648266792297363281819876,
    0.29603161769734304131773683366191107779741287231445319877
};

Neuron::Neuron(size_t numOutputs, size_t index) : m_index(index), m_gradient(0), m_output(0)
{
    for(size_t i = 0; i < numOutputs; ++i)
    {
        m_outputWeights.push_back(Connection());
        m_outputWeights.back().weight = weights[weights_index++];//randomWeight();
        std::cout << std::setprecision(100) << std::string(__PRETTY_FUNCTION__) << " Weight for neuron: " << index << " output: " << i <<" value: " << m_outputWeights.back().weight << std::endl;
    }
}

void Neuron::feedForward(Layer& prevLayer)
{
    double sum = 0.0;
    for(size_t i = 0; i < prevLayer.size(); ++i)
    {
    	std::cout << std::setprecision(100) << std::string(__PRETTY_FUNCTION__) +
    			" Neuron: " << m_index <<
				" output: " << prevLayer[i].getOutput() <<
				" weight: " << prevLayer[i].getOutputWeights()[m_index].weight <<
				" result: " << prevLayer[i].getOutput() * prevLayer[i].getOutputWeights()[m_index].weight << std::endl;
        sum += prevLayer[i].getOutput() * prevLayer[i].getOutputWeights()[m_index].weight;
    }
    m_output = Neuron::transferFunction(sum);
	std::cout << std::setprecision(100) << std::string(__PRETTY_FUNCTION__) <<
			" Neuron: " << m_index <<
			" sum: " << sum <<
			" total output:" << m_output << std::endl;
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
