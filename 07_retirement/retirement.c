#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  
  int months;
  double contribution;
  double rate_of_return;

};

typedef struct _retire_info retire_info;

void retirement (int startAge, double initial, retire_info working, retire_info retired){

  double currBalance = initial;
  int age = startAge;
  for(int i = 0; i < working.months; i++){
    printf("Age %3d month %2d you have $%.2lf\n",age/12,age%12,currBalance);
    currBalance = currBalance + currBalance * working.rate_of_return;
    currBalance = currBalance + working.contribution;
    age++;
  }
  for(int i = 0; i < retired.months; i++){
    printf("Age %3d month %2d you have $%.2lf\n",age/12,age%12,currBalance);
    currBalance = currBalance + currBalance * retired.rate_of_return;
    currBalance = currBalance + retired.contribution;
    age++;
  }
}

int main(void){
  retire_info working_period;
  retire_info retired_period;

  working_period.months = 489;
  working_period.contribution = 1000;
  working_period.rate_of_return = 0.045/(double)12;

  retired_period.months = 384;
  retired_period.contribution = -4000;
  retired_period.rate_of_return = 0.01/(double)12;

  int start_Age = 327;
  double start_balance = 21345;

  retirement(start_Age, start_balance, working_period, retired_period);

  return EXIT_SUCCESS;
}
