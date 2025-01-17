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

### Pushing to Main

Do **not** push directly to the `main` branch.

#### If You Are the Only Contributor:
1. Create a `dev` branch to manage your changes.
2. Push updates to the `dev` branch from your local computer.
3. Merge the `dev` branch into `main` when the code is stable and ready.

```bash
# Create the dev branch and push your latest commit to it
git checkout -b dev
git push origin dev
```

#### If There Are Multiple Contributors:
1. Do **not** use `main` for development.
2. Follow the guidelines in [Pushing to Branches](#Pushing-to-Branches) to collaborate effectively. 

This workflow ensures the `main` branch remains stable and avoids conflicts during development.

### Pushing to Branches
If you are working on a feature or bugfix, find the branch that seems most relevant to your current task and push to that branch with the proper commit messages. If you are working on a new major feature, or there is no related branch to the issue you're working on, see [Branches](#Branches) for how to create a new branch.

## Pull Requests
### When to Make
Pull requests should be made when you are ready to merge your changes into the master branch or a feature branch. This should be done when you have completed a feature or bugfix, or when you have reached a good stopping point in your work.
### Review
When pulling into the master branch your pull request will have to be reviewed by another member of the team. This is to ensure that the code is up to the standards of the team and that there are no obvious bugs or issues with the code.

## Branches
New branches should be created when a new major feature in the software is being worked on or there is no related branch to the issue you're working on. Branches can be named flexibly, but should generally fall under one of these categories.

**Categories**:
- **Feature Branches** (`feature/`)
   - For new features or functionalities.
   - Example: `feature/add-gyroscope-support`
- **Test Branches** (`test/`)
   - For adding unit, integration, or other tests, especially those with temporary changes.
   - Example: `test/gyro-integrity-checks`
- **Bugfix Branches** (`fix/`)
   - For fixing bugs in production or feature branches.
   - Example: `fix/gyro-range-error`
- **Refactor Branches** (`refactor/`)
   - For improving code structure without changing functionality.
   - Example: `refactor/reorganize-sensors`
- **Chore Branches** (`chore/`)
   - For non-code changes like documentation, configuration, or build scripts.
   - Example: `chore/update-readme`

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