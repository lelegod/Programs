#include <stdio.h>

typedef struct Mat3 Mat3;

struct Mat3 {
    double row1[3];
    double row2[3];
    double row3[3];
};

void Mat3_print(Mat3 M) {
    printf("{ { %f, %f, %f },\n  { %f, %f, %f },\n  { %f, %f, %f } }", M.row1[0], M.row1[1], M.row1[2], M.row2[0], M.row2[1], M.row2[2], M.row3[0], M.row3[1], M.row3[2]);
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

int main () {
    Mat3 A = {{2,1,5}, {2,10,5}, {3,1,4}};
    Mat3 B = {{8,7,1}, {4,2,7}, {2,3,5}};
    Mat3 P;
    Mat3 *pP = &P;
    Mat3_mulMat3(A, B, pP);
    Mat3_print(P);
    return 0;
}