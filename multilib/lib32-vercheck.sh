#!/usr/bin/bash

getpkgver() {
  pacman -Si "$1" 2>/dev/null | awk \
    'BEGIN { found=0; }
     /^Version/{ print($3); found=1; exit(0);}
     END { if (!found) exit(1); }'
}

for i in $(pacman -Ssq | grep '^lib32-'); do
  name32="$i"
  name="${i#lib32-}"
  ver32=$(getpkgver "$name32")
  ver=$(getpkgver "$name")
  if (( $? )); then
    echo "skipping: $name" >&2
    continue
  fi

  if [[ $ver32 != $ver ]]; then
    cmp=$(vercmp "$ver" "$ver32")
    if (( cmp < 0 )); then
      echo "WARNING: ${name32} is newer than ${name}" >&2
    elif (( cmp > 0 )); then
      echo "${name32}"
    fi
  fi
done
