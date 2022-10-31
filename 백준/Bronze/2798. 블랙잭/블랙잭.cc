#include<iostream>
#include<vector>
using namespace std;
 
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
 
    vector<int> deck;
    int result = 0;
    for (int i = 0; i < N; i++) {
        int card;
        scanf("%d", &card);
        deck.push_back(card);
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N ; j++) {
            if(i==j){
                continue;
            }
            for (int k =0; k < N; k++)
            {
                  if(k==j||k==i){
                continue;
            }
                
                if (deck[i] + deck[j] + deck[k] <= M &&M - (deck[i] + deck[j] + deck[k]) < M - result)
                {
                    result = deck[i] + deck[j] + deck[k];
 
                }
 
            }
        }
    }
 
    printf("%d", result);
 
    return 0;
}