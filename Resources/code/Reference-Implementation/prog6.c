
matrix1(2, int32)[2][3];
matrix2(2, int32)[3][2];
matrix3(2, int32)[2][3];
result(2, int32)[2][3];

int32 p;
input(p);

input(matrix1);
input(matrix2);

result = matrix1 - matrix3;
result = result - p;
//relational operation between two tensors
if(result>matrix1) then
{
    matrix2 = trans(result);
}
output(matrix2);


