#!/usr/bin/env bash
EXIT_CODE=0
declare VERBOSITY

while getopts "eqv" opt; do
  case $opt in
    e)
      EXIT_CODE=1
      ;;
    q)
      VERBOSITY="-q"
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
cpplint --quiet --recursive ./src && cpplint --quiet --recursive ./test