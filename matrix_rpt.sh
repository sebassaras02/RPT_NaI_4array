#!/bin/bash
start_time=$(date "+%s")


for i in {1..40000}
do 
    ./naidetector /G4-e/RPT_NaI_4array/matrix/macros/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_matrix.dat NaIDetector_matrix_pos$i.dat
    mv NaIDetector_matrix_pos$i.dat  /G4-e/results_RPT_ML/matrix/NaIDetector_matrix_pos$i.dat
    rm *.root
done

end_time=$(date "+%s")
s=60*60
let elapsed=($end_time-$start_time)/$s
echo "$elapsed hours"
