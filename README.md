<h2> An introduction to Cinder </h2>
<h3> ITP Unconference 2016 </h3>

Useful links:

<p>Download Cinder: https://libcinder.org/download </p>
<p>Cinder Forum: https://forum.libcinder.org/#AllForums </p>
<p>Cinder Reference: https://libcinder.org/docs/release/v0.9.0/reference/index.html </p>
<p>Learn OpenGL: http://learnopengl.com/ </p>

---

<h4> </h4>
<h5> </h5>


<h4>Setting up Cinder</h4>
<h5>1) Download Cinder:</h5>
<p> Go to the Cinder website and download the latest release - 0.9.0 for Mac OSX (https://libcinder.org/download) </p>

<h5>2)	Move Cinder to your Documents folder </h5>
<p>
Move the extracted folder to your Documents folder. It’s a good Idea to keep the Cinder folder at this level (eg. /Users/Craig/Documents/cinder_0.9.0).  You can rename the folder, but I suggest keeping the release number, ie “0.9.0”, projects don’t necessarily work across separate builds.  In other words, a project that you built with cinder 0.8.4 may not necessarily run using 0.9.0 as as part of the library may have been deprecated.
</p>

<h5>3) Test that everything works </h5>
<p>
Navigate to the examples (called ‘samples’ in Cinder) and open the Xcode project file.  I like this one: '/Users/Craig/Documents/cinder_0.9.0/samples/_opengl/ParticleSphereGPU' 

Now, navigate to the 'xcode' folder and open the 'ParticleSphereGPU.xcodeproj' file.

Build and run the project by clicking the ‘play’ button, or using the keyboard shortcut ‘cmd+r’
</p>

![alt text](screenshots/1-run)

---

<h4>Section B:	Your first project</h4>
<p>
Create a folder inside the Cinder directory, give it a name, eg. “myProjects”.  the path to the folder should look something like this: ‘Users/Craig/Documents/Cinder_0.9.0/myProjects/’ 
NB: DO NOT MOVE THIS FOLDER AT ANY POINT ONCE YOU’VE CREATED IT.

Cinder provides us with a very convenient tool for creating new projects.  Use Tinderbox every time you want to create a new project.

Navigate to the folder Cinder > tools > TinderBox-Mac and open TinderBox - if you’ve just downloaded it you’ll need to right-click and select ‘open’

You should see something like this: 
</p>
![alt text](screenshots/2-tinderbox.jpg)

<p>
‘Template’ should always be ‘Basic OpenGL’.

Give your project a name, I recommend calling this first one “TheBasics”.

For ‘location’, select the folder you created earlier - this is where all your future projects will be stored.

The environment is ‘xCode’ and make sure ‘create local git repository’ is unchecked.

Click Next.  Click Finish.
</p>

![alt text](screenshots/3-finish.jpg)

<p>
Navigate to the project folder and open your Xcode project file (‘your_project_name’.xcodeproj).

In Xcode, check that everything is working as it should by building and running the project (click the ‘play’ button, or cmd+r).
</p>

---

<h5>Section C:	What is Cinder? Why should we use it? and how does it work?</h5>
<p>
p5.js is an example of a library, or wrapper, for native javascript, designed to make creative coding more accessible to designers and artists etc.  In much the same way, Cinder, as well as openFrameworks, are creative coding frameworks based on the C++ language that are intended to make coding for creative purposes more accessible.  C++ is an incredibly powerful low-level language that puts a lot more of the decision making power into the hands of the programmer.  The power comes from the fact that you, as the programmer, are directly responsible for how your program uses your computer’s memory.  The advantage of this is that if you know what you’re doing,you can make things run incredibly efficiently.  The disadvantage of this however is that it’s significantly more complicated than higher level languages and, if you don’t manage the memory correctly, you can quite easily cause your application to crash.  Luckily, the folks who developed Cinder have created a comprehensive library of what are essentially convenience functions, that allow you to access the power of raw C++.  Furthermore, Cinder utilizes the power of OpenGL (Open Grapichs Library), which makes use of your computers GPU (Graphics Processing Unit) to achieve hardware-accelerated rendering.
</p>
<p>
C++ is a statically typed language.  A language is statically typed if the type of a variable is known at compile time. This in practice means that you as the programmer must specify what type each variable is (we’ll go through variable ‘types’ shortly).  Now, you might be asking yourself what exactly is “compile time”.  Well, when you build a c++ application, like a Cinder sketch, it goes through three stages before your application can be run: Preprocessing, Compilation, and Linking.
</p>
<p>
Preprocessing:
The preprocessor takes a C++ source code file and deals with the #includes, #defines and other preprocessor directives. The output of this step is a "pure" C++ file without pre-processor directives.  Any portion of the code that forms part of the preprocessor is marked with a hashtag ‘#’.  We’ll get to examples of these later.
</p>
<p>
Compilation:
The reason we use Xcode (or Microsoft Visual Studios for Windows) is because it comes with a compiler built-in.  The compiler takes the pre-processor's output and produces an object file from it.  Compilation refers to the processing of source code files (.c, .cc, or .cpp) and the creation of an 'object' file. This step doesn't create anything the user can actually run. Instead, the compiler merely produces the machine language instructions that correspond to the source code file that was compiled.  A simple way to think of this stage is to imagine that your compiler takes all the code from your separate .h and .cpp files (again, we’ll cover these soon), checks them for errors, and places them all in one file.  You can think of the p5.js, or p5.min.js files as the compiled versions of the p5 library for javascript.
</p>
<p>
Linking:
The linker takes the object files produced by the compiler and produces either a library or an executable file. Linking refers to the creation of a single executable file from multiple object files. In this step, it is common that the linker will complain about undefined functions (commonly, main itself). During compilation, if the compiler could not find the definition for a particular function, it would just assume that the function was defined in another file. If this isn't the case, there's no way the compiler would know -- it doesn't look at the contents of more than one file at a time. The linker, on the other hand, may look at multiple files and try to find references for the functions that weren't mentioned.
</p>
<p>
When you build and run your Cinder project, Xcode takes care of all three stages automatically.
</p>

---

<h5>Section D:	Hello World!</h5>
<p>
Open your newly created Xcode project  (eg. ‘TheBasics.xcodeproj’).

Xcode provides us with a debug console, similar to the one you’ll find in your web browser.  You can access the console by clicking the button shown in the screenshot below:
</p>
![alt text](screenshots/4-console.jpg)
<p>
Unlike a web browser, where you’d print something using Serial.print(“blah blah”), C++ uses the Standard Output Stream, which is part of the C++ Standard Template Library.  We usually access library member functions using the ‘::’ operator.  For example, to make use of the standard output stream or “cout” (think of this as an abbreviation for “console out”).  So, in order to print something to the console, the code would look like this:
	std::cout << “Hello World!”;

Try placing this line of code in your project’s setup() function.  Build and run the project.  Your result should look like this:
</p>
![alt text](screenshots/5-hello_world.jpg)
<p>
Having to write “std::” every time you want to print something to the console can be a bit tedious, along with using member functions from other libraries, so C++ allows us to use namespaces.  
</p>
![alt text](screenshots/6-namespaces.jpg)
<p>
You should see several lines of code in your project file that look like the image above.  “using namespace” is basically bringing everything from that library into your project’s scope.  Essentially, including “using namespace std;” in your code is like telling the compiler “consider everything in the std (standard ) library to be part of my project”.  By doing this, we can simply use: ‘cout << “Hello World!”; instead of “std::cout << “Hello World!”;

This seems trivial right now, but will save us time and effort later.

One last thing about about printing to the console… Think of Arduino’s “print()” function, it’ll print everything to the same line of the console, whereas “println()” includes a newline and carriage return, ie. it prints whatever you pass as an argument at the beginning of a new line.  To do this in C++, we include “endl” after “cout”, to tell the console stream that we want to end the line.  So, printing:

	cout << “Hello World, ”;
	cout << “my name is Craig.”;

will print the following to the console: 
	Hello World, my name is Craig.

whereas:

	cout << “Hello World, “ << endl;
	cout << “my name is Craig.” << endl;
	

will print:
<pre>
	```Hello World,```
	```my name is Craig.```
</pre>
<p>
