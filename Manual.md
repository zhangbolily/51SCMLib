51SCMLib
========

51SCMLib is a project with many C libraries for 51 single chip microcomputer.These libraries can drive the models linked to the chip.I develope these libraries on the platform of my STC89C52 51SCM bord.

**********************************************
Three folders are included in this project.
51SCMLib
|_____include
|_____src
|_____template

**********************************************
include
This folder contains all of the head files in this project.Setting the library correctly in Keil project and then you can use the functions of my project by including the head files.
A manual that has the introduction of every head file in detail and the explanation of the function containing in the file exists in this folder.

**********************************************
src
There are all of the source code that can be compiled to a library in this folder. Not only the manual that is the same as that one in the include folder, but also many notes that can be helpful for understanding.

**********************************************
template
This folder contains many templates. These templates work like the library. The manual in the folder intruduces the gengeral usage of every template and every template contains a mass mount of notes to help you understand its meanning.
We achieve the specific target through calling a function when we are using libraries. Different from the library, template is a standard form of a function that completes a specific work.Maybe you just need to change the name of a variable name.We can reduce the calling of functions and simplify the code in this way. This is a perfect choice for hackers.Not only this, you could add you own code to the template to achieve more functions.
