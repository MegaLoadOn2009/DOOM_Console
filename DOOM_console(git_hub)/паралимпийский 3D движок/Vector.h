#ifndef VECTOR_H
#define VECTOR_H
#include "Global.h"
vec2 VecSumm(vec2 vector1, vec2 vector2);
vec2 VecDif(vec2 vector1, vec2 vector2);
vec2 VecScale(vec2 vector1, double a);
void VecRotate(vec2& vector, double corner);
vec2 scanVecRotate(vec2 vector, double corner);
double roundToN(double a, int n);
#endif // VECTOR_H