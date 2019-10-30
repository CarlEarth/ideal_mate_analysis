#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    //-----------------------------------------
    int   i;
    int   number[100];
    char  yes,yes1;
    char  a[100][50];
    float e[100][2];
    float good,bad,sum;
    FILE  *log1,*log2;
    char  ll[100],dash[100];
    int   num,logic,logic1,logic2,first_time ;
    
    //-----------------------------------------
    
    log1=fopen("data","r");  //input the file name
    
    
    //------read the logfile in the following part---------------------------
    fscanf(log1,"data_number= %d\n",&num);
    
    fscanf(log1,"%s\n",dash);
    
    for (i=0; i<num; i++) {
      fscanf(log1,"No. %d\n",&number[i]);
      fscanf(log1,"%[^\n]%*c\n",a[i]);
      fscanf(log1,"%f %f\n",&e[i][0],&e[i][1]);
      fscanf(log1,"%s\n",dash);
    }
    fclose(log1);
    //-----------------------------------------
    
    printf("Hello~ Welcome to the Bayes' statistic!");
    printf("(Press Enter to Continue)");
    while( getchar() != '\n' );
    if (num==0) {
        printf("Do you want to make a new analysis?(y/n): ");
    }
    else{
    printf("Do you want to add new data?(y/n): ");
    }
    //--------------check if want to add new data---------------------------
    i=0;
    logic=0;
    first_time=num;
    while (logic<1) {
    
      scanf(" %c",&yes);
      //printf(" yes=%d\n",yes);
      if (yes==110 || yes==121) {
        break;
      }
      else{
        logic=0;
        printf("Sorry, please enter your choice again~(y/n)\n");
          }
    }
    //--------------------------------------------------------------------
    if (yes==121) {
      logic1=0;
      //-----input the new data ------------------------------
      while (logic1<1) {
            logic2=0;
            if (first_time==0) {
                printf("input the name of your target: ");
            } else {
              printf("input the event: ");
            }
            scanf(" %[^\n]%*c",a[num+i]);
             if (first_time==0) {
                 printf("input the prior probabilty for this person to be your ideal mate(0.0~1.0) ");
            } else {
              printf("input the probability that a ideal mate has this behavior(0.0~1.0): ");
            }
            scanf(" %f",&e[num+i][0]);
            if (first_time==0) {
                printf("input the prior probabilty for this person to be your unfavorable mate(0.0~1.0) ");
            } else {
              printf("input the probability that a unfavorable mate has this behavior(0.0~1.0): ");
            }
            scanf(" %f",&e[num+i][1]);
            first_time=first_time+1;
            printf("Do you want to add another new data?(y/n): ");
            while (logic2<1) {
                scanf(" %c",&yes1);
                if (yes1==110 || yes1==121) {
                    logic2=2;
                }
                else{
                    logic2=0;
                    printf("Sorry, please enter your choice again~(y/n)\n");
                }

            }
            if (yes1==121) {
                logic1=0;
                i=i+1;
            }
            else {
                logic1=2;
                
            }
          
        }
        
    }
    if (yes==121) {
    num=num+(i+1);
    }
    good=e[0][0];
    bad=e[0][1];
    
    //------Calculate the probability~--------------
    for (i=1; i<num; i++) {
        sum=good*e[i][0]+bad*e[i][1];
        good=good*e[i][0]/sum;
        bad=bad*e[i][1]/sum;
        
    }
    if (first_time==0) {
        printf("Bye Bye~ See you next time!\n");
    } else {
         printf("There is a %.2f %% chance %s will be your ideal mate. \n",good*100.0,a[0]);
    }
    
    //write the new data into log file
    
    log2=fopen("data","w");
    fprintf(log2,"data_number= %d\n",num);
    fprintf(log2,"-------------------------\n");
    for (i=0; i<num; i++) {
      fprintf(log2,"No. %d\n",i+1);
      fprintf(log2,"%s\n",a[i]);
      fprintf(log2,"%f %f\n",e[i][0],e[i][1]);
      fprintf(log2,"-------------------------\n");
    }
    
    fclose(log2);
return 0;
}
