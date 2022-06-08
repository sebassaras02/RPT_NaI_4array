#!/bin/bash
start_time=$(date "+%s")


for i in {1..200}
do 
    ./naidetector /G4-e/RPT_NaI_4array/data_/det1/macros/Hel/T1/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_D1.dat NaIDetector_D1_pos$i.dat
    mv NaIDetector_D1_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr1/pos$i.mac
    root -q det_reader2.C
    mv NaIDetector_D2.dat NaIDetector_D2_pos$i.dat
    mv NaIDetector_D2_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr1/pos$i.mac
    root -q det_reader3.C
    mv NaIDetector_D3.dat NaIDetector_D3_pos$i.dat
    mv NaIDetector_D3_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr1/pos$i.mac
    root -q det_reader4.C
    mv NaIDetector_D4.dat NaIDetector_D4_pos$i.dat
    mv NaIDetector_D4_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr1/pos$i.mac 
    rm *.root
    
    ./naidetector /G4-e/RPT_NaI_4array/data_/det1/macros/Hel/T2/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_D1.dat NaIDetector_D1_pos$i.dat
    mv NaIDetector_D1_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr2/pos$i.mac
    root -q det_reader2.C
    mv NaIDetector_D2.dat NaIDetector_D2_pos$i.dat
    mv NaIDetector_D2_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr2/pos$i.mac
    root -q det_reader3.C
    mv NaIDetector_D3.dat NaIDetector_D3_pos$i.dat
    mv NaIDetector_D3_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr2/pos$i.mac
    root -q det_reader4.C
    mv NaIDetector_D4.dat NaIDetector_D4_pos$i.dat
    mv NaIDetector_D4_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr2/pos$i.mac 
    rm *.root
    
    ./naidetector /G4-e/RPT_NaI_4array/data_/det1/macros/Hel/T3/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_D1.dat NaIDetector_D1_pos$i.dat
    mv NaIDetector_D1_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr3/pos$i.mac
    root -q det_reader2.C
    mv NaIDetector_D2.dat NaIDetector_D2_pos$i.dat
    mv NaIDetector_D2_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr3/pos$i.mac
    root -q det_reader3.C
    mv NaIDetector_D3.dat NaIDetector_D3_pos$i.dat
    mv NaIDetector_D3_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr3/pos$i.mac
    root -q det_reader4.C
    mv NaIDetector_D4.dat NaIDetector_D4_pos$i.dat
    mv NaIDetector_D4_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr3/pos$i.mac 
    rm *.root
    
    ./naidetector /G4-e/RPT_NaI_4array/data_/det1/macros/Hel/T4/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_D1.dat NaIDetector_D1_pos$i.dat
    mv NaIDetector_D1_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr4/pos$i.mac
    root -q det_reader2.C
    mv NaIDetector_D2.dat NaIDetector_D2_pos$i.dat
    mv NaIDetector_D2_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr4/pos$i.mac
    root -q det_reader3.C
    mv NaIDetector_D3.dat NaIDetector_D3_pos$i.dat
    mv NaIDetector_D3_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr4/pos$i.mac
    root -q det_reader4.C
    mv NaIDetector_D4.dat NaIDetector_D4_pos$i.dat
    mv NaIDetector_D4_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr4/pos$i.mac 
    rm *.root
    
    ./naidetector /G4-e/RPT_NaI_4array/data_/det1/macros/Hel/T5/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_D1.dat NaIDetector_D1_pos$i.dat
    mv NaIDetector_D1_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr5/pos$i.mac
    root -q det_reader2.C
    mv NaIDetector_D2.dat NaIDetector_D2_pos$i.dat
    mv NaIDetector_D2_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr5/pos$i.mac
    root -q det_reader3.C
    mv NaIDetector_D3.dat NaIDetector_D3_pos$i.dat
    mv NaIDetector_D3_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr5/pos$i.mac
    root -q det_reader4.C
    mv NaIDetector_D4.dat NaIDetector_D4_pos$i.dat
    mv NaIDetector_D4_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Hel/Tr5/pos$i.mac 
    rm *.root
done


for i in {1..200}
do 
    ./naidetector /G4-e/RPT_NaI_4array/data_/det1/macros/Str/T1/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_D1.dat NaIDetector_D1_pos$i.dat
    mv NaIDetector_D1_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr1/pos$i.mac
    root -q det_reader2.C
    mv NaIDetector_D2.dat NaIDetector_D2_pos$i.dat
    mv NaIDetector_D2_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr1/pos$i.mac
    root -q det_reader3.C
    mv NaIDetector_D3.dat NaIDetector_D3_pos$i.dat
    mv NaIDetector_D3_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr1/pos$i.mac
    root -q det_reader4.C
    mv NaIDetector_D4.dat NaIDetector_D4_pos$i.dat
    mv NaIDetector_D4_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr1/pos$i.mac 
    rm *.root
    
    ./naidetector /G4-e/RPT_NaI_4array/data_/det1/macros/Str/T2/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_D1.dat NaIDetector_D1_pos$i.dat
    mv NaIDetector_D1_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr2/pos$i.mac
    root -q det_reader2.C
    mv NaIDetector_D2.dat NaIDetector_D2_pos$i.dat
    mv NaIDetector_D2_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr2/pos$i.mac
    root -q det_reader3.C
    mv NaIDetector_D3.dat NaIDetector_D3_pos$i.dat
    mv NaIDetector_D3_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr2/pos$i.mac
    root -q det_reader4.C
    mv NaIDetector_D4.dat NaIDetector_D4_pos$i.dat
    mv NaIDetector_D4_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr2/pos$i.mac 
    rm *.root
    
    ./naidetector /G4-e/RPT_NaI_4array/data_/det1/macros/Str/T3/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_D1.dat NaIDetector_D1_pos$i.dat
    mv NaIDetector_D1_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr3/pos$i.mac
    root -q det_reader2.C
    mv NaIDetector_D2.dat NaIDetector_D2_pos$i.dat
    mv NaIDetector_D2_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr3/pos$i.mac
    root -q det_reader3.C
    mv NaIDetector_D3.dat NaIDetector_D3_pos$i.dat
    mv NaIDetector_D3_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr3/pos$i.mac
    root -q det_reader4.C
    mv NaIDetector_D4.dat NaIDetector_D4_pos$i.dat
    mv NaIDetector_D4_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr3/pos$i.mac 
    rm *.root
    
    ./naidetector /G4-e/RPT_NaI_4array/data_/det1/macros/Str/T4/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_D1.dat NaIDetector_D1_pos$i.dat
    mv NaIDetector_D1_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr4/pos$i.mac
    root -q det_reader2.C
    mv NaIDetector_D2.dat NaIDetector_D2_pos$i.dat
    mv NaIDetector_D2_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr4/pos$i.mac
    root -q det_reader3.C
    mv NaIDetector_D3.dat NaIDetector_D3_pos$i.dat
    mv NaIDetector_D3_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr4/pos$i.mac
    root -q det_reader4.C
    mv NaIDetector_D4.dat NaIDetector_D4_pos$i.dat
    mv NaIDetector_D4_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr4/pos$i.mac 
    rm *.root
    
    ./naidetector /G4-e/RPT_NaI_4array/data_/det1/macros/Str/T5/pos$i.mac
    root -q det_reader1.C
    mv NaIDetector_D1.dat NaIDetector_D1_pos$i.dat
    mv NaIDetector_D1_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr5/pos$i.mac
    root -q det_reader2.C
    mv NaIDetector_D2.dat NaIDetector_D2_pos$i.dat
    mv NaIDetector_D2_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr5/pos$i.mac
    root -q det_reader3.C
    mv NaIDetector_D3.dat NaIDetector_D3_pos$i.dat
    mv NaIDetector_D3_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr5/pos$i.mac
    root -q det_reader4.C
    mv NaIDetector_D4.dat NaIDetector_D4_pos$i.dat
    mv NaIDetector_D4_pos$i.dat /G4-e/RPT_NaI_4array/data_/det1/results/Str/Tr5/pos$i.mac 
    rm *.root
done


end_time=$(date "+%s")
s=60
let elapsed=($end_time-$start_time)/$s
echo "$elapsed minutes"
