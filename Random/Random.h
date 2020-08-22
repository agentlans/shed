#ifndef _RANDOMGEN
#define _RANDOMGEN

void* random_generator(unsigned long int seed);

double random_uniform(void* gen);
double random_gaussian(void* gen);
void random_uniform_fill(void* gen, double* arr, int n, double min, double max);
void random_gaussian_fill(void* gen, double* arr, int n, double mu, double sd);

void random_generator_free(void* gen);

#endif

