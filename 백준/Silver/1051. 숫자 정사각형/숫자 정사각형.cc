#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdio.h>
#define MAX 500
using namespace std;
 
int check(int field[MAX][MAX],int x, int y, int N, int M, int maxsize){
   int min_N_M = min(N, M);
   while (min_N_M != 0){
      if (sqrt(maxsize) > min_N_M){
         break;
      }
      else{
         if (field[x][y] == field[x + min_N_M-1][y] && field[x][y] == field[x][y + min_N_M-1] &&
            field[x][y] == field[x + min_N_M-1][y + min_N_M-1]){
            maxsize = min_N_M * min_N_M;
            break;
         }
      }
      min_N_M--;
   }
   return maxsize;
}
int main()
{
   int N, M;
   cin >> N >> M;
   int max_size = 1;
   int field[MAX][MAX];
   for (int a = 0; a < N; a++){
      string line;
      cin>>line;
      for (int b = 0; b < M; b++){
         field[a][b] = line.at(b);
      }
   }
   for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++){
         max_size = check(field, i, j, N, M, max_size);
      }
   }
   cout << max_size << endl;
}