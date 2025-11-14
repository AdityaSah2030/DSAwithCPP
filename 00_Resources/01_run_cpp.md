# C++ Setup Guide for VSCode on Windows 11

## Setup Steps (Brief)

### 1. Install Visual Studio Code
- Download from [code.visualstudio.com](https://code.visualstudio.com/)
- Run installer and follow prompts

### 2. Install MinGW-w64 (C++ Compiler)
- Download from [winlibs.com](https://winlibs.com/) or [msys2.org](https://www.msys2.org/)
- Extract to `C:\mingw64`
- Add `C:\mingw64\bin` to System PATH environment variable

### 3. Install C/C++ Extension in VSCode
- Open VSCode
- Go to Extensions (Ctrl+Shift+X)
- Search for "C/C++" by Microsoft
- Click Install

### 4. Verify Installation
- Open Command Prompt
- Type `g++ --version`
- Should display compiler version

---

## How to Run a C++ File (Detailed)

### Method 1: Using Terminal (Recommended for Beginners)

#### Step 1: Create Your C++ File
1. Open VSCode
2. Click **File → New File** or press `Ctrl+N`
3. Save the file with a `.cpp` extension (e.g., `hello.cpp`)
   - Click **File → Save As** or press `Ctrl+S`
   - Choose a location (create a folder for your projects if needed)
   - Type the filename: `hello.cpp`
   - Click **Save**

#### Step 2: Write Your C++ Code
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

#### Step 3: Open Terminal in VSCode
1. Click **Terminal** in the top menu
2. Select **New Terminal** or press `` Ctrl+` `` (backtick key)
3. A terminal panel will appear at the bottom of VSCode

#### Step 4: Navigate to Your File Directory
- The terminal usually opens in your workspace folder
- If not, use `cd` command to navigate:
  ```
  cd path\to\your\folder
  ```
  Example: `cd C:\Users\YourName\Documents\CPP_Projects`

#### Step 5: Compile Your C++ File
1. In the terminal, type the following command:
   ```
   g++ hello.cpp -o hello
   ```
   **Explanation:**
   - `g++` = The C++ compiler command
   - `hello.cpp` = Your source code file
   - `-o hello` = Output flag, creates an executable named `hello.exe`

2. Press **Enter**
3. If there are no errors, you'll see no output (which is good!)
4. If there are errors, they'll be displayed - fix them in your code and recompile

#### Step 6: Run Your Compiled Program
1. In the same terminal, type:
   ```
   .\hello
   ```
   Or:
   ```
   hello.exe
   ```
2. Press **Enter**
3. You should see the output: `Hello, World!`

#### Step 7: Making Changes and Re-running
1. Edit your C++ code in the editor
2. Save the file (`Ctrl+S`)
3. Recompile using the same `g++` command
4. Run the program again with `.\hello`

---

### Method 2: Using Code Runner Extension (Faster)

#### Setup:
1. Install **Code Runner** extension from Extensions marketplace
2. Open VSCode Settings (`Ctrl+,`)
3. Search for "Code Runner: Run In Terminal"
4. Check the box to enable it

#### Running:
1. Open your `.cpp` file
2. Click the **▶ Run** button in the top-right corner, or
3. Press `Ctrl+Alt+N`
4. The file will automatically compile and run in the terminal
5. To stop execution, press `Ctrl+Alt+M`

---

### Method 3: Using Tasks (Most Professional)

#### One-Time Setup:
1. Open your C++ file
2. Press `Ctrl+Shift+P` to open Command Palette
3. Type "Tasks: Configure Default Build Task"
4. Select "C/C++: g++.exe build active file"
5. VSCode creates a `tasks.json` file

#### Building:
1. Press `Ctrl+Shift+B` to build (compile) your file
2. Check the terminal for compilation results

#### Running:
1. After building, open terminal (`` Ctrl+` ``)
2. Type `.\filename` (without .cpp extension)
3. Press Enter

---

## Common Issues and Solutions

### Issue: "g++ is not recognized"
**Solution:** MinGW bin folder not in PATH
1. Search "Environment Variables" in Windows
2. Click "Edit the system environment variables"
3. Click "Environment Variables" button
4. Under "System variables", find "Path"
5. Click "Edit"
6. Click "New"
7. Add `C:\mingw64\bin`
8. Click OK on all windows
9. Restart VSCode

### Issue: "Permission denied" when running
**Solution:** The program might still be running
- Close any previous instances
- Try running again

### Issue: Accented characters display incorrectly
**Solution:** Set console to UTF-8
- Add at the beginning of main():
  ```cpp
  system("chcp 65001");
  ```

---

## Tips for Efficient Workflow

1. **Use keyboard shortcuts:**
   - `Ctrl+S` - Save
   - `` Ctrl+` `` - Toggle terminal
   - `Ctrl+Shift+B` - Build
   - `Ctrl+Alt+N` - Run (with Code Runner)

2. **Keep terminal open** - Leave it at the bottom of your screen for quick access

3. **Create a project folder** - Keep all your .cpp files organized

4. **Compile with warnings:**
   ```
   g++ -Wall hello.cpp -o hello
   ```
   The `-Wall` flag shows all warnings

5. **Use debugging:** Install the debugger and set breakpoints to step through code

---

## Quick Reference Commands

```bash
# Compile
g++ filename.cpp -o outputname

# Compile with warnings
g++ -Wall filename.cpp -o outputname

# Run
.\outputname

# Compile and run in one line (Windows PowerShell)
g++ filename.cpp -o outputname; .\outputname

# Clean up (delete executable)
del outputname.exe
```