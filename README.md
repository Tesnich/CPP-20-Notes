# CPP-20-Notes
## This repo serves as an online collection of code and notes I've written while doing an in-depth review of C++ and its modern concepts.

At time of writing all code builds with g++ (Homebrew GCC 12.2.0) 12.2.0 using -std=c++20. I've noticed some aspects of modern C++ structures failing to work properly with Apples' Clang compiler. In particular there are a few situations in which C++ 20 template concepts don't work properly or fail to build all together. If you find that to be the case please try a different compiler.

### All folders are considered there own workspace.

Below are my visual studio settings, if only to serve as a guide to my future self.

## tasks.json
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

## launch.json
```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "2. (lldb) Launch (MULTIPLE Files)", //update debugging name
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/program", //update program name to match what we build
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
            "preLaunchTask": "2. Build All Source Files With G++" //add our g++ build task as a pre launch task
        }
    ]
}
```

## c_cpp_properties.json
```
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "macFrameworkPath": [
                "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
            ],
            "compilerPath": "/usr/bin/clang",
            "intelliSenseMode": "macos-clang-arm64",
            "cppStandard": "c++20"
        }
    ],
    "version": 4
}
```
