# SoStronk - matchmaking solution

## Problem Statement

<p> <a href="problem.pdf">Please open the PDF to view the problem statement</a>.</p>

**UPDATE:** This project has been pivoted to serve lobbies where players have pre-made teams (with friends). Such `pre-made teams` are then clubbed together to form `final teams` which then comprise of a pre-set, variable input `finalTeamSize` that is suitable for any particular game mode.

The number of team members in the final teams (N) is variable input.

> `final team1` = `pre-made team1` + `pre-made team2` + `pre-made team3` + ... + `pre-made teamN`
>
> `final team2` = `pre-made team(N+1)` + `pre-made team(N+2)` + `pre-made team(N+3)` ...
>
>*... and so on.*


## Input structure

```
N <- finalTeamSize
```
*next N lines depict members of each pre-made team per line in the following syntax: -*
```
member1name member1score member2name member2score member3name member3 score
member1name member1score
member1name member1score member2name member2score
```

for example:-
```
3
a 41 b 50
c 65 d 68
e 78
f 40
```


## Output Structure
The final output is quality-sorted. The best possible competition is shown first in the output.

```
finalTeam1 (avg score) vs finalTeam2 (avg score)
finalTeamX (avg score) vs finalTeamY (avg score)
```

for example:-
```
a,b,e (56.3333) vs f,c,d (57.6667)
f,a,b (43.6667) vs c,d,e (70.3333)
```

## Build Instructions

The solution is set up as a CMake project.

### On Linux

1. To configure use: -
```
cd solution
mkdir
cd build
cmake ..
```
(please do note the two dots in the end of the last command ^)

2. To build use: -
```
make -j8
```

## How to test

1. To configure & build use: -
```
cmake ..
make
```

2. To run tests use: -
```
make tests
```

## How to use

- You can find the binary for my solution with the file name `matchmake` in `build/src/` after performing the build instructions.

## License

none