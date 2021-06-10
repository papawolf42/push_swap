- # push_swap

  [42Cursus] This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.



I attend to implement three program.

```shell
.
├── checker
├── push_swap
└── simulator
```



In current version, the initial part of the simulator is implemented, and only the following commands are available.

```shell
make simulator
```

Currently, the simulator sorts incoming arguments using merge sort.

```shell
➜  02_push_swap git:(main) ✗ ./simulator "1 3 5 4 2"
1 2 3 4 5
➜  02_push_swap git:(main) ✗ ./simulator "1 -2 4 -8 16 -32 64 -128 256"
-128 -32 -8 -2 1 4 16 64 256
```

