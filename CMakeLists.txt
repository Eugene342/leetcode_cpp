cmake_minimum_required(VERSION 3.15)
project(leetcode-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic)

enable_testing()

# Авто-генерация целей: для каждой подпапки problems/<name> создаём цель <name> из всех .cpp
if(EXISTS ${CMAKE_SOURCE_DIR}/problems)
  file(GLOB problems RELATIVE ${CMAKE_SOURCE_DIR}/problems ${CMAKE_SOURCE_DIR}/problems/*)
  foreach(problem ${problems})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/problems/${problem})
      # Найдём все .cpp в этой подпапке
      file(GLOB cpp_files ${CMAKE_SOURCE_DIR}/problems/${problem}/*.cpp)
      if(cpp_files)
        # Используем имя папки в качестве имени таргета (предполагаем уникальность)
        add_executable(${problem} ${cpp_files})
        target_compile_features(${problem} PRIVATE cxx_std_20)
        target_include_directories(${problem} PRIVATE ${CMAKE_SOURCE_DIR}/problems/${problem})
        # Регистрируем тест с тем же именем
        add_test(NAME ${problem} COMMAND ${problem})
      endif()
    endif()
  endforeach()
endif()
