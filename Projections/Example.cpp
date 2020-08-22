#include <iostream>
#include "Projections.h"

int main() {
	std::cout << scalar_projection({0, 1}, {1, 0}) << std::endl;
	std::cout << scalar_rejection({0, 1}, {1, 0}) << std::endl;
	return 0;
}

