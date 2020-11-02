set_mode bmc
#set_depth 10
create_rst  -rst rst

read_file -f filelist -top traffic -cmopts {+define RTL_BUG }
