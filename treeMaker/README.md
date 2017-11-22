Scripts and macros to create trees from raw data.

1. Run env.sh in folder scripts. It is needed to configure Root.
2. Script submitJobs.sh is for sending jobs to the cluster. Parameter - name of the list with initial trees (from
dir lists).
3. Generated trees will be in the directory output/date/name_of_list/.
4. Lists with initial trees were received from /lustre/nyx/hades/dst/... by ls $(PWD)/*.root

