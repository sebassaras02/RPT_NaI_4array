#!/bin/bash
start_time=$(date "+%s")


for i in {1..200}
do 
    ./naidetector /G4-e/RPT-posa/build/macros/Array_4/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_D1.dat NaIDetector_D1_pos$i.dat
    mv NaIDetector_D1_pos$i.dat /G4-e/RPT-posa/build/results/Array_4
    root -q det_reader2.C
    mv NaIDetector_D2.dat NaIDetector_D2_pos$i.dat
    mv NaIDetector_D2_pos$i.dat /G4-e/RPT-posa/build/results/Array_4
    root -q det_reader3.C
    mv NaIDetector_D3.dat NaIDetector_D3_pos$i.dat
    mv NaIDetector_D3_pos$i.dat /G4-e/RPT-posa/build/results/Array_4
    root -q det_reader4.C
    mv NaIDetector_D4.dat NaIDetector_D4_pos$i.dat
    mv NaIDetector_D4_pos$i.dat /G4-e/RPT-posa/build/results/Array_4

    
    rm *.root
done


end_time=$(date "+%s")
s=60
let elapsed=($end_time-$start_time)/$s
echo "$elapsed minutes"
