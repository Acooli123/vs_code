#include<stdio.h>
int main(){
    int arr[5]= {1,2,3,2,1};
    int brr[5];
    for(int i=0; i<=4; i++){
        brr[i]=arr[4-i];
    }
    if(brr[5]==arr[5]){
        printf("it is a palindrome");
    }
    
    
    
    return 0;
}