# Algorithms and Data Structures – Lab Exercises

This repository contains my solutions for the weekly laboratory assignments of the **"Algoritmi e Strutture Dati"** course (Algorithms and Data Structures).  
The exercises are written in **C** and organized by laboratory and exercise number.

The main purposes of this repo are:
- Keeping my work synchronized between computers
- Sharing with classmates who might find examples useful
- Building a personal reference library for future practice

---

## 📂 Repository Structure

advanced-c-labs/  
│  
├── lab01/  
│ ├── ex01/  
│ │ ├── src/ # source code (.c / .h)  
│ │ ├── tests/ # optional input/output test files  
│ │ ├── Makefile # build instructions (local Makefile)  
│ │ └── README.md # exercise description + notes  
│ ├── ex02/  
│ │ └── ...  
│ └── README.md # summary of Lab 01  
│  
├── lab02/  
│ └── ...  
│  
├── Makefile # root Makefile (build any lab/exercise)  
├── .gitignore # ignore build artifacts and IDE files  
└── README.md # this file  


---

## 🛠️ How to Build and Run
You can build exercises in two ways:

### 1. Using the root Makefile
From the project root, specify which lab and exercise to build:
```bash
make lab=lab01 ex=ex01 build   # compile
make lab=lab01 ex=ex01 run     # compile and run
make lab=lab01 ex=ex01 clean   # remove compiled binary
```
### 2. Using a local Makefile
Each exercise folder may include its own Makefile:
```bash
cd lab01/ex01_hello_world
make run
```

## 📚 Notes
- Code follows the C11 standard and is compiled with gcc using warnings enabled (-Wall -Wextra).
- Some exercises may include additional notes or comments inside their folder README.md.
- CLion users: this repo includes a .gitignore that excludes .idea/ and cmake-build-* to avoid clutter

## 🔑 License
This repository is shared for educational purposes only.  
Feel free to reference the solutions, but try to attempt the exercises on your own first 🙂.

## 👤 Author
Edoardo – Computer Engineering Student  
Course: Algoritmi e Strutture Dati (Algorithms and Data Structures)  
