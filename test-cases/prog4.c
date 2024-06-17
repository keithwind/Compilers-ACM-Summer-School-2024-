matrix1(2, int32)[2][2];
int32 var;
int8 count;

count = 0;

while(count<2){
    input(var);
    matrix1[0][count]=var;
    matrix1[1][count]=var*2;
}

matrix2(2, int32)[2][2];
matrix2 = matrix1/2;

matrix1 = matrix1**matrix2;
output(matrix1);
