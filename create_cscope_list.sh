#!/bin/bash
echo "run"
find . -name '*.c' > cscope.files
find /usr/local/share/cc65/include -name '*.h'  >> cscope.files
