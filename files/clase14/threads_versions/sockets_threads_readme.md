# Scokets and Threads together

## Example from geeksforgeeks

[Handling multiple clients on server with multithreading using Socket Programming in C/C++](https://www.geeksforgeeks.org/handling-multiple-clients-on-server-with-multithreading-using-socket-programming-in-c-cpp/)

Approach:

1. After accepting the connection to the desired port, receive an integer from the client that defines the choice for reading or writing. Choice 1 indicates reader, while choice 2 indicates writer.
1. After successfully receiving data, call for pthread_create to create reader threads and writer threads.
1. After making successful connections to the server-client asks the user for input on the choice variable.
1. After getting the choice from the user, the client then sends this choice to the server to call the reader or writer thread by creating a client thread for the request.

See:

- sockets_threads_v1_client.c
- sockets_threads_v1_server.c

## Example from StackOverflow

[Sockets and threads in C](https://stackoverflow.com/questions/55598857/sockets-and-threads-in-c)

- sockets_threads_v2_Makefile
- sockets_threads_v2_client.c
- sockets_threads_v2_server.c
