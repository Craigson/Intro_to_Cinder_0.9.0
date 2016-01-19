<h2> An introduction to Cinder </h2>
<h3> ITP Unconference 2016 </h3>

Useful links:

<p>Download Cinder: https://libcinder.org/download </p>
<p>Cinder Forum: https://forum.libcinder.org/#AllForums </p>
<p>Cinder Reference: https://libcinder.org/docs/release/v0.9.0/reference/index.html </p>
<p>Learn OpenGL: http://learnopengl.com/ </p>


<h4> </h4>
<h5> </h5>


<h4>Setting up Cinder</h4>
<h5>1) Download Cinder:</h5>
<p> Go to the Cinder website and download the latest release - 0.9.0 for Mac OSX (https://libcinder.org/download) </p>

<h5>2)	Move Cinder to your Documents folder </h5>
<p>
Move the extracted folder to your Documents folder. It’s a good Idea to keep the Cinder folder at this level (eg. /Users/Craig/Documents/cinder_0.9.0).  You can rename the folder, but I suggest keeping the release number, ie “0.9.0”, projects don’t necessarily work across separate builds.  In other words, a project that you built with cinder 0.8.4 may not necessarily run using 0.9.0 as as part of the library may have been deprecated.
</p>

<h5>3)Test that everything works </h5>
<p>
Navigate to the examples (called ‘samples’ in Cinder) and open the Xcode project file.  I like this one: '/Users/Craig/Documents/cinder_0.9.0/samples/_opengl/ParticleSphereGPU' 

Now, navigate to the 'xcode' folder and open the 'ParticleSphereGPU.xcodeproj' file.

Build and run the project by clicking the ‘play’ button, or using the keyboard shortcut ‘cmd+r’
</p>

![alt text](screenshots/1-run)

<h4>Section B:	Your first project</h4>
<p>
Create a folder inside the Cinder directory, give it a name, eg. “myProjects”.  the path to the folder should look something like this: ‘Users/Craig/Documents/Cinder_0.9.0/myProjects/’ 
NB: DO NOT MOVE THIS FOLDER AT ANY POINT ONCE YOU’VE CREATED IT.

Cinder provides us with a very convenient tool for creating new projects.  Use Tinderbox every time you want to create a new project.

Navigate to the folder Cinder > tools > TinderBox-Mac and open TinderBox - if you’ve just downloaded it you’ll need to right-click and select ‘open’

You should see something like this: 
</p>
![alt text](screenshots/1-tinderbox.jpg)

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

