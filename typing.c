#include <stdio.h>
#include <string.h>
#include <time.h>
int main()
{
 int i = 0 , n = 20;
 char temp[100];
 int correctWords = 0; 
 int totalWords = 0;
 float total_time = 0, sum = 0;
 float average_accuracy; 
 char input [100];
 float accuracy, totalAccuracy = 0;
 char *words[] = {"I love coding" , "typing helps improve focus" , "C is a structured programming language." , "This project is developed using C language." , "Thank you for using the Typing Speed Tester" };



// char *target = words[2];

printf( "\n \t TYPE THE GIVEN SENTENCES \t \n" );

for(int i=0; i<=4; i++){
    char *target = words[i];
    strcpy(temp, target);
   
char *original = strtok( temp, " ");    //original word count (spliting each word)

    printf("\n\n given :  %s \n", target);
 time_t start , end;

 start = time(NULL);

 printf("\n type here :  ");                //input sentence
 fgets(input, sizeof(input),stdin);
 char *typedword = strtok( input, " " );     //input words count
input[strcspn(input, "\n")] = 0;


end = time(NULL);

printf("\n time required is %.2f", difftime(end,start));     //time for one sentence
total_time += difftime(end,start);

while( original != NULL && typedword != NULL){    
if(strcmp(original,typedword) == 0)       //comparing words
{
    correctWords++;
}
 totalWords++;

 original = strtok(NULL, " ");      //move to next word
}


accuracy = ((float)correctWords / totalWords) * 100;          //calculaate accuracy
printf ("\n ACCURACY = %.2f ",accuracy);
sum += accuracy;

}

average_accuracy = sum / 5;

printf("\n \n FINAL RESULTS ");
printf("\n \n AVERAGE ACCURACY     :    %.2f ", average_accuracy);
printf("\n TOTAL TIME REQUIERED    :    %.2f ", total_time);
printf("\n \t  Thank You!");
return 0;
}