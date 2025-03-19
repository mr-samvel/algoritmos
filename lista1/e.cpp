#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void read_input(int &N, vector<int> &events, vector<int> &out_time) {
    cin >> N;

    events.resize(2*N);
    out_time.resize(N+1);

    for (int i = 0; i < 2*N; i++) {
        cin >> events[i];
        if (events[i] < 0)
            out_time[abs(events[i])] = i;
    }
}

// FIXME: 1 2 3 -2 -1 -3
vector<char> solve(vector<int> events, vector<int> out_time) {
    stack<int> G, S;
    vector<char> alocated_stack(out_time.size());
    vector<char> answer;
    
    for (int event : events) {
        int client = abs(event);
        if (event > 0) {
            bool can_be_G = G.empty() || out_time[client] < out_time[G.top()];
            bool can_be_S = S.empty() || out_time[client] < out_time[S.top()];

            if (!can_be_G && !can_be_S)
                return { '*' };
            
            if (can_be_G && can_be_S) {
                if (G.empty()) {
                    can_be_S = false;
                } else if (S.empty()) {
                    can_be_G = false;
                } else if (out_time[G.top()] > out_time[S.top()]) {
                    can_be_S = false;
                } else {
                    can_be_G = false;
                }
            }
            
            if (can_be_G) {
                G.push(client);
                alocated_stack[client] = 'G';
                answer.push_back('G');
            } else if (can_be_S) {
                S.push(client);
                alocated_stack[client] = 'S';
                answer.push_back('S');
            }
        } else if (event < 0) {
            if (alocated_stack[client] == 'G') {
                if(G.top() != client)
                    return { '*' };
                G.pop();
            } else if (alocated_stack[client] == 'S') {
                if (S.top() != client)
                    return { '*' };
                S.pop();
            }
        }
    }

    return answer;
}

int main() {
    int n;
    vector<int> events, out_time;
    
    read_input(n, events, out_time);
    vector<char> solution = solve(events, out_time);
    for (char s : solution)
        cout << s;
}