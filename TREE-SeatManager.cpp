// LeetCode 1845: Seat Reservation ManagerProblem DescriptionDesign a system that manages the reservation state of $n$ seats that are numbered from $1$ to $n$.  

class SeatManager {
private:
    // Min-heap to automatically keep the smallest available seat number at the top
    priority_queue<int, vector<int>, greater<int>> minHeap; 

public:
    // Constructor: Populates the min-heap with all seats from 1 to n
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            minHeap.push(i); // Insert each seat into the heap
        }
    }
    
    // Fetches and removes the smallest-numbered unreserved seat
    int reserve() {
        int lowestSeat = minHeap.top(); // Get the smallest available seat from the top of the heap
        minHeap.pop();                  // Remove it from the heap since it's now reserved
        return lowestSeat;              // Return the reserved seat number
    }
    
    // Puts a reserved seat back into the pool of available seats
    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);       // Insert the seat back into the heap to make it available again
    }
};
