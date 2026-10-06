🌐 Browser Navigation Using Two Stacks

A simple menu-driven browser navigation system written in C using two stacks.

This project demonstrates how the Stack data structure (LIFO) can be used to implement the Back and Forward functionality of a web browser.

📌 Features

🌐 Visit a new webpage

⬅️ Navigate to the previous page using Back

➡️ Navigate to the next page using Forward

📜 Display Back history

📜 Display Forward history

🚪 Exit the program

🧠 Data Structure Used

The program uses two stacks:

1. Back Stack

Stores previously visited pages.

When a new page is visited, the current page is pushed into the Back Stack.

2. Forward Stack

Stores pages that can be accessed again after pressing Back.

When the user visits a completely new page, the Forward Stack is cleared.

⚙️ How It Works

Suppose the user visits:

Home → Google → YouTube → GitHub


When the user presses Back:

GitHub → YouTube


The current page is moved to the Forward Stack.

If the user presses Forward:

YouTube → GitHub


The current page is moved back to the Back Stack.

🛠️ Technologies Used

C

Arrays

Stack Data Structure

Functions

switch-case

while loop

strcpy() from <string.h>

📋 Menu Options
1. Visit New Page
2. Back
3. Forward
4. Display Back History
5. Display Forward History
6. Exit

▶️ How to Run
Compile

Using GCC:

gcc Browser-Navigation.c -o Browser-Navigation

Run

On Windows:

Browser-Navigation


On Linux/macOS:

./Browser-Navigation

📂 Project Structure
Browser-Navigation/
│
├── Browser-Navigation.c
└── README.md

🎯 Learning Objective

The main objective of this project is to understand how two stacks can work together to implement browser navigation and how the LIFO (Last In, First Out) principle is applied in real-world applications.

👨‍💻 Author

Created as a C programming and Data Structures project.
