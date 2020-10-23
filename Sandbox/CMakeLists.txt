cmake_minimum_required(VERSION 3.18)

# Project name and a few useful settings. Other commands can pick up the results
project(
  Sandbox
  VERSION 0.1
  DESCRIPTION "A Sandbox Environment for PFE/"
  LANGUAGES CXX)

add_executable("${PROJECT_NAME}" "Main.cpp")
target_link_libraries("${PROJECT_NAME}" PRIVATE PFEngine::PFEngine)