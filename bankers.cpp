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
  ifstream inputFile("input.txt");

  if (!inputFile) {
    cerr << "Error opening file." << endl;
    return 1;
  }

  int numProcs, numRes;
  inputFile >> numProcs >> numRes;

  vector<vector<int>> allocMatrix(numProcs, vector<int>(numRes));
  vector<vector<int>> maxMatrix(numProcs, vector<int>(numRes));

  for (int i = 0; i < numProcs; i++) {
    for (int j = 0; j < numRes; j++) {
      inputFile >> allocMatrix[i][j];
    }
  }

  for (int i = 0; i < numProcs; i++) {
    for (int j = 0; j < numRes; j++) {
      inputFile >> maxMatrix[i][j];
    }
  }

  vector<int> availResources(numRes);
  for (int j = 0; j < numRes; j++) {
    inputFile >> availResources[j];
  }

  cout << "allocation:" << endl;
  for (int i = 0; i < numProcs; i++) {
    for (int j = 0; j < numRes; j++) {
      cout << allocMatrix[i][j] << ' ';
    }
    cout << endl;
  }

  cout << "max:" << endl;
  for (int i = 0; i < numProcs; i++) {
    for (int j = 0; j < numRes; j++) {
      cout << maxMatrix[i][j] << ' ';
    }
    cout << endl;
  }

  cout << "available:" << endl;
  for (int j = 0; j < numRes; j++) {
    cout << availResources[j] << ' ';
  }
  cout << endl;

  checkSafeState(allocMatrix, maxMatrix, availResources, numProcs, numRes);

  return 0;
}
