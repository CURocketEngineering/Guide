# Branch & Commit Naming Conventions

Clear and consistent naming helps us move fast without confusion. Stick to these conventions to keep things simple and maintainable.

---

## 🪴 Branch Naming

### Format

```
<type>/<short-name>
```

### Valid Types

* `feature` – New functionality
* `bugfix` – Fixing a bug
* `refactor` – Improving code without changing behavior
* `doc` – Documentation updates
* `test` – Adding or updating tests
* `infra` – Dev tools, scripts, CI/CD, or build system changes
* `hotfix` – Emergency production/staging fixes

### Examples

* `feature/apogee-estimator`
* `bugfix/altimeter-spike`
* `refactor/imu-state-machine`
* `doc/telemetry-readme`
* `test/unit-altitude-handler`
* `infra/flash-script-improvements`
* `hotfix/fix-bad-data-packet`

---

## 💬 Commit Naming

### Format

```
<type>: <concise description>
```

Keep the message short and action-oriented. If needed, add more detail in the commit body.

### Valid Types

* `feat` – New feature
* `fix` – Bug fix
* `ref` – Refactoring
* `docs` – Documentation
* `test` – Test code
* `infra` – Tooling or CI
* `chore` – Minor cleanup or version bumps
* `hotfix` – Emergency patch

### Examples

* `feat: add apogee prediction module`
* `fix: correct telemetry packet size`
* `ref: clean up finite state machine`
* `docs: add README for ground station`
* `test: add IMU integration test`
* `infra: update flash deploy script`
* `chore: remove unused enums`
* `hotfix: handle altimeter overflow`

# More Resources
- [How to Write a Git Commit Message](https://cbea.ms/git-commit/)

