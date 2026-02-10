# Caesar Cipher - File Encryption/Decryption (C++)

A comprehensive Caesar Cipher implementation in C++ using Object-Oriented Programming for encrypting and decrypting both files and text!

## Features

- 🔒 **File Encryption** - Encrypt entire text files with custom shift values
- 🔓 **File Decryption** - Decrypt encrypted files back to original text
- 🔤 **Quick Text Encryption/Decryption** - Encrypt or decrypt text directly without files
- 👁️ **File Viewer** - Preview file contents directly in the application
- 📊 **Customizable Shift** - Choose any shift value (1-25)
- ✨ **User-Friendly Menu** - Clean, intuitive interface
- 🛡️ **Input Validation** - Robust error handling and validation
- 🏗️ **OOP Design** - Clean class structure with encapsulation
- 📚 **Educational Info** - Learn about the Caesar Cipher algorithm

## What is Caesar Cipher?

The Caesar Cipher is one of the oldest and simplest encryption techniques. It's a **substitution cipher** where each letter in the plaintext is shifted by a fixed number of positions down the alphabet.

### Example (Shift = 3)

```text
Plain:  HELLO WORLD
Cipher: KHOOR ZRUOG
```

## How to Use

### 1. Compile the Program

```bash
g++ caesar-cipher.cpp -o caesar-cipher
```

### 2. Run the Program

```bash
./caesar-cipher        # Linux/Mac
caesar-cipher.exe      # Windows
```

### 3. Menu Options

- **Option 1: Encrypt a file** - Encrypt entire text files
- **Option 2: Decrypt a file** - Decrypt encrypted files
- **Option 3: Encrypt text (quick)** - Encrypt text directly without files
- **Option 4: Decrypt text (quick)** - Decrypt text directly without files
- **Option 5: View file content** - Preview any text file
- **Option 6: About Caesar Cipher** - Learn more about the algorithm
- **Option 7: Exit** - Close the application

## Example Usage

### Encrypting a File

1. Create a file called `secret.txt` with some text
2. Run the program and select option 1
3. Input file: `sample.txt`
4. Output file: `encrypted.txt`
5. Shift value: `5`
6. Your file is now encrypted! ✅

### Quick Text Encryption

1. Run the program and select option 3
2. Enter text: `Hello World`
3. Shift value: `7`
4. Output: `Olssv Dvysk` 🔒

## Code Structure

```cpp
class CaesarCipher {
    - Encryption/decryption logic
    - File I/O operations
    - Text processing
}

class CaesarCipherApp {
    - User interface
    - Menu system
    - Input handling
}
```

## Sample Files

A `sample.txt` file is included for testing. Try encrypting it!

## Technical Details

- **Algorithm**: Caesar Cipher (Substitution Cipher)
- **Supported Characters**: A-Z, a-z (uppercase and lowercase)
- **Non-alphabetic Characters**: Preserved as-is (numbers, spaces, punctuation)
- **Shift Range**: 1-25 (26 would result in no change)

## Learning Concepts

- Object-Oriented Programming (classes, encapsulation, methods)
- File I/O with `ifstream` and `ofstream`
- String manipulation with STL
- Character manipulation and ASCII values
- Modular arithmetic for wrapping
- Menu-driven program design
- Input validation with `cin` error handling
- Clean code architecture

## Security Note

⚠️ **Educational Purpose Only**: The Caesar Cipher is NOT secure for real-world use as it can be easily broken with frequency analysis or brute force (only 25 possible keys). This project is for learning file I/O, OOP, and basic cryptography concepts.

Enjoy learning about cryptography and C++! 🔐
