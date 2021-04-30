# particles

Implements particle systems using openGL

TODO: Add a representative image for your project here

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake -G "Visual Studio 16 2019" ..
particles/build $ start CS312-Particles.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
particles/build $ ../bin/Debug/billboard
particles/build $ ../bin/Debug/confetti
particles/build $ ../bin/Debug/demo
```

*macOS*

Open terminal to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake ..
particles/build $ make
```

To run each program from build, you would type

```
particles/build $ ../bin/billboard
particles/build $ ../bin/confetti
particles/build $ ../bin/demo
```

## Results

<img width="499" alt="Screen Shot 2021-04-30 at 12 03 48 AM" src="https://user-images.githubusercontent.com/79232961/116648098-3c57e780-a94a-11eb-97ee-4cddbb4c5ed9.png">

![confetti](https://user-images.githubusercontent.com/79232961/116648106-3eba4180-a94a-11eb-9ee3-56683e6b8608.gif)



TODO: Show your work
