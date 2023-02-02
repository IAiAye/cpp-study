//heap은 사용자가 자유롭게 할당하고 해제할 수 있다.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int student; 
    int i, input;
    int *score;
    int sum = 0;

    printf("학생의 수는? : ");
    scanf("%d", &student);

    score = (int *)malloc(student * sizeof(int));

    for ( i = 0; i < student; i++)
    {
        printf("학생 %d 의 점수 : ", i + 1);
        scanf("%d", &input);

        score[i] = input;
    }
    
    for ( i = 0; i < student; i++)
    {
        sum += score[i];
    }
    
    printf("전체 학생들의 평균 : %d \n", sum / student);
    free(score);

    return 0;
}