
# To open and run c++ project: 
## Download Visual Studio 2022 (only for Windows users)
from https://visualstudio.microsoft.com/ or Microsoft Store

find in the project folder file ```projectName.vcxproj``` open it with Visual Studio 2022
## to run project
click **run** ```main.cpp```


# To run c++ project without Microsoft Visual Studio 2022
## God bless you
download compiler GCC + MinGW from https://winlibs.com/

open archieve directly into ```C:``` storage

set system Environment Variable Path to your bin folder in mingw64 folder

should be ```C:\mingw64\bin```
## Download IDE for C++
for example CodeLite:
https://codelite.org/

add existing compiler to build settings (set the same path to bin ```C:\mingw64\bin```)

click Build and Execute to run.

##
##

# To Open and Run a Java Project

## Install Java Development Kit (JDK)
https://jdk.java.net/
Ensure Java is installed by running in Command Prompt/Terminal:
``` java -version ```
``` javac -version ```
If the commands fail, set the JAVA_HOME environment variable and add bin to the system PATH.

## Download and install IntelliJ IDEA(recommended) from:
https://www.jetbrains.com/idea/download

Ensure the JDK is set correctly in File → Project Structure → SDKs.
Run the project by clicking Run on Main.java (or the appropriate main class).
