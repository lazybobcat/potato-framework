#!/bin/bash

shopt -s globstar nullglob extglob
for f in **/*.@(cpp|hpp|inl); do
  cat header_file.h $f > $f.new
  mv $f.new $f
done
