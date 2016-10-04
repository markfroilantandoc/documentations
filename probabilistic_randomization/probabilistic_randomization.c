#include <stdio.h>

int main(int argc, char *argv[]){

  int probabilities[argc-1];
  int i, count, rn, index;

  count = argc-1;
  for(i=0; i<count; i++){
    probabilities[i] = atoi(argv[i+1]);
  }

  rn = (rand()%100) + 1;
  for(i=0, index=0; i<count; i++){
    index += probabilities[i];
    if(rn < index){
      break;
    }
  }
  printf("%d\n", i);

  return 0;

}
