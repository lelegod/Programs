#include <stdio.h>

typedef struct Mat3 Mat3;

struct Mat3 {
    double row1[3];
    double row2[3];
    double row3[3];
};

typedef struct Vec3 Vec3;

struct Vec3 {
    double x; double y; double z;
};

void Mat3_print(Mat3 M) {
    printf("{ { %f, %f, %f },\n  { %f, %f, %f },\n  { %f, %f, %f } }", M.row1[0], M.row1[1], M.row1[2], M.row2[0], M.row2[1], M.row2[2], M.row3[0], M.row3[1], M.row3[2]);
}

void Vec3_print(Vec3 V) {
    printf("{ %f, %f, %f }", V.x, V.y, V.z);
}

void Mat3_mulMat3(Mat3 A, Mat3 B, Mat3 *P) {
    P->row1[0] = A.row1[0]*B.row1[0]+A.row1[1]*B.row2[0]+A.row1[2]*B.row3[0];
    P->row1[1] = A.row1[0]*B.row1[1]+A.row1[1]*B.row2[1]+A.row1[2]*B.row3[1];
    P->row1[2] = A.row1[0]*B.row1[2]+A.row1[1]*B.row2[2]+A.row1[2]*B.row3[2];
    P->row2[0] = A.row2[0]*B.row1[0]+A.row2[1]*B.row2[0]+A.row2[2]*B.row3[0];
    P->row2[1] = A.row2[0]*B.row1[1]+A.row2[1]*B.row2[1]+A.row2[2]*B.row3[1];
    P->row2[2] = A.row2[0]*B.row1[2]+A.row2[1]*B.row2[2]+A.row2[2]*B.row3[2];
    P->row3[0] = A.row3[0]*B.row1[0]+A.row3[1]*B.row2[0]+A.row3[2]*B.row3[0];
    P->row3[1] = A.row3[0]*B.row1[1]+A.row3[1]*B.row2[1]+A.row3[2]*B.row3[1];
    P->row3[2] = A.row3[0]*B.row1[2]+A.row3[1]*B.row2[2]+A.row3[2]*B.row3[2];
}

void Mat3_mulVec3(Mat3 M, Vec3 V, Vec3 *P) {
    P->x  = V.x*M.row1[0]+V.y*M.row1[1]+V.z*M.row1[2];
    P->y  = V.x*M.row2[0]+V.y*M.row2[1]+V.z*M.row2[2];
    P->z  = V.x*M.row3[0]+V.y*M.row3[1]+V.z*M.row3[2];
}

int main () {
    Vec3 V = {3, 4 , 1};
    Mat3 S = {{3,0,0},{0,2,0},{0,0,1}};
    Vec3 SV;
    Vec3 *pSV = &SV;
    Mat3_mulVec3(S, V, pSV);
    Vec3_print(SV);
    printf("\n");

    Mat3 T = {{1,0,5}, {0,1,7},{0,0,1}};
    Vec3 TV;
    Vec3 *pTV = &TV;
    Mat3_mulVec3(T,V, pTV);
    Vec3_print(TV);
    printf("\n");

    Mat3 TS;
    Mat3 *pTS = &TS;
    Mat3_mulMat3(T,S,pTS);
    Vec3 TSV;
    Vec3 *pTSV = &TSV;
    Mat3_mulVec3(TS, V, pTSV);
    Vec3_print(TSV);
    return 0;
}