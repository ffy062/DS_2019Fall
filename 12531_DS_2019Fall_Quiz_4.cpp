#include <iostream>
#include <stack>
#include <string>

using namespace std;

char graph[1001][1001];
int dis_to[1001][1001], min_dis[1001][1001];
int pre[1001];

void init_ss(int vertex) {
    for(int i = 0; i )
}

void find_ss(int vertex) {

}
int detect_negcycle(int from, int to, int vertex) {
    for(int i = 0; i < vertex; ++i) {
        if(dis_to[from][to] > dis_to[from][i] + dis_to[i][to])
            return 1;
    }
    return 0;
}

int main() {
    int vertex, idxa, idxb, dis, update;
    string op_type;
    
    cin >> vertex;

    //initialize
    for(int i = 0; i < vertex; ++i) {
        for(int j = 0; j < vertex; ++j) {
            graph[i][j] = '0';
        }
    }
    update = 0;

    //input operation
    while(cin >> op_type) {
        cin >> idxa >> idxb;
        if(op_type == "Add") {
            update = 1;
            cin >> dis;
            graph[idxa][idxb] = '1';
            grpah[idxb][idxa] = '1';
            dis_to[idxa][idxb] = dis;
            dis_to[idxb][idxa] = dis;
        }
        else if(op_type == 'Delete') {
            update = 1;
            graph[idxa][idxb] = '0';
            graph[idxb][idxa] = '0';
        }
        else if(op_type == "Shrotest") {
            if(update == 1) {

            }
            else {

            }
            update = 0;
        }
    }
    return 0;
} 