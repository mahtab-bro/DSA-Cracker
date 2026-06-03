// LeetCode 1046: Last Stone Weight (Easy)
// You are given an array of integers stones where stones[i] is the weight of the $i^{th}$ stone.  We are playing a game with the stones.
//   On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. 
//   The result of this smash is:  If x == y, both stones are destroyed.  If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
//   At the end of the game, there is at most one stone left. Return the weight of the last remaining stone. If there are no stones left, return 0.

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // priority_queue in C++ is a Max-Heap by default.
        // Why? Because we constantly need the TWO HEAVIEST stones. 
        // A Max-Heap keeps the largest element at the top in O(1) time and re-sorts in O(log N) time.
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        
        // Loop runs as long as there are at least two stones left to smash together
        while (maxHeap.size() > 1) {
            // Top of the heap is always the absolute heaviest stone (y)
            int y = maxHeap.top();
            maxHeap.pop(); // Remove it so we can look at the next heaviest
            
            // The new top is now the second heaviest stone (x)
            int x = maxHeap.top();
            maxHeap.pop(); // Remove it to perform the smash simulation
            
            // If the stones are not equal, a smaller stone is born from the smash (y - x)
            if (x != y) {
                // Push the leftover weight back. The heap automatically repositions it.
                maxHeap.push(y - x);
            }
        }
        
        // If the heap is empty, all stones destroyed each other -> return 0.
        // If one stone is left, that's our winner -> return its weight.
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
