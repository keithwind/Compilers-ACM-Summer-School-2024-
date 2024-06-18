matrix1(2, int32)[2][2];
int32 var;
int32 count;

count = 0;
input(matrix1);
//while loop
while(count<2){
    input(var);
    matrix1 =matrix1 + var;
    count = count + 1;
}

matrix2(2, int32)[2][2];
matrix2 = matrix1/2; //dividing a tensor with a scalar

matrix1 = matrix1**matrix2; //matrix multiplication
output(matrix1);
