#!/bin/bash
echo $FT_NBR1 + $FT_NBR2 | sed 'y/'\''\\"?!mrdoc/0123401234/' | xargs echo 'obase=13; ibase=5;' | bc | sed 'y/0123456789ABC/gtaio luSnemf/'
