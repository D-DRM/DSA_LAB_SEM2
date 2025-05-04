#include <iostream>
#include <cstdio>
using namespace std;

//palindrome
bool ispalindrome(int* number){
    int* original= (int*)malloc(sizeof(int));
    *original=*number;
    int* reverse=(int*)malloc(sizeof(int));
    int* remainder=(int*)malloc(sizeof(int));
    if(reverse==nullptr||remainder==nullptr){
        printf("dynamic memory not allocated \n");
        return false;
    }
    *reverse=0;
    while((*number)!=0){
        *remainder=*number%10;
        *reverse=(*reverse)*10+(*remainder);
        *number/=10;
    }
    bool* result=(bool*)malloc(sizeof(bool));
    *result=((*original)==(*reverse));
    return *result;

    free(reverse);
    free(remainder);
}

//ARMSTRONG NUMBER
bool isarmstrong(int *number){
    int* original=(int*)malloc(sizeof(int));
    *original=*number;
    int* sum=(int*)malloc(sizeof(int));
    int* digit=(int*)malloc(sizeof(int));
    while(*number!=0){
        *digit=*number%10;
        *sum+=((*digit)*(*digit)*(*digit));
        *number/=10;
    }
    bool* result=(bool*)malloc(sizeof(bool));
    *result=((*original)==(*sum));
    return *result;
    free(original);
    free(sum);
    free(digit);
}

//PERFECT NUMBER
bool isperfect(int *number){
    int* original=(int*)malloc(sizeof(int));
    *original=*number;
    int* sum=(int*)malloc(sizeof(int));
    *sum=0;
    int* i=(int*)malloc(sizeof(int));
    for((*i)=1;(*i)<=((*original)/2);(*i)++){
        if((*original)%(*i)==0){
            *sum+=(*i);
        }
    }
    bool* result=(bool*)malloc(sizeof(bool));
    *result=((*original)==(*sum));
    return *result;

    free(sum);
    free(i);

}
void menu(){
        printf("The menu is: \n");
        printf("1. Palindrome\n");
        printf("2. Armstrong number \n");
        printf("3. Perfect number \n");
        printf("4.exit \n");
        printf("enter choice \n");
        } 

int main(){
    int* choice= (int*)malloc(sizeof(int));
    do{
        //menu driven program
        menu();
        scanf("%d",choice);
        int* number;
        number=(int*)malloc(sizeof(int));

        switch(*choice){
        case 1:
            
            printf("enter number \n");
            scanf("%d",number); 
            if(ispalindrome(number)){
                printf("It is a palindrome \n");
            }
            else{
                printf("It is not a palindrome \n");
            }
            break;

        case 2:
            printf("enter number \n");
            scanf("%d",number);
            if(isarmstrong(number)){
                printf("It is an armstrong number \n");
            }
            else{
                printf("It is not armstrong number \n");
            }
            break;

        case 3:
            printf("enter number \n");
            scanf("%d",number);
            if(isperfect(number)){
                printf("It is a perfect number \n");
            }
            else{
                printf("Not perfect number \n");
            }
            break;


        case 4:
            printf("Exiting operation \n");
            break;
        default:
            printf("Invalid input \n");
            break;

     }
      free(number);
    }while(*choice !=4);
    return 0;
   
}