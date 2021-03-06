#!/bin/bash
start_time=$(date "+%s")
# comment

for i in {1..200}
do 
	for j in {1..200}
	do 
	    ./naidetector /G4-e/RPT_NaI_4array/matrix/macros/traje${i}pos${j}.mac
	    root -q det_reader1.C
	    mv NaIDetector_matrix.dat NaIDetector_matrix_traje${i}pos${j}.dat
	    mv NaIDetector_matrix_traje${i}pos${j}.dat /G4-e/results_RPT_ML/matrix/NaIDetector_matrix_traje${i}pos${j}.dat
	    rm *.root
	done
done

end_time=$(date "+%s")
s=60*60
let elapsed=($end_time-$start_time)/$s
echo "$elapsed hours"
