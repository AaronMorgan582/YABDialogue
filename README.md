# YABDialogue
This repository holds the code for thet partial refactoring of the dialogue system that I worked on for my capstone game, Your Average Bear (https://store.steampowered.com/app/2349870/Your_Average_Bear/).

This repository is not so average; due to Unreal Engine holding the source code under one main folder, I cannot create a repository for it (since it contains work not done by me). Instead, I decided to separate out my current work into separate folders so I could put them on github.

It was originally fully done in Blueprints, but I figured it would be a good lesson in C++ to refactor it. Most of the work I did on the game was with UI and Widgets, and as
I found out while refactoring, handling Widgets in C++ is a bit more cumbersome than handling them in Blueprints.

I may try to refactor all of my work done in the game into C++, but part of the difficulty is the fact that it has to interact with my teammate's work, who also worked
in Blueprints (about half of my team worked in Blueprints, and half in C++). This means I would have to refactor my work in such a manner that would encompass both
Blueprint functionality and C++ functionality, which is quite the project.

As of right now though, I would prefer to work on other games so I can expand my skillset into others areas, such as AI.
