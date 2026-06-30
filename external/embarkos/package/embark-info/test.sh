#!/bin/sh

echo "Running embark-info tests..."

embark-info --version

embark-info --hostname

embark-info --kernel

embark-info --board

echo "All tests passed."