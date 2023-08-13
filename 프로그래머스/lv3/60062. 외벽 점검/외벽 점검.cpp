#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 987654321;
    int weak_size = weak.size();
    
    for(int i=0; i<weak_size-1; i++){//2배로 늘리기!
        weak.push_back(weak[i] + n);
    }
    
    sort(dist.begin(), dist.end());
    
    
    do {
        for(int i=0; i<weak_size; i++) {//시작지점 선택!
            
            int start = weak[i];//시작점
            int end = weak[i+weak_size-1];//끝점
            
            for(int j=0; j<dist.size(); j++) {
                start += dist[j]; //차례대로 친구연결
                
                if(start >= end) { //시작점이 끝점을 넘어갈때 -- > 탐색끝!
                    answer = min(answer, j+1);
                    break;
                }
                
                for(int z=i+1; z<i+weak_size; z++) {//탐색이 안끝났을때! 첫번째친구를 다음 지점으로 이동! 다시탐색시작!
                    if(weak[z] > start) {
                        start = weak[z];
                        break;
                    }
                }
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == 987654321) return -1;
    
    return answer;
}