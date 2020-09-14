# System-Programming-lab7
Write a program called tenthreads that uses 10 threads to increment a shared variable.
Each thread must loop 6 times, incrementing the shared variable by its Thread ID (tid) in every
iteration of the loop. This number for the tid will be in single digits from 0-9.
Once a thread has finished looping, print the ID of the thread saying “Thread [ID] has finished.”
It is important to make use of mutexes so that only one thread is incrementing the shared variable at
a time.
Output the value of the shared variable once all threads have finished incrementing it.
Before submission, make sure you clean up the directories so that no miscellaneous files are kept
around in the submission. (Grade would be deducted if useless files are found in the homework
directories.) Include the source code and the Makefile in the submission.
• Take a screenshot of the screen showing the output of running tenthreads on ocelot. Name it
FirstNameLastName.png or .jpg.
Submit your source file, the screenshot and your Makefile in one zip file called
FirstnameLastnameL7.zip to the assignment dropbox in Canvas.
If the program does not compile and do something useful when it runs it will not earn any credit.
