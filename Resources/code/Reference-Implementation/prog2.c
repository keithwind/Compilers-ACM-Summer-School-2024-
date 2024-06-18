matrix1(2, int32)[2][2];
matrix2(2, int32)[2][2];
matrix3(2, int32)[2][2];

int32 init;

input(init);
input(matrix1);
input(matrix2); //taking tensors as inputs from stdin

//example of if-else branching 
if(init>10) then
{
    matrix3 = matrix1 + matrix2;
}
else
{
    matrix3 = matrix1 * matrix2;
}
output(matrix3); //printing matrix to the stdout
