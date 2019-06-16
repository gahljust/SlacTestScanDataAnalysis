
if [ $# -gt 0 ] ; then
	run_list=$*
else
	run_list=$(tail +7 values_by_run.csv | awk -F',' '{print $1}')
fi

for run_num in ${run_list} ; do
	detector=$(awk -F, '$1==val{print $4}' val=${run_num} values_by_run.csv)
	signal=$(awk -F, '$1==val{print $7}' val=${run_num} values_by_run.csv)
	if [[ ${signal} == "-1" ]] ; then
		#root -l "pmt_analyzer_pedestal.c(${run_num})"
		continue
	elif [[ ${signal} == "" ]] ; then
		continue
	elif [[ ${detector:0:5} == "mainz" || ${detector:1:3} == "am" ]] ; then
		continue
	elif [[ ${detector} == "tandem" ]] ; then
		#root -l "pmt_analyzer_tandem.c(${run_num})"
		continue
	elif [[ ${detector:3:4} == "1b1s" ]] ; then
		root -l -b -q "pmt_analyzer_benchmark.c(${run_num})"
		continue
	elif [[ ${detector:3:4} == "1b2s" ]] ; then
		root -l -b -q "pmt_analyzer_benchmark.c(${run_num})"
		continue
	elif [[ ${detector:3:4} == "1b1q" ]] ; then
		root -l -b -q"pmt_analyzer_showermax.c(${run_num})"
		continue
	elif [[ ${detector:3:4} == "1a1q" ]] ; then
		root -l -b -q"pmt_analyzer_showermax.c(${run_num})"
		continue
	elif [[ ${detector:3:4} == "1a2s" ]] ; then
		root -l -b -q "pmt_analyzer_benchmark.c(${run_num})"
		continue
	elif [[ ${detector:3:4} == "1b3s" ]] ; then
		root -l -b -q "pmt_analyzer_benchmark.c(${run_num})"
		continue
	elif [[ ${detector:3:4} == "1a3s" ]] ; then
		root -l -b -q "pmt_analyzer_benchmark.c(${run_num})"
		continue
	elif [[ ${detector:3:4} == "1b4s" ]] ; then
		root -l -b -q "pmt_analyzer_benchmark.c(${run_num})"
		continue
	elif [[ ${detector:3:4} == "1a4s" ]] ; then
		root -l -b -q "pmt_analyzer_benchmark.c(${run_num})"
		continue
	else
		root -l -b -q "pmt_analyzer_showermax.c(${run_num})"
		continue
	fi
	sleep 0.5
done
