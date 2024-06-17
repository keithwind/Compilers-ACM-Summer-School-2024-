int32 n;
int32 m;
input(n);
input(m);
matrix1(2, int32)[n][m];
matrix2(2, int32)[m][n];
matrix3(2, int32)[n][m];
result(2, int32)[n][m];

int32 p;
input(p);

input(matrix1);
input(matrix2);

result = matrix1 - matrix3;
result = result - p;
matrix2 = trans(result);
output(matrix2);

