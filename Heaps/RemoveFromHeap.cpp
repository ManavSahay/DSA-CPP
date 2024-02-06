#include <iostream>
#include <vector>

using namespace std;

class Heap {
    private:
        void heapify(int i) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int minIdx = i;

            if (left < vec.size() && vec.at(minIdx) > vec.at(left)) {
                minIdx = left;
            }
            
            if (right < vec.size() && vec.at(minIdx) > vec.at(right)) {
                minIdx = right;
            }

            if (minIdx != i) {
                int temp = vec.at(i);
                vec[i] = vec.at(minIdx);
                vec[minIdx] = temp;

                heapify(minIdx);
            }
        }

    public:
        vector<int> vec;

        void add(int data) {
            vec.push_back(data);

            int x = vec.size() - 1;
            int par = (x - 1) / 2;

            while (vec.at(x) < vec.at(par)) {
                int temp = vec.at(x);
                vec[x] = vec[par];
                vec[par] = temp;

                x = par;
                par = (x - 1) / 2;
            }
        }

        int peek() {
            return vec.at(0);
        }

        int remove() {
            int data = vec.at(0);

            int temp = vec.at(0);
            vec[0] = vec.at(vec.size() - 1);
            vec[vec.size() - 1] = temp;

            vec.pop_back();

            heapify(0);
            return 0;
        }

        bool isEmpty() {
            return vec.size() == 0;
        }
};

int main() {
    Heap heap;
    heap.add(3);
    heap.add(4);
    heap.add(1);
    heap.add(5);

    while (!heap.isEmpty()) {
        cout << heap.peek() << endl;
        heap.remove();
    }

    return 0;
}