#!/usr/bin/env python3
import subprocess
import json
import os

def get_json(path):
    with open(path, 'r') as file:
        data_dict = json.load(file)
    return data_dict

if __name__ == "__main__":

    git_dict = get_json('source/git-repository.json')

    cmd = 'git config --get user.name'
    user_name = subprocess.check_output(cmd, shell=True).decode('utf-8').strip(" \n")

    for git, repository in git_dict.items():
        source_root_dir = os.path.dirname(os.path.realpath(__file__))
        # cloning all git        
        cmd = 'git -C {} clone \"ssh://{}@wall.lge.com:29448/{}\"'.format(source_root_dir, user_name, repository)
        subprocess.check_output(cmd, shell=True)
        git_dir = os.path.join(source_root_dir, git)
        cmd = 'find %s -name index.rst -exec rm {} \\;'%git_dir
        subprocess.check_output(cmd, shell=True)
        if git == 'hal-libs-header':
            cmd = 'find %s/documentation_mo -maxdepth 1 -type f -exec rm -f {} +'%git_dir
            subprocess.check_output(cmd, shell=True)
            cmd = 'find %s/documentation_mo/source ! -name "*gal.rst" -maxdepth 1 -type f -exec rm -f {} +'%git_dir
            subprocess.check_output(cmd, shell=True)
        else :
            cmd = 'find %s/documentation -maxdepth 1 -type f -exec rm -f {} +'%git_dir
            subprocess.check_output(cmd, shell=True)
            cmd = 'find %s/documentation/source ! -name "*pvr.rst" -maxdepth 1 -type f -exec rm -f {} +'%git_dir
            subprocess.check_output(cmd, shell=True)