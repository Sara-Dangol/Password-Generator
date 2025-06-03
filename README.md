🔐 Password Generator and Authentication Program

📝 Description
This C program serves two main purposes:
Generate a strong, random password based on a user-defined length.
Authenticate a user by prompting them to input the generated password, allowing up to 3 attempts.
It's a simple yet educational example demonstrating:
Random number generation
Secure input handling using fgets
String comparison
Basic password security practices


📂 Features
✅ User-defined password length (8 to 99 characters)
✅ Includes lowercase, uppercase, numbers, and symbols
✅ Prevents buffer overflow using safe input methods
✅ Authentication mechanism with 3 attempts allowed
✅ Clear and friendly error messages and prompts


🛠️ Requirements
A C compiler (e.g., gcc, clang)

Works on most platforms (Linux, Windows, macOS)


🧑‍💻 How to Compile and Run
Compile
bash
Copy
Edit
gcc password_auth.c -o password_auth
Replace password_auth.c with the filename you saved the code as.

Run
bash
Copy
Edit
./password_auth


🚀 Program Flow
Prompt for Password Length
The user is asked to enter a password length between 8 and 99.

Generate Password
A random password is generated using a set of characters including:
Lowercase letters
Uppercase letters
Numbers
Special characters
Display Password
The generated password is shown to the user.


Authentication
The user is prompted to re-enter the password they just saw, with a maximum of 3 tries.


Result
If correct: Access granted.
If incorrect after 3 attempts: Access denied.


📌 Notes

Input is sanitized using fgets to avoid buffer overflows.
The random number generator is seeded with time(NULL) to ensure unique passwords on each run.
The program uses strcmp to compare user input with the generated password securely.

      
📃 License
This is a simple educational project. Feel free to use or modify it for learning purposes.
