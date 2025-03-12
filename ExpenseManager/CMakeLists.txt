cmake_minimum_required(VERSION 3.27)
project(Lab07bun)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab07bun main.cpp
        Repository/Repo.cpp
        Domain/Expense.cpp
        Tests/Tests.cpp
        Service/Service.h
        Repository/Repo.h
        Service/Service.cpp
        UI/UI.h
        UI/UI.cpp
)
