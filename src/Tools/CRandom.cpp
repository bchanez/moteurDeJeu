#include "CRandom.hpp"

namespace CRandom {

	std::minstd_rand gen;

	void init()
	{
		gen.seed(std::random_device{}());
	}

	int intInRange(int low, int high)
	{
		std::uniform_int_distribution<int> dist(low, high);
		return dist(gen);
	}

	float floatInRange(float low, float high)
	{
		std::uniform_real_distribution<float> dist(low, high);
		return dist(gen);
	}

}
