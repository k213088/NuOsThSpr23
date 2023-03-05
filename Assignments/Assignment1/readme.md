                       OS ASSIGNMENT NO 1
                                  21k-3088
Check our present kernel
 ![image](https://user-images.githubusercontent.com/127028606/222973876-6d2a4652-74bd-4e4c-99b7-05bc4a135ac0.png)


Download new kernel files
 ![image](https://user-images.githubusercontent.com/127028606/222973884-d85e4a9e-26cd-44b5-95b5-ab878c29fa1a.png)

Run all these commands
sudo apt-get install gcc
 • sudo apt-get install libncurses5-dev 
• sudo apt-get install bison
 • sudo apt-get install flex 
• sudo apt install make
 • sudo apt-get install libssl-dev
 • sudo apt-get install libelf-dev
 • sudo add-apt-repository "deb http://archive.ubuntu.com/ubuntu $(lsb_release -sc) main universe"
 • sudo apt-get updated
• sudo apt-get upgrade
 
 ![image](https://user-images.githubusercontent.com/127028606/222973889-b83eedcf-56ca-4070-8055-4c5ddb8270fb.png)
![image](https://user-images.githubusercontent.com/127028606/222973892-146c565d-4bd6-45f3-895b-b1f474e4d56d.png)
![image](https://user-images.githubusercontent.com/127028606/222973902-70c51ece-2d1b-463f-9e1d-27650ba5e216.png)
![image](https://user-images.githubusercontent.com/127028606/222973909-9fe53419-1cfe-4512-b3e9-26a21dffa5e3.png)
![image](https://user-images.githubusercontent.com/127028606/222973918-9210c120-c73d-4dfb-8d81-7ce73781592b.png)
![image](https://user-images.githubusercontent.com/127028606/222973925-f0c27c71-df49-4f01-84ae-5ce3597b17e4.png)
![image](https://user-images.githubusercontent.com/127028606/222973932-456dcee8-05f0-4345-bba5-3a4e56d99409.png)
![image](https://user-images.githubusercontent.com/127028606/222973936-038f5567-6723-493e-9ee7-6c954de7a2d2.png)
![image](https://user-images.githubusercontent.com/127028606/222973940-516c1a0e-0cf3-40ba-8726-90a8e4266f6f.png)
![image](https://user-images.githubusercontent.com/127028606/222973948-610a6f0b-af8e-47f9-b85a-1bc684d0ce39.png)

 
 
 
 
 
 
 
 

Now extract the zip file of new kernel 
![image](https://user-images.githubusercontent.com/127028606/222973963-a66713c3-c47f-45bc-81b4-3f7f1eee36c9.png)

 
Now make hello.c and Makefile files in new kernel
 ![image](https://user-images.githubusercontent.com/127028606/222973974-a198402e-af03-45c2-80c6-1cdba54680f8.png)

And add code in hello.c given below
#include 
asmlinkage long sys_hello(void)
 { 
printk("Hello world\n"); return 0; 
}
And add this in Makefile
obj-y := hello.o

Now make folder with this name /arch/x86/entry/syscalls/syscall_64.tbl 
 
 
![image](https://user-images.githubusercontent.com/127028606/222973995-a92460fa-8d6d-45ad-82fb-144255afbbfe.png)
![image](https://user-images.githubusercontent.com/127028606/222973998-34bfd12d-5615-44eb-84c7-0e42ac393b29.png)



Now open the file and make these manipulation
 ![image](https://user-images.githubusercontent.com/127028606/222974016-91601afb-ad54-49fb-999d-2ae6852f1385.png)


Now open this file /include/linux/syscalls.h
 ![image](https://user-images.githubusercontent.com/127028606/222974025-4d691453-2bd7-4de5-b00c-9fd0bf700c56.png)

And paste hello.c function name in last
 

Now Change version and add the hello folder in the kernel’s Makefile
![image](https://user-images.githubusercontent.com/127028606/222974043-b3c805e1-a013-4814-ba20-c41d05209a4f.png)

 
Assign your roll number to EXTRAVERSION -21k-????

Now add hello/ at the end of second instance of core-y
 
![image](https://user-images.githubusercontent.com/127028606/222974048-c9e46a71-21e1-4290-a3df-7fd9d0424c71.png)

Run this command ls /boot | grep config
 ![image](https://user-images.githubusercontent.com/127028606/222974057-2b22b85b-9701-40ff-b81a-97ea05b3594a.png)

Type pwd and then cp /boot/config-4.10.0-28-generic kernel directory obtain by pwd
| make oldconfig -j4 run this command
 
![image](https://user-images.githubusercontent.com/127028606/222974062-9ec6bbb4-c0c4-4288-90ba-e1663f34e11e.png)

Now run these commands make clean –j2 and make –j2
2 is the number of cpu you have given please check yours and place it and do it with sodu su
  ![image](https://user-images.githubusercontent.com/127028606/222974066-6d3558ed-d7cc-4f1e-9645-d41d33b1734b.png)
![image](https://user-images.githubusercontent.com/127028606/222974069-4b7aa0ea-784d-49f1-a43f-2d9e40be305a.png)

Now install it with this command make modules_install install
  ![image](https://user-images.githubusercontent.com/127028606/222974112-0eb4d3bf-1e36-4e2e-a158-98a9a1ac9bed.png)
![image](https://user-images.githubusercontent.com/127028606/222974084-d8d26005-d4b4-4274-b9d6-eb0f052a6b5e.png)
![image](https://user-images.githubusercontent.com/127028606/222974087-e448ff13-ec41-4d71-b15c-b68e9fc1cf45.png)

Now shift to updated kernel
 
![image](https://user-images.githubusercontent.com/127028606/222974094-91eceb02-dffb-4aa2-b9f8-179555296e0b.png)
![image](https://user-images.githubusercontent.com/127028606/222974101-c0b60a07-de4e-4033-a800-c2d902e7ccfc.png)
![image](https://user-images.githubusercontent.com/127028606/222974108-facf0d6c-6491-43b0-bb0c-18418efa5a1a.png)
![image](https://user-images.githubusercontent.com/127028606/222974119-9e0560c1-6d5b-4123-a8c7-9f4f525ec771.png)
 
 
 


Code is executed
 ![image](https://user-images.githubusercontent.com/127028606/222974153-1e30b0d6-316c-44f4-980b-5da9c86c06ce.png)


DONE 


   
