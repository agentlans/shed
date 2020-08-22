#include <stdio.h>
#include "Random.h"

int main()
{
	void* rng = random_generator(10);
	double arr[3];
	random_gaussian_fill(rng, arr, 3, 1, 2);
	for (int i = 0; i < 3; ++i) {
		printf("%f, ", arr[i]);
	}
	random_generator_free(rng);
}


