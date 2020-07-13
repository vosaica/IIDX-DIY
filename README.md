![IIDX Controller](https://vosaica.github.io/BlogImg/IIDX_DIY/iidxController.jpg)

# **1. Intro**
This repo includes CAD files and arduino scripts to help you build your own IIDX controller with relatively low budget.

You can access my repository at my Github page: [IIDX-DIY](https://github.com/VOSAICA/IIDX-DIY)

#### **For the case of the controller**
The case is build with acrylic. You will need to find a factory and provide them with the CAD files. After getting them all cutted, you can glue them together. Some parts will also need screws to be assembled, you need to buy them in stores.  

#### **For the circuit of the controller**
We are using arduino as the basic control device here. For my own controller, I am using the arduino micro, but of course you can choose other type of arduino, but to ensure they have enough ports.

For building the complete circuit, the basic tools you will need are wires, soldering tin, and electric soldering iron. 

Besides, the bottons for the controller, the connection cables will also be needed. Since you could hardly find an excactly same type of the botton with the IIDX arcade, I will recommend you to search arcade botton on AliExpress. The encoder is also needed for the rotating part.

# **2. Let's begin!!!**

## Building the case

After you have get the cutted acrylic, you can assemble them according to the diagram below.

![explosion](https://vosaica.github.io/BlogImg/IIDX_DIY/explosion.png)

notice that there are special glue for acrylic, it can dissolve the acrylic so the case would be in better quality.

The bottom plank of the case should not be glued, be careful.

The extra hole on the top panel of the box is for moving the disk futher to attain the arcade distance standard. And for you can moving the disk anytime you want, you should use metal columns and glue to assemble the support for the disk.

![metalColumns](https://vosaica.github.io/BlogImg/IIDX_DIY/metalColumn.jpg)


## Building the circuit

The circuit part is based on arduino. 1 encoder, 9 bottons, wires, and a long microUSB cable are needed. Though you can use different model of arduino, I recommend you to use the arduino micro, since it could be powered directly by the microUSB port. 

For the wiring, I soldered my arduino on a board with holes and use wire to prolong the position of connecting the bottons. 

<center class="half">
    <img src="https://vosaica.github.io/BlogImg/IIDX_DIY/board1.jpg" width="200"/> &nbsp &nbsp &nbsp &nbsp <img src="https://vosaica.github.io/BlogImg/IIDX_DIY/board2.jpg" width="200"/>
</center>

I used port 4, 5, 7, 8, 9, 10, 14, 15 and 16 on arduino for connecting 9 bottons. The encoder used port 2 and 3 **It's necessary for encoder to use the 2 and 3 ports for special function. Do not change them** And you will have to give all the bottons a common ground, which is GND port on arduino and give encoder a 5V and GND.

My controller's wire looks like this:
![inside](https://vosaica.github.io/BlogImg/IIDX_DIY/inside.jpg)

## Now for the programs

The program will analog a keyboard input. You should have seen my program file in the repo, download an IDE for arduino and just upload that program. If you are using different port or key configuration, remember to change the buttonFunc function.

Change this section to give different ports with different keys:

    buttonFunc(6, 'g');
    buttonFunc(7, 'h');
    buttonFunc(8, 'j');
    buttonFunc(9, 'v');
    buttonFunc(10, 'b');
    buttonFunc(14, 'n');
    buttonFunc(16, 'm');
    buttonFunc(4, 'q');
    buttonFunc(15, 'e');

One more thing to notice is that the encoder I used is 600 p/r, if you are using different encoder, the sensitivity would change, and you can adjust that by changing the the first parameter in the encoderFunc. 

    encoderFunc(3, KEY_RIGHT_SHIFT, KEY_LEFT_SHIFT);
    //change the 3 to a larger value for higher sensitivity
    //Vice versa

# 3. **Something else**

The rotate disk of my controller is not fixed to the encoder, so it might drop. If you want to solve that problem, you could change the cad file of the transparent one. Replacing the disk with the part under it.

![replace the disk with this](https://vosaica.github.io/BlogImg/IIDX_DIY/disk.png)

Then you could 3d print this part with the 3D model included in my repo and glue them together.

![3D Part](https://vosaica.github.io/BlogImg/IIDX_DIY/3dPart.png)

Since 3D printing is in better accuracy, it could fit to the encoder better.

<center>
Have fun in IIDX!
</center>
<p align="right">vosaica</p>