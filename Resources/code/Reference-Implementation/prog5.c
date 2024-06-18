matrix1(2, int32)[2][2];

int32 i;
int32 j;

i = 0;
j = 0;

int32 var;

while(i<2){
    while(j<2){
        input(var);
        matrix1[i][j]=var;
        j= j+1;
    }
    i = i+1;
    j=0;
}

matrix2(2, int32)[2][2];
matrix2 = trans(matrix1);

matrix3(2, int32)[2][2];
matrix3 = matrix1@matrix2;

output(matrix3);
