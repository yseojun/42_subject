#!/bin/bash

make;make clean;
# make bonus;make clean;

printf "invalid path   | "; ./cub3d map/wrong_path.cub
printf "invalid1.cub   | "; ./cub3d map/invalid1.cub
printf "invalid2.cub   | "; ./cub3d map/invalid2.cub
printf "invalid3.cub   | "; ./cub3d map/invalid3.cub
printf "invalid4.cub   | "; ./cub3d map/invalid4.cub
printf "invalid5.cub   | "; ./cub3d map/invalid5.cub
printf "invalid6.cub   | "; ./cub3d map/invalid6.cub
printf "invalid7.cub   | "; ./cub3d map/invalid7.cub
printf "invalid8.cub   | "; ./cub3d map/invalid8.cub
printf "invalid9.cub   | "; ./cub3d map/invalid9.cub
printf "invalid10.cubb | "; ./cub3d map/invalid10.cubb