#include <iostream>
#include <vector>

using namespace std;

class Job {
    public:
        int deadline;
        int profit;
        int id;

        Job(int id, int deadline, int profit): id(id), deadline(deadline), profit(profit) {}

        bool operator < (Job j1) {
            return this->profit < j1.profit;
        }
};

int main() {
    int jobsInfo[][2] = {{4, 20}, {1, 10}, {1, 40}, {1, 30}};
    int length = sizeof(jobsInfo) / sizeof(jobsInfo[0]);
    vector<Job> jobs;

    for (int i = 0; i < length; i++) {
        jobs.push_back(Job(i, jobsInfo[i][0], jobsInfo[i][1]));
    }

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (jobs[i] < jobs[j]) {
                Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    vector<int> seq;
    int time = 0;

    for (int i = 0; i < jobs.size(); i++) {
        Job curr = jobs.at(i);
        if (curr.deadline > time) {
            seq.push_back(curr.id);
            time++;
        }
    }

    cout << "Max Jobs = " << seq.size() << endl;
    for (int i = 0; i < seq.size(); i++) {
        cout << seq.at(i) << " ";
    }
    cout << endl;

    return 0;
}