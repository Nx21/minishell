# Minishell 42

Welcome to Minishell 42, a simplified Unix-like shell implementation inspired by the Bash shell. This project is part of the curriculum at École 42 and aims to deepen your understanding of system calls, processes, and basic shell functionalities.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Contributing](#contributing)

## Features

- Command execution
- Basic input/output redirection
- Pipes
- && and ||
- Environment variables
- Signal handling
- Wildcard
- Redirections
- Signals
- And more...

## Getting Started

Follow these instructions to get a copy of the project up and running on your local machine.

1. Clone the repository:

  ```sh
  git clone https://github.com/Nx21/minishell.git
  cd minishell-42
  ```
2. Build the project:
  ```sh
  make
  ```
3. Run
  ```sh
  ./minishell
  ```
## Usage
Minishell supports most basic shell functionalities. You can run external commands, redirect input/output, create pipelines, and utilize built-in commands.

  ```sh
  $ ls -l
  $ echo "Hello, Minishell!"
  $ cat file.txt > newfile.txt
  $ ls | grep ".txt"
  $ cd /path/to/directory
  $ export MY_VARIABLE=42
  ```
## Built-in Commands

Minishell supports the following built-in commands:
- echo
- cd
- pwd
- export
- unset
- env
- exit

## Contributing
Contributions are welcome! If you find any issues or want to enhance the functionality, feel free to submit a pull request. Please follow the standard coding guidelines and ensure your changes are well-documented.

Fork the repository.
Create a new branch: git checkout -b feature/your-feature.
Make your changes and test thoroughly.
Commit your changes: git commit -m "Add feature XYZ".
Push the branch: git push origin feature/your-feature.
Create a pull request explaining your changes.

