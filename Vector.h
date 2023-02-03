#pragma once

typedef struct Vector2{
    float x;
    float y;
} Vector2;

typedef struct Vector3{
    float x;
    float y;
    float z;
} Vector3;

typedef struct Vector4{
    float x;
    float y;
    float z;
    float w;
} Vector4;

Vector2 *Vector2Create(float x, float y);
Vector3 *Vector3Create(float x, float y, float z);
Vector4 *Vector4Create(float x, float y, float z, float w);

Vector2 *Vector2Add(Vector2 *a, Vector2 *b);
Vector3 *Vector3Add(Vector3 *a, Vector3 *b);
Vector4 *Vector4Add(Vector4 *a, Vector4 *b);

Vector2 *Vector2Sub(Vector2 *a, Vector2 *b);
Vector3 *Vector3Sub(Vector3 *a, Vector3 *b);
Vector4 *Vector4Sub(Vector4 *a, Vector4 *b);

Vector2 *Vector2Mul(Vector2 *a, Vector2 *b);
Vector3 *Vector3Mul(Vector3 *a, Vector3 *b);
Vector4 *Vector4Mul(Vector4 *a, Vector4 *b);

Vector2 *Vector2Div(Vector2 *a, Vector2 *b);
Vector3 *Vector3Div(Vector3 *a, Vector3 *b);
Vector4 *Vector4Div(Vector4 *a, Vector4 *b);

float Vector3Dot(Vector3 *a, Vector3 *b);

Vector3 *Vector3Normalize(Vector3 *a);
Vector3 *Vector3Cross(Vector3 *a, Vector3 *b);
float Vector3Length(Vector3 *a);
float Vector3Distance(Vector3 *a, Vector3 *b);
