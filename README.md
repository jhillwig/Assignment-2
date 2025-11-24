# Assignment-2
Banker's Assignment Operating Systems Kent State By Josh Hillwig

---
## Assignment information
Requirements:
- Use C/C++ in Linux/Unix. Consider installing virtualBox in your non-Linux environment.
- Programs must succeed in compilation and execution as required (80 points).
- Readme, documentation, and examples are required (20 points).

Banker’s Algorithm for deadlock avoidance.

Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken 


Implement the Banker’s algorithm to answer the following question：Is the system in a safe state? If Yes, then what is the safe sequence?

What should be included in the submission:
• Source codes (C/C++)
• Input file (you should create an input file, e.g., .txt, with your customized format that
stores the data that is provided in the table).
• Your code should print out the safe sequence if the system is safe. (example output
like screenshots)
• Documents and readme.

---

## Collecting Data
The Data is collected from the input file set up like this: 

<img width="194" height="580" alt="image" src="https://github.com/user-attachments/assets/fd3f92c6-4bc7-4304-84ea-992c5a0b6081" />


---
## Compilation/Running the Program:
Run the commands `g++ -o bankers bankers.cpp`and `./bankers` to produce the same output as this screenshot:
<img width="1316" height="770" alt="image" src="https://github.com/user-attachments/assets/1eb1e365-eb5b-4371-b116-4eac226f3af3" />


According to the program, the system is in a safe state! The Sequence is:
Process 1 -> Process 3 -> Process 4 -> Process 0 -> Process 2

---

