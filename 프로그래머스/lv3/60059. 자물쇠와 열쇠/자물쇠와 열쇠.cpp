#include <string>
#include <vector>

using namespace std;

int K, L, B;

void rotate_key(vector<vector<int>> &key) {
    vector<vector<int>> tmp(K, vector<int>(K, 0));
    for(int i=0; i<K; ++i) {
        for(int j=0; j<K; ++j) {
            tmp[i][j] = key[K-(j+1)][i];
        }
    }
    
    key = tmp;
}

bool check(vector<vector<int>> &board, vector<vector<int>> &key, int y, int x) {
    bool ret = true;
    for(int i=0; i<K; ++i) {
        for(int j=0; j<K; ++j) {
            board[i+y][j+x] += key[i][j];
        }
    }
    
    // 가운데 lock 영역이 모두 1이면 true, 아니면 false
    for(int i=0; i<L; ++i) {
        for(int j=0; j<L; ++j) {
            if(board[i+K-1][j+K-1] != 1) {
                ret = false;
                break;
            }
        }
    }    
    
    for(int i=0; i<K; ++i) {
        for(int j=0; j<K; ++j) {
            board[i+y][j+x] -= key[i][j];
        }
    }
    
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    K = key.size(), L = lock.size();
    B = 2*(K-1) + L;
    
    vector<vector<int>> board(B, vector<int>(B, 0));
    
    // 가운데에 lock 영역 두기 (3번)
    for(int i=0; i<L; ++i) {
        for(int j=0; j<L; ++j) {
            board[i+K-1][j+K-1] = lock[i][j];
        }
    }    
    
    for(int r=0; r<4; ++r) { // key 4번 회전
        for(int i=0; i<=B-K; ++i) { // key를 처음부터 끝까지 슬라이딩 (1, 2번)
            for(int j=0; j<=B-K; ++j) {
                if(check(board, key, i, j)) return true;
            }
        }
        
        rotate_key(key);
    }
    
    return false;
}