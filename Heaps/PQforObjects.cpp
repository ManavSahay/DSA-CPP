#include <iostream>
#include <queue>

using namespace std;

class Student {
    public:
        string name;
        int rank;

        Student(string name, int rank): name(name), rank(rank) {}

        bool operator > (Student s1) const {
            return this->rank > s1.rank;
        }
};

int main() {
    priority_queue<Student, vector<Student>, greater<Student>> pq;

    pq.push(Student("A", 4));
    pq.push(Student("B", 5));
    pq.push(Student("C", 2));
    pq.push(Student("D", 12));

    while (!pq.empty()) {
        cout << pq.top().name << " --> " << pq.top().rank << endl;
        pq.pop();
    }

    return 0;
}