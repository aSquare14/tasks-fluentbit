# This repository contains the technical tasks that were given for interview

### Problem Statements

#### 1.Fluent Bit & Linked Lists

Fluent Bit uses linked lists heavily, but they are different than a normal list where a node point to the next node from the same type. We use our own copy of Linux Kernel linked list style, please read about them here:

https://kernelnewbies.org/FAQ/LinkedLists

better explanation on page 85 of this book (please read it):

https://doc.lagout.org/operating%20system%20/linux/Linux%20Kernel%20Development%2C%203rd%20Edition.pdf

In Fluent Bit, we use the same approach and our header file that implement the macros and overall functions for linked list management are here (you can grab a copy of that header file for the task):

https://github.com/fluent/fluent-bit/blob/master/lib/monkey/include/monkey/mk_core/mk_list.h

In a C program do the following:

Having a structure of the following type, please create a C program that creates a linked list of 10 nodes where the 'id' number is an incremental number starting from zero:

struct data {
    int id;
};

note: review how Fluent Bit headers files under include/fluent-bit. the structure above is not ready to be used since it misses a field that will be used to convert it to a linked list.

In a second step in the same program, iterate the list and print all the values of id.

in another step, remove the node that contains node id = 5.

iterate the list again and print all the values.

#### 2. Fluent Bit / Build from scratch and link external plugin

Build  Fluent Bit locally in your machine, this means to install dependencies, configure it and compile it:

- https://docs.fluentbit.io/manual/installation/build_install

Then dig into 'how to' create an external plugin for Fluent Bit, use the following repository as a reference:

https://github.com/fluent/fluent-bit-plugin

you must be able to build the external plugin and load it with the compiled Fluent Bit. You should use 'stdout2' plugin as a test.

Now take a look at out_stdout2 plugin source code and explain what flb_pack_print() does inside the flush callback.

#### 3.Fluent Bit filtering

Fluent Bit provides a data pipeline where it allows us to collect, filter and deliver log records to different destinations. One of our filters provides Lua scripting. That means that writing a simple function in Lua you can do record modifications as soon as they hit the filtering phase.

On this task, creates a Fluent Bit configuration files that read CPU metrics and on every record append two new key/value pairs, one containing the 'hostname' from the local machine and other containing the 'tag' associated with the record. We expect that every record contains the original keys plus two new records called hostname and tag.

The hostname value must be taken from the environment variable in your Linux system.

Please use the following documentation as a reference:

- https://docs.fluentbit.io/manual/getting_started
- https://docs.fluentbit.io/manual/filter/lua

as an output destination, use the standard output plugin formatting to JSON in separate lines.

### Structure of this repository

Each folder task1-task3 contains the files for each task.
