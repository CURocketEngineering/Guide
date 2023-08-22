# Repository Guidelines
## Introduction
This guide will help you get started with working with repositories within this github organization. It will cover how to work with repositories, how to work with branches, and how to work with pull requests.

The most useful commands can be [found](https://education.github.com/git-cheat-sheet-education.pdf) here for quick reference.

## Pushing
### Commit Messages
Commit messages should be clear and concise, try and summarize what you did as breifly as possible such as "Fix Bug 208" or "Add Telemetry Downlink". If you need to go into more detail, then you can add a description to the commit message.

For the main message follow this guide:
- `[Add/Fix/Remove/Update/Refactor/Document] [summary]`

For the description consider answering these questions:
- Why is it necessary? (Bug fix, feature, improvements?)
- How does the change address the issue? 
- What side effects does this change have?
- Include a link to the ticket, if any.
### Pushing to Master
Don't.   
- If only one person is working on the project, then create a `dev` branch where you can push updates from your local computer. Pull the `dev` branch into master when the code is in a good place. 
```
    // Will create the dev branch and push your latest commit to it
    git push origin dev    
```

- If multiple people are working on the code then see [Pushing to Branches](#Pushing-to-Branches)
### Pushing to Branches
If you are working on a feature or bugfix, find the branch that seems most relevant to your current task and push to that branch with the proper commit messages. If you are working on a new major feature, or there is no related branch to the issue you're working on, see [Branches](#Branches) for how to create a new branch.

## Pull Requests
### When to Make
Pull requests should be made when you are ready to merge your changes into the master branch or a feature branch. This should be done when you have completed a feature or bugfix, or when you have reached a good stopping point in your work.
### Review
When pulling into the master branch your pull request will have to be reviewed by another member of the team. This is to ensure that the code is up to the standards of the team and that there are no obvious bugs or issues with the code.

## Branches
New branches should be created when a new major feature in the software is being worked on or there is no related branch to the issue you're working on. Branches can be named flexibly, but should generally fall under one of these categories:
- Feature Branches
    - These branches are for new features that are being added to the software. A [pull request](#pull-requests) should be made to merge into master when the feature is complete.
- Test Branches
    - Often times during software tests, small changes have to made to get it working properly. Use a test branch to organize all these small changes made during the test. 
- Bugfix Branches
    - Whenever there is a bug found in main code, a new branch should be created to fix the bug. These branches should be merged into their respective feature branch or master when the bug is fixed.
- Misc. Branches
    - These branches are for any other major changes or overhauls that don't fall under the other two categories. These branches should be merged into their respective feature branch or master when the changes are complete.

## The GIT way to change code
1. Create a new local [branch](#Branches) based on the change you plan on making.  
`git branch feature/gyroscope`
2. Checkout your branch  
`git checkout feature/gyroscope`
3. Edit the code to make your changes
4. Add the edited files to be staged  
`git add sensor_handling.py`
5. Commit the staged changes to your local branch  
`git commit -m "Add gyroscope support"`
6. [Push](#Pushing-to-branches) the changes the remote repository  
`git push origin feature/gyroscope`
7. Within GitHub, create a pull requests to merge the new feature into the master branch. 
8. Once the pull requests is approved, the code has been succesfully changed. 