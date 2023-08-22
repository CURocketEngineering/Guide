# Repository Guidelines
## Introduction
This guide will help you get started with working with repositories within this github organization. It will cover how to work with repositories, how to work with branches, and how to work with pull requests.

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

    ```git push ```

- If multiple people are working on the code then see [Pushing to Branches](#Pushing-to-Branches)

### Pushing to Branches

## Pull Requests

## Branches
- Feature Branches
- Bugfix branches
- Dev Branches