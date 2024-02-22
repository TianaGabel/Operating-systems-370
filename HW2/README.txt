Coordinator.c is responsible for creating processes,
- it takes in 5 arguments, with the first being a divisor and the next 4 dividends
- a process will be forked, and the execlp() to load the process with checker.c, and will then wait for the process to complete
- this is repeated for all commandline arguments

Checker
- This will take in 2 arguments 1 divisor and 1 dividend
- print the result, and return 0 or 1 based on a false or positive result

Notes
- Checker reads argv[1] and argv[2], this is necessary due to the way the execlp call is phrased

