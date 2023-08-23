import os

branch  = os.popen('git branch').read().split('\n')
active_branch = ""
for br in branch:
	if '*' in br:
		active_branch = br.split('*')[-1].strip()

if active_branch == 'master':
	version = os.popen('git describe --abbrev=0 --match submissions/[0-9][0-9][0-9]').read().strip().replace('submissions/', '').split('-')[0]
else:
	version = os.popen('git describe').read().strip().replace('submissions/', '').split('-')[0]
print(version)
