# 📌 Expense Manager Application

## 📖 Description
This application is a structured and modular `Expense Management System`, developed using an `Object-Oriented Programming (OOP)` approach. It allows users to efficiently manage expenses by providing functionalities for adding, updating, deleting, filtering, and analyzing expense records.

---

## ✨ Key Features
### 🔹 **1. Object-Oriented and Modular Architecture**
- **Encapsulation**: Each functionality is encapsulated within appropriate classes (Domain, Repository, Service, UI).
- **Layered Structure**: Separation of concerns through Domain, Repository, Service, and UI layers ensures maintainability and scalability.
- **Modularity**: Components can be modified or extended without affecting the entire system

### 🔹 **2. Core Functionalities**
The application provides the following key features:
- 📌 **Add an expense**: Users can register a new expense by specifying its number, total cost, and type.
- 📌 **Update an expense**: Modify existing expense details.
- 📌 **Delete expenses**: Remove expenses based on their type.
- 📌 **List all expenses**: View all stored expenses.
- 📌 **Filter expenses:**:
    - By type (e.g., filter only "gas" expenses).
    - By value (e.g., filter expenses greater than a specific amount).
- 📌 **Calculate total expenses by type**: Sum up all expenses of a specific category.
- 📌 **Statistics & Summaries**: Retrieve financial insights by computing total expenses for specific categories
  
### 🔹 **3. User-Friendly Interface**
✅ Simple command-based interface for interaction.  
✅ Menu-driven approach with clear options.
✅ Real-time display of results after operations.

---

## 🏗️ Code Structure
The program follows a well-structured, `layered architecture`:
- 📂 **Domain (Expense.h, Expense.cpp)**: Defines the `Expense` class and its attributes.
- 📂 **Repository (Repo.h, Repo.cpp)**: Manages storage and retrieval of expenses.
- 📂 **Service (Service.h, Service.cpp)**: Implements business logic and operations on expenses.
- 📂 **UI (UI.h, UI.cpp)**: Provides an interactive menu-based user interface.
- 📂 **Tests (Tests.h, Tests.cpp)**: Contains unit tests for validating program correctness.
- 📂 **main.cpp**: The entry point of the application, initializing and integrating all modules.

---

## 🏆 Conclusion
This Expense Manager Application is an excellent example of a well-structured, modular, and scalable OOP project. Its layered architecture ensures maintainability, reusability, and clarity in code. 🚀
