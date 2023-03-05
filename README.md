# CPP-20-Notes
##This repo serves as an online collection of code and notes I've written while doing an in-depth review of C++ and its modern concepts.

At time of writing all code builds with g++ (Homebrew GCC 12.2.0) 12.2.0 using -std=c++20. I've noticed some aspects of modern C++ structures failing to work properly with Apples' Clang compiler. In particular there are a few situations in which C++ 20 template concepts don't work properly or fail to build all together. If you find that to be the case please try a different compiler.

###All folders are considered there own workspace.

##The tasks.json I used per folder...
```
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "2. Build All Source Files With G++",
			"command": "/opt/homebrew/bin/g++",
			"args": [
				"-fdiagnostics-color=always",
				"-g",
				"",
				"${fileDirname}/*.cpp",
				"-o",
				"${fileDirname}/program"
				//"${fileDirname}/${fileBasenameNoExtension}"
			],
			"options": {
				"cwd": "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": "build",
			"detail": "compiler: /opt/homebrew/bin/g++"
		}
	]
}
```
