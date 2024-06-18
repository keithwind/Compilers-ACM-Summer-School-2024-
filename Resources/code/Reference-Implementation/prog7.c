matrix1(2, int32)[2][2];

int32 i;
i = 0;

int32 var;
input(matrix1);
while(i<10)
{
    input(var);
    matrix1 = matrix1 * var;
    i=i+1;
}

matrix2(2, int32)[2][2];
matrix2 = trans(matrix1);

matrix3(2, int32)[2][2];
matrix3 = matrix1@matrix2;

output(matrix3);
