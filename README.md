# OS_Project
5.36-
Programming Exercise 3.20 required you to design a PID manager that
allocated a unique process identifier to each process. Exercise 4.20
required you to modify your solution to Exercise 3.20 by writing a
program that created a number of threads that requested and released
process identifiers. Now modify your solution to Exercise 4.20 by
ensuring that the data structure used to represent the availability of
process identifiers is safe from race conditions. Use Pthreads mutex
locks, described in Section 5.9.4.

4.20-
Modify programming problem Exercise 3.20 from Chapter 3, which asks
you to design a pid manager. This modification will consist of writing
a multithreaded program that tests your solution to Exercise 3.20. You
will create a number of threadsfor example, 100and each threadwill
request a pid, sleep for a random period of time, and then release the pid.
(Sleeping for a random period of time approximates the typical pid usage
in which a pid is assigned to a new process, the process executes and
then terminates, and the pid is released on the processs termination.) On
UNIX and Linux systems, sleeping is accomplished through the sleep()
function, which is passed an integer value representing the number of
seconds to sleep. This problem will be modified in Chapter 5.

3.20-
An operating systems pid manager is responsible for managing process
identifiers. When a process is first created, it is assigned a unique pid
by the pid manager. The pid is returned to the pid manager when the
process completes execution, and the manager may later reassign this
pid. Process identifiers are discussed more fully in Section 3.3.1. What
is most important here is to recognize that process identifiers must be
unique; no two active processes can have the same pid.
Use the following constants to identify the range of possible pid values:
#define MIN PID 300
#define MAX PID 5000
You may use any data structure of your choice to represent the availability
of process identifiers. One strategy is to adopt what Linux has
done and use a bitmap in which a value of 0 at position i indicates that
a process id of value i is available and a value of 1 indicates that the
process id is currently in use.
Implement the following API for obtaining and releasing a pid:
 int allocate map(void)Creates and initializes a data structure
for representing pids; returns1 if unsuccessful, 1 if successful
 int allocate pid(void)Allocates and returns a pid; returns
1 if unable to allocate a pid (all pids are in use)
 void release pid(int pid)Releases a pid
