#include <iostream>
#include <vector>

using namespace std;

class Heap {
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
            }
        }
};

int main() {
    Heap heap;
    heap.add(3);
    heap.add(1);
    heap.add(2);
    heap.add(4);
    heap.add(5);

    return 0;
}