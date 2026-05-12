#!/usr/bin/env bash

test_array=(
	"0"
	"+0"
	"-0"
	"42.0f"
	"42.f0"
	"+42.0f"
	"42.a0f"
	"-42.0f"
	"23.af"
	"23.0"
	"23.a0f"
	"-23.a0f"
	"nan"
	"nanf"
	"-inff"
	"+inff"
	"-inf"
	"+inf"
	"a"
	"s"
	"-s"
)

for item in ${test_array[@]}; do
	echo item: $item
	./main $item
	echo
done
