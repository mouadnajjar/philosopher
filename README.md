# Philosophers Project (philo)

## 🧠 Description
This project is a simulation of the classic **Dining Philosophers Problem** using multithreading in C, following the **42 Network** (1337 School) rules. It explores the challenges of synchronization, avoiding deadlocks, and accurate timing in concurrent environments.

---

## 🛠️ Features
- Philosophers are represented as threads.
- Each philosopher alternates between **thinking**, **eating**, and **sleeping**.
- Forks are represented using **mutexes** to ensure mutual exclusion.
- A **monitoring thread** checks for philosopher death and ensures simulation halts if:
  - A philosopher dies from starvation.
  - All philosophers have eaten a required number of times.
- Precise sleep function used to maintain timing accuracy.

---

## 📦 Compilation
```bash
make
```

This compiles the program into an executable named `philo`.

---

## ▶️ Usage
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Arguments
- `number_of_philosophers`: Number of philosopher threads.
- `time_to_die`: Time in milliseconds a philosopher can live without eating.
- `time_to_eat`: Time in milliseconds a philosopher spends eating.
- `time_to_sleep`: Time in milliseconds a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat`: *(optional)* The simulation stops when all philosophers have eaten at least this number of times.

---

## 🧪 Example
```bash
./philo 5 800 200 200 4
```
Each philosopher:
- Dies if not eating for 800 ms
- Eats for 200 ms
- Sleeps for 200 ms
- Simulation ends when each has eaten 4 times

---

## 📚 What I Learned
- Basics and intricacies of **POSIX threads (pthreads)**
- Using **mutexes** to prevent **data races** and **deadlocks**
- Handling **time-based simulation** with millisecond precision
- Importance of **thread-safe print operations**
- Applying the **observer (monitor) pattern** for checking philosopher state

---

## 🔍 Debugging Tips
- Use `valgrind` to check for memory leaks or uninitialized variables.
- Ensure **all mutexes** are destroyed and memory is freed.
- Use **ThreadSanitizer** to detect data races:
  ```bash
  gcc -fsanitize=thread ...
  ```

---

## 🧩 Future Improvements
- Handle extremely low `time_to_die` inputs more gracefully
- Optimize for CPU usage by fine-tuning the monitor sleep interval
- Add visual simulation (ncurses or graphical representation)

---

## 🧠 Keywords to Restudy
- `pthread_create`, `pthread_join`, `pthread_mutex_lock`, `pthread_mutex_unlock`
- `usleep`, `gettimeofday`, `get_time_in_ms()`
- `mutex` initialization, destruction
- Deadlock, starvation, race condition, CPU burn

---

## 👨‍💻 Author
**Mouad Najjar**  
Student at 1337 | Passionate about systems programming and concurrency
