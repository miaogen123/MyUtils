#!/bin/bash -e
echo "before you first usr,you may wanna customize perf arguments"
read -p "input pid you wanna perf: "
pid=$REPLY
read -p "input specificer of you perf file: "
file_prefix=$REPLY
echo $pid
perf record -F 300 -p $pid -g --call-graph fp  -- sleep 3
time_suffix=`date '+%m%d_%H%M'`
perf script | sed -e 's/T[0-9]*\.//g;s/F[0-9]*\.\([a-z_]\{10\}\)[a-z_0-9]*/\1/g;s/io[0-9]*/io/g;s/\(worker-pri[0-9]*\)-[0-9]*/\1/g' | ./FlameGraph/stackcollapse-perf.pl > "${file_prefix}_${time_suffix}out.perf-folded"
./FlameGraph/flamegraph.pl "${file_prefix}_${time_suffix}out.perf-folded" > "${file_prefix}_${time_suffix}.svg"
