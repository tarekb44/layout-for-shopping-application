#!/bin/bash
reqSpace=5000000
availSpace=$(df "$HOME" | awk 'NR==2 { print $4 }')
if (( availSpace < reqSpace )); then
  echo "insufficent disk space" >&2
  exit 1
fi
module add clion qt/5.3.1 cmake/3.8.2 
rm -f ./report/index.html
rm -rf ./report/images
mkdir -p report
echo "<html><body>" >> report/index.html
echo "<h4>cmake output</h4><pre>" >> ./report/index.html
echo "running cmake..."
PWD=$(pwd -P) cmake . &>> ./report/index.html
echo "running make..."
make clean &>> ./report/index.html
echo "</pre>" >> ./report/index.html
echo "<h4>make output</h4><pre>" >> ./report/index.html
make &>> ./report/index.html
echo "</pre>" >> ./report/index.html
echo "<h4>program output</h4><pre>" >> ./report/index.html
echo "running coursework..."
./cw1 1  &>> ./report/index.html
dir="$(pwd)"
echo "$dir"
echo "zipping..."
parentzip="$(dirname "$dir")/generate_$(whoami).zip"
zip -r -q "$parentzip" .
echo "report written, src & output zipped: now submit $parentzip"
