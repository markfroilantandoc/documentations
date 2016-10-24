#include <iostream>
#include <cmath>

int similarity(int a, int b){
  return 100 - std::abs(a-b);
}

int main() {
	
  int array1[5] = {1, 2, 3, 4, 5};
  int array2[5] = {3, 5, 1, 2, 4};
  int s_matrix[5][5];
  int ans[5];
	
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      s_matrix[i][j] = similarity(array1[i], array2[j]);
    }
  }
	
  for(int k=0; k<5; k++){
    int besti = 0;
    int bestj = 0;
    for(int i=0; i<5; i++){
      for(int j=0; j<5; j++){
        if(s_matrix[besti][bestj] < s_matrix[i][j]){
          besti = i;
          bestj = j;
        }
      }
    }
    ans[besti] = bestj;
    for(int i=0; i<5; i++){
      s_matrix[besti][i] = s_matrix[i][bestj] = 0;
    }
  }

  for(int i=0; i<5; i++){
    std::cout << i << "-" << ans[i] << std::endl; 
  }

  return 0;
}
