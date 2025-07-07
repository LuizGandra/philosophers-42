# Philosophers

Philosophers is a implementation of the classic "Dining Philosophers Problem" developed as a project for the [42 São Paulo](https://www.42sp.org.br/) Common Core curriculum. The goal is to simulate a group of philosophers sitting around a table, alternating between eating, thinking, and sleeping, while managing shared resources (forks) to avoid deadlocks, starvation, and race conditions. The project is implemented in C, using threads and mutexes for the mandatory part.
Features

![42 São Paulo](https://img.shields.io/badge/42-São_Paulo-black?style=flat-square&logo=42)

## About 42

[42 São Paulo](https://www.42sp.org.br/) is a tuition-free, global coding school emphasizing peer-to-peer learning and project-based education. This project sharpens algorithmic thinking and optimization skills in C.

## Project Overview

- **Mandatory Part:** implements the dining philosophers problem using threads and mutexes.

### Key Features

- **Threads and Mutexes:** each philosopher is a thread, and each fork is protected by a mutex to prevent race conditions.
- **Deadlock and Starvation Prevention:** ensures no philosopher starves or causes a deadlock.
- **Status Monitoring and Logging:** outputs the status of each philosopher (e.g., "has taken a fork," "is eating," "is sleeping," "is thinking," "died") with timestamps in milliseconds.
- **Automatic program termination:** stops when a philosopher dies or when all philosophers have eaten the specified number of times (if provided).

### Restrictions

- Written in C, compliant with the 42 Norm.
- No unexpected crashes (e.g., segmentation faults).
- No memory leaks from heap allocations.
- Compiled with `-Wall -Wextra -Werror`.

## Getting Started

### Prerequisites

- C compiler (e.g., `gcc` or `clang`).
- `make` utility.

### How to Build and Run

1. Clone the repository:

   ```bash
   git clone https://github.com/LuizGandra/philosophers-42.git
   cd philosophers
   ```

2. Build the mandatory part:

   ```bash
   make
   ```

3. Run `philosophers`:

   ```bash
   ./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
   ```

#### Arguments

- `number_of_philosophers` is the number of philosophers (and forks).
- `time_to_die` is the time in milliseconds before a philosopher dies if they haven't eaten.
- `time_to_eat` is the time in milliseconds a philosopher takes to eat.
- `time_to_sleep` is the time in milliseconds a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` is the optional number of meals each philosopher must eat to stop the simulation.

#### Additional commands

- `make clean`: remove object files.
- `make fclean`: remove the program and object files.
- `make re`: rebuild everything.

## Project Structure

- `include/*.h`: header files.
- `src/init.c`: initializes all project data such as philosophers and forks.
- `src/main.c`: main entry point of the program.
- `src/states.c`: implement all possible states for a philosopher, such as eating and sleeping, for example.
- `src/tasks.c`: defines the task that each thread (philosopher) will execute.
- `src/watch.c`: watch philosophers states to detect death or completion.
- `src/*.c`: error handling, validations, utility functions, and the rest of the program logic.
- `src/lib/*.c`: auxiliary functions for managing memory and mutexes.

## License

This project is part of the 42 curriculum and intended for educational use.
