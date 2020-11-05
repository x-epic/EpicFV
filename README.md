# EpicFV
Install steps:
You need a C++ compiler with C++11 support (up-to-date CLANG or GCC is
recommended) and some standard tools such as GNU Flex, GNU Bison, and GNU Make.
TCL, readline and libffi are optional.
 
On Ubuntu:
	$ sudo apt-get install build-essential clang bison flex \
                libreadline-dev gawk tcl-dev libffi-dev git \
                graphviz xdot pkg-config python3 libboost-system-dev \
                libboost-python-dev libboost-filesystem-dev zlib1g-dev

on CentOS:
	# yum install clang tcl-devel readline-devel

make

run steps:

setenv EPICFV_HOME $PWD

cd example/run

$EPICFV_HOME/epic_fv -f demo1.tcl [-worker <8>] [-session <sessionName>]
