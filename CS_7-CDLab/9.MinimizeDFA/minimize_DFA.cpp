
#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int t[N][N]; // transition table
bool fs[N]; // final states
bool printed[N];
vector<vector<int> > pi[2]; // set of equivalence classes

// n is no of states, m is no of input symbols, nfs is no of final states
int n, m, nfs;

// Returns the index of the equivalence class containing x in pi[0]
int idx(int x) {
	for(int i=0; i<pi[0].size(); i++) {
		for(int j=0; j<pi[0][i].size(); j++) {
			if(pi[0][i][j] == x) return i;
		}
	}
}

// Prints the minimised DFA
void print_min() {
    cout << "\n Minimised DFA Table:\n";
    cout << "---------------------\n";
    cout << "Q\t";
    for(int j=0; j<m; j++) cout << j << "\t"; cout << endl << endl;
    for(int i=0; i<n; i++) {
        if(printed[i] == 1) continue;
        int ind = idx(i);
        cout << "[";
        for(int k=0; k<pi[0][ind].size(); k++) {
            cout << pi[0][ind][k];
            printed[k] = 1;
        }
        cout << "]\t";
        for(int j=0; j<m; j++) { 
            ind = idx(t[i][j]);
            cout << "[";
            for(int k=0; k<pi[0][ind].size(); k++) {
                cout << pi[0][ind][k];
            }
            cout << "]\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){

    /*
        Input:
            1 2
            1 3
            1 2
            1 4
            1 2
    
    */

    n = 5, m = 2;
    nfs = 1; // only 1 final state  
    // mark the final states:
    fs[4] = 1;

    // Input transition table:
    for(int i=0; i<n; i++) {
    	for(int j=0; j<m; j++) {
    		cin >> t[i][j];
    	}
    }

    // Init the set of equivalence classes
    vector<int> v[2];
    for(int i=0; i<n; i++) {
    	v[fs[i]].push_back(i);
    }
    pi[0].push_back(v[0]); pi[0].push_back(v[1]);
    pi[1] = pi[0];

    // max iterations 
    int iters = 100;
    // Decompose the equivalence classes till old and new pi are not equal
    while(iters--) {
    	pi[0] = pi[1];
        // pi[1] is the new set, pi[0] is the old set

    	for(int i=0; i<pi[1].size(); i++) {
    		for(int j=1; j<pi[1][i].size(); j++) {
                // find the correct equivalence class for pi[1][i][j]
    			bool placed = 0;
    			for(int k=0; k<j; k++) {
    				// check pi[1][i][j] with pi[1][i][k]
    				bool compat = 1;
    				for(int l=0; l<m; l++) {
    					if(idx(t[pi[1][i][j]][l]) != idx(t[pi[1][i][k]][l])) {
                            compat = 0;
                            break;
                        }
    				}
    				if(compat) {
    					// pi[1][i][j] can remain in same place
    					placed = 1;
    					break;
    				}
    			}
    			if(placed) continue;
    			for(int x = pi[0].size(); x<pi[1].size(); x++) {
	    			for(int k=0; k<pi[1][x].size(); k++) {
	    				// check pi[1][i][j] with pi[1][x][k]
	    				bool compat = 1;
	    				for(int l=0; l<m; l++) {
	    					if(idx(t[pi[1][i][j]][l]) != idx(t[pi[1][x][k]][l])) {
                                compat = 0;
                                break;
                            }
	    				}
	    				if(compat) {
	    					// remove pi[1][i][j] from pi[1][i], insert in pi[1][x]
	    					pi[1][x].push_back(pi[1][i][j]);
	    					pi[1][i].erase(pi[1][i].begin() + j);
	    					placed = 1;
	    					break;
	    				}
	    			}
	    			if(placed) break;
    			}
    			if(placed) continue;
    			// create new set {pi[1][i][j]} and insert at end of pi[1]
    			vector<int> vv; vv.push_back(pi[1][i][j]);
    			pi[1].push_back(vv); pi[1][i].erase(pi[1][i].begin() + j);
    		}
    	}
    	// compare pi[0] and pi[1]
    	for(int i=0; i<pi[0].size(); i++) {
    		sort(pi[0][i].begin(), pi[0][i].end());
    	}
    	sort(pi[0].begin(), pi[0].end());
    	for(int i=0; i<pi[1].size(); i++) {
    		sort(pi[1][i].begin(), pi[1][i].end());
    	}
    	sort(pi[1].begin(), pi[1].end());
    	if(pi[0] == pi[1]) break;
    }

    assert(pi[0] == pi[1]);

    print_min();

    return 0; 
}
