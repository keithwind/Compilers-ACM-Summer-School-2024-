matrix1(2, int32)[2][2];     matrix2(2, int32)[2][2];

result(2,int32)[2][2];

matrix1[0][0]=0; matrix2[0][0]=0;
matrix1[0][1]=1; matrix2[0][1]=1;
matrix1[1][0]=2; matrix2[1][0]=2;
matrix1[1][1]=3; matrix2[1][1]=3;

if(matrix1==matrix2) then {
    matrix1=matrix1*5;
    result=matrix1**matrix2;
}

else {
    result=matrix1@matrix2;
}
