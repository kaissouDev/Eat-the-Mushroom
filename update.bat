@echo off

echo "update ..."
git submodule update --init --recursive > NUL
git pull > NUL
echo "update finish !"