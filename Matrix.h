#pragma once

#include <math.h>
#include "Vector.h"

typedef struct Matrix4{
    float m[4][4];
} Matrix4;

Matrix4 *Matrix4Create();
Matrix4 *Matrix4Identity();
Matrix4 *Matrix4Ortho(float left, float right, float bottom, float top, float near, float far);
Matrix4 *Matrix4Perspective(float fov, float aspect, float near, float far);
Matrix4 *Matrix4Translate(Vector3 *vector);
Matrix4 *Matrix4Rotate(float angle, Vector3 *axis);
Matrix4 *Matrix4Scale(Vector3 *vector);
Matrix4 *Matrix4Multiply(Matrix4 *a, Matrix4 *b);
Matrix4 *Matrix4LookAt(Vector3 *eye, Vector3 *center, Vector3 *up);
Matrix4 *Matrix4Transpose(Matrix4 *matrix);
Matrix4 *Matrix4Inverse(Matrix4 *matrix);
Matrix4 *Matrix4Copy(Matrix4 *matrix);
void Matrix4Print(Matrix4 *matrix);
