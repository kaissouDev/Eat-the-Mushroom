@echo off
rm -r build

if not exist "build" (
  echo build is not found
)