matrix1(2, int32)[2][2];
int32 init;
int8 count;

init=2;
count=0;

matrix1[0][0]=init*init;
matrix1[0][1]=init/init;
matrix1[1][0]=init+init;
matrix1[1][1]=init-init;

while(count<2){
    matrix1[count][0] = matrix1[count][0] - 1;
    matrix1[count][1] = matrix1[count][1] + 1;
    count = count+1;
}
