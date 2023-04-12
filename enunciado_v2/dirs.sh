#!/bin/bash

# Create temporary directory
dir=`mktemp -d`

# Create directory structure
cd $dir
mkdir a a/b a/c a/b/d a/e a/f

# Populate directory with files
touch a/g # Create an empty file
ln      a/g a/h 
ln -s   a/c a/i

# Full listing of directory "a"
ls -la a

# Cleanup
rm -rf $dir
