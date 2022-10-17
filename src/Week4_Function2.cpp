//============================================================================
// Name        : Week4_Function2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FunctionPart {
public:

	FunctionPart(const char &new_operation, const double &new_value) {
		operation = new_operation;
		value = new_value;
	}

	double Apply(const double &num) const {
		if (operation == '+') {
			return num + value;
		} else if (operation == '*') {
			return num * value;
		} else if (operation == '-') {
			return num - value;
		} else {
			return num / value;
		}
	}

	void Invert() {
		if (operation == '+') {
			operation = '-';
		} else if (operation == '-') {
			operation = '+';
		} else if (operation == '*') {
			operation = '/';
		} else {
			operation = '*';
		}
	}

private:
	char operation;
	double value;
};

class Function {
public:
	void AddPart(const char &operation, const double &value) {
		functionparts.push_back( { operation, value });
		/*Another ways of creating new object.
		 functionparts.push_back(FunctionParts(operation, value));
		 Function part;
		 functionparts.push_back(part);
		 */
	}
	double Apply(double value) const {
		for (const auto &functionpart : functionparts) {
			value = functionpart.Apply(value);
		}
		return value;
	}

	void Invert() {
		for (auto &functionpart : functionparts) {
			functionpart.Invert();
		}
		reverse(begin(functionparts), end(functionparts));
	}

private:
	vector<FunctionPart> functionparts;
};

/*struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params {
	double a;
	double b;
	double c;
};

Function MakeWeightFunction(const Params &params, const Image &image) {
	Function function;
	function.AddPart('*', params.a);
	function.AddPart('-', image.freshness * params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params &params, const Image &image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params &params, const Image &image,
		double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}*/

int main() {
	/*Image image = { 10, 2, 6 };
	Params params = { 4, 2, 6 };
	cout << ComputeImageWeight(params, image) << endl;
	cout << ComputeQualityByWeight(params, image, 52) << endl;
	return 0;*/
}

