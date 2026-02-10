# Caesar Cipher - File Encryption/Decryption

A powerful Caesar Cipher implementation in C for encrypting and decrypting text files!

## Features

- 🔒 **File Encryption** - Encrypt entire text files with custom shift values
- 🔓 **File Decryption** - Decrypt encrypted files back to original text
- 👁️ **File Viewer** - Preview file contents directly in the application
- 📊 **Customizable Shift** - Choose any shift value (1-25)
- ✨ **User-Friendly Menu** - Clean, intuitive interface
- 🛡️ **Input Validation** - Robust error handling and validation
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
gcc caesar-cipher.c -o caesar-cipher
```

### 2. Run the Program

```bash
./caesar-cipher        # Linux/Mac
caesar-cipher.exe      # Windows
```

### 3. Menu Options

- **Option 1: Encrypt a file**
  - Provide input filename
  - Provide output filename
  - Enter shift value (1-25)
  - File will be encrypted!

- **Option 2: Decrypt a file**
  - Provide encrypted filename
  - Provide output filename
  - Enter the same shift value used for encryption
  - File will be decrypted!

- **Option 3: View file content**
  - View any text file's content

- **Option 4: About Caesar Cipher**
  - Learn more about the algorithm

## Example Usage

### Encrypting a File

1. Create a file called `secret.txt` with some text
2. Run the program and select option 1
3. Input file: `sample.txt`
4. Output file: `encrypted.txt`
5. Shift value: `5`
6. Your file is now encrypted! ✅

### Decrypting a File

1. Run the program and select option 2
2. Input file: `encrypted.txt`
3. Output file: `decrypted.txt`
4. Shift value: `5` (same as encryption)
5. Your file is now decrypted! ✅

## Sample Files

A `sample.txt` file is included for testing. Try encrypting it!

## Technical Details

- **Algorithm**: Caesar Cipher (Substitution Cipher)
- **Supported Characters**: A-Z, a-z (uppercase and lowercase)
- **Non-alphabetic Characters**: Preserved as-is (numbers, spaces, punctuation)
- **Shift Range**: 1-25 (26 would result in no change)

## Learning Concepts

- File I/O operations (`fopen`, `fclose`, `fgetc`, `fputc`)
- Character manipulation and ASCII values
- Modular arithmetic for wrapping
- Menu-driven program design
- Input validation and error handling
- String processing

## Security Note

⚠️ **Educational Purpose Only**: The Caesar Cipher is NOT secure for real-world use as it can be easily broken with frequency analysis or brute force (only 25 possible keys). This project is for learning file I/O and basic cryptography concepts.

Enjoy learning about cryptography! 🔐
