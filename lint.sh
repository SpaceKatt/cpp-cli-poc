#!/usr/bin/env bash
EXIT_CODE=0
declare VERBOSITY='-q'

while getopts ":e:t:v" opt; do
  case $opt in
    e)
      EXIT_CODE=1
      ;;
    v)
      VERBOSITY="-v"
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
  esac
done

cppcheck --enable=all --suppressions-list=suppressions.txt --inline-suppr --inconclusive --force --error-exitcode=${EXIT_CODE} ${VERBOSITY} src/