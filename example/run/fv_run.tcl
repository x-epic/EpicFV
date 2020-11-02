#------------------------------------
#configuration of Formal--
#mode
#worker number
#engine setting
#depth of proven
#-------------------------------------
#

#-------------------------------------
# compile design and SVA environment
#-------------------------------------

read_file -top $TOP  -f ./filelist +dir ../RTL/xxx 
# NOTE: 
# about -top 
#     customer might will use same filelist while switching the design top from high level to lower level.
#     so better we support "-top" to define design top in the future.
#     but for now , if do not support, it is also fine.
# about -f/-file
#     this option requires customer to provide the filelist with correct path which include all the RTL files and SVA files.
#     we can translate into our comments per file as you shown in the morning.
# about +dir 
#     this might can be optional, for the free version on github, we can request user providing correct filelist.
#     but in the future we need to support customer adding more directory for searching files on filelist.

create_rst -rst/rstn $rst

#Note:
#create_clk not supportted, clk is extracted implicitly
