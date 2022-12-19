# BombGame

Problem Description:

A helper header file is provided for this problem. Additional information is available at the end of the problem description.
BB Inc. recently launched a new online game called the Bomb Game. In this online game, players have to constantly upgrade their armors to protect themselves from bombing attacks.
The playfield can be seen as a one-dimensional grid containing N cells numbered from 1 to N. A round of the Bomb Game consists of a series of events. An event can be in one of the following two forms:
1. A new player enters the game. The player is located at cell ci and has a defence level of di. (We assume that the player never changes location.)
2. A bombing attack occurs. The attack spans cells in the range li to ri (inclusive). It has an explosive power of pi and will deal ki points of damage to all players in the range whose defence levels are not greater than pi (i.e., the player j takes damage if li ≤ cj ≤ ri and dj ≤ pi).
Now, given all M events in a round of the Bomb Game, can you figure out the total damage dealt to each player?


Input:

The first line of the input contains two integers N and M, representing the length of the field and the number of events in the round, respectively. Then M lines follow, the i-th of which describes the event i. Each line starts with a character Ti — the event type:
• If Ti = ‘P’, the i-th event is a new player event. The line then contains two more integers ci and di, representing the player’s location and defence level, respectively.
• Otherwise Ti = ‘A’, meaning the i-th event is a bombing attack. The line contains four more integers li, ri, pi, and ki, representing the range of the attack ([li,ri]), the attack’s explosive power, and the damage dealt per player.
• 1 ≤ N, M ≤ 105
• 1≤ci ≤N
• 1≤li ≤ri ≤N
• 1≤di,pi ≤109
• 1≤ki ≤104

Helper Header File:

This header file provides a one-dimensional array that supports fast range addition.
The array has N = 200000 cells, numbered from 1 to N. The values in these cells are initially all zeros. There are three functions to alter and access the array values:
• void Memory::reset(): Explicitly fill the whole array with zeros. This function runs in O(N) time.
• void Memory::add(int l, int r, int k): Add k to each cell in the range [l,r]. The argu- ments should satisfy the condition 1 ≤ l ≤ r ≤ N, while k can be any signed 32-bit integer. This function runs in O(log(N)) time.
• long long Memory::get(int x): This function returns the value currently stored in cell x. The argument x should be a positive integer not greater than N. This function also runs in O(log(N)) time.

Hint:

• You may want to try divide-and-conquer on the event timeline.
