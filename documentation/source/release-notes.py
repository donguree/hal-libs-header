#!/usr/bin/env python3
import subprocess

cmd = 'git tag --list --merged HEAD --sort=-taggerdate | grep ^submissions/'
output = subprocess.check_output(cmd, shell=True).decode('utf-8').strip(" \n")

print("""Release Notes
=============

.. contents::
  :local:

This file can be generated by using this command:

.. code-block:: text

  $ cd socts/Documentation/source
  $ ./release-notes.py > release-notes.rst
""")

fmt = """.. _{0}:

{0}
{1}

.. git_changelog::
  :rev-list: {2}
  :hide_details: True
  :hide_date: True
"""

tags = output.split("\n")
if tags:
    if len(tags) == 1:
        print(fmt.format(tags[0], "-" * len(tags[0]), "%s" % (tags[0])))
    else:
        for i in range(len(tags) - 1):
            print(fmt.format(tags[i], "-" * len(tags[i]), "%s..%s" % (tags[i+1], tags[i])))
        print(fmt.format(tags[-1], "-" * len(tags[-1]), "%s" % (tags[-1])))
