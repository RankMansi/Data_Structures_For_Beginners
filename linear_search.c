// #include<stdio.h>
// #include<conio.h>

// int main(){
//     int ele, num;
//     int arr[ele];
//     printf("Enter the numeber of elements: ");
//     scanf("%d",&ele);

//     printf("Enter the elements of an array: ");
//     for(int i=0 ; i<ele ; i++){
//             scanf("%d",&arr[i]);
//     }

//     printf("Enter the number you want to search: ");
//     scanf("%d",&num);

//     for(int i=0 ; i<ele ; i++){
//         if(arr[i]==num){
//             printf("%d is present at index %d\n",num,i+1);
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include<conio.h>
    int main(){
    int n, number, i, index ,flag;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    flag=0;
    printf("Enter Number to be searched: ");
    scanf("%d", &number);
    for (i = 0; i < n; i++) {
        if (number == arr[i]) {
            index = i;
            flag = 1;
            break; 
        }
    }
    if (flag == 1) {
        printf("Number is found at index %d in array", index);
    } 
    else {
        printf("Number not found");
    }
    return 0;
}