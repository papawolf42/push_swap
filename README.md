# push_swap


these repo has submodules, so you need to command as like

```
git clone --recurse-submodules git@github.com:papawolf42/push_swap.git
```

  [42Cursus] This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.



I attend to implement three program.

```shell
.
├── checker
├── push_swap
└── simulator
```



In current version, the beta version of simulator is implemented, to build simulator, this command is available.

```shell
make simulator
```



Currently, the simulator work like this

```shell
➜  02_push_swap git:(main) ✗ ./simulator "2 1" 3 "6 5 8"
--------------------------------------------------------------------------------
Init a and b
2 
1 
3 
6 
5 
8 
- -
a b
--------------------------------------------------------------------------------
Exec sa [1]:
1 
2 
3 
6 
5 
8 
- -
a b
--------------------------------------------------------------------------------
Exec pb pb pb [4]:
6 3
5 2
8 1
- -
a b
--------------------------------------------------------------------------------
Exec ra rb [6]:
8 1
6 3
5 2
- -
a b
--------------------------------------------------------------------------------
Exec rra rrb [8]:
6 3
5 2
8 1
- -
a b
--------------------------------------------------------------------------------
Exec sa [9]:
5 3
6 2
8 1
- -
a b
--------------------------------------------------------------------------------
Exec pa pa pa [12]:
1 
2 
3 
5 
6 
8 
- -
a b
--------------------------------------------------------------------------------
```