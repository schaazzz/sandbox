#!/usr/bin/env python
import os, sys, shutil

if(os.path.exists('python-post-commit') and os.path.exists(os.path.join('..', '..', 'python'))):
    shutil.copyfile('python-post-commit', os.path.join('..', '..', 'python', '.git', 'hooks', 'post-commit'))
