# École 42
# École 1337

## Get_Next_Line


This projects is about creating a function that, allows to read a line ending
with a newline character ('\\n') from a file descriptor, without knowing its
size beforehand. One of the goal of this project is to learn a highly
interesting new concept in C programming: static variables, and to gain a deeper
understanding of allocations, whether they happen on the stack memory or in the
heap memory.
The program must compile with the flag-D BUFFER_SIZE=xx which will be used as the buffer size for the read calls in get_next_line.
