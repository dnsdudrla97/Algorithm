// #include <stdio.h>
// int main(void)
// {
//     int array[3]={10,20,30};
//     int i=0;
//     int* p=NULL;

//     p=array;

//     for (i=0; i<3; i++)
//     {
//         printf("%d %d %d \n", *(p+i), *&p[i], p[i]);
//     }

//     printf("------------------------------\n");
//     for (i=0; i<3; i++)
//     {
//         printf("%d %d %d \n", *(array+i), *&array[i], array[i]);
//     }
//     return (0);
// }