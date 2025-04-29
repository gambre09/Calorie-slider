# 🧮 Calorie Slicer — Weekly Calorie Balancer App (Qt C++)

**Calorie Slicer** is a simple Qt-based desktop application that helps users balance their weekly calorie intake using 7 vertical sliders (one for each day). It ensures the total calories consumed across the week match your maintenance calorie goal, helping you visually plan your diet.

---

## 🖼️ Screenshot
![image](https://github.com/user-attachments/assets/5dcc6ee5-96fa-42b4-a38f-884cf52cf05b)

---

## 🚀 Features

- 📥 Input your **daily maintenance calories**
- 📆 Adjust each day's calories with intuitive sliders
- 🔁 **Auto-balances** the 7th day's slider
- 📊 Displays:
  - Weekly calorie budget (auto-calculated)
  - Average daily calories
  - Total calories consumed across 7 days

---

## 🧰 Tech Stack

- Language: **C++**
- Framework: **Qt 5 / Qt 6**
- GUI: **Qt Widgets**

---

## 🛠️ How to Run

### Option 1: Using Qt Creator

1. Open `main.cpp` in Qt Creator.
2. Set up a Qt Widgets Application project.
3. Paste the code into `main.cpp`.
4. Build and run.

---

### Option 2: Using CMake (optional)

If you'd like to compile via CMake, use this file:

**CMakeLists.txt**
```cmake
cmake_minimum_required(VERSION 3.5)
project(CalorieSlicerApp)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)

add_executable(calorie_slicer main.cpp)
target_link_libraries(calorie_slicer Qt5::Widgets)
