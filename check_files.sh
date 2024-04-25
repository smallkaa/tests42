#!/bin/bash

export SCRIPT_NAME=$(basename "$0")

cd "$(dirname "$0")"

find . -type f -not \( -path './.git/*' -prune \) -not \( -name '*.c' -o -name '*.h' -o -name 'Makefile' -o -name "$SCRIPT_NAME" \) -print

