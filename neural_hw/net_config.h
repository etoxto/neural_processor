#ifndef _NET_CONFIGURATION_H_
#define _NET_CONFIGURATION_H_

#include <vector>

class NetConfig {

public:
	NetConfig();
	NetConfig(std::vector<float> input, int layers_amount, std::vector<int> layers_neurons_amount, std::vector<float> weights);
	~NetConfig();

	int get_layers_amount();
	std::vector<float>& get_input();
	std::vector<float>& get_weights();
	std::vector<int>& get_layers_neurons_amount();

private:
	int layers_amount;
	std::vector<int> layers_neurons_amount;
	std::vector<float> input;
	std::vector<float> weights;
};


#endif // !_DATASET_H_