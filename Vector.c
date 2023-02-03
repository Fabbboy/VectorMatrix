#include <stdlib.h>
#include "Vector.h"
#include <math.h>

Vector2 *Vector2Create(float x, float y){
    Vector2 *vector = malloc(sizeof(Vector2));
    vector->x = x;
    vector->y = y;
    return vector;
};
Vector3 *Vector3Create(float x, float y, float z){
    Vector3 *vector = malloc(sizeof(Vector3));
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return vector;
};
Vector4 *Vector4Create(float x, float y, float z, float w){
    Vector4 *vector = malloc(sizeof(Vector4));
    vector->x = x;
    vector->y = y;
    vector->z = z;
    vector->w = w;
    return vector;
};

Vector2 *Vector2Add(Vector2 *a, Vector2 *b){
    Vector2 *vector = malloc(sizeof(Vector2));
    vector->x = a->x + b->x;
    vector->y = a->y + b->y;
    return vector;
};
Vector3 *Vector3Add(Vector3 *a, Vector3 *b){
    Vector3 *vector = malloc(sizeof(Vector3));
    vector->x = a->x + b->x;
    vector->y = a->y + b->y;
    vector->z = a->z + b->z;
    return vector;
};
Vector4 *Vector4Add(Vector4 *a, Vector4 *b){
    Vector4 *vector = malloc(sizeof(Vector4));
    vector->x = a->x + b->x;
    vector->y = a->y + b->y;
    vector->z = a->z + b->z;
    vector->w = a->w + b->w;
    return vector;
};

Vector2 *Vector2Sub(Vector2 *a, Vector2 *b){
    Vector2 *vector = malloc(sizeof(Vector2));
    vector->x = a->x - b->x;
    vector->y = a->y - b->y;
    return vector;
};
Vector3 *Vector3Sub(Vector3 *a, Vector3 *b){
    Vector3 *vector = malloc(sizeof(Vector3));
    vector->x = a->x - b->x;
    vector->y = a->y - b->y;
    vector->z = a->z - b->z;
    return vector;
};
Vector4 *Vector4Sub(Vector4 *a, Vector4 *b){
    Vector4 *vector = malloc(sizeof(Vector4));
    vector->x = a->x - b->x;
    vector->y = a->y - b->y;
    vector->z = a->z - b->z;
    vector->w = a->w - b->w;
    return vector;
};

Vector2 *Vector2Mul(Vector2 *a, Vector2 *b){
    Vector2 *vector = malloc(sizeof(Vector2));
    vector->x = a->x * b->x;
    vector->y = a->y * b->y;
    return vector;
};
Vector3 *Vector3Mul(Vector3 *a, Vector3 *b){
    Vector3 *vector = malloc(sizeof(Vector3));
    vector->x = a->x * b->x;
    vector->y = a->y * b->y;
    vector->z = a->z * b->z;
    return vector;
};
Vector4 *Vector4Mul(Vector4 *a, Vector4 *b){
    Vector4 *vector = malloc(sizeof(Vector4));
    vector->x = a->x * b->x;
    vector->y = a->y * b->y;
    vector->z = a->z * b->z;
    vector->w = a->w * b->w;
    return vector;
};

Vector2 *Vector2Div(Vector2 *a, Vector2 *b){
    Vector2 *vector = malloc(sizeof(Vector2));
    vector->x = a->x / b->x;
    vector->y = a->y / b->y;
    return vector;
};
Vector3 *Vector3Div(Vector3 *a, Vector3 *b){
    Vector3 *vector = malloc(sizeof(Vector3));
    vector->x = a->x / b->x;
    vector->y = a->y / b->y;
    vector->z = a->z / b->z;
    return vector;
};
Vector4 *Vector4Div(Vector4 *a, Vector4 *b){
    Vector4 *vector = malloc(sizeof(Vector4));
    vector->x = a->x / b->x;
    vector->y = a->y / b->y;
    vector->z = a->z / b->z;
    vector->w = a->w / b->w;
    return vector;
};

float Vector3Dot(Vector3 *a, Vector3 *b){
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

Vector3 *Vector3Normalize(Vector3 *a){
    float length = Vector3Length(a);
    Vector3 *vector = malloc(sizeof(Vector3));
    vector->x = a->x / length;
    vector->y = a->y / length;
    vector->z = a->z / length;
    return vector;
};
Vector3 *Vector3Cross(Vector3 *a, Vector3 *b){
    Vector3 *vector = malloc(sizeof(Vector3));
    vector->x = a->y * b->z - a->z * b->y;
    vector->y = a->z * b->x - a->x * b->z;
    vector->z = a->x * b->y - a->y * b->x;
    return vector;
};
float Vector3Length(Vector3 *a){
    return sqrtf(a->x * a->x + a->y * a->y + a->z * a->z);
};
float Vector3Distance(Vector3 *a, Vector3 *b){
    return Vector3Length(Vector3Sub(a, b));
};
