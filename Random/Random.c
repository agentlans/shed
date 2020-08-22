#include <math.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>

#include "Random.h"

void* random_generator(unsigned long int seed) {
	gsl_rng* rng = gsl_rng_alloc(gsl_rng_taus);
	gsl_rng_set(rng, seed);
	return (void*) rng;
}

double random_uniform(void* gen) {
	return gsl_rng_uniform((gsl_rng*) gen);
}

double random_gaussian(void* gen) {
	return gsl_ran_gaussian((gsl_rng*) gen, 1.0);
}

void random_uniform_fill(void* gen, double* arr, int n, double min, double max) {
	double range = fabs(max - min);
	for (int i = 0; i < n; ++i) {
		arr[i] = random_uniform(gen)*range + min;
	}
}

void random_gaussian_fill(void* gen, double* arr, int n, double mu, double sd) {
	for (int i = 0; i < n; ++i) {
		arr[i] = random_gaussian(gen)*sd + mu;
	}
}

void random_generator_free(void* gen) {
	gsl_rng_free((gsl_rng*) gen);
}

