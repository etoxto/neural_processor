#include "net_config.h"


NetConfig::NetConfig() {

}

NetConfig::NetConfig(std::vector<float> input, int layers_amount, std::vector<int> layers_neurons_amount, std::vector<float> weights)
	: input{ input }, layers_amount{ layers_amount }, layers_neurons_amount{ layers_neurons_amount }, weights{ weights } {

}

NetConfig::~NetConfig() {

}

int NetConfig::get_layers_amount() {
	return layers_amount;
}

std::vector<float>& NetConfig::get_input() {
	return input;
}

std::vector<float>& NetConfig::get_weights() {
	return weights;
}

std::vector<int>& NetConfig::get_layers_neurons_amount() {
	return layers_neurons_amount;
}