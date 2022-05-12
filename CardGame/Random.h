#pragma once
#include <vector>
#include <string>
#include <chrono>
#include <random>
using namespace std;

namespace rndtimer {
	namespace detail {

		static std::default_random_engine rnd(
			static_cast<uint32_t>(
				std::chrono::system_clock::now().time_since_epoch().count()
				)
		);
	}
	inline int32_t Random(int32_t minvalue, int32_t maxvalue) {
		if (minvalue > maxvalue)
			std::swap(minvalue, maxvalue);
		return detail::rnd() % (maxvalue - minvalue + 1) + minvalue;
	}
}

vector<string> shuffle(vector<string> arr) {
	vector<string> arr2;
	for (int i = 0; i < arr.size() * arr.size(); ++i) {
		//swap(arr[rndtimer::Random(0, arr.size() - 1)], arr[rndtimer::Random(0, arr.size() - 1)]);
		int iter = 0;
		while (iter < 36) {
			int s = rndtimer::Random(0, arr.size()-1);
			arr2.push_back(arr[s]);
			swap(arr[s], arr.back());
			arr.pop_back();
			++iter;
		}
	}
	return arr2;
}