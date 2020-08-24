#include <armadillo>

using namespace arma;

#include "Projections.h"

double scalar_projection(vec a, vec b) {
	return dot(a, normalise(b));
}

vec vector_projection(vec a, vec b) {
	vec nb = normalise(b);
	return dot(a, nb) * nb;
}

vec vector_rejection(vec a, vec b) {
	return a - vector_projection(a, b);
}

double scalar_rejection(vec a, vec b) {
	return norm(vector_rejection(a, b));
}

// Copies a C-style double array to Armadillo vector
vec to_armadillo(const double* x, int n) {
	vec v(n);
	for (int i = 0; i < n; ++i) {
		v[i] = x[i];
	}
	return v;
}

extern "C" double c_scalar_rejection(const double* a, const double* b, int n) {
	vec av = to_armadillo(a, n);
	vec bv = to_armadillo(b, n);
	return scalar_rejection(av, bv);
}

extern "C" double c_scalar_projection(const double* a, const double* b, int n) {
	vec av = to_armadillo(a, n);
	vec bv = to_armadillo(b, n);
	return scalar_projection(av, bv);
}


