//
// Created by Neptune on 5/2/16.
//

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

    class UnionFind {
        vector<int> id_;
        int count_;

      public:
        UnionFind(int N) : id_(vector<int>(N)), count_(N) {
            for (int i = 0; i < N; ++i)
                id_[i] = i;
        }

        int count() {
            return count_;
        }

        int find(int p) {
            return id_[p];
        }

        bool connected(int p, int q) {
            return id_[p] == id_[q];
        }

        void union_pq(int p, int q) {
            int pID = id_[p];
            int qID = id_[q];

            if (pID == qID)
                return;

            for (int i = 0; i < id_.size(); ++i) {
                if (id_[i] == pID) id_[i] = qID;
            }
        }
    };

  public:
    bool validTree(int n, vector<vector<int>> &edges) {
        return true;
    }

};

int main() {
    return 0;
}
