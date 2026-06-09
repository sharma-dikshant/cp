#include<iostream>
using namespace std;


int findParent(int node, vector<int>& parents) {
    if (parents[node] == node) return node;
    return findParent(parents[node], parents);
}

int unionNodes(int x, int y, vector<int>& parents) {
    int parent_x = findParent(x, parents),
        parent_y = findParent(y, parents);

    if (parent_x == parent_y) return parent_x;

    parents[parent_y] = parent_x;
    return parent_x;
}


int main() {

    cout << "Disjoint Union Set" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Option '1': Tell the parent of node x:" << endl;
    cout << "Option '2': Union the nodes x, y:" << endl;
    cout << "Option '3': Does node x and y belong to same parent:" << endl;
    cout << "Option '-1': exit" << endl;
    cout << "----------------------------------------------------------" << endl;

    
    cout << ">> Enter the Maximum Possible nodes: ";
    int n; cin >> n;
    vector<int>parents(n);

    for (int i = 0; i < n; i++) parents[i] = i;

    while (true) {
        cout << ">> Enter Choices: ";
        int t, x, y; cin >> t;

        switch (t) {
        case 1: {
            cout << ">> Enter the node values (x): ";
            cin >> x;
            cout << "Parent: " << findParent(x, parents) << endl;
            break;
        }
        case 2: {
            cout << ">> Enter the node values (x, y): ";
            cin >> x >> y;
            unionNodes(x, y, parents);
            cout << "Union Done!" << endl;
            break;
        }
        case 3: {
            cout << ">> Enter the node values (x, y): ";
            cin >> x >> y;
            int parent_x = findParent(x, parents),
            parent_y = findParent(y, parents);
            
            if (parent_x != parent_y) {
                cout << "nodes (x, y) belongs to same set" << false << endl;
            } else {
                cout << "nodes (x, y) belongs to same set" << true << ", " << parent_x << endl;
            }
            break;
        }
        case -1:
            cout << "Program End!" << endl;
            return 0;
        default:
            cout << "invalid input!" << endl;
            break;
        }
    }

return 0;
}