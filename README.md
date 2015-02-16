# streams

This repo is a fork of the original stream from http://www.cs.virginia.edu/stream/ref.html
Original source by John D. McCalpin, Ph.D.
john <at> mccalpin <dot> com

For any benchmark use, please refer to the original source @ http://www.cs.virginia.edu/stream/FTP/Code/


What is STREAM?
---------------
The STREAM benchmark is a simple synthetic benchmark program that measures sustainable memory bandwidth (in MB/s) and the corresponding computation rate for simple vector kernels. 

A "second-generation" STREAM benchmark (STREAM2) is being evaluated, with the source code and some results available at the STREAM2 page.   STREAM2 emphases measurements across all levels of the memory hierarchy, and tries to focus on the difference between read and write performance in memory systems.
Counting Bytes and FLOPS
It may be surprising, but there are at least three different ways to count Bytes for a benchmark like STREAM, and unfortunately all three are in common use!

The three conventions for counting can be called:

    bcopy
    STREAM
    hardware

    "bcopy" counts how many bytes get moved from one place in memory to another.  So if it takes your computer 1 second to  read 1 million bytes at one location and write those 1 million bytes to a second location, the resulting "bcopy bandwidth" is said to be "1 MB per second".
    "STREAM" counts how many bytes the user asked to be read plus how many bytes the user asked to be written.  For the simple "Copy" kernel, this is exactly twice the number obtained from the "bcopy" convention.   Why does STREAM do this?  Because 3 of the 4 kernels do arithmetic, so it makes sense to count both the data read into the CPU and the data written back from the CPU.   The "Copy" kernel does no arithmetic, but I chose to count bytes the same way as the other three.
    "hardware" may move a different number of bytes than what the user specified.  In particular, most cached systems perform what is called a "write allocate" when a store operation misses the data cache.  The system loads the cache line containing the data before overwriting it.


Why does it do this?
It does it so that there will be a single copy of the cache line in the system for which all the bytes are current and valid.   If you only wrote 1/2 the bytes in the cache line, for example, the result would have to be merged with the other 1/2 of the bytes from memory.  The best place to do this is in the cache, so the data is loaded there first and life is much simpler.
 

The table below shows how many Bytes and FLOPs are counted in each iteration of the STREAM loops.
The test consists of multiple repetitions of four the kernels, and the best results of (typically) 10 trials are chosen.

    ------------------------------------------------------------------
    name        kernel                  bytes/iter      FLOPS/iter
    ------------------------------------------------------------------
    COPY:       a(i) = b(i)                 16              0
    SCALE:      a(i) = q*b(i)               16              1
    SUM:        a(i) = b(i) + c(i)          24              1
    TRIAD:      a(i) = b(i) + q*c(i)        24              2
    ------------------------------------------------------------------

So you need to be careful comparing "MB/s" from different sources.  STREAM always uses the same approach, and always counts only the bytes that the user program requested to be loaded or stored, so results are always directly comparable. 

streams
