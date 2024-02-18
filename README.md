# STM32-Tutorials-NucleoF334R8T6

This repository is a store for code used in [this](https://www.youtube.com/playlist?list=PLfMIkQ1CFX80ZINgbXPbDya_wZHMWcH8L) subset of YouTube videos to help anyone who wants to build an understanding of embedded software with specific emphasis on the STM32 Nucleo development boards. The board used in this subset of tutorials is the STM32F334R8T6 Nucleo board.

## Pre-requisites
This subset of tutorials focuses on setting up a STM32 Nucleo board and as such uses the STM32CubeIDE as the development tool which can be found [here](https://www.st.com/en/development-tools/stm32cubeide.html#get-software).

Also, there are some electronic circuits used throughout this series and requires components to be used in setting up those circuits. Of those that do have component circuits, basic circuit diagrams will be provided on the branch of each tutorial if that tutorial uses one. If there is no circuit for a tutorial the diagram folder will be empty on that branch.

## How to Use This Repo
The main branch of this repo contains the Hello World project from the first video in the tutorial series. Every subsequent video is then housed on it's own branch. Simply clone the project and checkout the branch of the tutorial you wish to use.

## Pointer Example
To build the pointer example code, enter the `Pointers Example` directory and run `cmake -S . -B Build`

Then enter the `Build` directory and run `make`

Then to run the executable run `./exe_output`
