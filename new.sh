home='/Users/justin/slactest'

for f in $(ls ${home}/rootfiles/*.root) ; do

        # Calculate run number from filename
        run=$(echo ${f} | awk -F'[_|.]' '{print $2}')
#       echo "${run}"
        if [ ${run} -lt 212 -o ${run} -gt 221 ] ; then
                continue
        fi
        nPEs=$(root -l -b -q "${home}/slac-test-beam-quartz-analysis/scan_1.c(${run})")
        nPEs=$(echo ${nPEs} | awk '{print $NF}')

        echo "${run},${nPEs}" >> nPEs.csv
done
