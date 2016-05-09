#!/bin/csh -f

set i=1
while ($i <= $argv[2]) 
    dohpart nets/$argv[1].net Results/$argv[1].res $i 0.45
    @ i+=1
end
stats $argv[2] Results/$argv[1].res >> Results/$argv[1].res



