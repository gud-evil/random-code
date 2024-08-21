# random-code
# This is just a place to put my learning, sample, and test code
# Notes

https://stackoverflow.com/questions/17815895/can-i-edit-two-files-then-make-one-commit-using-github-web-based-editor

There is a web-based workaround:

Create a temporary branch, switch to it;
Edit multiple files, commit each file separately;
Make pull request;
Under Merge pull request button, choose Squash and merge (if the repo allows it), then confirm merge;
Delete temporary branch.
I use this method on a PC which I don't want to install git on.

Share
Improve this answer
Follow
edited Dec 29, 2020 at 4:10
chharvey's user avatar
chharvey
9,12899 gold badges5757 silver badges9797 bronze badges
answered Sep 26, 2014 at 16:04
Victor Istomin's user avatar
Victor Istomin
1,15688 silver badges1414 bronze badges
23
It works great. Just one important thing, when you validate and merge the pull request, make sure to select Confirm Squash and Merge, and not Confirm Merge (default). help.github.com/articles/about-pull-request-merge-squashing – 
Mar Cnu
 CommentedMay 20, 2016 at 16:51
Can you expand on steps 3 and 4? I want to edit 2 files in my fork of a repo, then submit a PR with only one commit with the two edits. How can I make a pull request (against my own fork?) and merge it? I don't have write access to the original repo. – 
Dan Dascalescu
 CommentedJul 6, 2016 at 9:17
2
1. Create your fork and temporary branch. 2. Edit files on temp branch. 3.1. Squash commits to your master branch. 3.1.1. On temporary branch, hit "create pull request" and ensure that 'base' is your master. Create 'local' pull request. 4. Hit "merge pull request" and fill commit message. Hit green button "Confirm squash and merge". Now you have single commit with 2 edited files on your 'master'. 5. To propagate pull request to origin, create pull request and specify original repo as 'base'. When pull request is created, authors will be able to review and merge your changes. – 
Victor Istomin
 CommentedJul 6, 2016 at 22:10
