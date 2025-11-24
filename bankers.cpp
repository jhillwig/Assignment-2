#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool checkSafeState(vector<vector<int>>& allocMatrix, vector<vector<int>>& maxMatrix, vector<int>& availResources, int numProcs, int numRes) {
  vector<int> work(availResources);
  vector<bool> finish(numProcs, false);
  
  int numFinished = 0;
  // Looking for processes who's needs can be met by currently available resources
  while (numFinished < numProcs) {
    bool found = false;

    // Checking each process to see if it can run safely
    for (int i = 0; i < numProcs; ++i) {
      if (!finish[i]) {
        bool canExecute = true;

        // Checking to see if a process can run based off of resources needed vs resources available
        for (int j = 0; j < numRes; ++j) {
          if (maxMatrix[i][j] - allocMatrix[i][j] > work[j]) {
            canExecute = false;
              break;
          }
        }

        // Simulate finishing the process if it can run
        if (canExecute) {
          for (int j = 0; j < numRes; ++j) {
            work[j] += allocMatrix[i][j];
          }

          finish[i] = true;    // Mark as completed
          found = true;        // Progress was made
          ++numFinished;       // Counting finished processes

          cout << "Executing Process " << i << endl;
        }
      }
    }

    // If the process couldnt run, the system is considered unsafe 
    if (!found) {
      cout << "System is not in a safe state." << endl;
      return false;
    }
  }

  // All processes could run safely
  cout << "System is in a safe state." << endl;
  return true;
  }


int main() {
  ifstream inputFile("input.txt");

  // Check file open
  if (!inputFile) {
    cerr << "Error opening file." << endl;
    return 1;
  }

  int numProcs, numRes;
  // Reading number of processes and resource types
  inputFile >> numProcs >> numRes;

  // Creating allocation and maximum matrices
  vector<vector<int>> allocMatrix(numProcs, vector<int>(numRes));
  vector<vector<int>> maxMatrix(numProcs, vector<int>(numRes));

  // Read allocation matrix
  for (int i = 0; i < numProcs; i++) {
    for (int j = 0; j < numRes; j++) {
      inputFile >> allocMatrix[i][j];
    }
  }

  // Reading Maximum matrix
  for (int i = 0; i < numProcs; i++) {
    for (int j = 0; j < numRes; j++) {
      inputFile >> maxMatrix[i][j];
    }
  }

  // Reading in available resources
  vector<int> availResources(numRes);
  for (int j = 0; j < numRes; j++) {
    inputFile >> availResources[j];
  }

  // Printing matrices for verification
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

  // Run Banker's algortihm
  checkSafeState(allocMatrix, maxMatrix, availResources, numProcs, numRes);

  return 0;
}
