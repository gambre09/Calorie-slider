# Calorie-slider
A Qt-based desktop application that helps you balance weekly calorie intake using interactive sliders. Enter your daily maintenance calories and auto-adjust each day to stay on track. Visual, intuitive, and perfect for diet planning.

# 🧮 Calorie Slicer — Weekly Calorie Balancer App (Qt C++)

**Calorie Slicer** is a simple Qt-based desktop application that helps users balance their weekly calorie intake using 7 vertical sliders (one for each day). It ensures the total calories consumed across the week match your maintenance calorie goal, helping you visually plan your diet.

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

## 🖼️ Screenshot
> *(Add your own)*  
<img src="./screenshots/app-preview.png" width="600">

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
