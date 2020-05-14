#include <stdio.h>

void check(int *avaliable, int *needed, int *max, int *printNum);
void printN(int *printNum);
void rotate(int *avaliable, int *needed, int *max, int *printNum);
void changeHead(int a, int *needed, int *max, int *printNum);
void swapNum(int a, int b, int *arr);
void swap(int a, int b, int *arr);

int main()
{
    int totalResources[3] = {10, 5, 7};
    int allocation[12] = {0, 1, 0,2, 0, 0, 3, 0, 2,2, 1, 1};
    int max[12] = {7, 5, 3, 3, 2, 2, 9, 0, 2, 2, 2, 2};
    int needed[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int avaliable[3] = {10, 5, 7};
    int printNum[5] = {1, 2, 3, 4, 0};
    printf("Safe sequence: \n");

    for (size_t i = 0; i < 4; i++)
    {
        avaliable[0] = avaliable[0] - allocation[i*3+0];
        avaliable[1] = avaliable[1] - allocation[i*3+1];
        avaliable[2] = avaliable[2] - allocation[i*3+2];
    }

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            needed[i*3+j] = max[i*3+j] - allocation[i*3+j];
        }
    }
    for (size_t i = 0; i < 4; i++)
    {
        changeHead(i,&needed[0], &max[0], printNum);
        rotate(avaliable, &needed[0], &max[0], printNum);
    }
    
    printf("total %d safe sequence.",printNum[4]);
    return 0;
}

void rotate(int *avaliable, int *needed, int *max, int *printNum){
    for (size_t i = 0; i < 6; i++)
    {
        if (i%2 == 0)
        {
            swap(2,3,needed);
            swap(2,3,max);
            swapNum(2,3,printNum);
        }
        else
        {
            swap(1,2,needed);
            swap(1,2,max);
            swapNum(1,2,printNum);
        }
        check(avaliable,needed,max,printNum);
    }
    
}

void changeHead(int a, int *needed, int *max, int *printNum){
    int temp = 0;
    swap(a,0,needed);
    swap(a,0,max);
    swapNum(a,0,printNum);
    
}
void swapNum(int a, int b, int *arr){
    int temp = 0;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void swap(int a,int b,int *arr){
    int temp[3] = {0,0,0};
    for (size_t i = 0; i < 3; i++)
    {
        temp[i] = arr[a*3+i];
        arr[a*3+i] = arr[b*3+i];
        arr[b*3+i] = temp[i];
    }
}

void check(int *avaliable, int *needed, int *max, int *printNum)
{
    int avaliableNew[3] = {0, 0, 0};
    int isMeet = 1;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (needed[3 * i + j] > avaliable[j]+avaliableNew[j])
            {
                isMeet = 0;
                break;
            }
            else
            {
                avaliableNew[j] = avaliableNew[j] + max[3 * i + j] - needed[3 * i + j];
                isMeet = 1;
            }
            
        }
        if (isMeet == 0)
        {
            break;
        }
    }
    if (isMeet == 1)
    {
        printNum[4]++;
        printN(printNum);
    }
}

void printN(int *printNum)
{
    for (size_t i = 0; i < 4; i++)
    {
        printf("%c", 80);
        printf("%d ", printNum[i]);
        if (i != 3)
        {
            printf("%c%c ", 45,62);
        }
    }
    printf("\n");
}