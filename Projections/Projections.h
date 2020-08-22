#ifndef _PROJECTIONS
#define _PROJECTIONS

#ifdef __cplusplus
#include <armadillo>
using namespace arma;

double scalar_projection(vec a, vec b);
vec vector_projection(vec a, vec b);
vec vector_rejection(vec a, vec b);
double scalar_rejection(vec a, vec b);
#endif

#ifdef __cplusplus
extern "C" {
#endif
	double c_scalar_rejection(double* a, double* b, int n);
	double c_scalar_projection(double* a, double* b, int n);
#ifdef __cplusplus
}
#endif

#endif

