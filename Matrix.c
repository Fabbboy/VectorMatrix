#include "Matrix.h"

#include <stdlib.h>
#include <printf.h>
#include "../Matrix.h"

Matrix4 *Matrix4Create(){
    Matrix4 *matrix = malloc(sizeof(Matrix4));
    return matrix;
};
Matrix4 *Matrix4Identity(){
    Matrix4 *matrix = malloc(sizeof(Matrix4));
    matrix->m[0][0] = 1.0f;
    matrix->m[0][1] = 0.0f;
    matrix->m[0][2] = 0.0f;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = 0.0f;
    matrix->m[1][1] = 1.0f;
    matrix->m[1][2] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = 0.0f;
    matrix->m[2][1] = 0.0f;
    matrix->m[2][2] = 1.0f;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = 0.0f;
    matrix->m[3][1] = 0.0f;
    matrix->m[3][2] = 0.0f;
    matrix->m[3][3] = 1.0f;
    return matrix;
};
Matrix4 *Matrix4Ortho(float left, float right, float bottom, float top, float near, float far){
    Matrix4 *matrix = malloc(sizeof(Matrix4));
    matrix->m[0][0] = 2.0f / (right - left);
    matrix->m[0][1] = 0.0f;
    matrix->m[0][2] = 0.0f;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = 0.0f;
    matrix->m[1][1] = 2.0f / (top - bottom);
    matrix->m[1][2] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = 0.0f;
    matrix->m[2][1] = 0.0f;
    matrix->m[2][2] = -2.0f / (far - near);
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = -(right + left) / (right - left);
    matrix->m[3][1] = -(top + bottom) / (top - bottom);
    matrix->m[3][2] = -(far + near) / (far - near);
    matrix->m[3][3] = 1.0f;
    return matrix;
};
Matrix4 *Matrix4Perspective(float fov, float aspect, float near, float far){
    Matrix4 *matrix = malloc(sizeof(Matrix4));
    float f = 1.0f / tan(fov * 0.5f);
    matrix->m[0][0] = f / aspect;
    matrix->m[0][1] = 0.0f;
    matrix->m[0][2] = 0.0f;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = 0.0f;
    matrix->m[1][1] = f;
    matrix->m[1][2] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = 0.0f;
    matrix->m[2][1] = 0.0f;
    matrix->m[2][2] = (far + near) / (near - far);
    matrix->m[2][3] = -1.0f;
    matrix->m[3][0] = 0.0f;
    matrix->m[3][1] = 0.0f;
    matrix->m[3][2] = (2.0f * far * near) / (near - far);
    matrix->m[3][3] = 0.0f;
    return matrix;
};
Matrix4 *Matrix4Translate(Vector3 *vector){
    Matrix4 *matrix = malloc(sizeof(Matrix4));
    matrix->m[0][0] = 1.0f;
    matrix->m[0][1] = 0.0f;
    matrix->m[0][2] = 0.0f;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = 0.0f;
    matrix->m[1][1] = 1.0f;
    matrix->m[1][2] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = 0.0f;
    matrix->m[2][1] = 0.0f;
    matrix->m[2][2] = 1.0f;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = vector->x;
    matrix->m[3][1] = vector->y;
    matrix->m[3][2] = vector->z;
    matrix->m[3][3] = 1.0f;
    return matrix;
};
Matrix4 *Matrix4Rotate(float angle, Vector3 *axis){
    Matrix4 *matrix = malloc(sizeof(Matrix4));
    float c = cos(angle);
    float s = sin(angle);
    float t = 1.0f - c;
    matrix->m[0][0] = t * axis->x * axis->x + c;
    matrix->m[0][1] = t * axis->x * axis->y + s * axis->z;
    matrix->m[0][2] = t * axis->x * axis->z - s * axis->y;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = t * axis->x * axis->y - s * axis->z;
    matrix->m[1][1] = t * axis->y * axis->y + c;
    matrix->m[1][2] = t * axis->y * axis->z + s * axis->x;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = t * axis->x * axis->z + s * axis->y;
    matrix->m[2][1] = t * axis->y * axis->z - s * axis->x;
    matrix->m[2][2] = t * axis->z * axis->z + c;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = 0.0f;
    matrix->m[3][1] = 0.0f;
    matrix->m[3][2] = 0.0f;
    matrix->m[3][3] = 1.0f;
    return matrix;
};
Matrix4 *Matrix4Scale(Vector3 *vector){
    Matrix4 *matrix = malloc(sizeof(Matrix4));
    matrix->m[0][0] = vector->x;
    matrix->m[0][1] = 0.0f;
    matrix->m[0][2] = 0.0f;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = 0.0f;
    matrix->m[1][1] = vector->y;
    matrix->m[1][2] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = 0.0f;
    matrix->m[2][1] = 0.0f;
    matrix->m[2][2] = vector->z;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = 0.0f;
    matrix->m[3][1] = 0.0f;
    matrix->m[3][2] = 0.0f;
    matrix->m[3][3] = 1.0f;
    return matrix;
};
Matrix4 *Matrix4Multiply(Matrix4 *a, Matrix4 *b){
    Matrix4 *matrix = malloc(sizeof(Matrix4));
    matrix->m[0][0] = a->m[0][0] * b->m[0][0] + a->m[0][1] * b->m[1][0] + a->m[0][2] * b->m[2][0] + a->m[0][3] * b->m[3][0];
    matrix->m[0][1] = a->m[0][0] * b->m[0][1] + a->m[0][1] * b->m[1][1] + a->m[0][2] * b->m[2][1] + a->m[0][3] * b->m[3][1];
    matrix->m[0][2] = a->m[0][0] * b->m[0][2] + a->m[0][1] * b->m[1][2] + a->m[0][2] * b->m[2][2] + a->m[0][3] * b->m[3][2];
    matrix->m[0][3] = a->m[0][0] * b->m[0][3] + a->m[0][1] * b->m[1][3] + a->m[0][2] * b->m[2][3] + a->m[0][3] * b->m[3][3];
    matrix->m[1][0] = a->m[1][0] * b->m[0][0] + a->m[1][1] * b->m[1][0] + a->m[1][2] * b->m[2][0] + a->m[1][3] * b->m[3][0];
    matrix->m[1][1] = a->m[1][0] * b->m[0][1] + a->m[1][1] * b->m[1][1] + a->m[1][2] * b->m[2][1] + a->m[1][3] * b->m[3][1];
    matrix->m[1][2] = a->m[1][0] * b->m[0][2] + a->m[1][1] * b->m[1][2] + a->m[1][2] * b->m[2][2] + a->m[1][3] * b->m[3][2];
    matrix->m[1][3] = a->m[1][0] * b->m[0][3] + a->m[1][1] * b->m[1][3] + a->m[1][2] * b->m[2][3] + a->m[1][3] * b->m[3][3];
    matrix->m[2][0] = a->m[2][0] * b->m[0][0] + a->m[2][1] * b->m[1][0] + a->m[2][2] * b->m[2][0] + a->m[2][3] * b->m[3][0];
    matrix->m[2][1] = a->m[2][0] * b->m[0][1] + a->m[2][1] * b->m[1][1] + a->m[2][2] * b->m[2][1] + a->m[2][3] * b->m[3][1];
    matrix->m[2][2] = a->m[2][0] * b->m[0][2] + a->m[2][1] * b->m[1][2] + a->m[2][2] * b->m[2][2] + a->m[2][3] * b->m[3][2];
    matrix->m[2][3] = a->m[2][0] * b->m[0][3] + a->m[2][1] * b->m[1][3] + a->m[2][2] * b->m[2][3] + a->m[2][3] * b->m[3][3];
    matrix->m[3][0] = a->m[3][0] * b->m[0][0] + a->m[3][1] * b->m[1][0] + a->m[3][2] * b->m[2][0] + a->m[3][3] * b->m[3][0];
    matrix->m[3][1] = a->m[3][0] * b->m[0][1] + a->m[3][1] * b->m[1][1] + a->m[3][2] * b->m[2][1] + a->m[3][3] * b->m[3][1];
    matrix->m[3][2] = a->m[3][0] * b->m[0][2] + a->m[3][1] * b->m[1][2] + a->m[3][2] * b->m[2][2] + a->m[3][3] * b->m[3][2];
    matrix->m[3][3] = a->m[3][0] * b->m[0][3] + a->m[3][1] * b->m[1][3] + a->m[3][2] * b->m[2][3] + a->m[3][3] * b->m[3][3];
    return matrix;
};

Matrix4 *Matrix4LookAt(Vector3 *eye, Vector3 *center, Vector3 *up){
    Vector3 *f = Vector3Normalize(Vector3Sub(center, eye));
    Vector3 *s = Vector3Normalize(Vector3Cross(f, up));
    Vector3 *u = Vector3Cross(s, f);
    Matrix4 *matrix = malloc(sizeof(Matrix4));
    matrix->m[0][0] = s->x;
    matrix->m[0][1] = u->x;
    matrix->m[0][2] = -f->x;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = s->y;
    matrix->m[1][1] = u->y;
    matrix->m[1][2] = -f->y;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = s->z;
    matrix->m[2][1] = u->z;
    matrix->m[2][2] = -f->z;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = -Vector3Dot(s, eye);
    matrix->m[3][1] = -Vector3Dot(u, eye);
    matrix->m[3][2] = Vector3Dot(f, eye);
    matrix->m[3][3] = 1.0f;
    return matrix;
};
Matrix4 *Matrix4Transpose(Matrix4 *matrix){
    Matrix4 *m = malloc(sizeof(Matrix4));
    m->m[0][0] = matrix->m[0][0];
    m->m[0][1] = matrix->m[1][0];
    m->m[0][2] = matrix->m[2][0];
    m->m[0][3] = matrix->m[3][0];
    m->m[1][0] = matrix->m[0][1];
    m->m[1][1] = matrix->m[1][1];
    m->m[1][2] = matrix->m[2][1];
    m->m[1][3] = matrix->m[3][1];
    m->m[2][0] = matrix->m[0][2];
    m->m[2][1] = matrix->m[1][2];
    m->m[2][2] = matrix->m[2][2];
    m->m[2][3] = matrix->m[3][2];
    m->m[3][0] = matrix->m[0][3];
    m->m[3][1] = matrix->m[1][3];
    m->m[3][2] = matrix->m[2][3];
    m->m[3][3] = matrix->m[3][3];
    return m;
};
Matrix4 *Matrix4Inverse(Matrix4 *matrix){
    Matrix4 *m = malloc(sizeof(Matrix4));
    float s0 = matrix->m[0][0] * matrix->m[1][1] - matrix->m[1][0] * matrix->m[0][1];
    float s1 = matrix->m[0][0] * matrix->m[1][2] - matrix->m[1][0] * matrix->m[0][2];
    float s2 = matrix->m[0][0] * matrix->m[1][3] - matrix->m[1][0] * matrix->m[0][3];
    float s3 = matrix->m[0][1] * matrix->m[1][2] - matrix->m[1][1] * matrix->m[0][2];
    float s4 = matrix->m[0][1] * matrix->m[1][3] - matrix->m[1][1] * matrix->m[0][3];
    float s5 = matrix->m[0][2] * matrix->m[1][3] - matrix->m[1][2] * matrix->m[0][3];
    float c5 = matrix->m[2][2] * matrix->m[3][3] - matrix->m[3][2] * matrix->m[2][3];
    float c4 = matrix->m[2][1] * matrix->m[3][3] - matrix->m[3][1] * matrix->m[2][3];
    float c3 = matrix->m[2][1] * matrix->m[3][2] - matrix->m[3][1] * matrix->m[2][2];
    float c2 = matrix->m[2][0] * matrix->m[3][3] - matrix->m[3][0] * matrix->m[2][3];
    float c1 = matrix->m[2][0] * matrix->m[3][2] - matrix->m[3][0] * matrix->m[2][2];
    float c0 = matrix->m[2][0] * matrix->m[3][1] - matrix->m[3][0] * matrix->m[2][1];
    float invdet = 1.0f / (s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0);
    m->m[0][0] = ( matrix->m[1][1] * c5 - matrix->m[1][2] * c4 + matrix->m[1][3] * c3) * invdet;
    m->m[0][1] = (-matrix->m[0][1] * c5 + matrix->m[0][2] * c4 - matrix->m[0][3] * c3) * invdet;
    m->m[0][2] = ( matrix->m[3][1] * s5 - matrix->m[3][2] * s4 + matrix->m[3][3] * s3) * invdet;
    m->m[0][3] = (-matrix->m[2][1] * s5 + matrix->m[2][2] * s4 - matrix->m[2][3] * s3) * invdet;
    m->m[1][0] = (-matrix->m[1][0] * c5 + matrix->m[1][2] * c2 - matrix->m[1][3] * c1) * invdet;
    m->m[1][1] = ( matrix->m[0][0] * c5 - matrix->m[0][2] * c2 + matrix->m[0][3] * c1) * invdet;
    m->m[1][2] = (-matrix->m[3][0] * s5 + matrix->m[3][2] * s2 - matrix->m[3][3] * s1) * invdet;
    m->m[1][3] = ( matrix->m[2][0] * s5 - matrix->m[2][2] * s2 + matrix->m[2][3] * s1) * invdet;
    m->m[2][0] = ( matrix->m[1][0] * c4 - matrix->m[1][1] * c2 + matrix->m[1][3] * c0) * invdet;
    m->m[2][1] = (-matrix->m[0][0] * c4 + matrix->m[0][1] * c2 - matrix->m[0][3] * c0) * invdet;
    m->m[2][2] = ( matrix->m[3][0] * s4 - matrix->m[3][1] * s2 + matrix->m[3][3] * s0) * invdet;
    m->m[2][3] = (-matrix->m[2][0] * s4 + matrix->m[2][1] * s2 - matrix->m[2][3] * s0) * invdet;
    m->m[3][0] = (-matrix->m[1][0] * c3 + matrix->m[1][1] * c1 - matrix->m[1][2] * c0) * invdet;
    m->m[3][1] = ( matrix->m[0][0] * c3 - matrix->m[0][1] * c1 + matrix->m[0][2] * c0) * invdet;
    m->m[3][2] = (-matrix->m[3][0] * s3 + matrix->m[3][1] * s1 - matrix->m[3][2] * s0) * invdet;
    m->m[3][3] = ( matrix->m[2][0] * s3 - matrix->m[2][1] * s1 + matrix->m[2][2] * s0) * invdet;
    return m;
};
Matrix4 *Matrix4Copy(Matrix4 *matrix){
    Matrix4 *m = malloc(sizeof(Matrix4));
    m->m[0][0] = matrix->m[0][0];
    m->m[0][1] = matrix->m[0][1];
    m->m[0][2] = matrix->m[0][2];
    m->m[0][3] = matrix->m[0][3];
    m->m[1][0] = matrix->m[1][0];
    m->m[1][1] = matrix->m[1][1];
    m->m[1][2] = matrix->m[1][2];
    m->m[1][3] = matrix->m[1][3];
    m->m[2][0] = matrix->m[2][0];
    m->m[2][1] = matrix->m[2][1];
    m->m[2][2] = matrix->m[2][2];
    m->m[2][3] = matrix->m[2][3];
    m->m[3][0] = matrix->m[3][0];
    m->m[3][1] = matrix->m[3][1];
    m->m[3][2] = matrix->m[3][2];
    m->m[3][3] = matrix->m[3][3];
    return m;
};
void Matrix4Print(Matrix4 *matrix){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%f ", matrix->m[i][j]);
        }
        printf("\n");
    }
};
