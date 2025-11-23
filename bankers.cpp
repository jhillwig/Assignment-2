#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool checkSafeState(vector<vector<int>>& allocMatrix, vector<vector<int>>& maxMatrix, vector<int>& availResources, int numProcs, int numRes) {
  vector<int> work(availResources);
  vector<bool> finish(numProcs, false);
  
  int numFinished = 0;
  while (numFinished < numProcs) {
    bool found = false;

    for (int i = 0; i < numProcs; ++i) {
      if (!finish[i]) {
        bool canExecute = true;

        for (int j = 0; j < numRes; ++j) {
          if (maxMatrix[i][j] - allocMatrix[i][j] > work[j]) {
            canExecute = false;
              break;
          }
        }

        if (canExecute) {
          for (int j = 0; j < numRes; ++j) {
            work[j] += allocMatrix[i][j];
          }

          finish[i] = true;
          found = true;
          ++numFinished;

          cout << "Executing Process " << i << endl;
        }
      }
    }

    if (!found) {
      cout << "System is not in a safe state." << endl;
      return false;
    }
  }
  
  cout << "System is in a safe state." << endl;
  return true;
  }

int main() {

}
